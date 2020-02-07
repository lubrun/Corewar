.name "XOR"
.comment "TESTS XOR"

l2:		xor r1, %0, r2
		st r2, 17
		xor %0, %0, r3

live:	live %1
		zjmp %:live
