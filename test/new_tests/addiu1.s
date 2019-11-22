# addiu1
# Source assembly code:
# > addiu $2, $2, 69
# > addiu $2, $2, 50
# > jr $0
# > sll $0, $0, 0 
B: "\x24\x42\x00\x45\x24\x42\x00\x32\x00\x00\x00\x08\x00\x00\x00\x00"
T: "addiu1, ADDIU"
A: "fd5117, # safe addiu  /ExCode 119"
I: ""
O: ""
E: "119"
