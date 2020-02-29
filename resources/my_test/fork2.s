.name "FORK2"
.comment "TESTS FORK2"

l1:		ld %0, r10
		fork %:l2
		st r1, 6
		live %42
		and %0, %0, r5
		ld %0, r14
		st r10, 0
and:	and %3, %3, r5
		and %4, %4, r5
		and %0, %0, r5
jump:	zjmp %:l1

l2:		sti r10, %:and, %1
		ld %-1, r3
		sti r3, %:live, %1
		ld %0, r2

live:	live %1
		zjmp %:l2
