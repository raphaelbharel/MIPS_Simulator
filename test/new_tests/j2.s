# j2
# Source assembly code:
# > sll $0, $0, 0
# > j -2
# > sll $0, $0, 0
# > jr $0
# > sll $0, $0, 0 
B: "\x00\x00\x00\x00\x0b\xff\xff\xfe\x00\x00\x00\x00\x00\x00\x00\x08\x00\x00\x00\x00"
T: "j2, J"
A: "fd5117, # Jump to unsafe position  /ExCode 245"
I: ""
O: ""
E: "245"
