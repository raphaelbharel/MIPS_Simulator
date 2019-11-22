#lwr
#17
#daryllimyt
#aligned offset 3
#
#

lui $3, 0x2000
lui $4, 0xAABB
addi $4, $4, 0xCC11
sw $4, 0($3)
ori $2, $0, 0x1234
lwr $2, 3($3)
sll $0, $0, 0
jr $0
sll $0, $0, 0