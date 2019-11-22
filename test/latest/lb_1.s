#lb
#200
#daryllimyt
#normal
#
#

lui $3, 0x2000
addi $4, $0, 200
sw $4, 0($3)
lb $5, 0($3)
lb $6, 1($3)
lb $7, 2($3)
lb $8, 3($3)
add $2, $5, $6
add $3, $7, $8
add $2, $2, $3
jr $0
sll $0, $0, 0