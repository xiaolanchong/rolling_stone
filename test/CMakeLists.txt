cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(../googletest/googletest/include)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

set(rs_hdr_files
	../src/bitstring.h
	../src/board.h
	../src/conflicts.h
	../src/deadlock.h
	../src/deadsearch.h
	../src/debug.h
	../src/gtv.h
	../src/hashtable.h
	../src/histogram.h
	../src/ida.h
	../src/init.h
	../src/io.h
	../src/lowerbound.h
	../src/macro.h
	../src/mark.h
	../src/moves.h
	../src/mymem.h
	../src/pensearch.h
	../src/stats.h
	../src/time.h
	../src/tree.h
	../src/weights.h
)

set(rs_src_files
	../src/bitstring.c
	../src/conflicts.c
	../src/deadlock.c
	../src/deadsearch.c
	../src/debug.c
	../src/gtv.c
	../src/hashtable.c
	../src/histogram.c
	../src/ida.c
	../src/init.c
	../src/io.c
	../src/lowerbound.c
	../src/macro.c
	../src/mark.c
	../src/moves.c
	../src/mymem.c
	../src/pensearch.c
	../src/stats.c
	../src/time.c
	../src/tree.c
	../src/weights.c
)

add_executable(rolling_stone_test
	RollingStoneTest.h
	RollingStoneTest.cpp
	OriginalSokobanTest.cpp
	solution_test.cpp

	${rs_hdr_files}
	${rs_src_files}
)

# Little-endian numbers
add_compile_definitions(PC)

if(MSVC)
    # Force to compile with W4
	if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
		string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
	else()
		add_compile_options(/W4)
	endif()
    set_property(TARGET rolling_stone_test PROPERTY
		MSVC_RUNTIME_LIBRARY "MultiThreadedDebugDLL<$<CONFIG:Debug>:Debug>")
    set_property(TARGET rolling_stone_test PROPERTY
		MSVC_RUNTIME_LIBRARY "MultiThreadedDLL<$<CONFIG:Release>:Release>")
	target_link_options(rolling_stone_test PRIVATE /STACK:50000000)
	target_link_options(rolling_stone_test PRIVATE /DEBUG)
	add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
else()
	add_compile_options(rolling_stone_test -Wall -Wextra -Wpedantic -Werror)
endif()

target_link_libraries(rolling_stone_test
  GTest::gtest_main
)
