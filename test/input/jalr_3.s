#JALR
#-11
#RaphaelBijaoui
#Outside bounds
#
#

lui $10, 0x4000
addi $2, $0, 1
jalr $10
sll $0, $0, 0
addi $2, $2, -1
addi $2, $2, 5
add $2, $2, $2
jr $0