# bltzal4
# Source assembly code:
# > addi $2, $0, -1
# > bltzal $2, 2
# > addi $2, $0, 9
# > addi $31, $0, 0
# > add $2, $2, $31 
# > jr $0
# > sll $0, $0, 0 
B: "\x20\x02\xff\xff\x04\x50\x00\x02\x20\x02\x00\x09\x20\x1f\x00\x00\x00\x5f\x10\x20\x00\x00\x00\x08\x00\x00\x00\x00"
T: "bltzal4, BLTZAL"
A: "fd5117, # Delay slot  /ExCode 21"
I: ""
O: ""
E: "21"
