# subu1
# Source assembly code:
# > addiu $21, $21, 3
# > sll $21, $21, 28
# > subu $16, $17, $18
# > sw $16, 4($21)
# > addiu $17, $17, 300
# > addiu $18, $18, 220
# > subu $16, $17, $18
# > sw $16, 4($21)
# > addiu $18, $18, 230
# > subu $16, $17, $18
# > sw $16, 4($21)
# > sll $17, $17, 20
# > subu $16, $17, $18
# > sw $16, 4($21)
# > jr $0
# > sll $0, $0, 0 
B: "\x26\xb5\x00\x03\x00\x15\xaf\x00\x02\x32\x80\x23\xae\xb0\x00\x04\x26\x31\x01\x2c\x26\x52\x00\xdc\x02\x32\x80\x23\xae\xb0\x00\x04\x26\x52\x00\xe6\x02\x32\x80\x23\xae\xb0\x00\x04\x00\x11\x8d\x00\x02\x32\x80\x23\xae\xb0\x00\x04\x00\x00\x00\x08\x00\x00\x00\x00"
T: "subu1, SUBU"
A: "fd5117, # Several safe subtractions and storing to ADDR_PUTC /ExCode 0"
I: ""
O: "\x00Pj>"
E: "0"
