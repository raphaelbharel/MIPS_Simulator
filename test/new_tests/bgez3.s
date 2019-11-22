# bgez3
# Source assembly code:
# > addi $2, $0, 0
# > bgez $2, 2
# > addi $2, $2, 10
# > sll $0, $0, 0
# > jr $0
# > sll $0, $0, 0 
B: "\x20\x02\x00\x00\x04\x41\x00\x02\x20\x42\x00\x0a\x00\x00\x00\x00\x00\x00\x00\x08\x00\x00\x00\x00"
T: "bgez3, BGEZ"
A: "fd5117, # delayed slot  /ExCode 10"
I: ""
O: ""
E: "10"
