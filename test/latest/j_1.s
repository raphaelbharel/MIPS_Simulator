#j
#12
#daryllimyt
#
#

addi $2, $0, 1
j func
addi $2, $2, 1
addi $2, $2, 1
addi $2, $2, 1

func: addi $2, $2, 10
jr $0
sll $0, $0, 0