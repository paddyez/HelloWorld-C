find_program(CLANG_TIDY NAMES clang-tidy)
if (CLANG_TIDY)
	add_custom_target(
			clang-tidy
			COMMAND ${CLANG_TIDY}
			--checks='*'
			--fix
			--fix-errors
			--header-filter='.*'
			${SOURCE_FILES}
			--
			-std=c18
			-I ${CMAKE_SOURCE_DIR}/include
	)
endif ()
