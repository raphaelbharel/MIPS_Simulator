#jalr
#20
#daryllimyt
#
#

lui $1, 0x1000
addi $1, $1, 40
addi $2, $0, 1
jalr $1
sll $0, $0, 0
addi $2, $2, 1
addi $2, $2, 1
addi $2, $2, 1
jr $0
sll $0, $0, 0


func:
addi $2, $31, 0
jr $0
sll $0, $0, 0