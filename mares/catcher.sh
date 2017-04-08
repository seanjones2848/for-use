./mangercentos & PID=$!
kill -14 $PID
read -n 1 -p "Dearest King, The horses have been coralled, would you like them tamedor to remain wild? (t/w)" ans
if &ans = "t"; then
	./tame & echo "Here are your tamed horses."
else
	./wild & echo "You asked for it..."
fi
