#lwl
#51
#daryllimyt
#misaligned by 3 bytes
#
#

lui $3, 0x2000
lui $4, 0xAABB
addi $4, $4, 0x2233
sw $4, 0($3)
ori $2, $0, 0xCCDD
lwl $2, 3($3)
nop
srl $2, $2, 24
jr $0