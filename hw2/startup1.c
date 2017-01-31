/* C startup file, called from startup0.s-- */
void startupc(void);

void startupc(void){
	clr_bss();                    /* clear BSS area (uninitialized data) */
	init_devio();                 /* latch onto Tutor-supplied info, code */
	//(void)main();                 /* execute user-supplied main */
	(void)tunix_kernel_init();
}
