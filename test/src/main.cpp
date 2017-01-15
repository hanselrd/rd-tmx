#include "test_lib.hpp"
#include "tmxutil.hpp"
#include <cassert>

int main(int argc, char** argv) {
	rd::tmx::test::run();
	std::string str = "   whitespace   ";
	assert(str == "   whitespace   ");
	rd::tmxutil::trim(str);
	assert(str == "whitespace");
	return 0;
}