#lwr
#17
#daryllimyt
#misaligned offset 2
#
#

lui $3, 0x2000
lui $4, 0xAABB
ori $4, $4, 0xCCDD
sw $4, 0($3)
lui $2, 0x11EE
ori $2, $2, 0x1234
lwr $2, 2($3)
sll $0, $0, 0
srl $2, $2, 24
jr $0
sll $0, $0, 0