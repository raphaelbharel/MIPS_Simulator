#mult
#-128
#daryllimyt
#overflow
#
#

lui $3, 0x8000
ori $4, $0, -1
mult $4, $3
mflo $2
srl $2, $2, 24
jr $0
sll $0, $0, 0