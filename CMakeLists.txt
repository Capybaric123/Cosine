cmake_minimum_required(VERSION 3.20)

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

project(opengl)

file(GLOB SRC CONFIGURE_DEPENDS
	src/*.c
)

add_executable(opengl ${SRC})

target_include_directories(opengl PRIVATE
	${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(opengl PRIVATE
	${CMAKE_SOURCE_DIR}/lib/libglfw.so
	GL
	X11
	pthread
	Xrandr
	Xi
	dl
)
