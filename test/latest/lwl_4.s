#lwl
#35
#daryllimyt
#misaligned by 2 bytes
#
#

lui $3, 0x2000
lui $4, 0xAABB
addi $4, $4, 0xCCDD
sw $4, 0($3)
ori $2, $0, 0x23ff
lwl $2, 2($3)
nop
srl $2, $2, 8
jr $0