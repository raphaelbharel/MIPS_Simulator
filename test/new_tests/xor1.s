# xor1
# Source assembly code:
# > addiu $16, $16, 3
# > sll $16, $16, 28
# > addiu $17, $0, 65535
# > addiu $18, $0, 38
# > xor $19, $17, $18
# > sw $19, 4($16)
# > xor $19, $0, $18
# > sw $19, 4($16)
# > addiu $20, $0, 464
# > xor $19, $20, $18
# > sw $19, 4($16)
# > jr $0
# > sll $0, $0, 0 
B: "\x26\x10\x00\x03\x00\x10\x87\x00\x24\x11\xff\xff\x24\x12\x00\x26\x02\x32\x98\x26\xae\x13\x00\x04\x00\x12\x98\x26\xae\x13\x00\x04\x24\x14\x01\xd0\x02\x92\x98\x26\xae\x13\x00\x04\x00\x00\x00\x08\x00\x00\x00\x00"
T: "xor1, XOR"
A: "ms8817, # Several safe xor  /ExCode 0"
I: ""
O: "\xd9&\xf6"
E: "0"
