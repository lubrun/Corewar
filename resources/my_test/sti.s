.name "STI"
.comment "TESTS STI"

l2:		sti r1, 19, %18
		and %0, %1, r3

live:	live %1
		zjmp %:live
