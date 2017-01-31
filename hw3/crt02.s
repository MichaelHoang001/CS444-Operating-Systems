# file:  crt02.s

.globl _ustart2
.text

_ustart2:       movl $0x3ffff0, %esp         #reinit the stack
                movl $0, %ebp                # and frame pointer
                call _main2                   #call main in the uprog.c
                pushl %eax                   #push the retval=exit_code on stack
                call _exit                   # call sysycall exit

