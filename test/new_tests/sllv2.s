# sllv2
# Source assembly code:
# > addiu $16, $0, 49
# > addiu $17, $0, 1
# > sllv $2, $16, $17
# > addiu $17, $0, 31
# > sllv $16, $16, $17
# > addu $2, $2, $16
# > jr $0
# > sll $0, $0, 0 
B: "\x24\x10\x00\x31\x24\x11\x00\x01\x02\x30\x10\x04\x24\x11\x00\x1f\x02\x30\x80\x04\x00\x50\x10\x21\x00\x00\x00\x08\x00\x00\x00\x00"
T: "sllv2, SLLV"
A: "ms8817, # Performs some safe left logical shifts variable  /ExCode 98"
I: ""
O: ""
E: "98"
