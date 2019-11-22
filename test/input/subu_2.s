#SUBU
#-11
#RaphaelBijaoui
#Unsigned subtraction in edge of ADDR_INSTR
#
#

lui $29, 0x1100
addi $5, $0, 1
addi $6, $0, 7
jr $29
subu $2, $5, $6
jr $0
nop