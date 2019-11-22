#andi
#25
#daryllimyt
#zero imm extension
#
#

lui $2, 0xFFFF
andi $2, $2, 0xFFFF
bltz $2, -10
sll $0, $0, 0 
addiu $2, $2, 0xFF
andi $2, $2, 25
jr $0
sll $0, $0, 0 