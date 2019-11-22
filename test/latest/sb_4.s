#sb
#0
#daryllimyt
#putc successful write
#
#F

lui $30, 0x3000
ori $30, $30, 4
ori $2, $0, 70
sb $2, 3($30)
jr $0
sll $0, $0, 0