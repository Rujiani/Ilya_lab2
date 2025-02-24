add_executable(test test.cpp ../Word.cpp ../ArrayOfWords.cpp)

find_package(GTest REQUIRED)

target_link_libraries(test PRIVATE GTest::GTest GTest::Main gcov)
target_compile_options(test PRIVATE --coverage -Wextra -Wall)