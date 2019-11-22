# jal2
# Source assembly code:
# > sll $0, $0, 0
# > jal -2
# > sll $0, $0, 0 
# > jr $0
# > sll $0, $0, 0 
B: "\x00\x00\x00\x00\x0f\xff\xff\xf5\x00\x00\x00\x00\x00\x00\x00\x08\x00\x00\x00\x00"
T: "jal2, JAL"
A: "fd5117, # Jump to unsafe position  /ExCode 245"
I: ""
O: ""
E: "245"
