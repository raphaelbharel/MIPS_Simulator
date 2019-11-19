add3;ADD;8;daryllimyt
tests/bin/ADD-overflow.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <_entry>:
10000000:	3c027fff 	addi $3, $0, 7
10000004:	3442ffff 	addi $4, $0, 5
10000008:	3463ffff 	add $2, $3, $4
1000000c:	00631020 	jr $0
10000010:	03e00008 	jr	ra
10000014:	00000000 	nop
10000018:	00000000 	nop

addi $3, $0, 7
addi $4, $0, 5
add $2, $3, $4
jr $0