#date command is date +%T
HMS=(date +"%H:%M:%S")
while sleep 1
do HMS=$(date +"%H:%M:%S")
echo $HMS > stdin
done
