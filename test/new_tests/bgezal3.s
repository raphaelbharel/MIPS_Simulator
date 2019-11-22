# bgezal3
# Source assembly code:
# > bgezal $0, 2
# > sll $0, $0, 0
# > addi $31, $0, 0
# > add $2, $0, $31 
# > jr $0
# > sll $0, $0, 0 
B: "\x04\x11\x00\x02\x00\x00\x00\x00\x20\x1f\x00\x00\x00\x1f\x10\x20\x00\x00\x00\x08\x00\x00\x00\x00"
T: "bgezal3, BGEZAL"
A: "fd5117, # linking  /ExCode 8"
I: ""
O: ""
E: "8"
