#include <stdio.h>
#include <stdlib.h>

#include <check.h>

START_TEST(test_1) {

    /* here's a template we can use for unit testing lol */
    ck_assert (1);

} END_TEST

int main (int argc, char **argv) {

    Suite *test_suite;
    TCase *test_case;
    SRunner *suite_runner;

    int n_failures;

    test_case = tcase_create ("Test case 1");
    tcase_add_test (test_case, test_1);

    test_suite = suite_create ("Test suite 1");
    suite_add_tcase (test_suite, test_case);

    suite_runner = srunner_create (test_suite);
    srunner_run_all (suite_runner, CK_NORMAL);
    n_failures = srunner_ntests_failed (suite_runner);

    srunner_free (suite_runner);

    return n_failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
