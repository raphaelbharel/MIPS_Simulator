# bgez1
# Source assembly code:
# > addi $16, $16, 2
# > addi $16, $16, -1
# > bgez $16, -2
# > sll $0, $0, 0
# > jr $0
# > sll $0, $0, 0 
B: "\x22\x10\x00\x02\x22\x10\xff\xff\x06\x01\xff\xfe\x00\x00\x00\x00\x00\x00\x00\x08\x00\x00\x00\x00"
T: "bgez1, BGEZ"
A: "fd5117, # branches to safe position  /ExCode 0"
I: ""
O: ""
E: "0"
