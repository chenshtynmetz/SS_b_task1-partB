/**
 * AUTHORS: <chen>
 * 
 * Date: 03/2022
 */

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

// tests with good cases.
TEST_CASE("Good input") {
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
													 "@-------@\n"
													 "@-@@@@@-@\n"
													 "@-@---@-@\n"
													 "@-@@@@@-@\n"
													 "@-------@\n"
													 "@@@@@@@@@"));
	
	CHECK(nospaces(mat(9, 7, '@', '@')) == nospaces("@@@@@@@@@\n" 
													 "@@@@@@@@@\n"
													 "@@@@@@@@@\n"
													 "@@@@@@@@@\n"
													 "@@@@@@@@@\n"
													 "@@@@@@@@@\n"
													 "@@@@@@@@@")); //only 1 symbole.

	CHECK(nospaces(mat(9, 1, '@', '#')) == nospaces("@@@@@@@@@\n"));
	CHECK(nospaces(mat(1, 7, '#', '@')) == nospaces("#\n"
													"#\n"
													"#\n"
													"#\n"
													"#\n"
													"#\n"
													"#\n"
													"#\n"));

	CHECK(nospaces(mat(3, 7, '#', '-')) == nospaces("###\n"
													"#-#\n"
													"#-#\n"
													"#-#\n"
													"#-#\n"
													"#-#\n"
													"###\n"));
	
	CHECK(nospaces(mat(1, 1, '#', '-')) == nospaces("#\n")); // only 1 char.
	CHECK(nospaces(mat(5, 5, '$', '-')) == nospaces("$$$$$\n"
												 	"$---$\n"
												 	"$-$-$\n"
													"$---$\n"
													"$$$$$\n"));
	CHECK(nospaces(mat(3, 3, '#', '-')) == nospaces("###\n"
													"#-#\n"
													"###"));

}

// tests with bad cases.
TEST_CASE("Bad input") {
    CHECK_THROWS(mat(10, 5, '$', '%')); //even number is wrong.
    CHECK_THROWS(mat(5, 10, '$', '%'));
	CHECK_THROWS(mat(8, 8, '$', '%'));
	CHECK_THROWS(mat(12, 5, '$', '%'));
	CHECK_THROWS(mat(10, 50, '$', '%'));
	CHECK_THROWS(mat(12, 5, '$', '%'));
	CHECK_THROWS(mat(10, 50, '$', '%'));
	CHECK_THROWS(mat(-11, 5, '$', '%')); //negative number is wrong.
	CHECK_THROWS(mat(0, 50, '$', '%')); // 0 is wrong.
	CHECK_THROWS(mat(-13, -5, '$', '%'));
	CHECK_THROWS(mat(1, -5, '$', '%'));
	CHECK_THROWS(mat(12, -5, '$', '%'));
}

