#lh
#-1
#QFSW
#EOF
#tests/sample2.txt
#hello:)

addi $5, $0, -1
addi $4, $0, 8
lui $3, 0x3000

read:
lh $2, 2($3)
nop
beq $2, $5 writeskp
nop

write:
sw $2, 4($3)

writeskp:
addi $4, $4, -1
bgez $4, read
nop

jr $0
