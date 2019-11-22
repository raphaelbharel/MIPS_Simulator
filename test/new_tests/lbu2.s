# lbu2
# Source assembly code:
# > addiu $16, $16, 2
# > sll $16, $16, 28
# > addiu $17, $17, 97
# > lbu $17, -1($16)
# > sll $0, $0, 0
# > jr $0
# > sll $0, $0, 0 
B: "\x26\x10\x00\x02\x00\x10\x87\x00\x26\x31\x00\x61\x92\x11\xff\xff\x00\x00\x00\x00\x00\x00\x00\x08\x00\x00\x00\x00"
T: "lbu2, LBU"
A: "ms8817, # Lbu loads from position (ADDR_DATA - 1)  /ExCode 245"
I: ""
O: ""
E: "245"
