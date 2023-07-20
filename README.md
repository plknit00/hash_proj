# README

In terminal, run the following the first time:

1. mkdir build
2. cd build
3. cmake ..

To run code in general:

1. make
2. ./main

To quit

1. control c

Debug:

1. cmake .. -DCMAKE_BUILD_TYPE=Debug
2. make
3. lldb ./main
4. r
5. bt (to look at backtrace)
6. f 4 (to look at frame 4 for example)
7. p <variable> to print variable's value
8. q to quit
9. y for yes
