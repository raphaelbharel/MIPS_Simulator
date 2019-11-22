#sh
#25
#daryllimyt
#normal
#

lui $30, 0x2000
addi $3, $0, 25
sh $3, 2($30)
lw $2, 0($30)
sll $0, $0, 0
jr $0
sll $0, $0, 0