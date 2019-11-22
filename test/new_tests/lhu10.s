# lhu10
# Source assembly code:
# > addiu $16, $16, 1
# > sll $16, $16, 28
# > lhu $17, -2($16)
# > sll $0, $0, 0 
# > jr $0
# > sll $0, $0, 0 
B: "\x26\x10\x00\x01\x00\x10\x87\x00\x96\x11\xff\xfe\x00\x00\x00\x00\x00\x00\x00\x08\x00\x00\x00\x00"
T: "lhu10, LHU"
A: "ms8817, # Lhu reads from position (ADDR_INSTR - 2)  /ExCode 245"
I: ""
O: ""
E: "245"
