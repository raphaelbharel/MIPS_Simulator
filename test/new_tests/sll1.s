# sll1
# Source assembly code:
# > addiu $2, $2, 4
# > sll $2, $2, 3
# > jr $0
# > sll $0, $0, 0 
B: "\x24\x42\x00\x04\x00\x02\x10\xc0\x00\x00\x00\x08\x00\x00\x00\x00"
T: "sll1, SLL"
A: "ms8817, # Safe Sll  /ExCode 32"
I: ""
O: ""
E: "32"
