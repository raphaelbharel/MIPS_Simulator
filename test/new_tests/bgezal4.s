# bgezal4
# Source assembly code:
# > bgezal $0, 2
# > addi $2, $0, 1
# > addi $31, $0, 0
# > add $2, $2, $31 
# > jr $0
# > sll $0, $0, 0 
B: "\x04\x11\x00\x02\x20\x02\x00\x01\x20\x1f\x00\x00\x00\x5f\x10\x20\x00\x00\x00\x08\x00\x00\x00\x00"
T: "bgezal4, BGEZAL"
A: "fd5117, # Delay slot  /ExCode 9"
I: ""
O: ""
E: "9"
