.name "LD"
.comment "TESTS LD"

l2:		ld 14, r1
		sti r1, %:live, %1
		ld %-2, r2
		ld %0, r2

live:	live %1
		zjmp %:live
