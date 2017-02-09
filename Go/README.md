# How to install Go language
```bash
#
#  install Go
#
wget https://storage.googleapis.com/golang/go1.7.5.linux-amd64.tar.gz
tar -C /usr/local -xzf go1.7.5.linux-amd64.tar.gz 
rm go1.7.5.linux-amd64.tar.gz 
echo "export PATH=\$PATH:/usr/local/go/bin" >> /etc/profile
echo "export GOPATH=\$HOME/go" >> /etc/profile
echo "export PATH=\$PATH:\$GOPATH/bin" >> /etc/profile
. /etc/profile
```


# Configuration of $PATH, $GOPATH variables
From the ["Getting Started"](https://golang.org/doc/install) page of [golang.org](https://golang.org/):

> Add `/usr/local/go/bin` to the PATH environment variable.
> You can do this by adding this line to your `/etc/profile` (for a system-wide installation)
> or `$HOME/.profile`: 

```bash
export PATH=$PATH:/usr/local/go/bin
```

Most of the times that I have used a combination of Go and Beego framework, I add the following lines:

```bash
export PATH=$PATH:/usr/local/go/bin
export GOPATH=$HOME/go

# and for the `bee` tool:
export PATH=$PATH:$GOPATH/bin
```
