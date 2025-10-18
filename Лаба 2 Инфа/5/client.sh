while read y;do
echo $y | ncat localhost 733
ncat -l 732
done