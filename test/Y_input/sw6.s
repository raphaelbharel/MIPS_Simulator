#sw
#0
#ChrisDeverall
#instr
#
#

lui $30, 0x10000000
addi $15, $0, 82
sw $15, 0($30)
jr $0
nop