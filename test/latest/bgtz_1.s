#bgtz
#0
#daryllimyt
#branch back
#

addi $3, $0, 1
bgtz $3, l2
sll $0, $0, 0 
addi $2, $0, 69

l1:
jr $0
sll $0, $0, 0 

l2:
bgtz $3, l1
sll $0, $0, 0 
