.comment "zob"
.name "fdsfs"

live:
		ld  %:live, r1 
		and :live, %:live, r1 
		xor r1, r2,					 r3
		zjmp %4294967294
		and :live, %:live, r1 
		ld  %:live, r1
 