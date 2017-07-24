#pragma once

#include <string>
#include <vector>

namespace mutils
{
	//! Splits given string between each instance of the "delimiter" char
	//! If no delimiter is found, just return the same string inside a vector
	//! If the string is empty, return an empty vector
	std::vector<std::string> split(const std::string& s, char delimiter);
}