# lhu7
# Source assembly code:
# > addiu $16, $16, 3
# > sll $16, $16, 28
# > lhu $17, 4($16)
# > sll $0, $0, 0 
B: "\x26\x10\x00\x03\x00\x10\x87\x00\x96\x11\x00\x04\x00\x00\x00\x00"
T: "lhu7, LHU"
A: "ms8817, # Lhu loads from ADDR_PUTC  /ExCode 245"
I: ""
O: ""
E: "245"
