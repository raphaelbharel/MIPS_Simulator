# bgezal1
# Source assembly code:
# > addi $16, $16, 1
# > bgezal $16, 2
# > sll $0, $0, 0
# > addi $31, $0, 0
# > beq $0, $31, -10
# > sll $0, $0, 0
# > jr $0
# > sll $0, $0, 0 
B: "\x22\x10\x00\x01\x06\x11\x00\x02\x00\x00\x00\x00\x20\x1f\x00\x00\x10\x1f\xff\xf6\x00\x00\x00\x00\x00\x00\x00\x08\x00\x00\x00\x00"
T: "bgezal1, BGEZAL"
A: "fd5117, # branches to safe position  /ExCode 0"
I: ""
O: ""
E: "0"

#bgezal
#2
#daryllimyt
#normal branch
#

addi $2, $0, 1
sub $3, $0, $2
bgez $2 end
addi $2, $2, 1
addi $2, $2, 1
addi $2, $2, 1

end: jr $0
