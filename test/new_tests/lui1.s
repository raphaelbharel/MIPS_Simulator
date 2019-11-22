# lui1
# > lui $16, 12288
# > addiu $17, $17, 55
# > sw $17, 4($16)
# > jr $0
# > sll $0, $0, 0 
B: "\x3c\x10\x30\x00\x26\x31\x00\x37\xae\x11\x00\x04\x00\x00\x00\x08\x00\x00\x00\x00"
T: "lui1, LUI"
A: "fd5117, # LUI store address; then store  /ExCode 0"
I: ""
O: "7"
E: "0"
