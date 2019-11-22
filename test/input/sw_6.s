#SW
#-11
#RaphaelBijaoui
#LSB address error check
#
#

lui $30, 0x2000
addi $30, $30, 1
addi $15, $0, 82
sw $15, 0($30)
jr $0
nop