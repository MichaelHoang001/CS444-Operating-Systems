#include <stdio.h>
#include <serial.h>
#include <cpu.h>
#include <gates.h>
#include "io_public.h"

void tunix_kernel_init(void);
//void set_trap_gate(int n, IntHandler *inthand_addr);
void syscallc(int, int, char *,int);
//void sys_call_exit(void);


void tunix_kernel_init(){
	ioinit();
	//set_trap_gate(0x80, &syscall);
	main();
	//call _ustart();
}
/*
void set_trap_gate(int n, IntHandler *inthand_addr){
}
*/
void syscallc(int eax, int dev, char *buf, int nchar){
	printf("eax>%d<\n",eax);
	syswrite(dev,buf,nchar);
/*	iir = inpt(baseport+UART_IIR)
	switch(iir&UART_IIR_ID){
		case UART_IIR_RDI:
			//rx function
		case UART_IIR_THRI:
			//tx function
			//no need to turn off tx int
		default:
			//default function
	}*/
}

