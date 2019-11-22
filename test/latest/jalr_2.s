#jalr
#20
#QFSW
#
#

lui $1, 0x1000
addi $1, $1, 40
addi $2, $0, 1
jalr $2, $1
sll $0, $0, 0
addi $2, $2, 1
addi $2, $2, 1
addi $2, $2, 1
jr $0
sll $0, $0, 0


func:
jr $0
sll $0, $0, 0