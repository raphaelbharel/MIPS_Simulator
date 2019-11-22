#multu
#127
#daryllimyt
#large number
#
#

lui $4, 0x8000
ori $3, $0, -1
multu $4, $3
mfhi $2
srl $2, $2, 24
jr $0
