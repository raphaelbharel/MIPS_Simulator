#SW
#-11
#RaphaelBijaoui
#Misaligned store of 'R' to ADDR_data
#
#

lui $30, 0x2000
addi $15, $0, 82
sw $15, 1($30)
jr $0
nop