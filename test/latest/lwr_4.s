#lwr
#85
#daryllimyt
#misaligned offset 0
#
#

lui $3, 0x2000
lui $4, 0x11EE
ori $4, $4, 0x22FF
sw $4, 0($3)
lui $2, 0xAABB
ori $2, $2, 0xCCDD
lwr $2, 0($3)
sll $0, $0, 0
jr $0
sll $0, $0, 0