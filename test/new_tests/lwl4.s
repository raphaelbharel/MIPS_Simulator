# lwl4
# Source assembly code:
# > addiu $16, $16, 3
# > sll $16, $16, 28
# > lwl $2, 0($16)
# > sll $0, $0, 0 
# > jr $0
# > sll $0, $0, 0 
B: "\x26\x10\x00\x03\x00\x10\x87\x00\x8a\x02\x00\x00\x00\x00\x00\x00\x00\x00\x00\x08\x00\x00\x00\x00"
T: "lwl4, LWL"
A: "ms8817, # LWL loads from ADDR_GETC /ExCode 97"
I: "a"
O: ""
E: "97"
