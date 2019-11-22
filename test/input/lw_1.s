#lw
#42
#daryllimyt
#aligned word
#
#

lui $3, 0x2000
addi $4, $0, 42
sw $4, 0($3)
lw $2, 0($3)
jr $0
sll $0, $0, 0