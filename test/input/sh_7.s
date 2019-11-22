#sh
#-11
#daryllimyt
#reading above datablock
#
#

lui $3, 0x2400
sh $2, 0($3)
jr $0
sll $0, $0, 0