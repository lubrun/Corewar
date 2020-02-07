.name "SUB"
.comment "TESTS SUB"

l2:		sub r1, r2, r1
		st r1, 11
		sub r1, r1, r3

live:	live %1
		zjmp %:live
