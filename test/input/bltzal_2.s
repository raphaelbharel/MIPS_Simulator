#bgezal
#5
#daryllimyt
#manually set link
#

lui $31, 0x2000
addi $4, $0, 5
addi $3, $0, -2

bltzal $4 crash
sll $0, $0, 0 
addi $2, $2, 1
bne $2, $4 func
sll $0, $0, 0 
jr $0
sll $0, $0, 0 


crash:
lui $3, 0x2000
jr $3
sll $0, $0, 0 

func:
jr $31
sll $0, $0, 0 