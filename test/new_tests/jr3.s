# jr3
# Source assembly code:
# > addiu $16, $16, 1
# > sll $16, $16, 28
# > addiu $16, $16, 20
# > jr $16
# > sll $0, $0, 0 
# > jr $0
# > sll $0, $0, 0 
B: "\x26\x10\x00\x01\x00\x10\x87\x00\x26\x10\x00\x14\x00\x00\x00\x00\x02\x00\x00\x08\x00\x00\x00\x00\x00\x00\x00\x08\x00\x00\x00\x00"
T: "jr3, JR"
A: "fd5117, # Jump to 0  /ExCode 0"
I: ""
O: ""
E: "0"
