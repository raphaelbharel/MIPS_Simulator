#bgez
#0
#daryllimyt
#branch back
#

bgez $0, l2
sll $0, $0, 0 
addi $2, $0, 95

l1:
jr $0
sll $0, $0, 0 

l2:
bgez $0, l1
sll $0, $0, 0 
