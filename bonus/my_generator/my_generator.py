#!/usr/bin/python3

import random

def write_direct(file):
    if (random.randint(0, 1) == 1):
        file.write("%" + str(random.randint(-999999999999, 999999999999)) + ",")
    else:
        file.write("%:label" + str(random.randint(0, 20)) + ",")


def write_register(file):
    file.write("r" + str(random.randint(1, 16)) + ",")


def write_indirect(file):
    if (random.randint(0, 1) == 1):
        file.write(str(random.randint(-999999999999, 999999999999)) + ",")
    else:
        file.write(":label" + str(random.randint(0, 20)) + ",")


def live(file):
    file.write("live ")
    write_direct(file)
    file.write("\n")


def ld(file):
    file.write("ld ")
    if (random.randint(0, 1) == 1):
        write_direct(file)
    else:
        write_indirect(file)
    write_register(file)
    file.write("\n")


def st(file):
    file.write("st ")
    write_register(file)
    if (random.randint(0, 1) == 1):
        write_indirect(file)
    else:
        write_register(file)
    file.write("\n")


def add(file):
    file.write("add ")
    write_register(file)
    write_register(file)
    write_register(file)
    file.write("\n")


def sub(file):
    file.write("sub ")
    write_register(file)
    write_register(file)
    write_register(file)
    file.write("\n")


def and_func(file):
    file.write("and ")
    rand = random.randint(0, 2)
    if (rand == 0):
        write_register(file)
    elif (rand == 1):
        write_direct(file)
    else:
        write_indirect(file)
    rand = random.randint(0, 2)
    if (rand == 0):
        write_register(file)
    elif (rand == 1):
        write_direct(file)
    else:
        write_indirect(file)
    write_register(file)
    file.write("\n")


def or_func(file):
    file.write("or ")
    rand = random.randint(0, 2)
    if (rand == 0):
        write_register(file)
    elif (rand == 1):
        write_direct(file)
    else:
        write_indirect(file)
    rand = random.randint(0, 2)
    if (rand == 0):
        write_register(file)
    elif (rand == 1):
        write_direct(file)
    else:
        write_indirect(file)
    write_register(file)
    file.write("\n")


def xor_func(file):
    file.write("xor ")
    rand = random.randint(0, 2)
    if (rand == 0):
        write_register(file)
    elif (rand == 1):
        write_direct(file)
    else:
        write_indirect(file)
    rand = random.randint(0, 2)
    if (rand == 0):
        write_register(file)
    elif (rand == 1):
        write_direct(file)
    else:
        write_indirect(file)
    write_register(file)
    file.write("\n")


def zjmp(file):
    file.write("zjmp ")
    write_direct(file)
    file.write("\n")


def ldi(file):
    file.write("ldi ")
    rand = random.randint(0, 2)
    if (rand == 0):
        write_register(file)
    elif (rand == 1):
        write_direct(file)
    else:
        write_indirect(file)
    if (random.randint(0, 1) == 1):
        write_direct(file)
    else:
        write_register(file)
    write_register(file)
    file.write("\n")


def sti(file):
    file.write("sti ")
    write_register(file)
    rand = random.randint(0, 2)
    if (rand == 0):
        write_direct(file)
    elif (rand == 1):
        write_indirect(file)
    else:
        write_register(file)
    if (random.randint(0, 1) == 1):
        write_direct(file)
    else:
        write_register(file)
    file.write("\n")


def fork(file):
    file.write("fork ")
    write_direct(file)
    file.write("\n")


def lld(file):
    file.write("lld ")
    if (random.randint(0, 1) == 1):
        write_direct(file)
    else:
        write_indirect(file)
    write_register(file)
    file.write("\n")


def lldi(file):
    file.write("lldi ")
    rand = random.randint(0, 2)
    if (rand == 0):
        write_register(file)
    elif (rand == 1):
        write_direct(file)
    else:
        write_indirect(file)
    if (random.randint(0, 1) == 1):
        write_direct(file)
    else:
        write_register(file)
    write_register(file)
    file.write("\n")


def lfork(file):
    file.write("lfork ")
    write_direct(file)
    file.write("\n")


def aff(file):
    file.write("aff ")
    write_register(file)
    file.write("\n")


def gen_champ():
    tab_command = [live, ld, st, add, sub, and_func, or_func,
                   xor_func, zjmp, ldi, sti, fork, lld, lldi, lfork, aff]
    while True:
        try:
            name_file = str(input("number of the champion:"))
        except ValueError:
            print("retry with a valid name")
        break
    file = open(name_file + ".s", "w")
    while True:
        try:
            nb_line = int(input("number of line in the file:"))
        except ValueError:
            print("retry with a valid value (> 20)")
        break

    # <for header>
    file.write(".name \"\"")
    file.write("\n")
    file.write(".comment \"\"")
    # </for header>

    # <to fill file>
    file.write("\n")
    label_value = 0
    for i in range(0, nb_line):
        if (label_value <= 20):
            if (random.randint(0, nb_line) < nb_line / 20):
                file.write("label" + str(label_value) + ":")
                label_value += 1
                file.write("\n")
        function = random.choice(tab_command)
        function(file)
    for i in range(label_value, 20):
        file.write("label" + str(i) + ":")
        file.write("\n")
    file.close()
    # </to fill file>


if __name__ == '__main__':
    gen_champ()
