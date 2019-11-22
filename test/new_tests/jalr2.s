# jalr2
# Source assembly code:
# > addiu $16, $16, 1
# > sll $16, $16, 28
# > addiu $16, $16, 24
# > jalr $2, $16
# > sll $0, $0, 0 
# > addiu $2, $0, 0
# > jr $0
# > sll $0, $0, 0 
B: "\x26\x10\x00\x01\x00\x10\x87\x00\x26\x10\x00\x18\x02\x00\x10\x09\x00\x00\x00\x00\x24\x02\x00\x00\x00\x00\x00\x08\x00\x00\x00\x00"
T: "jalr2, JALR"
A: "fd5117, # linking  /ExCode 20"
I: ""
O: ""
E: "20"
