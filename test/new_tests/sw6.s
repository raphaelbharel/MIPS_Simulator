# sw6
# Source assembly code:
# > addiu $16, $16, 2
# > sll $16, $16, 28
# > sw $17, 0($16)
# > sw $18, 4096($16)
# > addiu $19, $19, 4
# > sll $19, $19, 24
# > addi $19, $19, -4
# > addu $19, $19, $16
# > sw $20, 0($19)
# > jr $0
# > sll $0, $0, 0 
B: "\x26\x10\x00\x02\x00\x10\x87\x00\xae\x11\x00\x00\xae\x12\x10\x00\x26\x73\x00\x04\x00\x13\x9e\x00\x26\x73\xff\xfc\x02\x70\x98\x21\xae\x74\x00\x00\x00\x00\x00\x08\x00\x00\x00\x00"
T: "sw6, SW"
A: "ms8817, # Sw stores to three safe positions: ADDR_DATA; ADDR_DATA + 0x1000; ADDR_DATA + ADDR_DATA_LEN - 4 /ExCode 0"
I: ""
O: ""
E: "0"
