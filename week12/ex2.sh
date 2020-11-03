gcc ex2.c -o ex2
# use sysctl -a | grep machdep.cpu because /proc/cpuinfo does not work on Mac OS
# and these two commands are equivalent
sysctl -a | grep machdep.cpu | ./ex2 ex2.txt
rm ex2
