# and1
# Source assembly code:
# > addiu $17, $0, 65535
# > addiu $18, $0, 38
# > and $2, $17, $18
# > and $19, $0, $17
# > jr $0
# > sll $0, $0, 0 
B: "\x24\x11\xff\xff\x24\x12\x00\x26\x02\x32\x10\x24\x00\x11\x98\x24\x00\x00\x00\x08\x00\x00\x00\x00"
T: "and1, AND"
A: "ms8817, # Safe And  /ExCode 38"
I: ""
O: ""
E: "38"
