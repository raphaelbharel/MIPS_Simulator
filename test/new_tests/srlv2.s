# srlv2
# Source assembly code:
# > lui $18, 65535
# > addiu $20, $0, 31
# > srlv $2, $18, $20
# > jr $0
# > sll $0, $0, 0 
B: "\x3c\x12\xff\xff\x24\x14\x00\x1f\x02\x92\x10\x06\x00\x00\x00\x08\x00\x00\x00\x00"
T: "srlv2, SRLV"
A: "ms8817, # Performs some safe right logical shifts variable  /ExCode 1"
I: ""
O: ""
E: "1"
