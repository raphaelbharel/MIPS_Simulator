#sb
#69
#QFSW
#composite
#

addi $30, $0, 0x20
sll $30, $30, 24
addi $3, $0, 1
sb $3, 0($30)
sb $3, 1($30)
sb $3, 2($30)
sb $3, 3($30)
lw $2, 0($30)
or $6, $6, $3
sll $3, $3, 8
or $6, $6, $3
sll $3, $3, 8
or $6, $6, $3
sll $3, $3, 8
or $6, $6, $3
beq $2, $6 success
nop


jr $0
nop

success:
addi $2, $0, 69
jr $0
nop