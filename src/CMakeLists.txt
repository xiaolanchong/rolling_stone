cmake_minimum_required(VERSION 3.5)

set(hdr_files
	bitstring.h
	board.h
	conflicts.h
	deadlock.h
	deadsearch.h
	debug.h
	dl.h
	gtv.h
	hashtable.h
	histogram.h
	ida.h
	init.h
	io.h
	lowerbound.h
	macro.h
	mark.h
	menu.h
	moves.h
	mymem.h
	pensearch.h
	stats.h
	time.h
	tree.h
	weights.h
)

set(src_files
	bitstring.c
	conflicts.c
	deadlock.c
	deadsearch.c
	debug.c
	dl.c
	gtv.c
	hashtable.c
	histogram.c
	ida.c
	init.c
	io.c
	lowerbound.c
	macro.c
	mark.c
	menu.c
	moves.c
	mymem.c
	pensearch.c
	stats.c
	time.c
	tree.c
	weights.c
)
add_executable(rolling_stone ${hdr_files} ${src_files})

# Little-endian numbers
add_compile_definitions(PC)
# dump GTV tree
#add_compile_definitions(GTV)
# extra logging
#add_compile_definitions(DEBUG)

if (MSVC)
    # Force to compile with W4
	if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
		string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
	else()
		add_compile_options(/W4)
	endif()
	target_link_options(rolling_stone PRIVATE /STACK:50000000)
	target_link_options(rolling_stone PRIVATE /DEBUG)
	add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
else()
    # additional warnings
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()
