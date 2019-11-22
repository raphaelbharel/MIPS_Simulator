# lw11
# Source assembly code:
# > addiu $16, $16, 1
# > sll $16, $16, 28
# > lw $2, 0($16)
# > sll $0, $0, 0 
# > lw $18, 4096($16)
# > sll $0, $0, 0 
# > addiu $19, $19, 1
# > sll $19, $19, 24
# > addi $19, $19, -4
# > addu $19, $19, $16
# > lw $20, 0($19)
# > sll $0, $0, 0 
# > jr $0
# > sll $0, $0, 0 
B: "\x26\x10\x00\x01\x00\x10\x87\x00\x8e\x02\x00\x00\x00\x00\x00\x00\x8e\x12\x10\x00\x00\x00\x00\x00\x26\x73\x00\x01\x00\x13\x9e\x00\x22\x73\xff\xfc\x02\x70\x98\x21\x8e\x74\x00\x00\x00\x00\x00\x00\x00\x00\x00\x08\x00\x00\x00\x00"
T: "lw11, LW"
A: "ms8817, # Lw reads from three safe positions: ADDR_INSTR; ADDR_INSTR + 0x1000; ADDR_INSTR + ADDR_INSTR_LEN - 4 /ExCode 1"
I: ""
O: ""
E: "1"
