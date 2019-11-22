#mult
#-128
#ChrisDeverall
#overflow
#
#

addi $3, $0, 1
sll $3, $3, 31
addi $4, $0, -1
mult $4, $3
mflo $2
srl $2, $2, 24

jr $0
nop