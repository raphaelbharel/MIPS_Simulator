# andi2
# Source assembly code:
# > lui $2, 65535
# > andi $2, $2, 65535
# > bltz $2, -10
# > sll $0, $0, 0 
# > addiu $2, $2, 255
# > andi $2, $2, 37
# > jr $0
# > sll $0, $0, 0 
B: "\x3c\x02\xff\xff\x30\x42\xff\xff\x04\x40\xff\xf6\x00\x00\x00\x00\x24\x42\x00\xff\x30\x42\x00\x25\x00\x00\x00\x08\x00\x00\x00\x00"
T: "andi2, ANDI"
A: "ms8817, # Zero immediate extension  /ExCode 37"
I: ""
O: ""
E: "37"
