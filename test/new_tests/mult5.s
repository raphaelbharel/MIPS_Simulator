# mult5
# Source assembly code:
# > lui $16, 32767
# > addi $16, $16, 32767
# > addi $16, $16, 32767
# > addi $16, $16, 1
# > add $17, $0, $16
# > mult $16, $17
# > sll $0, $0, 0 
# > mfhi $2
# > jr $0
# > sll $0, $0, 0 
B: "\x3c\x10\x7f\xff\x22\x10\x7f\xff\x22\x10\x7f\xff\x22\x10\x00\x01\x00\x10\x88\x20\x02\x11\x00\x18\x00\x00\x00\x00\x00\x00\x10\x10\x00\x00\x00\x08\x00\x00\x00\x00"
T: "mult5, MULT"
A: "fd5117, # multiplication result in Hi  /ExCode 255"
I: ""
O: ""
E: "255"
