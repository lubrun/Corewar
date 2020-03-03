.name "FORK3"
.comment "TESTS FORK3"

l1:		ld %2852126720, r10
		fork %:l2
		st r1, 6
		live %42
		and %0, %0, r5
and:	st r12, 7
		and %4, %4, r5
		and %0, %0, r5
jump:	zjmp %:l1

l2:		sti r10, %:and, %1
		sti r3, %:live, %1
		ld %0, r2

live:	live %1
		zjmp %:l2
