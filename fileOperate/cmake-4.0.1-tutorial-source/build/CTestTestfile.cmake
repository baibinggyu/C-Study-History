# CMake generated Testfile for 
# Source directory: /home/bai-yu/c++learn/fileOperate/cmake-4.0.1-tutorial-source/Complete
# Build directory: /home/bai-yu/c++learn/fileOperate/cmake-4.0.1-tutorial-source/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(Runs "/home/bai-yu/c++learn/fileOperate/cmake-4.0.1-tutorial-source/build/Tutoriald" "25")
set_tests_properties(Runs PROPERTIES  _BACKTRACE_TRIPLES "/home/bai-yu/c++learn/fileOperate/cmake-4.0.1-tutorial-source/Complete/CMakeLists.txt;62;add_test;/home/bai-yu/c++learn/fileOperate/cmake-4.0.1-tutorial-source/Complete/CMakeLists.txt;0;")
add_test(Usage "/home/bai-yu/c++learn/fileOperate/cmake-4.0.1-tutorial-source/build/Tutoriald")
set_tests_properties(Usage PROPERTIES  PASS_REGULAR_EXPRESSION "Usage:.*number" _BACKTRACE_TRIPLES "/home/bai-yu/c++learn/fileOperate/cmake-4.0.1-tutorial-source/Complete/CMakeLists.txt;65;add_test;/home/bai-yu/c++learn/fileOperate/cmake-4.0.1-tutorial-source/Complete/CMakeLists.txt;0;")
add_test(Comp4 "/home/bai-yu/c++learn/fileOperate/cmake-4.0.1-tutorial-source/build/Tutoriald" "4")
set_tests_properties(Comp4 PROPERTIES  PASS_REGULAR_EXPRESSION "4 is 2" _BACKTRACE_TRIPLES "/home/bai-yu/c++learn/fileOperate/cmake-4.0.1-tutorial-source/Complete/CMakeLists.txt;72;add_test;/home/bai-yu/c++learn/fileOperate/cmake-4.0.1-tutorial-source/Complete/CMakeLists.txt;79;do_test;/home/bai-yu/c++learn/fileOperate/cmake-4.0.1-tutorial-source/Complete/CMakeLists.txt;0;")
add_test(Comp9 "/home/bai-yu/c++learn/fileOperate/cmake-4.0.1-tutorial-source/build/Tutoriald" "9")
set_tests_properties(Comp9 PROPERTIES  PASS_REGULAR_EXPRESSION "9 is 3" _BACKTRACE_TRIPLES "/home/bai-yu/c++learn/fileOperate/cmake-4.0.1-tutorial-source/Complete/CMakeLists.txt;72;add_test;/home/bai-yu/c++learn/fileOperate/cmake-4.0.1-tutorial-source/Complete/CMakeLists.txt;80;do_test;/home/bai-yu/c++learn/fileOperate/cmake-4.0.1-tutorial-source/Complete/CMakeLists.txt;0;")
add_test(Comp5 "/home/bai-yu/c++learn/fileOperate/cmake-4.0.1-tutorial-source/build/Tutoriald" "5")
set_tests_properties(Comp5 PROPERTIES  PASS_REGULAR_EXPRESSION "5 is 2.236" _BACKTRACE_TRIPLES "/home/bai-yu/c++learn/fileOperate/cmake-4.0.1-tutorial-source/Complete/CMakeLists.txt;72;add_test;/home/bai-yu/c++learn/fileOperate/cmake-4.0.1-tutorial-source/Complete/CMakeLists.txt;81;do_test;/home/bai-yu/c++learn/fileOperate/cmake-4.0.1-tutorial-source/Complete/CMakeLists.txt;0;")
add_test(Comp7 "/home/bai-yu/c++learn/fileOperate/cmake-4.0.1-tutorial-source/build/Tutoriald" "7")
set_tests_properties(Comp7 PROPERTIES  PASS_REGULAR_EXPRESSION "7 is 2.645" _BACKTRACE_TRIPLES "/home/bai-yu/c++learn/fileOperate/cmake-4.0.1-tutorial-source/Complete/CMakeLists.txt;72;add_test;/home/bai-yu/c++learn/fileOperate/cmake-4.0.1-tutorial-source/Complete/CMakeLists.txt;82;do_test;/home/bai-yu/c++learn/fileOperate/cmake-4.0.1-tutorial-source/Complete/CMakeLists.txt;0;")
add_test(Comp25 "/home/bai-yu/c++learn/fileOperate/cmake-4.0.1-tutorial-source/build/Tutoriald" "25")
set_tests_properties(Comp25 PROPERTIES  PASS_REGULAR_EXPRESSION "25 is 5" _BACKTRACE_TRIPLES "/home/bai-yu/c++learn/fileOperate/cmake-4.0.1-tutorial-source/Complete/CMakeLists.txt;72;add_test;/home/bai-yu/c++learn/fileOperate/cmake-4.0.1-tutorial-source/Complete/CMakeLists.txt;83;do_test;/home/bai-yu/c++learn/fileOperate/cmake-4.0.1-tutorial-source/Complete/CMakeLists.txt;0;")
add_test(Comp-25 "/home/bai-yu/c++learn/fileOperate/cmake-4.0.1-tutorial-source/build/Tutoriald" "-25")
set_tests_properties(Comp-25 PROPERTIES  PASS_REGULAR_EXPRESSION "-25 is (-nan|nan|0)" _BACKTRACE_TRIPLES "/home/bai-yu/c++learn/fileOperate/cmake-4.0.1-tutorial-source/Complete/CMakeLists.txt;72;add_test;/home/bai-yu/c++learn/fileOperate/cmake-4.0.1-tutorial-source/Complete/CMakeLists.txt;84;do_test;/home/bai-yu/c++learn/fileOperate/cmake-4.0.1-tutorial-source/Complete/CMakeLists.txt;0;")
add_test(Comp0.0001 "/home/bai-yu/c++learn/fileOperate/cmake-4.0.1-tutorial-source/build/Tutoriald" "0.0001")
set_tests_properties(Comp0.0001 PROPERTIES  PASS_REGULAR_EXPRESSION "0.0001 is 0.01" _BACKTRACE_TRIPLES "/home/bai-yu/c++learn/fileOperate/cmake-4.0.1-tutorial-source/Complete/CMakeLists.txt;72;add_test;/home/bai-yu/c++learn/fileOperate/cmake-4.0.1-tutorial-source/Complete/CMakeLists.txt;85;do_test;/home/bai-yu/c++learn/fileOperate/cmake-4.0.1-tutorial-source/Complete/CMakeLists.txt;0;")
subdirs("MathFunctions")
