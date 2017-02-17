Docker - quick reference
========================

## Links
 - [MySQL Docker Containers: Understanding the basics](https://severalnines.com/blog/mysql-docker-containers-understanding-basics)
 
## Images
 - search for images on https://hub.docker.com
 - pull image example: `docker pull resin/rpi-raspbian`
 - list available (already pulled) images `docker images`
 - delete image example: `docker rmi resin/rpi-raspbian`

## Containers
### Run

```bash
#  Most of the times I used the following...
#  but it has problems because .profile is not used
#  and you have to do it manually
docker run -itd --name=CONTAINER_NAME ubuntu:TAG /bin/bash

#  To overcome this I started using the following:
docker run -itd --name=CONTAINER_NAME ubuntu:TAG bash -l

#  more info here:
#  http://stackoverflow.com/questions/38024160/how-to-get-etc-profile-to-run-automatically-in-alpine-docker
```

 - run a new container example: `docker run -it resin/rpi-raspbian`
    - docker creates a `new` container based on the image selected and assigns a random name, for example `lonely_keller`
    - run a new container providing name: `docker run --name ndpi_test -it resin/rpi-raspbian`
    - changes to this container (apt-get install... etc) will not affect future containers being generated based on the same image
 - start the container with: `docker start lonely_keller`
 - stop the container with: `docker stop lonely_keller`
 - rename a container with: `docker rename old_container_name new_container_name`
 - get access to the console of every running container with: `docker attach container_name`
 - return back to the host by pressing `Ctrl+p` and then `Ctrl+q`
 - list the running containers: `docker ps`
 - list all the containers: `docker ps -a`
 - remove container: `docker rm container_name`
 - remove all containers: `docker rm $(docker ps -a -q)`
  - maybe you will have to stop all containers first: `docker stop $(docker ps -a -q)`

## Commit images to Docker Hub
example:
```bash
docker commit temp_container tgogos/ffmpeg:bbbunny-480
docker push tgogos/ffmpeg:bbbunny-480
```

### Possible states
figure from: [https://docs.docker.com/engine/reference/api/docker_remote_api/](https://docs.docker.com/engine/reference/api/docker_remote_api/)
 ![docker events](event_state.png)


## Docker networking
[https://blog.docker.com/2016/01/webinar-qa-docker-networking/](https://blog.docker.com/2016/01/webinar-qa-docker-networking/)

`docker0` (172.17.0.1/16) is the default bridge network that new containers are attached to if nothing else is specified.
### Create a new network and run a container
```bash
docker network create frontend # (172.18.0.1/16)
docker network ls
docker run  -d --name rose --net=frontend busybox top
#busybox is the docker image to pull (if not already available) and then start with command "top"
docker exec rose ifconfig
```
### Ping the container
```bash
docker run --rm busybox ping -c 4 rose
# you get ping: bad address 'rose'
# the above is because of network isolation. By default docker0 is used so 'rose' cannot be found.
# it works only if network is specified, like this:
docker run --rm --net=frontend busybox ping -c 4 rose
```

### Create another network and connect the container
```bash
docker network create backend # (172.19.0.1/16)
docker network connect backend rose
docker exec rose ifconfig
```

### Disconnect from a network and destroy it
```bash
docker network disconnect backend rose
docker exec rose ifconfig
docker network rm backend
docker network ls
```

## Copy files from host to container
`docker cp /path/filename container_name:/path/filename`


## Expose Docker Remote API
```bash
cd /etc/systemd/system/docker.service.d
# create a file: remote-api.conf
sudo nano remote-api.conf

# add the following lines (without the #):
#   [Service]
#   ExecStart=
#   ExecStart=/usr/bin/dockerd -H tcp://0.0.0.0:4243 -H unix:///var/run/docker.sock

# reloading daemon definitions
sudo systemctl daemon-reload
sudo systemctl restart docker
```

## apt-get install ... (packages sometimes needed)
```bash
#  ifconfig
apt-get install net-tools

#  ping
apt-get install iputils-ping

#  traceroute
apt-get install traceroute
```
