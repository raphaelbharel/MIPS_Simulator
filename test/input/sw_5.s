#SW
#0
#RaphaelBijaoui
#Store of 'R' at PUTC
#
#R

lui $30, 0x3000
addi $30, $30, 4
addi $10, $0, 82
sw $10, 0($30)
jr $0
nop