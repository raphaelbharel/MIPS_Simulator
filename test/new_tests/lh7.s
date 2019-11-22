# lh7
# Source assembly code:
# > addiu $16, $16, 3
# > sll $16, $16, 28
# > lh $17, 4($16)
# > sll $0, $0, 0 
B: "\x26\x10\x00\x03\x00\x10\x87\x00\x86\x11\x00\x04\x00\x00\x00\x00"
T: "lh7, LH"
A: "ms8817, # Lh loads from ADDR_PUTC  /ExCode 245"
I: ""
O: ""
E: "245"
