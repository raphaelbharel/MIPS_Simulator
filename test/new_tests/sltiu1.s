# sltiu1
# Source assembly code:
# > addiu $16, $16, 30
# > addiu $2, $2, 255
# > sltiu $2, $16, 65535
# > jr $0
# > sll $0, $0, 0 
B: "\x26\x10\x00\x1e\x24\x42\x00\xff\x2e\x02\xff\xff\x00\x00\x00\x08\x00\x00\x00\x00"
T: "sltiu1, SLTIU"
A: "fd5117, # negative numbers test  /ExCode 1"
I: ""
O: ""
E: "1"
