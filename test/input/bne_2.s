#bne
#2
#daryllimyt
#source!=dest
#

ori $2, $0, 1
sub $3, $0, $2
bne $0, $3 end
addi $2, $2, 1
addi $2, $2, 1
addi $2, $2, 1
end: jr $0
sll $0, $0, 0