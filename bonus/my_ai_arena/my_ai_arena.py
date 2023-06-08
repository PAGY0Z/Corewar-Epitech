
import os
import subprocess

CHAMPIONS_SRC_FILES_PATH = "champions_src_files/"
CHAMPIONS_COR_FILES_PATH = "champions_cor_files/"
REFERENCE_ASM_PATH = "reference_asm_binary/"
REFERENCE_COREWAR_PATH = "reference_corewar_binary/"
CHAMPIONS_SCORE_LIST = []
TEST_NUMBER = 0

def remove_identical_champions():
    files = os.listdir(CHAMPIONS_SRC_FILES_PATH)
    for file in files:
        for file2 in files:
            if file != file2:
                return_value = subprocess.call(["diff", CHAMPIONS_SRC_FILES_PATH + file, CHAMPIONS_SRC_FILES_PATH + file2])
                if return_value == 0:
                    subprocess.call(["rm", CHAMPIONS_SRC_FILES_PATH + file2])

def compile_champions():
    files = os.listdir(CHAMPIONS_SRC_FILES_PATH)
    for file in files:
        return_value = subprocess.call(["./" + REFERENCE_ASM_PATH + "asm", CHAMPIONS_SRC_FILES_PATH + file])
        if return_value == 84:
            print("Error on file: " + file)
            subprocess.call(["rm", file])
        else:
            subprocess.call(["mv", file[:-2] + ".cor", CHAMPIONS_COR_FILES_PATH])

def clear_champions_cor_files():
    subprocess.call(["rm", "-rf", CHAMPIONS_COR_FILES_PATH + "*.cor"])

def init_champions_score_list():
    files = os.listdir(CHAMPIONS_COR_FILES_PATH)
    for file in files:
        if file.find(".cor") != -1:
            CHAMPIONS_SCORE_LIST.append({"name": file, "error": 0, "win": 0, "lose": 0, "tie": 0})

def clear_champions_score_list(max_champions):
    CHAMPIONS_SCORE_LIST.sort(key=lambda x: x["win"], reverse=True)
    while len(CHAMPIONS_SCORE_LIST) > max_champions:
        CHAMPIONS_SCORE_LIST.pop()
    CHAMPIONS_SCORE_LIST.sort(key=lambda x: x["win"], reverse=True)

def display_champions_score_list():
    CHAMPIONS_SCORE_LIST.sort(key=lambda x: x["win"], reverse=True)
    rank = 1
    print("Challenge score list:")
    for champion in CHAMPIONS_SCORE_LIST:
        champion_total = champion["win"] + champion["lose"] + champion["tie"] + champion["error"]
        champion_error_rate = champion["error"] / champion_total * 100
        champion_win_rate = champion["win"] / champion_total * 100
        champion_lose_rate = champion["lose"] / champion_total * 100
        champion_tie_rate = champion["tie"] / champion_total * 100
        print(str(rank) + ". " + champion["name"] + ": " + str(champion["win"]) + " wins, " + str(round(champion_win_rate, 2)) + "%, " + str(champion["lose"]) + " loses, " + str(round(champion_lose_rate, 2)) + "%, " + str(champion["tie"]) + " ties, " + str(round(champion_tie_rate, 2)) + "%, " + str(champion["error"]) + " errors, " + str(round(champion_error_rate, 2)) + "%")
        rank += 1

def init_result_file():
    if os.path.exists("result.txt"):
        subprocess.call(["rm", "-rf", "result.txt"])
    subprocess.call(["touch", "result.txt"])

def write_result_file(file_name):
    with open(file_name, "w") as result_file:
        CHAMPIONS_SCORE_LIST.sort(key=lambda x: x["win"], reverse=True)
        rank = 1
        result_file.write("Ranking:\n")
        for champion in CHAMPIONS_SCORE_LIST:
            champion_total = champion["win"] + champion["lose"] + champion["tie"] + champion["error"]
            champion_error_rate = champion["error"] / champion_total * 100
            champion_win_rate = champion["win"] / champion_total * 100
            champion_lose_rate = champion["lose"] / champion_total * 100
            champion_tie_rate = champion["tie"] / champion_total * 100
            result_file.write(str(rank) + ". " + champion["name"] + ": " + str(champion["win"]) + " wins, " + str(round(champion_win_rate, 2)) + "%, " + str(champion["lose"]) + " loses, " + str(round(champion_lose_rate, 2)) + "%, " + str(champion["tie"]) + " ties, " + str(round(champion_tie_rate, 2)) + "%, " + str(champion["error"]) + " errors, " + str(round(champion_error_rate)) + "%\n")
            rank += 1

def display_champion_stats(champions):
    champion_total = champions["win"] + champions["lose"] + champions["tie"] + champions["error"]
    if champion_total == 0:
        print(champions["name"] + ": " + str(0) + " wins, " + str(round(0, 2)) + "%, " + str(0) + " loses, " + str(round(0, 2)) + "%, " + str(0) + " ties, " + str(round(0, 2)) + "%, " + str(0) + " errors, " + str(round(0, 2)) + "%")
        return
    champion_error_rate = champions["error"] / champion_total * 100
    champion_win_rate = champions["win"] / champion_total * 100
    champion_lose_rate = champions["lose"] / champion_total * 100
    champion_tie_rate = champions["tie"] / champion_total * 100
    print(champions["name"] + ": " + str(champions["win"]) + " wins, " + str(round(champion_win_rate, 2)) + "%, " + str(champions["lose"]) + " loses, " + str(round(champion_lose_rate, 2)) + "%, " + str(champions["tie"]) + " ties, " + str(round(champion_tie_rate, 2)) + "%, " + str(champions["error"]) + " errors, " + str(round(champion_error_rate, 2)) + "%")

def run_matches_two():
    global TEST_NUMBER
    for champion1 in CHAMPIONS_SCORE_LIST:
        for champion2 in CHAMPIONS_SCORE_LIST:
            if champion1["name"] != champion2["name"]:
                display_champion_stats(champion1)
                display_champion_stats(champion2)
                init_result_file()
                with open("result.txt", "w") as result_file:
                    try:
                        print("TESTS: " + str(TEST_NUMBER) + " - " + champion1["name"] + " vs " + champion2["name"])
                        TEST_NUMBER += 1
                        return_value = subprocess.call(["./" + REFERENCE_COREWAR_PATH + "corewar", CHAMPIONS_COR_FILES_PATH + champion1["name"], CHAMPIONS_COR_FILES_PATH + champion2["name"]], stdout=result_file, timeout=5)
                        if return_value == 84:
                            print("Error on file: " + champion1["name"] + " or " + champion2["name"])
                            champion1["error"] += 1
                            champion2["error"] += 1
                            continue
                        last_line = subprocess.check_output(["tail", "-1", "result.txt"]).decode('latin-1')
                        if last_line == "No winner !":
                            champion1["tie"] += 1
                            champion2["tie"] += 1
                            continue
                        if last_line.find("The player 0(") and last_line.find("has won."):
                            champion1["win"] += 1
                            champion2["lose"] += 1
                            continue
                        if last_line.find("The player 1(") and last_line.find("has won."):
                            champion1["lose"] += 1
                            champion2["win"] += 1
                            continue
                    except subprocess.TimeoutExpired:
                        print("Timeout expired " + champion1["name"] + " or " + champion2["name"])
                        champion1["error"] += 1
                        champion2["error"] += 1
                        continue

def run_matches_three():
    global TEST_NUMBER
    for champion1 in CHAMPIONS_SCORE_LIST:
        for champion2 in CHAMPIONS_SCORE_LIST:
            for champion3 in CHAMPIONS_SCORE_LIST:
                if champion1["name"] != champion2["name"] and champion1["name"] != champion3["name"] and champion2["name"] != champion3["name"]:
                    display_champion_stats(champion1)
                    display_champion_stats(champion2)
                    display_champion_stats(champion3)
                    init_result_file()
                    with open("result.txt", "w") as result_file:
                        try:
                            print("TESTS: " + str(TEST_NUMBER) + " - " + champion1["name"] + " vs " + champion2["name"] + " vs " + champion3["name"])
                            TEST_NUMBER += 1
                            subprocess.call(["./" + REFERENCE_COREWAR_PATH + "corewar", CHAMPIONS_COR_FILES_PATH + champion1["name"], CHAMPIONS_COR_FILES_PATH + champion2["name"], CHAMPIONS_COR_FILES_PATH + champion3["name"]], stdout=result_file, timeout=5)
                            last_line = subprocess.check_output(["tail", "-1", "result.txt"]).decode('latin-1')
                            if last_line == "No winner !":
                                champion1["tie"] += 1
                                champion2["tie"] += 1
                                champion3["tie"] += 1
                                continue
                            if last_line.find("The player 0(") and last_line.find("has won."):
                                champion1["win"] += 1
                                champion2["lose"] += 1
                                champion3["lose"] += 1
                                continue
                            if last_line.find("The player 1(") and last_line.find("has won."):
                                champion1["lose"] += 1
                                champion2["win"] += 1
                                champion3["lose"] += 1
                                continue
                            if last_line.find("The player 2(") and last_line.find("has won."):
                                champion1["lose"] += 1
                                champion2["lose"] += 1
                                champion3["win"] += 1
                                continue
                        except subprocess.TimeoutExpired:
                            print("Timeout expired " + champion1["name"] + " or " + champion2["name"] + " or " + champion3["name"])
                            champion1["error"] += 1
                            champion2["error"] += 1
                            champion3["error"] += 1
                            continue

def run_matches_four():
    global TEST_NUMBER
    for champion1 in CHAMPIONS_SCORE_LIST:
        for champion2 in CHAMPIONS_SCORE_LIST:
            for champion3 in CHAMPIONS_SCORE_LIST:
                for champion4 in CHAMPIONS_SCORE_LIST:
                    if champion1["name"] != champion2["name"] and champion1["name"] != champion3["name"] and champion1["name"] != champion4["name"] and champion2["name"] != champion3["name"] and champion2["name"] != champion4["name"] and champion3["name"] != champion4["name"]:
                        display_champion_stats(champion1)
                        display_champion_stats(champion2)
                        display_champion_stats(champion3)
                        display_champion_stats(champion4)
                        init_result_file()
                        with open("result.txt", "w") as result_file:
                            try:
                                print("TESTS: " + str(TEST_NUMBER) + " - " + champion1["name"] + " vs " + champion2["name"] + " vs " + champion3["name"] + " vs " + champion4["name"])
                                TEST_NUMBER += 1
                                subprocess.call(["./" + REFERENCE_COREWAR_PATH + "corewar", CHAMPIONS_COR_FILES_PATH + champion1["name"], CHAMPIONS_COR_FILES_PATH + champion2["name"], CHAMPIONS_COR_FILES_PATH + champion3["name"], CHAMPIONS_COR_FILES_PATH + champion4["name"]], stdout=result_file, timeout=5)
                                last_line = subprocess.check_output(["tail", "-1", "result.txt"]).decode('latin-1')
                                if last_line == "No winner !":
                                    champion1["tie"] += 1
                                    champion2["tie"] += 1
                                    champion3["tie"] += 1
                                    champion4["tie"] += 1
                                    continue
                                if last_line.find("The player 0(") and last_line.find("has won."):
                                    champion1["win"] += 1
                                    champion2["lose"] += 1
                                    champion3["lose"] += 1
                                    champion4["lose"] += 1
                                    continue
                                if last_line.find("The player 1(") and last_line.find("has won."):
                                    champion1["lose"] += 1
                                    champion2["win"] += 1
                                    champion3["lose"] += 1
                                    champion4["lose"] += 1
                                    continue
                                if last_line.find("The player 2(") and last_line.find("has won."):
                                    champion1["lose"] += 1
                                    champion2["lose"] += 1
                                    champion3["win"] += 1
                                    champion4["lose"] += 1
                                    continue
                                if last_line.find("The player 3(") and last_line.find("has won."):
                                    champion1["lose"] += 1
                                    champion2["lose"] += 1
                                    champion3["lose"] += 1
                                    champion4["win"] += 1
                                    continue
                            except subprocess.TimeoutExpired:
                                print("Timeout expired " + champion1["name"] + " or " + champion2["name"] + " or " + champion3["name"] + " or " + champion4["name"])
                                champion1["error"] += 1
                                champion2["error"] += 1
                                champion3["error"] += 1
                                champion4["error"] += 1
                                continue

def run_matches_five():
    global TEST_NUMBER
    for champion1 in CHAMPIONS_SCORE_LIST:
        for champion2 in CHAMPIONS_SCORE_LIST:
            for champion3 in CHAMPIONS_SCORE_LIST:
                for champion4 in CHAMPIONS_SCORE_LIST:
                    for champion5 in CHAMPIONS_SCORE_LIST:
                        if champion1["name"] != champion2["name"] and champion1["name"] != champion3["name"] and champion1["name"] != champion4["name"] and champion1["name"] != champion5["name"] and champion2["name"] != champion3["name"] and champion2["name"] != champion4["name"] and champion2["name"] != champion5["name"] and champion3["name"] != champion4["name"] and champion3["name"] != champion5["name"] and champion4["name"] != champion5["name"]:
                            display_champion_stats(champion1)
                            display_champion_stats(champion2)
                            display_champion_stats(champion3)
                            display_champion_stats(champion4)
                            display_champion_stats(champion5)
                            init_result_file()
                            with open("result.txt", "w") as result_file:
                                try:
                                    print("TESTS: " + str(TEST_NUMBER) + " - " + champion1["name"] + " vs " + champion2["name"] + " vs " + champion3["name"] + " vs " + champion4["name"] + " vs " + champion5["name"])
                                    TEST_NUMBER += 1
                                    subprocess.call(["./" + REFERENCE_COREWAR_PATH + "corewar", CHAMPIONS_COR_FILES_PATH + champion1["name"], CHAMPIONS_COR_FILES_PATH + champion2["name"], CHAMPIONS_COR_FILES_PATH + champion3["name"], CHAMPIONS_COR_FILES_PATH + champion4["name"], CHAMPIONS_COR_FILES_PATH + champion5["name"]], stdout=result_file, timeout=5)
                                    last_line = subprocess.check_output(["tail", "-1", "result.txt"]).decode('latin-1')
                                    if last_line == "No winner !":
                                        champion1["tie"] += 1
                                        champion2["tie"] += 1
                                        champion3["tie"] += 1
                                        champion4["tie"] += 1
                                        champion5["tie"] += 1
                                        continue
                                    if last_line.find("The player 0(") and last_line.find("has won."):
                                        champion1["win"] += 1
                                        champion2["lose"] += 1
                                        champion3["lose"] += 1
                                        champion4["lose"] += 1
                                        champion5["lose"] += 1
                                        continue
                                    if last_line.find("The player 1(") and last_line.find("has won."):
                                        champion1["lose"] += 1
                                        champion2["win"] += 1
                                        champion3["lose"] += 1
                                        champion4["lose"] += 1
                                        champion5["lose"] += 1
                                        continue
                                    if last_line.find("The player 2(") and last_line.find("has won."):
                                        champion1["lose"] += 1
                                        champion2["lose"] += 1
                                        champion3["win"] += 1
                                        champion4["lose"] += 1
                                        champion5["lose"] += 1
                                        continue
                                    if last_line.find("The player 3(") and last_line.find("has won."):
                                        champion1["lose"] += 1
                                        champion2["lose"] += 1
                                        champion3["lose"] += 1
                                        champion4["win"] += 1
                                        champion5["lose"] += 1
                                        continue
                                    if last_line.find("The player 4(") and last_line.find("has won."):
                                        champion1["lose"] += 1
                                        champion2["lose"] += 1
                                        champion3["lose"] += 1
                                        champion4["lose"] += 1
                                        champion5["win"] += 1
                                        continue
                                except subprocess.TimeoutExpired:
                                    print("Timeout expired " + champion1["name"] + " or " + champion2["name"] + " or " + champion3["name"] + " or " + champion4["name"] + " or " + champion5["name"])
                                    champion1["error"] += 1
                                    champion2["error"] += 1
                                    champion3["error"] += 1
                                    champion4["error"] += 1
                                    champion5["error"] += 1
                                    continue


    
def main():
    remove_identical_champions()
    compile_champions()
    init_champions_score_list()
    init_result_file()

    run_matches_two()
    write_result_file("result2.txt")
    display_champions_score_list()
    clear_champions_score_list(27)

    run_matches_three()
    write_result_file("result3.txt")
    display_champions_score_list()
    clear_champions_score_list(16)

    run_matches_four()
    write_result_file("result4.txt")
    display_champions_score_list()
    clear_champions_score_list(5)

    run_matches_five()
    write_result_file("result5.txt")
    display_champions_score_list()
    clear_champions_score_list(1)

    display_champions_score_list()
    clear_champions_cor_files()

main()