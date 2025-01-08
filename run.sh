
for i in $(seq 1 10);
do
	taskset -c 0 ./victim  >> out &
	BACK_PID=$!
	taskset -c 0 ./attacker >> out &
	BACK_PID2=$!
	wait $BACK_PID
	wait $BACK_PID2

done
