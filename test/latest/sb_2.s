#sb
#25
#daryllimyt
#chained
#

lui $30, 0x2000
ori $3, $0, 0xAABBCCDD
sb $3, 0($30)
sb $3, 1($30)
sb $3, 2($30)
sb $3, 3($30)
lw $6, 0($30)
ori $7, 0xDDDDDDDD
beq $7, $6 success
nop


jr $0
nop

success:
addi $2, $0, 25
jr $0
nop