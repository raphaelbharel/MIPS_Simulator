# sw5
# Source assembly code:
# > addiu $16, $16, 3
# > sll $16, $16, 28
# > addiu $17, $17, 97
# > sw $17, 4($16)
# > addiu $17, $0, 256
# > sw $17, 4($16)
# > jr $0
# > sll $0, $0, 0 
B: "\x26\x10\x00\x03\x00\x10\x87\x00\x26\x31\x00\x61\xae\x11\x00\x04\x24\x11\x01\x00\xae\x11\x00\x04\x00\x00\x00\x08\x00\x00\x00\x00"
T: "sw5, SW"
A: "ms8817, # Sw stores to ADDR_PUTC /ExCode 0"
I: ""
O: "a\x00"
E: "0"
