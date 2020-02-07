.name "OR"
.comment "TESTS OR"

l2:		or 24, 24, r2
		st r2, 17
		or %0, %0, r3

live:	live %-1
		zjmp %:live
