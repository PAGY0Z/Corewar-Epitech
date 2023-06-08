.name "zork"
.comment "I'M ALIIIIVE"


	ld %145162240, r2	#load bytes that translate to: 06 a7 00 00 into r2   --> 06 is 'and' operation. a7 == 10100111 encoding byte which is INVALID (DIR, DIR, REG, 11). It will trigger the cursor to skip 11 bytes
	st r2, :label		#which is stored at label:

label:
	xor 69, r3, r4		#(4 of) these 6 bytes are overwritten by previous 'st' and skipped
	st r1, 20			#perfectly valid operation will be skipped! (5 bytes)
	live %-1			# previous 11 bytes are skipped
