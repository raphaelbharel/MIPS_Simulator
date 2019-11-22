# jr2
# Source assembly code:
# > addiu $16, $16, 4
# > jr $16
# > sll $0, $0, 0 
B: "\x26\x10\x00\x04\x02\x00\x00\x08\x00\x00\x00\x00"
T: "jr2, JR"
A: "fd5117, # Jump to 4  /ExCode 245"
I: ""
O: ""
E: "245"
