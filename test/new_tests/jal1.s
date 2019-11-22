# jal1
# Source assembly code:
# > jal 2
# > sll $0, $0, 0 
# > add $2, $0, $31
# > jr $0
# > sll $0, $0, 0 
B: "\x0c\x00\x00\x02\x00\x00\x00\x00\x00\x1f\x10\x20\x00\x00\x00\x08\x00\x00\x00\x00"
T: "jal1, JAL"
A: "fd5117, # Jump to safe position  /ExCode 8"
I: ""
O: ""
E: "8"
