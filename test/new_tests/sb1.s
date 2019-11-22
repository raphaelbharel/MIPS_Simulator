# sb1
# Source assembly code:
# > sb $0, 0($0)
# > sll $0, $0, 0 
B: "\xa0\x00\x00\x00\x00\x00\x00\x00"
T: "sb1, SB"
A: "ms8817, # Storing byte to invalid position  /ExCode 245"
I: ""
O: ""
E: "245"
