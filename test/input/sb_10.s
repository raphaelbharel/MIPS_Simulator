#sb
#0
#daryllimyt
#reading datablock top
#
#

lui $3, 0x2400
sb $2, -1($3)
jr $0
sll $0, $0, 0