# To create a .cor file: ./asm champ.s
# Each line starts with an operation followed by it's arguments (seperated by
# a comma).
#
# %1 --> percentage means DIRECT type
# 42069 --> a number without prefix is of INDIRECT type
# r1 --> a number between 1 and 16 prefixed with a 'r' is a REGISTRY
# :label1 -> INDIRECT_LABEL
# %:label2 -> DIRECT_LABEL
# sti	T_REG	T_REG | T_DIR | T_IND	T_REG | T_DIR

.name			"Whoami?"
.comment        "In registry 1 i put 4 + whats in registry 3"

	sti r1, %4, r3
