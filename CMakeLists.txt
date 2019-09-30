cmake_minimum_required(VERSION 3.14)
file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "libft/srcs/*.c")
file(GLOB_RECURSE HEADERS RELATIVE ${CMAKE_SOURCE_DIR} "libft/includes/*.h")
file(GLOB_RECURSE SOURCES2 RELATIVE ${CMAKE_SOURCE_DIR} "srcs/*.c")
file(GLOB_RECURSE HEADERS2 RELATIVE ${CMAKE_SOURCE_DIR} "includes/*.h")
project(fractal C)

set(CMAKE_C_STANDARD 11)

include_directories(includes)
include_directories(libft)
include_directories(libft/includes)
include_directories(libft/sources)
include_directories(srcs)

add_executable(fractal
        ${SOURCES}
        ${HEADERS}
        ${HEADERS2}
        ${SOURCES2}
        srcs/main.c srcs/camera.c srcs/mandebort.c)
target_link_libraries(fractal mlx)
target_link_libraries(fractal "-framework OpenGl")
target_link_libraries(fractal "-framework Appkit")
