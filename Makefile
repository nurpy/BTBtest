

test: victim attacker
	echo "Testing"
	taskset -c 0 ./attacker &
	taskset -c 0 ./victim &
victim: 
	gcc -c victim.c -o victim.o
	gcc victim.o -T linkerScriptVictim.ld -o victim
	echo "Compiled victim"
attacker:
	gcc -c attacker.c -o attacker.o
	gcc attacker.o -T linkerScriptAttacker.ld -o attacker
	echo "Compiled attacker"
clean:
	rm *.o
	rm victim
	rm attacker


