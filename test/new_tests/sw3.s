# sw3
# Source assembly code:
# > addiu $16, $16, 2
# > sll $16, $16, 28
# > sw $17, 1($16)
# > jr $0
# > sll $0, $0, 0 
B: "\x26\x10\x00\x02\x00\x10\x87\x00\xae\x11\x00\x01\x00\x00\x00\x08\x00\x00\x00\x00"
T: "sw3, SW"
A: "ms8817, # Sw stores data to (ADDR_DATA + 1)  /ExCode 245"
I: ""
O: ""
E: "245"
