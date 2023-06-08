.name "zork"
.comment "I'M ALIIIIVE"

l2:		sti r1, %:live, %1
		and -4, %0, r1

live:	lld :l2, r5
		zjmp %:live
