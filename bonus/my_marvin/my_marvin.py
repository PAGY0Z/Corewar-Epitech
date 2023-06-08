##
## EPITECH PROJECT, 2023
## B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
## File description:
## my_marvin
##

import os
import subprocess

TESTING_FILES_FOLDER = "testing_files/"
REFERENCE_ASM_BINARY_FOLDER = "reference_asm_binary/"
MY_ASM_BINARY_FOLDER = "my_asm_binary/"
REFERENCE_RESULTS_FOLDER = "reference_results/"
MY_ASM_RESULTS_FOLDER = "my_asm_results/"
RELATIVE_ROOT_FOLDER = "../../"
LOG_FILE_NAME = "log_file"
LOG_FILE_CONTENT = []
FAIL_TESTS_FILES = []

def compile_my_asm_binary():
    subprocess.call(["make", "-C", RELATIVE_ROOT_FOLDER])
    subprocess.call(["mv", "../../asm/asm", MY_ASM_BINARY_FOLDER + "asm"])
    subprocess.call(["make", "-C", RELATIVE_ROOT_FOLDER, "fclean"])
    subprocess.call(["clear"])

def init_log_file():
    if os.path.exists(LOG_FILE_NAME):
        subprocess.call(["rm", LOG_FILE_NAME])
    subprocess.call(["touch", LOG_FILE_NAME])

def compile_tests_files_reference():
    files = os.listdir(TESTING_FILES_FOLDER)
    for file in files:
        return_value = subprocess.call(["./" + REFERENCE_ASM_BINARY_FOLDER + "asm", TESTING_FILES_FOLDER + file])
        if return_value == 84:
            print("Error on file: " + file)
        else:
            subprocess.call(["mv", file[:-2] + ".cor", REFERENCE_RESULTS_FOLDER])

def compile_tests_files():
    files = os.listdir(TESTING_FILES_FOLDER)
    for file in files:
        return_value = subprocess.call(["./" + MY_ASM_BINARY_FOLDER + "asm", TESTING_FILES_FOLDER + file])
        if return_value == 84:
            print("Error on file: " + file)
            FAIL_TESTS_FILES.append(TESTING_FILES_FOLDER + file)
        else:
            subprocess.call(["mv", file[:-2] + ".cor", MY_ASM_RESULTS_FOLDER])

def run_diff_tests():
    files = os.listdir(REFERENCE_RESULTS_FOLDER)
    for file in files:
        return_value = subprocess.call(["diff", REFERENCE_RESULTS_FOLDER + file, MY_ASM_RESULTS_FOLDER + file])
        if return_value != 0:
            LOG_FILE_CONTENT.append("------------------------------------\n")
            LOG_FILE_CONTENT.append("Test failed on file: " + file + "\n")
            LOG_FILE_CONTENT.append("Reference: " + REFERENCE_RESULTS_FOLDER + file + "\n")
            LOG_FILE_CONTENT.append("My_ASM: " + MY_ASM_RESULTS_FOLDER + file + "\n")
            LOG_FILE_CONTENT.append("------------------------------------\n")
            print("------------------------------------")
            print("Test failed on file: " + file)
            print("Reference: " + REFERENCE_RESULTS_FOLDER + file)
            print("My_ASM: " + MY_ASM_RESULTS_FOLDER + file)
            print("------------------------------------")

def edit_log_file():
    if len(LOG_FILE_CONTENT) == 0:
        print("All tests passed")
        subprocess.call(["rm", LOG_FILE_NAME])
        return
    else:
        with open(LOG_FILE_NAME, "w") as log_file:
            for line in LOG_FILE_CONTENT:
                log_file.write(line)
        subprocess.call(["mkdir", "logs"])
        subprocess.call(["mv", LOG_FILE_NAME, "logs"])
        for files in FAIL_TESTS_FILES:
            subprocess.call(["cp", files, "logs"])
        subprocess.call(["tar", "-czf", "logs.tar.gz", "logs"])
        subprocess.call(["rm", "-rf", "logs"])

def clean_folders():
    for file in os.listdir(REFERENCE_RESULTS_FOLDER):
        if file != ".gitkeep":
            subprocess.call(["rm", REFERENCE_RESULTS_FOLDER + file])
    for file in os.listdir(MY_ASM_RESULTS_FOLDER):
        if file != ".gitkeep":
            subprocess.call(["rm", MY_ASM_RESULTS_FOLDER + file])
    subprocess.call(["rm", MY_ASM_BINARY_FOLDER + "asm"])

def main():
    compile_my_asm_binary()
    init_log_file()
    compile_tests_files_reference()
    compile_tests_files()
    run_diff_tests()
    edit_log_file()
    clean_folders()

main()
