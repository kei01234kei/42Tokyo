#!/bin/bash
arc=$(uname -a)
pcpu=$(grep "physical id" /proc/cpuinfo | sort | uniq | wc -l) 
vcpu=$(grep -c "^processor" /proc/cpuinfo)
tram=$(free -m | awk '$1 == "Mem:" {print $2}')
uram=$(free -m | awk '$1 == "Mem:" {print $3}')
pram=$(free | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')
tdisk=$(df --total -BG | awk '$1 == "total" {print $2}')
udisk=$(df --total -BM | awk '$1 == "total" {print $3}' | cut -f 1 -d "M")
pdisk=$(df --total -BG | awk '$1 == "total" {print $5}')
cpul=$(top -bn1 | grep '^%Cpu' | cut -c 9- | xargs | awk '{printf("%.1f%%"), $1 + $3}')
lb=$(who -b | awk '$1 == "system" {print $3 " " $4}')
lvmu=$(if [ "$(lsblk | grep -c "lvm")" -eq 0 ]; then echo no; else echo yes; fi)
ctcp=$(ss -t | grep -c ESTAB)
ulog=$(who | cut -d " " -f 1 | sort -u | wc -l)
ip=$(hostname -I)
mac=$(ip link show | grep "ether" | awk '{print $2}')
cmds=$(journalctl _COMM=sudo | grep -c COMMAND)
wall "	#Architecture: $arc
	#CPU physical: $pcpu
	#vCPU: $vcpu
	#Memory Usage: $uram/${tram}MB ($pram%)
	#Disk Usage: $udisk/${tdisk}b ($pdisk)
	#CPU load: $cpul
	#Last boot: $lb
	#LVM use: $lvmu
	#Connections TCP: $ctcp ESTABLISHED
	#User log: $ulog
	#Network: IP $ip ($mac)
	#Sudo: $cmds cmd"
	