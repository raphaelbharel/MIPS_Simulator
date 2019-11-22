# lwl1
# Source assembly code:
# > lwl $0, 0($0)
# > sll $0, $0, 0 
B: "\x88\x00\x00\x00\x00\x00\x00\x00"
T: "lwl1, LWL"
A: "ms8817, # Loading left word from invalid position  /ExCode 245"
I: ""
O: ""
E: "245"
