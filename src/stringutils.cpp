#include <mutils/stringutils.hpp>

#include <algorithm>
#include <sstream>
#include <iterator>


template<typename Out>
void split_verbose(const std::string &s, char delim, Out result) {
    std::stringstream ss (s);
    std::string item;
    while (std::getline(ss, item, delim)) {
    	if (!item.empty())
    	{
    		*(result++) = item;	
    	}
    }
}

std::vector<std::string> mutils::split(const std::string& s, char delim)
{
	std::vector<std::string> elems;
    split_verbose(s, delim, std::back_inserter(elems));
    return elems;
}