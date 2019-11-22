# bltzal5
# Source assembly code:
# > addi $3, $0, -1
# > bltzal $3, 2
# > addu $2, $0, $31
# > addu $2, $0, $0 
# > jr $0
# > sll $0, $0, 0 
B: "\x20\x03\xff\xff\x04\x70\x00\x02\x00\x1f\x10\x21\x00\x00\x10\x21\x00\x00\x00\x08\x00\x00\x00\x00"
T: "bltzal5, BLTZAL"
A: "fd5117, # linking before calling delay slot  /ExCode 12"
I: ""
O: ""
E: "12"
