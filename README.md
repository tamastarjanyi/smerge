# smerge

A really simple program to take multiple input stream and merge those into one output stream.

Simple usage:

```bash
M=1 ./smerge \
<(while true ; do echo "$(date) - slave $(tr -dc A-Za-z </dev/urandom|head -c 32; echo '')" ; sleep $((RANDOM%M)); done &) \
<(while true ; do echo "$(date) - master $(tr -dc A-Za-z </dev/urandom|head -c 32; echo '')" ; sleep $((RANDOM%M)); done &)
```


Complex usage (Don't do that!!!):

```bash
mkfifo fa; mkfifo fb;
./smerge fa fb
while true ; do echo "$(date) -  slave" ; sleep $((RANDOM%3)); done >>fa &
while true ; do echo "$(date) - master" ; sleep $((RANDOM%3)); done >>fb & 
```
