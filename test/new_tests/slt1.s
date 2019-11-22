# slt1
# Source assembly code:
# > addiu $16, $16, 30
# > addiu $17, $17, 30
# > addiu $2, $2, 255
# > slt $2, $16, $17
# > jr $0
# > sll $0, $0, 0 
B: "\x26\x10\x00\x1e\x26\x31\x00\x1e\x24\x42\x00\xff\x02\x11\x10\x2a\x00\x00\x00\x08\x00\x00\x00\x00"
T: "slt1, SLT"
A: "fd5117, # equal numbers test  /ExCode 0"
I: ""
O: ""
E: "0"
