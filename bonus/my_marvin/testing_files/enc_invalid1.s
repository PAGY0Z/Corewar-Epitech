.name "zork"
.comment "I'M ALIIIIVE"


	ld %50266112, r2	#load bytes that translate to: 02 ff 00 00 into r2
	st r2, :label		#which is stored at label:

label:
	xor 69, r3, r4		#(4 of) these 6 bytes are overwritten
	live %-1			# previous 6 bytes are skipped
