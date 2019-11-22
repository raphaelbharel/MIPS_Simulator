# srlv1
# Source assembly code:
# > addiu $17, $0, 98
# > addiu $20, $20, 1
# > srlv $2, $17, $20
# > addiu $20, $0, 1000
# > srlv $17, $17, $20
# > addu $2, $2, $17
# > jr $0
# > sll $0, $0, 0
B: "\x24\x11\x00\x62\x26\x94\x00\x01\x02\x91\x10\x06\x24\x14\x03\xe8\x02\x91\x88\x06\x00\x51\x10\x21\x00\x00\x00\x08\x00\x00\x00\x00"
T: "srlv1, SRLV"
A: "ms8817, # Performs some safe right logical shifts variable  /ExCode 49"
I: ""
O: ""
E: "49"
