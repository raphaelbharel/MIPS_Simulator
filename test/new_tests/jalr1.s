# jalr1
# Source assembly code:
# > addiu $16, $16, 1
# > sll $16, $16, 28
# > addiu $16, $16, 1
# > jalr $31, $16
# > sll $0, $0, 0 
# > jr $0
# > sll $0, $0, 0 
B: "\x26\x10\x00\x01\x00\x10\x87\x00\x26\x10\x00\x01\x02\x00\xf8\x09\x00\x00\x00\x00\x00\x00\x00\x08\x00\x00\x00\x00"
T: "jalr1, JALR"
A: "fd5117, # Jump register not 4-multiple  /ExCode 245"
I: ""
O: ""
E: "245"
