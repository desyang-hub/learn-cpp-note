export MALLOC_TRACE=build/mtrace.log
./build/mtrace_test

# mtrace build/mtrace.log

gcc -g -O0 -fsanitize=address -o mtrace_test mtrace_test.cpp