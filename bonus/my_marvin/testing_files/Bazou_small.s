.name "Bazou"
.comment "C'est comme un petit lapin mais en plus peureux et avec des moins grandes oreilles."

	ld %0, r14
start:
i:	zjmp %:first

two:

first:
	st r1, 13
	ld %33554431, r1
	zjmp %-5
	ld -4, r2
	st r1, :start
	st r2, -451

