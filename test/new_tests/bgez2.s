# bgez2
# Source assembly code:
# > addi $16, $16, 10
# > bgez $16, -5
# > sll $0, $0, 0
# > jr $0
# > sll $0, $0, 0 
B: "\x22\x10\x00\x0a\x06\x01\xff\xfb\x00\x00\x00\x00\x00\x00\x00\x08\x00\x00\x00\x00"
T: "bgez2, BGEZ"
A: "fd5117, # branches to unsafe position  /ExCode 245"
I: ""
O: ""
E: "245"
