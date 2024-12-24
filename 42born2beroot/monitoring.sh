#!/bin/bash

architecture=$(uname -a)
iprocessors=$(grep "physical id" /proc/cpuinfo | wc -l)
vcpu=$(nproc)
Ram_usage=$(free -m | grep Mem | awk '{printf "%s/%s MB (%.2f%%)", $3, $2, $3/$2 * 100 }')
Disk_usage=$(df -m --total | grep 'total' | awk '{printf "%d/%dGb (%s)",$3, $4/1024, $5}')
cpu_usage=$(top -b -n 1 | grep  "Cpu(s)" | awk '{printf "%.1f%%",($2 + $4)}')
last_boot=$(who -b | awk '{print $3, $4}')
numbre_connections=$(ss -t | wc -l)
count_users=$(who  | wc -l)
s_cmd=$(grep -c "sudo" ~/,bash_history)
check_vgm (){
if lsblk -o NAME,TYPE | grep -q "lvm";then
        echo "yes"
else
        echo "no"
fi
}

print_ip_mac () {
IP=$(hostname -I)
MAC=$(ip link show | grep ether | awk '{print $2}')
echo "$IP ($MAC)"
}


status() {
echo "#architecture: $architecture"
echo "#processors: $iprocessors"
echo "#vcpu: $vcpu"
echo "#Memory Usage: $Ram_usage"
echo "#Disk Usage: $Disk_usage"
echo "#CPU lead: $cpu_usage"
echo "#Last boot: $last_boot"
echo "#LVM use: $(check_vgm)"
echo "#Connections TCP: $numbre_connections ESTABLISHED"
echo "#User log: $count_users"
echo "#Network: IP $(print_ip_mac)"
echo"#Sudo: $s_cmd cmd"
}

while true; do
        status | wall
        sleep 600
done
