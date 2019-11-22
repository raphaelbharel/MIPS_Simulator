# andi1
# Source assembly code:
# > addiu $2, $0, 38
# > andi $2, $2, 255
# > jr $0
# > sll $0, $0, 0 
B: "\x24\x02\x00\x26\x30\x42\x00\xff\x00\x00\x00\x08\x00\x00\x00\x00"
T: "andi1, ANDI"
A: "ms8817, # Safe andi  /ExCode 38"
I: ""
O: ""
E: "38"
