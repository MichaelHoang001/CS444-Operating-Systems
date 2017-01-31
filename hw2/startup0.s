# asm startup file
# very first module in load
.globl _startup0exit
.text

   movl $0x3ffff0, %esp   # set user program stack
   movl $0, %ebp          # make debugger backtrace terminate here
   call _startupc         # call C startup, which calls user main
_startup0exit:
   int $3                 # return to Tutor

