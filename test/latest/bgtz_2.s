#bgtz
#4
#daryllimyt
#source<0
#

addi $2, $0, 1
sub $3, $0, $2
bgtz $3 end
addi $2, $2, 1
addi $2, $2, 1
addi $2, $2, 1
end: jr $0
sll $0, $0, 0 