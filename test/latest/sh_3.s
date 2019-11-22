#sh
#-11
#daryllimyt
#reading above datablock
#

lui $30, 0x2400
addi $3, $0, -5
sh $3, 2($30)
lw $2, 0($30)
sll $0, $0, 0
jr $0
sll $0, $0, 0