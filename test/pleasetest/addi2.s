#addi
#-10
#daryllimyt
#positive Overflow
#
#

addi $3, $3, 0x7FFF
sll $3, $3, 16
addi $2, $2, 0x7FFF
sll $2, $2, 1
add $3, $3, $2
addi $3, $3, 0x3BC9
jr $0
sll $0, $0, 0 