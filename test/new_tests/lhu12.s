# lhu12
# Source assembly code:
# > addiu $16, $16, 1
# > sll $16, $16, 28
# > addiu $19, $19, 1
# > sll $19, $19, 24
# > addu $19, $19, $16
# > lhu $20, 0($19)
# > sll $0, $0, 0 
# > jr $0
# > sll $0, $0, 0 
B: "\x26\x10\x00\x01\x00\x10\x87\x00\x26\x73\x00\x01\x00\x13\x9e\x00\x02\x70\x98\x21\x96\x74\x00\x00\x00\x00\x00\x00\x00\x00\x00\x08\x00\x00\x00\x00"
T: "lhu12, LHU"
A: "ms8817, # Lhu reads from unsafe positions: ADDR_INSTR + ADDR_INSTR_LEN /ExCode 245"
I: ""
O: ""
E: "245"
