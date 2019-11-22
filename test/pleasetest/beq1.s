#beq
#2
#daryllimyt
#source=dest
#
#

addi $2, $0, 1
sub $3, $0, $2
beq $0, $0 end
addi $2, $2, 1
addi $2, $2, 1
addi $2, $2, 1
end: jr $0
sll $0, $0, 0 