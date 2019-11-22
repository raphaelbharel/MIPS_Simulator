#sb
#25
#daryllimyt
#normal
#

lui $30, 0x2000
ori $3, $0, 25
sb $3, 3($30)
lw $2, 0($30)
sll $0, $0, 0
jr $0
sll $0, $0, 0