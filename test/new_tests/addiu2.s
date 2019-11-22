# addiu2
# Source assembly code:
# > addiu $2, $2, 65535
# > bgtz $2, -10 
# > sll $0, $0, 0 
# > jr $0
# > sll $0, $0, 0 
B: "\x24\x42\xff\xff\x1c\x40\xff\xf6\x00\x00\x00\x00\x00\x00\x00\x08\x00\x00\x00\x00"
T: "addiu2, ADDIU"
A: "fd5117, # immediate extension  /ExCode 255"
I: ""
O: ""
E: "255"
