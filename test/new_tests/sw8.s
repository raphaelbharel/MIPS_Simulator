# sw8
# Source assembly code:
# > addiu $16, $16, 3
# > sll $16, $16, 28
# > sw $17, 0($16)
# > sll $0, $0, 0 
B: "\x26\x10\x00\x03\x00\x10\x87\x00\xae\x11\x00\x00\x00\x00\x00\x00"
T: "sw8, SW"
A: "ms8817, # Sw stores to ADDR_GETC  /ExCode 245"
I: ""
O: ""
E: "245"
