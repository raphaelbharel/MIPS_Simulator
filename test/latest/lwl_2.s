#lwl
#1
#daryllimyt
#misaligned by 1 byte
#
#

lui $3, 0x2000
lui $4, 0xAABB
addi $4, $4, 0xCCDD
sw $4, 0($3)
ori $2, $0, 0xFF01
lwl $2, 1($3)
nop
srl $2, $2, 0
jr $0