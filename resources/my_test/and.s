.name "AND"
.comment "TESTS AND"

l2:		and 21, 21, r2
		st r2, 14
		and r1, %0, r3

live:	live %-1
		zjmp %:live
