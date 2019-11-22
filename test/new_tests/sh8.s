# sh8
# Source assembly code:
# > addiu $16, $16, 1
# > sll $16, $16, 24
# > sh $17, 0($16)
# > sll $0, $0, 0 
B: "\x26\x10\x00\x01\x00\x10\x86\x00\xa6\x11\x00\x00\x00\x00\x00\x00"
T: "sh8, SH"
A: "ms8817, # Sh stores to ADDR_INSTR  /ExCode 245"
I: ""
O: ""
E: "245"
