#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "../src/dynslice.h"

START_TEST(dynamic_slice_test) {

    int value = 10;
    int i;
    
    struct DynamicSlice *dynslice;
    dynslice = create_dynamic_slice(sizeof(void *));
    
    append(dynslice, &value);
    append(dynslice, &value);
    append(dynslice, &value);
    append(dynslice, &value);
    
    for (i = 0; i < dynslice->size; i++) {

        int a = *(int *) get (dynslice, i);
        int b = value;
        printf("get: %d ;", a);
        printf("value: %d\n", b);
        ck_assert_int_eq (a, b);
        value++;
    }

    free_dynamic_slice (dynslice);

} END_TEST

int main (int argc, char **argv) {

    TCase *test_case;
    Suite *test_suite;
    SRunner *suite_runner;

    int n_failures;

    test_case = tcase_create ("dynamic slice test case");
    tcase_add_test (test_case, dynamic_slice_test);

    test_suite = suite_create ("dynamic slice test suite");
    suite_add_tcase (test_suite, test_case);

    suite_runner = srunner_create (test_suite);
    srunner_run_all (suite_runner, CK_NORMAL);
    n_failures = srunner_ntests_failed (suite_runner);

    srunner_free (suite_runner);

    return n_failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
