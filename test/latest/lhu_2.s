#lhu
#-11
#daryllimyt
#misaligned
#
#

lui $3, 0x2000
addi $4, $0, 420
sw $4, 0($3)
lhu $2, 3($3)
jr $0
sll $0, $0, 0