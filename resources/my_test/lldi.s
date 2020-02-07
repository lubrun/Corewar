.name "LLDI"
.comment "TESTS LLDI"

l2:		lldi %1, %32, r2
		sti r2, %:live, %1
		and %0, %1, r3
		lldi %0, %400, r5

live:	live %-1
		zjmp %:live
