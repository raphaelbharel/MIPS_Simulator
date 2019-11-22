# multu4
# Source assembly code:
# > addiu $18, $18, 237
# > addiu $17, $17, 96
# > multu $18, $17
# > sll $0, $0, 0 
# > mflo $2
# > jr $0
# > sll $0, $0, 0 
B: "\x26\x52\x00\xed\x26\x31\x00\x60\x02\x51\x00\x19\x00\x00\x00\x00\x00\x00\x10\x12\x00\x00\x00\x08\x00\x00\x00\x00"
T: "multu4, MULTU"
A: "fd5117, # multiplication result in Lo  /ExCode 224"
I: ""
O: ""
E: "224"
