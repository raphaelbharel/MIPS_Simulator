# bgezal2
# Source assembly code:
# > addi $16, $16, 1
# > bgezal $16,-4
# > sll $0, $0, 0
# > jr $0
# > sll $0, $0, 0 
B: "\x22\x10\x00\x01\x06\x11\xff\xfc\x00\x00\x00\x00\x00\x00\x00\x00\x08\x00\x00\x00\x00"
T: "bgezal2, BGEZAL"
A: "fd5117, # Branch to unsafe position  /ExCode 245"
I: ""
O: ""
E: "245"
