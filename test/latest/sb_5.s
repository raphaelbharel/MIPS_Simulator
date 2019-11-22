#sb
#-11
#daryllimyt
#getc unsuccessful write
#
#

lui $30, 0x3000
addi $2, $0, 70
sb $2, 3($30)
jr $0
sll $0, $0, 0