# multu3
# Source assembly code:
# > addiu $18, $18, 237
# > addiu $17, $17, 96
# > multu $18, $17
# > sll $0, $0, 0 
# > mfhi $2
# > jr $0
# > sll $0, $0, 0 
B: "\x26\x52\x00\xed\x26\x31\x00\x60\x02\x51\x00\x19\x00\x00\x00\x00\x00\x00\x10\x10\x00\x00\x00\x08\x00\x00\x00\x00"
T: "multu3, MULTU"
A: "fd5117, # multiplication result in Hi  /ExCode 0"
I: ""
O: ""
E: "0"
