# or2
# Source assembly code:
# > addiu $17, $0, 32
# > addiu $18, $0, 15
# > or $2, $17, $18
# > jr $0
# > sll $0, $0, 0 
B: "\x24\x11\x00\x20\x24\x12\x00\x0f\x02\x32\x10\x25\x00\x00\x00\x08\x00\x00\x00\x00"
T: "or2, OR"
A: "ms8817, # Safe or  /ExCode 47"
I: ""
O: ""
E: "47"
