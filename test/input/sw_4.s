#SW
#-11
#RaphaelBijaoui
#Incorrect store of 'R' at GETC
#
#

lui $30, 0x3000
addi $10, $0, 82
sw $10, 0($30)
jr $0
nop