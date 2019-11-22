# lhu9
# Source assembly code:
# > addiu $16, $16, 2
# > sll $16, $16, 28
# > addiu $17, $0, 1152
# > sll $17, $17, 8
# > sw $17, 0($16)
# > lhu $18, 2($16)
# > sll $0, $0, 0 
# > srl $18, $18, 12
# > addiu $19, $0, 3
# > sll $19, $19, 28
# > sw $18, 4($19)
# > lhu $18, 0($16)
# > sll $0, $0, 0 
# > sw $18, 4($19)
# > jr $0
# > sll $0, $0, 0 
B: "\x26\x10\x00\x02\x00\x10\x87\x00\x24\x11\x04\x80\x00\x11\x8a\x00\xae\x11\x00\x00\x96\x12\x00\x02\x00\x00\x00\x00\x00\x12\x93\x02\x24\x13\x00\x03\x00\x13\x9f\x00\xae\x72\x00\x04\x96\x12\x00\x00\x00\x00\x00\x00\xae\x72\x00\x04\x00\x00\x00\x08\x00\x00\x00\x00"
T: "lhu9, LHU"
A: "ms8817, # Check lhu sign extend the loaded byte correctly  /ExCode 0"
I: ""
O: "\x08\x04"
E: "0"
