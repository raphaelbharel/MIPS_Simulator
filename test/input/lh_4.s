#lh
#-1
#daryllimyt
#sign ext
#
#

lui $3, 0x2000
addi $4, $0, -1
sw $4, 0($3)
lh $2, 2($3)
sll $0, $0, 0
srl $2, $2, 24
jr $0
sll $0, $0, 0