#jal
#7
#daryllimyt
#delay slot
#

addi $2, $0, 1
jal func
addi $2, $2, 1
addi $2, $2, 1
addi $2, $2, 1

func: addi $2, $2, 5
jr $0