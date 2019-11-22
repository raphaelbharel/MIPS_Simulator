# sw9
# Source assembly code:
# > addiu $16, $16, 1
# > sll $16, $16, 24
# > sw $17, 0($16)
# > sll $0, $0, 0 
B: "\x26\x10\x00\x01\x00\x10\x86\x00\xae\x11\x00\x00\x00\x00\x00\x00"
T: "sw9, SW"
A: "ms8817, # Sw stores to ADDR_INSTR  /ExCode 245"
I: ""
O: ""
E: "245"
