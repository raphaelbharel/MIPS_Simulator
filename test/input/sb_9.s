#sb
#0
#daryllimyt
#putc successful write lower 8 bits
#
#F

lui $3, 0x3000
addi $4, $0, 70
sb $4, 7($3)
addi $5, $0, 72
sb $5, 6($3)
jr $0
sll $0, $0, 0