/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
** File description:
** tests_asm_programm_main
*/

#include "tests_include_header.h"

Test(display_asm_help, tests_display_asm_help, .init=redirect, .timeout=1) {
    cr_assert_eq(display_asm_help(NULL), 84);
    cr_assert_eq(display_asm_help((char **)asm_help), 0);
}

Test(check_asm_args, tests_check_asm_args, .init=redirect, .timeout=1) {
    char *args[] = {"./asm", "tests/asm/asm_files/valid_file.s", NULL};
    char *args2[] = {"./asm", "tests/asm/asm_files/invalid_file", NULL};
    cr_assert_eq(check_asm_args(1, NULL), false);
    cr_assert_eq(check_asm_args(2, args2), false);
    cr_assert_eq(check_asm_args(2, args), true);
}

Test(asm_programm_main, tests_asm_programm_main, .init=redirect, .timeout=1) {
    char *args[] = {"./asm", "-h", NULL};
    char *args2[] = {"./asm", "tests/asm/asm_files/invalid_file", NULL};
    cr_assert_eq(asm_programm_main(2, args), 0);
    cr_assert_eq(asm_programm_main(2, args2), 84);

    // VALID TESTS CHAMPIONS
    FILE *stream1 = NULL; FILE *stream2 = NULL;
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/abel.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("abel.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/abel.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/bill.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("bill.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/bill.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/jon_snow.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("jon_snow.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/jon_snow.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/luke.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("luke.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/luke.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/pdd.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("pdd.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/pdd.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/tyron.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("tyron.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/tyron.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/rabel.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("rabel.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/rabel.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/raurollan.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("raurollan.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/raurollan.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/rbigzork.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("rbigzork.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/rbigzork.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/rbill.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("rbill.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/rbill.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/rCar.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("rCar.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/rCar.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/rcepalle.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("rcepalle.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/rcepalle.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/rcepalle2.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("rcepalle2.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/rcepalle2.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/rcorruption.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("rcorruption.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/rcorruption.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/rcorup.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("rcorup.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/rcorup.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/rex.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("rex.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/rex.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/rfluttershy.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("rfluttershy.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/rfluttershy.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/rGagnant.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("rGagnant.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/rGagnant.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/rjumper.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("rjumper.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/rjumper.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/rkroz.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("rkroz.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/rkroz.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/rmaxidef.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("rmaxidef.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/rmaxidef.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/rmortel.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("rmortel.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/rmortel.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/rOctobre_Rouge_V4.2.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("rOctobre_Rouge_V4.2.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/rOctobre_Rouge_V4.2.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/rpdd.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("rpdd.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/rpdd.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/rppichier.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("rppichier.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/rppichier.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/rslider2.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("rslider2.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/rslider2.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/rsujet.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("rsujet.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/rsujet.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/rtoto.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("rtoto.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/rtoto.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/rtyron.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("rtyron.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/rtyron.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/aurollan.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("aurollan.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/aurollan.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/bigzork.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("bigzork.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/bigzork.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/bill copy.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("bill copy.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/bill copy.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/Car.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("Car.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/Car.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/cepalle.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("cepalle.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/cepalle.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/cepalle2.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("cepalle2.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/cepalle2.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/corruption.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("corruption.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/corruption.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/corup.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("corup.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/corup.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/ex.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("ex.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/ex.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/fluttershy.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("fluttershy.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/fluttershy.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/Gagnant.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("Gagnant.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/Gagnant.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/jumper.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("jumper.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/jumper.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/kroz.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("kroz.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/kroz.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/maxidef.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("maxidef.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/maxidef.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/mortel.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("mortel.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/mortel.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/Octobre_Rouge_V4.2.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("Octobre_Rouge_V4.2.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/Octobre_Rouge_V4.2.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/pdd copy.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("pdd copy.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/pdd copy.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/ppichier.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("ppichier.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/ppichier.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/slider2.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("slider2.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/slider2.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/sujet.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("sujet.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/sujet.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/toto.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("toto.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/toto.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/champions/tyron copy.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("tyron copy.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/champions/tyron copy.cor")));
    fclose(stream1); fclose(stream2);

    // VALID TESTS METADATA

    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/metadata_valids/metadata_valid00.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("metadata_valid00.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/metadata_valids/metadata_valid00.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/metadata_valids/metadata_valid01.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("metadata_valid01.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/metadata_valids/metadata_valid01.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/metadata_valids/metadata_valid02.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("metadata_valid02.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/metadata_valids/metadata_valid02.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/metadata_valids/metadata_valid03.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("metadata_valid03.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/metadata_valids/metadata_valid03.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/metadata_valids/metadata_valid04.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("metadata_valid04.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/metadata_valids/metadata_valid04.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/metadata_valids/metadata_valid05.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("metadata_valid05.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/metadata_valids/metadata_valid05.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/metadata_valids/metadata_valid06.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("metadata_valid06.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/metadata_valids/metadata_valid06.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/metadata_valids/metadata_valid07.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("metadata_valid07.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/metadata_valids/metadata_valid07.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/metadata_valids/metadata_valid08.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("metadata_valid08.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/metadata_valids/metadata_valid08.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/metadata_valids/metadata_valid09.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("metadata_valid09.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/metadata_valids/metadata_valid09.cor")));
    fclose(stream1); fclose(stream2);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/metadata_valids/metadata_valid10.s", NULL}), 0);
    cr_assert_file_contents_eq((stream1 = get_file_stream("metadata_valid10.cor")), (stream2 = get_file_stream("tests/asm_reference_binaries/metadata_valids/metadata_valid10.cor")));
    fclose(stream1); fclose(stream2);

    // INVALID TESTS

    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/metadata_invalids/metadata_invalid00.s", NULL}), 84);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/metadata_invalids/metadata_invalid00.s", NULL}), 84);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/metadata_invalids/metadata_invalid01.s", NULL}), 84);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/metadata_invalids/metadata_invalid02.s", NULL}), 84);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/metadata_invalids/metadata_invalid03.s", NULL}), 84);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/metadata_invalids/metadata_invalid04.s", NULL}), 84);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/metadata_invalids/metadata_invalid05.s", NULL}), 84);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/metadata_invalids/metadata_invalid06.s", NULL}), 84);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/metadata_invalids/metadata_invalid07.s", NULL}), 84);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/metadata_invalids/metadata_invalid08.s", NULL}), 84);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/metadata_invalids/metadata_invalid09.s", NULL}), 84);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/metadata_invalids/metadata_invalid10.s", NULL}), 84);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/metadata_invalids/metadata_invalid11.s", NULL}), 84);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/metadata_invalids/metadata_invalid12.s", NULL}), 84);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/metadata_invalids/metadata_invalid13.s", NULL}), 84);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/metadata_invalids/metadata_invalid14.s", NULL}), 84);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/metadata_invalids/metadata_invalid15.s", NULL}), 84);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/metadata_invalids/metadata_invalid16.s", NULL}), 84);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/metadata_invalids/metadata_invalid17.s", NULL}), 84);
    cr_assert_eq(asm_programm_main(2, (char *[]){"./asm", "tests/asm_reference_binaries/metadata_invalids/metadata_invalid18.s", NULL}), 84);
}