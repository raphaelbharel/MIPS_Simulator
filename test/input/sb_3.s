#sb
#-11
#daryllimyt
#reading above datablock
#

lui $30, 0x2400
addi $3, $0, -2
sb $3, 0($30)
lw $2, 0($30)
nop
jr $0
nop