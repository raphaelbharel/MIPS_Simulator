#lw
#-11
#daryllimyt
#out of bounds memory read
#
#

lui $3, 0x4000
lw $2, 5($3)
jr $0
sll $0, $0, 0