# lh11
# Source assembly code:
# > addiu $16, $16, 1
# > sll $16, $16, 28
# > lh $2, 2($16)
# > sll $0, $0, 0 
# > jr $0
# > sll $0, $0, 0 
B: "\x26\x10\x00\x01\x00\x10\x87\x00\x86\x02\x00\x02\x00\x00\x00\x00\x00\x00\x00\x08\x00\x00\x00\x00"
T: "lh11, LH"
A: "ms8817, # Lh reads from (ADDR_INSTR + 2)  /ExCode 1"
I: ""
O: ""
E: "1"
