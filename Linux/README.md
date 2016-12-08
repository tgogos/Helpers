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

#### use it together with `echo`
The output of the following is an empty string, making this approach safe for processes that are not running:

```bash
echo ps cax | grep aasdfasdf | grep -o '^[ ]*[0-9]*'
```

This approach is suitable for writing a simple empty string test, then even iterating through the discovered PIDs.

```bash
#!/bin/bash
PROCESS=$1
PIDS=`ps cax | grep $PROCESS | grep -o '^[ ]*[0-9]*'`
if [ -z "$PIDS" ]; then
  echo "Process not running." 1>&2
  exit 1
else
  for PID in $PIDS; do
    echo $PID
  done
fi
```

### kill process by sending `Ctrl`+`c` signal

```bash
# Basically Ctrl C sends the SIGINT (interrupt) signal
# while kill sends the SIGTERM (termination) signal by default unless you specify the signal to send.
$ kill -SIGINT processPIDHere
```
