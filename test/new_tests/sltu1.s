# sltu1
# Source assembly code:
# > lui $16, 65535
# > lui $17, 35
# > addiu $2, $2, 255
# > sltu $2, $16, $17 
# > jr $0
# > sll $0, $0, 0 
B: "\x3c\x10\xff\xff\x3c\x11\x00\x23\x24\x42\x00\xff\x02\x11\x10\x2b\x00\x00\x00\x08\x00\x00\x00\x00"
T: "sltu1, SLTU"
A: "fd5117, # Negative numbers test  /ExCode 0"
I: ""
O: ""
E: "0"
