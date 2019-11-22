#mult
#0
#daryllimyt
#overflow
#
#

lui $3, 0x8000
ori $4, $0, -1
mult $4, $3
mfhi $2
jr $0
sll $0, $0, 0