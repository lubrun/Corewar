.name "LD"
.comment "TESTS LD"

l2:		ld %-1, r3
		sti r3, %:live, %1
		ld %-1, r2
		ld %0, r2

live:	live %1
		zjmp %65535
