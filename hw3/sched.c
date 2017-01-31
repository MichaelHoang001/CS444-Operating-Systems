#include <stdio.h>
#include "sched.h"
#include "tsystm.h"

extern void ustart1(void), ustart2(void), ustart3(void);
int main(void){
	return 0;
}

void schedule(){
	PEntry *newproc = &proctab[0];
	PEntry curprocRef = *curproc;	// these four lines are a
	PEntry newprocRef;		// mess of variables
	char zomchar;			// needed to keep debug
	char out[10];			// log running smoothly
	int i;
	for (i = 1; i<NPROC; i++){
		if (proctab[i].p_status == RUN){
			newproc = &proctab[i];
			i = NPROC;
		}
	}
	newprocRef = *newproc;

	//debug_log string builder
	if (curprocRef.p_status == ZOMBIE)
		zomchar = 'z';
	sprintf(out, "|(%d%c-%d)", curprocRef.p_id, zomchar, newprocRef.p_id);
	debug_log(out);

	asmswtch(curproc,newproc);
}


void sleep(WaitCode event){
	PEntry curentry;
	cli();
	curentry = *curproc;
	curentry.p_status = BLOCKED;
	curentry.p_waitcode = event;
	sti();
	schedule();
}

void wakeup(WaitCode event){
	int i;
	cli();
	for(i=0; i<NPROC; i++){
		if (proctab[i].p_status == BLOCKED && proctab[i].p_waitcode == event){
			proctab[i].p_status = RUN;
		}
	}
	sti();
}
