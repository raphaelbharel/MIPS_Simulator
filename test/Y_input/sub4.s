#SUB
#-10
#RaphaelBijaoui
#Integer overflow
#
#

lui $3, 0x1000
lui $4, 0x100
sub $2, $3, $4
jr $0
nop