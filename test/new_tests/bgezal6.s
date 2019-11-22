# bgezal6
# Source assembly code:
# > addiu $3, $0, -1
# > bgezal $3, 2
# > addu $2, $0, $31
# > jr $0
# > sll $0, $0, 0 
B: "\x24\x03\xff\xff\x04\x71\x00\x02\x00\x1f\x10\x21\x00\x00\x00\x08\x00\x00\x00\x00"
T: "bgezal6, BGEZAL"
A: "fd5117, # Linking even if not branching  /ExCode 8"
I: ""
O: ""
E: "12"
