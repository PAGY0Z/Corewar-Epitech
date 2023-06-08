.name "zork"
.comment "I'M ALIIIIVE"


	ld %72399550, r2			#load bytes that translate to: 04 50 ba be into r2   --> 04 is 'add' operation. 
								#50 == 01010000 encoding byte which is INVALID (REG, REG, 00, 00). 
								#It will trigger the cursor to skip 4 bytes (add is missing 3rd argument)
	st r2, :label				#which is stored at label:

label:
	xor %3133016936, r1, r1		#(4 of) these 8 bytes are overwritten by previous 'st' and skipped. 
								# %3133016936 are 4 bytes (ba be 0b 68), but first two are SKIPPED!
								# '0b' is valid opcode for 'sti' and 68 is a valid encoding byte (01101000)! 
								#The first r1 counts as the first argument for sti, the second r1 is used 
								# together with the opcode of the next line.
	zjmp %300					#previous r1 together with opcode of zjmp form: 01 09
								# %300 forms 01 2c
								#now the sti operation is formed with valid encoding byte and arguments!
								# So by inserting a bug using 'ld' and 'st', the second part of xor together with
								# zjmp formed a completely new valid operation sti.
	live %-1
