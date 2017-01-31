#include <stdio.h>
#include "io_public.h"

void main(void){
	//kprintf("test1.c main called!/n");
	int got, lib_console_dev, ldev;
	lib_console_dev = sys_get_console_dev();
	switch(lib_console_dev){
		case COM1:
			ldev = TTY0;
			break;
		case COM2:
			ldev = TTY1;
			break;
		default:
			printf("Unknown console device\n");
			return;
	}

	got = syswrite(ldev, "SYSWRITE\n",9);
//	exitcode();
}
