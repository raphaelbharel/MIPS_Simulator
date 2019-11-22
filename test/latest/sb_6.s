#sb
#-11
#daryllimyt
#instruction memory area
#
#

lui $30, 0x1000
ori $30, $30, 4
addi $2, $0, 70
sb $2, 3($30)
jr $0
sll $0, $0, 0