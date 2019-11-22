# xori1
# Source assembly code:
# > addiu $16, $16, 3
# > sll $16, $16, 28
# > addiu $17, $0, 65535
# > xori $19, $17, 38
# > sw $19, 4($16)
# > xori $19, $0, 38
# > sw $19, 4($16)
# > addiu $20, $0, 464
# > xori $19, $20, 38
# > sw $19, 4($16)
# > jr $0
# > sll $0, $0, 0 
B: "\x26\x10\x00\x03\x00\x10\x87\x00\x24\x11\xff\xff\x3a\x33\x00\x26\xae\x13\x00\x04\x38\x13\x00\x26\xae\x13\x00\x04\x24\x14\x01\xd0\x3a\x93\x00\x26\xae\x13\x00\x04\x00\x00\x00\x08\x00\x00\x00\x00"
T: "xori1, XORI"
A: "ms8817, # Several safe xori  /ExCode 0"
I: ""
O: "\xd9&\xf6"
E: "0"
