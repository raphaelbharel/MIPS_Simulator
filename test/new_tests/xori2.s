# xori2
# Source assembly code:
# > lui $17, 65535 
# > xori $2, $17, 65535
# > srl $2, $2, 16
# > jr $0
# > sll $0, $0, 0 
B: "\x3c\x11\xff\xff\x3a\x22\xff\xff\x00\x02\x14\x02\x00\x00\x00\x08\x00\x00\x00\x00"
T: "xori2, XORI"
A: "ms8817, # zero immediate extension  /ExCode 255"
I: ""
O: ""
E: "255"

