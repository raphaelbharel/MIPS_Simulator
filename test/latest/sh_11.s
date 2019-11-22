#sh
#0
#daryllimyt
#reading datablock top
#
#

lui $3, 0x2400
sh $2, -2($3)
jr $0
sll $0, $0, 0