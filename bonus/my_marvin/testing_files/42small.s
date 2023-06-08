.name		"test"
.comment        "Just a basic Winner Program"

entree:	live	%76
	zjmp	%:ld
	ld	%08, r5
ld:	
	zjmp	%:ld
