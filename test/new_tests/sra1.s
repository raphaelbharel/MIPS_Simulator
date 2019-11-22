# sra1
# Source assembly code:
# > addiu $17, $0, 98
# > sra $2, $17, 1
# > sra $17, $17, 31
# > addu $2, $2, $17
# > jr $0
# > sll $0, $0, 0 
B: "\x24\x11\x00\x62\x00\x11\x10\x43\x00\x11\x8f\xc3\x00\x51\x10\x21\x00\x00\x00\x08\x00\x00\x00\x00"
T: "sra1, SRA"
A: "ms8817, # Performs some safe right arithmetic shifts  /ExCode 49"
I: ""
O: ""
E: "49"
