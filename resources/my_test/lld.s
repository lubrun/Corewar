.name "LLD"
.comment "TESTS LLD"

l2:		lld 17, r3
		sti r3, %:live, %1
		lld %-1, r2
		lld %0, r2

live:	live %1
		zjmp %:live
