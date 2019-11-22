#bltzal
#9
#daryllimyt
#normal
#

addi $2, $0, 1
bltzal $2, func
addi $2, $2, 2
addi $2, $2, 3
addi $2, $2, 3
jr $0
sll $0, $0, 0 


func: addi $2, $2, 10
jr $31
sll $0, $0, 0 