# lhu5
# Source assembly code:
# > addiu $16, $16, 3
# > sll $16, $16, 28
# > lhu $2, 2($16)
# > sll $0, $0, 0 
# > lhu $17, 2($16)
# > sll $0, $0, 0 
# > jr $0
# > sll $0, $0, 0 
B: "\x26\x10\x00\x03\x00\x10\x87\x00\x96\x02\x00\x02\x00\x00\x00\x00\x96\x11\x00\x02\x00\x00\x00\x00\x00\x00\x00\x08\x00\x00\x00\x00"
T: "lhu5, LHU"
A: "ms8817, # Lhu loads from ADDR_GETC + 2 and ADDR_GETC + 1 /ExCode 97"
I: "a"
O: ""
E: "97"
