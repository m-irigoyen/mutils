#include <mutils/algorithm.hpp>

#include <algorithm>

namespace mutils
{
	bool almostEqual(const float & a, const float & b, const float & epsilon)
	{
		return (fabs(a - b) <= epsilon * std::max(fabs(a), fabs(b)));
	}
}