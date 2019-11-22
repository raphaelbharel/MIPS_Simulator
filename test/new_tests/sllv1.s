# sllv1
# Source assembly code:
# > addiu $2, $0, 4
# > addiu $16, $0, 3
# > sllv $2, $2, $16
# > jr $0
# > sll $0, $0, 0 
B: "\x24\x02\x00\x04\x24\x10\x00\x03\x02\x02\x10\x04\x00\x00\x00\x08\x00\x00\x00\x00"
T: "sllv1, SLLV"
A: "ms8817, # Performs safe left logical shifts variable  /ExCode 32"
I: ""
O: ""
E: "32"
