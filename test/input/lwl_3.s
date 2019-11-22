#lwl
#15
#daryllimyt
#instruction memory area
#
#
ori $5, $0, 15
lui $3, 0x1000
lwl $2, 3($3)
sll $0, $0, 0
srl $2, $2, 24
jr $0
sll $0, $0, 0