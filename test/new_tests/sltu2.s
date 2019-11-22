# sltu2
# Source assembly code:
# > lui $16, 37999
# > lui $17, 42093
# > addiu $2, $2, 255
# > sltu $2, $16, $17 
# > jr $0
# > sll $0, $0, 0 
B: "\x3c\x10\x94\x6f\x3c\x11\xa4\x6d\x24\x42\x00\xff\x02\x11\x10\x2b\x00\x00\x00\x08\x00\x00\x00\x00"
T: "sltu2, SLTU"
A: "fd5117, # negative numbers test  /ExCode 1"
I: ""
O: ""
E: "1"
