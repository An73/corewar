cmake_minimum_required(VERSION 3.9)
project(corewar C)

set(CMAKE_C_STANDARD 99)

add_executable(corewar main.c libft.h corewar.h valid_champ.c get_next_line.c get_next_line.h battlefield.c pushback.c enc_byte.c convert.c cycle_die.c cycle.c
        operation_1.c process.c)
target_link_libraries(corewar /Users/dkotenko/EX/corewar/v1/libft.a)