#add
#-10
#QFSW
#underflow
#
#

addi $3, $0, 1
sll $3, $3, 31
addi $3, $3, 2
add $2, $3, $3
jr $0