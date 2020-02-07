.name "AFF"
.comment "TESTS AFF"

l2:		ld %-1, r3
		sti r3, %:live, %1
		ld %52, r2
		ld %50, r4
		ld %3, r5
		ld %4, r6
		ld %71, r7
		ld %103, r8
		aff r2
		aff r4
		aff r5
		aff r6
		aff r7
		aff r8

live:	live %1
		zjmp %:live
