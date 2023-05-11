set(PROJECT_TEST unit_tests)
add_executable(${PROJECT_TEST})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -lcriterion")

target_sources(unit_tests PRIVATE
		"${CMAKE_CURRENT_SOURCE_DIR}/test_parser.cpp"

		)

target_link_libraries(${PROJECT_TEST} ${CMAKE_DL_LIBS} config++)

enable_testing()
add_test(
		NAME test1
		COMMAND $<TARGET_FILE:unit_tests>
)
