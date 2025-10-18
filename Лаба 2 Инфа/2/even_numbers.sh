for i in {1..20}; do
num=$((i % 2))
if [ "$num" -eq 0 ];then
echo "$i"
fi
done
sleep 3