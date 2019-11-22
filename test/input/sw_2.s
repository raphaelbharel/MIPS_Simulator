#SW
#0
#RaphaelBijaoui
#Store 'R' to ADDR_data
#
#

lui $30, 0x2000
addi $15, $0, 82
sw $15, 0($30)
jr $0
nop