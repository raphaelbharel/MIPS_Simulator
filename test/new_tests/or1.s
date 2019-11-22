# or1
# Source assembly code:
# > addiu $17, $0, 65535
# > addiu $18, $0, 38
# > or $2, $17, $18
# > jr $0
# > sll $0, $0, 0 
B: "\x24\x11\xff\xff\x24\x12\x00\x26\x02\x32\x10\x25\x00\x00\x00\x08\x00\x00\x00\x00"
T: "or1, OR"
A: "ms8817, # Safe or  /ExCode 255"
I: ""
O: ""
E: "255"
