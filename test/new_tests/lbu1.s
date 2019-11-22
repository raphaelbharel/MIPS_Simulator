# lbu1
# Source assembly code:
# > lbu $0, 0($0)
# > sll $0, $0, 0 
B: "\x90\x00\x00\x00\x00\x00\x00\x00"
T: "lbu1, LBU"
A: "ms8817, # Loading byte from invalid position  /ExCode 245"
I: ""
O: ""
E: "245"
