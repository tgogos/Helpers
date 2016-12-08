# Linux


## Processes
Sources:
- [http://stackoverflow.com/questions/9117507/linux-unix-command-to-determine-if-process-is-running](http://stackoverflow.com/questions/9117507/linux-unix-command-to-determine-if-process-is-running)
- [http://stackoverflow.com/questions/514771/equivalent-of-ctrl-c-in-command-to-cancel-a-program](http://stackoverflow.com/questions/514771/equivalent-of-ctrl-c-in-command-to-cancel-a-program)


### find list of PIDs

```bash
# example for "httpd"
# this could give back:
# 3519 3521 3523 3524
$ ps cax | grep httpd | grep -o '^[ ]*[0-9]*'
```


### kill process by sending `Ctrl`+`c` signal

```bash
# Basically Ctrl C sends the SIGINT (interrupt) signal
# while kill sends the SIGTERM (termination) signal by default unless you specify the signal to send.
$ kill -SIGINT processPIDHere
```

