# srl1
# Source assembly code:
# > addiu $17, $0, 98
# > srl $2, $17, 1
# > srl $17, $17, 31
# > addu $2, $2, $17
# > jr $0
# > sll $0, $0, 0 
B: "\x24\x11\x00\x62\x00\x11\x10\x42\x00\x11\x8f\xc2\x00\x51\x10\x21\x00\x00\x00\x08\x00\x00\x00\x00"
T: "srl1, SRL"
A: "ms8817, # Performs some safe right logical shifts  /ExCode 49"
I: ""
O: ""
E: "49"
