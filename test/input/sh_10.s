#sh
#0
#daryllimyt
#putc successful write offset 2
#
#F

lui $3, 0x3000
ori $4, $0, 70
sh $4, 6($3)
ori $5, $0, 72
sh $5, 4($3)
jr $0
sll $0, $0, 0