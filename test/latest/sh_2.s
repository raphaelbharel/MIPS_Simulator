#sh
#25
#daryllimyt
#chained
#

lui $30, 0x2000
ori $3, $0, 0xAAAA
sh $3, 0($30)
sh $3, 2($30)
lw $2, 0($30)
ori $6, 0xAAAAAAAA
beq $2, $6 success
sll $0, $0, 0


jr $0
sll $0, $0, 0

success:
addi $2, $0, 25
jr $0
sll $0, $0, 0