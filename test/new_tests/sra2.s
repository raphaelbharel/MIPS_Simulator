# sra2
# Source assembly code:
# > lui $18, 65535
# > sra $2, $18, 31
# > jr $0
# > sll $0, $0, 0 
B: "\x3c\x12\xff\xff\x00\x12\x17\xc3\x00\x00\x00\x08\x00\x00\x00\x00"
T: "sra2, SRA"
A: "ms8817, # Performs some safe right arithmetic shifts  /ExCode 255"
I: ""
O: ""
E: "255"
