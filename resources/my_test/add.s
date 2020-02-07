.name "ADD"
.comment "TESTS ADD"

l2:		add r1, r2, r1
		st r1, 11
		add r3, r3, r3

live:	live %1
		zjmp %:live
