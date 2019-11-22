#addi
#-10
#daryllimyt
#positive Overflow
#
#

addi $3, $3, 32767
sll $3, $3, 16
addi $2, $2, 32767
sll $2, $2, 1
add $3, $3, $2
addi $3, $3, 15305
jr $0
sll $0, $0, 0 