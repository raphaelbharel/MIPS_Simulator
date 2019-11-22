# lhu8
# Source assembly code:
# > addiu $16, $16, 2
# > sll $16, $16, 28
# > addiu $17, $0, 27259
# > sw $17, 0($16)
# > lhu $2, 2($16)
# > sll $0, $0, 0 
# > jr $0
# > sll $0, $0, 0 
B: "\x26\x10\x00\x02\x00\x10\x87\x00\x24\x11\x6a\x7b\xae\x11\x00\x00\x96\x02\x00\x02\x00\x00\x00\x00\x00\x00\x00\x08\x00\x00\x00\x00"
T: "lhu8, LHU"
A: "ms8817, # Use sw to store a number; read a part of it with lhu; check if it is what expected /ExCode 123"
I: ""
O: ""
E: "123"
