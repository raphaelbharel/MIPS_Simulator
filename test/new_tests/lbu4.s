# lbu4
# Source assembly code:
# > addiu $16, $16, 3
# > sll $16, $16, 28
# > lbu $2, 3($16)
# > sll $0, $0, 0
# > lbu $17, 1($16)
# > sll $0, $0, 0
# > jr $0
# > sll $0, $0, 0 
B: "\x26\x10\x00\x03\x00\x10\x87\x00\x92\x02\x00\x03\x00\x00\x00\x00\x92\x11\x00\x01\x00\x00\x00\x00\x00\x00\x00\x08\x00\x00\x00\x00"
T: "lbu4, LBU"
A: "ms8817, # Lbu loads from ADDR_GETC + 3 and ADDR_GETC + 1 /ExCode 97"
I: "a"
O: ""
E: "97"
