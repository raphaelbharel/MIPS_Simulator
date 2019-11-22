#lwl
#15
#daryllimyt
#aligned
#
#

lui $3, 0x2000
ori $4, $0, 15
sw $4, 0($3)
ori $2, $0, 10
lwl $2, 0($3)
jr $0