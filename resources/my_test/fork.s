.name "FORK"
.comment "TESTS FORK"

l1:		fork %:l2
		and %0, %0, r5
		zjmp %:l1

l2:		ld %-1, r3
		sti r3, %:live, %1
		ld %0, r2

live:	live %1
		zjmp %:live
