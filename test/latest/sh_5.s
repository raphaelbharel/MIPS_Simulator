#sh
#-11
#daryllimyt
#getc unsuccessful write
#
#

lui $30, 0x3000
addi $2, $0, 70
sh $2, 2($30)
jr $0
sll $0, $0, 0