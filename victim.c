

#include"stdio.h"
#include<sched.h>
#include<time.h>

void funcCall(){

for(int i = 0 ; i < 100000; i++){
	__asm__ ( "F1: jmp L1;" // code with branches
		"F2: jmp L2;"
		"F3: jmp L3;"
		"F4: jmp L4;"
		"F5: jmp L5;"
		"F6: jmp L6;"
		"F7: jmp L7;"
		"F8: jmp L8;"
		"movl $10, %eax;"
		   "nop;"
	   	   "nop;"
		   "nop;"
		   "nop;"	   	
		"movl $10, %eax;"
                "movl $20, %ebx;"
                "addl %ebx, %eax;"
		   "nop;"
		   "nop;"
		   "nop;"
		"L1: nop;"
		"L2: nop;"
		"L3: nop;"
		"L4: nop;"
		"L5: nop;"
		"L6: nop;"
		"L7: nop;"
		"L8: nop;"
			);

}

}

int main(){
clock_t start,end;
start=clock();

funcCall();



printf("Hello wolrd victim program\n");
printf("Process 1: Starting...\n");
end=clock();
double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
printf("CPU time used: %f seconds.\n", cpu_time_used);



sched_yield();  // Yield the CPU, allowing other processes to run
usleep(1000);



start=clock();
printf("Process 1: Resumed...\n");

funcCall();

end=clock();
cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
printf("CPU time used: %f seconds.\n", cpu_time_used);


return 0;
}
