# bgezal5
# Source assembly code:
# > bgezal $0, 2
# > addu $2, $0, $31
# > addiu $2, $0, 0
# > jr $0
# > sll $0, $0, 0 
B: "\x04\x11\x00\x02\x00\x1f\x10\x21\x24\x02\x00\x00\x00\x00\x00\x08\x00\x00\x00\x00"
T: "bgezal5, BGEZAL"
A: "fd5117, # linking before call delayed slot  /ExCode 8"
I: ""
O: ""
E: "8"
