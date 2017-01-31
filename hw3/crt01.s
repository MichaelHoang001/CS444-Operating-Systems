# file:  crt01.s

.globl _ustart1
.text

_ustart1:       movl $0x3ffff0, %esp         #reinit the stack
                movl $0, %ebp                # and frame pointer
                call _main1                   #call main in the uprog.c
                pushl %eax                   #push the retval=exit_code on stack
                call _exit                   # call sysycall exit

