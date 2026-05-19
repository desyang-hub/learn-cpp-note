project(samrt_ptr C CXX)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(unique_ptr_test unique_ptr_test.cc)
add_executable(shared_ptr_test shared_ptr_test.cc)

add_executable(unique_ptr_deleter_ebo_test unique_ptr_deleter_ebo_test.cc)