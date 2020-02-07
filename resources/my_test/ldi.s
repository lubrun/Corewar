.name "LDI"
.comment "TESTS LDI"

l2:		ldi 19, %33, r2
		sti r2, %:live, %1
		and %0, %1, r3
		ldi %1, %5, r5

live:	live %-1
		zjmp %:live
