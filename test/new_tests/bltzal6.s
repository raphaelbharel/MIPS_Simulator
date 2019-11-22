# bltzal6
# Source assembly code:
# > bltzal $0, 2
# > addu $2, $0, $31 
# > jr $0
# > sll $0, $0, 0 
B: "\x04\x10\x00\x02\x00\x1f\x10\x21\x00\x00\x00\x08\x00\x00\x00\x00"
T: "bltzal6, BLTZAL"
A: "fd5117, # linking even if branch not taken  /ExCode 8"
I: ""
O: ""
E: "8"
