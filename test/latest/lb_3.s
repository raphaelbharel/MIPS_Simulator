#lb
#-11
#daryllimyt
#out of bounds memory read
#
#

lui $3, 0x4000
lb $2, 5($3)
jr $0