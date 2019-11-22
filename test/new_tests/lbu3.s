# lbu3
# Source assembly code:
# > addiu $16, $16, 2
# > sll $16, $16, 28
# > addiu $19, $19, 4
# > sll $19, $19, 24
# > addu $19, $19, $16
# > addiu $20, $20, 97
# > lbu $20, 0($19)
# > sll $0, $0, 0
# > jr $0
# > sll $0, $0, 0 
B: "\x26\x10\x00\x02\x00\x10\x87\x00\x26\x73\x00\x04\x00\x13\x9e\x00\x02\x70\x98\x21\x26\x94\x00\x61\x92\x74\x00\x00\x00\x00\x00\x00\x00\x00\x00\x08\x00\x00\x00\x00"
T: "lbu3, LBU"
A: "ms8817, # Lbu loads from unsafe position: ADDR_DATA + ADDR_DATA_LEN. /ExCode 245"
I: ""
O: ""
E: "245"
