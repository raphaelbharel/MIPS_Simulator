# sw7
# Source assembly code:
# > addiu $16, $16, 3
# > sll $16, $16, 28
# > lw $17, 0($16)
# > sll $0, $0, 0 
# > sw $17, 4($16)
# > addiu $17, $17, 1
# > sw $17, 4($16)
# > jr $0
# > sll $0, $0, 0 
B: "\x26\x10\x00\x03\x00\x10\x87\x00\x8e\x11\x00\x00\x00\x00\x00\x00\xae\x11\x00\x04\x26\x31\x00\x01\xae\x11\x00\x04\x00\x00\x00\x08\x00\x00\x00\x00"
T: "sw7, SW"
A: "ms8817, # Read 'a' from input; write it to output; increment it to 'b' and write again /ExCode 0"
I: "a"
O: "ab"
E: "0"
