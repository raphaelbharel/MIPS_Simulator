# bltzal3
# Source assembly code:
# > addi $17, $17, -2
# > bltzal $17, 2
# > sll $0, $0, 0
# > addi $31, $0, 0 
# > add $2, $0, $31
# > jr $0
# > sll $0, $0, 0 
B: "\x22\x31\xff\xfe\x06\x30\x00\x02\x00\x00\x00\x00\x20\x1f\x00\x00\x00\x1f\x10\x20\x00\x00\x00\x08\x00\x00\x00\x00"
T: "bltzal3, BLTZAL"
A: "fd5117, # Linking  /ExCode 12"
I: ""
O: ""
E: "12"
