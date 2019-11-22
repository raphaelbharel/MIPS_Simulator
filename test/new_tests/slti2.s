# slti2
# Source assembly code:
# > addiu $16, $16, 30
# > addiu $2, $2, 255
# > slti $2, $16, 255
# > jr $0
# > sll $0, $0, 0 
B: "\x26\x10\x00\x1e\x24\x42\x00\xff\x2a\x02\x00\xff\x00\x00\x00\x08\x00\x00\x00\x00"
T: "slti2, SLTI"
A: "fd5117, # negative number test  /ExCode 1"
I: ""
O: ""
E: "1"
