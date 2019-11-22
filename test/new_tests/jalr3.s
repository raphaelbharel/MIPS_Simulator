# jalr3
# Source assembly code:
# > addiu $16, $16, 1
# > sll $16, $16, 28
# > addiu $16, $16, 24
# > jalr $31, $16
# > addu $2, $0, $31
# > sll $0, $0, 0 
# > jr $0
# > sll $0, $0, 0 
B: "\x26\x10\x00\x01\x00\x10\x87\x00\x26\x10\x00\x18\x02\x00\xf8\x09\x00\x1f\x10\x21\x00\x00\x00\x00\x00\x00\x00\x08\x00\x00\x00\x00"
T: "jalr3, JALR"
A: "fd5117, # linking before calling delay slot  /ExCode 20"
I: ""
O: ""
E: "20"
