# CMake generated Testfile for 
# Source directory: /home/yijie/AI3613-Project-2022-Spring/tests/query
# Build directory: /home/yijie/AI3613-Project-2022-Spring/build/tests/query
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(seq_scan_executor_test "/home/yijie/AI3613-Project-2022-Spring/build/tests/query/seq_scan_executor_test")
set_tests_properties(seq_scan_executor_test PROPERTIES  _BACKTRACE_TRIPLES "/home/yijie/AI3613-Project-2022-Spring/tests/query/CMakeLists.txt;2;add_test;/home/yijie/AI3613-Project-2022-Spring/tests/query/CMakeLists.txt;0;")
add_test(insert_executor_test "/home/yijie/AI3613-Project-2022-Spring/build/tests/query/insert_executor_test")
set_tests_properties(insert_executor_test PROPERTIES  _BACKTRACE_TRIPLES "/home/yijie/AI3613-Project-2022-Spring/tests/query/CMakeLists.txt;5;add_test;/home/yijie/AI3613-Project-2022-Spring/tests/query/CMakeLists.txt;0;")
add_test(update_executor_test "/home/yijie/AI3613-Project-2022-Spring/build/tests/query/update_executor_test")
set_tests_properties(update_executor_test PROPERTIES  _BACKTRACE_TRIPLES "/home/yijie/AI3613-Project-2022-Spring/tests/query/CMakeLists.txt;8;add_test;/home/yijie/AI3613-Project-2022-Spring/tests/query/CMakeLists.txt;0;")
add_test(filter_executor_test "/home/yijie/AI3613-Project-2022-Spring/build/tests/query/filter_executor_test")
set_tests_properties(filter_executor_test PROPERTIES  _BACKTRACE_TRIPLES "/home/yijie/AI3613-Project-2022-Spring/tests/query/CMakeLists.txt;11;add_test;/home/yijie/AI3613-Project-2022-Spring/tests/query/CMakeLists.txt;0;")
add_test(projection_executor_test "/home/yijie/AI3613-Project-2022-Spring/build/tests/query/projection_executor_test")
set_tests_properties(projection_executor_test PROPERTIES  _BACKTRACE_TRIPLES "/home/yijie/AI3613-Project-2022-Spring/tests/query/CMakeLists.txt;14;add_test;/home/yijie/AI3613-Project-2022-Spring/tests/query/CMakeLists.txt;0;")
add_test(nested_loop_join_executor_test_without_predicate "/home/yijie/AI3613-Project-2022-Spring/build/tests/query/nested_loop_join_executor_test")
set_tests_properties(nested_loop_join_executor_test_without_predicate PROPERTIES  _BACKTRACE_TRIPLES "/home/yijie/AI3613-Project-2022-Spring/tests/query/CMakeLists.txt;17;add_test;/home/yijie/AI3613-Project-2022-Spring/tests/query/CMakeLists.txt;0;")
add_test(nested_loop_join_executor_test_with_predicate "/home/yijie/AI3613-Project-2022-Spring/build/tests/query/nested_loop_join_executor_test" "1")
set_tests_properties(nested_loop_join_executor_test_with_predicate PROPERTIES  _BACKTRACE_TRIPLES "/home/yijie/AI3613-Project-2022-Spring/tests/query/CMakeLists.txt;18;add_test;/home/yijie/AI3613-Project-2022-Spring/tests/query/CMakeLists.txt;0;")
add_test(hash_join_executor_test "/home/yijie/AI3613-Project-2022-Spring/build/tests/query/hash_join_executor_test")
set_tests_properties(hash_join_executor_test PROPERTIES  _BACKTRACE_TRIPLES "/home/yijie/AI3613-Project-2022-Spring/tests/query/CMakeLists.txt;21;add_test;/home/yijie/AI3613-Project-2022-Spring/tests/query/CMakeLists.txt;0;")
add_test(group_by_executor_test "/home/yijie/AI3613-Project-2022-Spring/build/tests/query/group_by_executor_test")
set_tests_properties(group_by_executor_test PROPERTIES  _BACKTRACE_TRIPLES "/home/yijie/AI3613-Project-2022-Spring/tests/query/CMakeLists.txt;24;add_test;/home/yijie/AI3613-Project-2022-Spring/tests/query/CMakeLists.txt;0;")
add_test(aggregate_executor_test "/home/yijie/AI3613-Project-2022-Spring/build/tests/query/aggregate_executor_test")
set_tests_properties(aggregate_executor_test PROPERTIES  _BACKTRACE_TRIPLES "/home/yijie/AI3613-Project-2022-Spring/tests/query/CMakeLists.txt;27;add_test;/home/yijie/AI3613-Project-2022-Spring/tests/query/CMakeLists.txt;0;")
