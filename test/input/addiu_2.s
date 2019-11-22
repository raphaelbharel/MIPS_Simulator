#addiu
#-1
#daryllimyt
#imm extension
#
#

addiu $2, $2, 0xFFFF
bgtz $2, -10 
sll $0, $0, 0 
jr $0
sll $0, $0, 0 