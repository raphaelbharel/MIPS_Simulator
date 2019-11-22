# j1
# Source assembly code:
# > j 3
# > addiu $2, $0, 10
# > addiu $2, $0, 0
# > sll $0, $0, 0
# > jr $0
# > sll $0, $0, 0 
B: "\x08\x00\x00\x03\x24\x02\x00\x0a\x24\x02\x00\x00\x00\x00\x00\x00\x00\x00\x00\x08\x00\x00\x00\x00"
T: "j1, J" 
A: "fd5117, # delay slot  /ExCode 10"
I: "" 
O: ""
E: "10"