add_test( Test1/testCurrentRate.initalTest/2 /home/ukasz/CLionProjects/CurrencyRates/build/tests/myTest [==[--gtest_filter=Test1/testCurrentRate.initalTest/0]==] --gtest_also_run_disabled_tests)
set_tests_properties( Test1/testCurrentRate.initalTest/2 PROPERTIES WORKING_DIRECTORY /home/ukasz/CLionProjects/CurrencyRates/build/tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==] VS_DEBUGGER_WORKING_DIRECTORY)
set( myTest_TESTS Test1/testCurrentRate.initalTest/2)
