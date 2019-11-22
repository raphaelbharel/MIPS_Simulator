#addi
#-10
#daryllimyt
#negative Overflow
#
#

addi $2, $2, 3
sll $2, $2, 29
add $2, $2, $2
jr $0
sll $0, $0, 0 