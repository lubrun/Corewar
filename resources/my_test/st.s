.name "ST"
.comment "TESTS ST"

l2:		st r1, 13
		ld %0, r2

live:	live %1
		zjmp %:live
