.name"Zork"

.comment "I'M ALIIIIVE"

l2:		sti r1, 45, %1
		ld  %:live, r1
		and r1, %0, r1 
		xor r1, r2, r3
		zjmp %4294967294
