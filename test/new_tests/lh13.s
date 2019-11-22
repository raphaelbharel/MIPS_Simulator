# lh13
# Source assembly code:
# > addiu $16, $16, 1
# > sll $16, $16, 28
# > lh $2, 0($16)
# > sll $0, $0, 0 
# > lh $18, 4096($16)
# > sll $0, $0, 0 
# > addiu $19, $19, 1
# > sll $19, $19, 24
# > addi $19, $19, -2
# > addu $19, $19, $16
# > lh $20, 0($19)
# > sll $0, $0, 0 
# > jr $0
# > sll $0, $0, 0 
B: "\x26\x10\x00\x01\x00\x10\x87\x00\x86\x02\x00\x00\x00\x00\x00\x00\x86\x12\x10\x00\x00\x00\x00\x00\x26\x73\x00\x01\x00\x13\x9e\x00\x22\x73\xff\xfe\x02\x70\x98\x21\x86\x74\x00\x00\x00\x00\x00\x00\x00\x00\x00\x08\x00\x00\x00\x00"
T: "lh13, LH"
A: "ms8817, # Lh reads from three safe positions: ADDR_INSTR; ADDR_INSTR + 0x1000; ADDR_INSTR + ADDR_INSTR_LEN - 2 /ExCode 16"
I: ""
O: ""
E: "16"
