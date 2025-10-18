while true;do
ncat -l 733 | while read;do
echo "Сообщение получено" | ncat localhost 732
done
done