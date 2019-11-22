#sh
#-11
#daryllimyt
#misaligned offset 3
#

lui $30, 0x2000
ori $3, $0, 13
sh $3, 3($30)
lw $2, 0($30)
sll $0, $0, 0
jr $0
sll $0, $0, 0