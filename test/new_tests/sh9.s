#sh
#-11
#QFSW
#misaligned
#

addi $30, $0, 0x20
sll $30, $30, 24
addi $3, $0, 13
sh $3, 3($30)
lw $2, 0($30)
nop
jr $0
nop