#j
#12
#QFSW
#delay-slot
#

addi $2, $0, 1
j func
addi $2, $2, 1
addi $2, $2, 1
addi $2, $2, 1

func: addi $2, $2, 10
jr $0