#addu
#1
#daryllimyt
#underflow
#
#


addi $5, $0, 1
sll $5, $5, 30
addi $3, $0, 1
sll $3, $3, 30
addu $5, $3, $5
srl $2, $5, 31
jr $0
sll $0, $0, 0


