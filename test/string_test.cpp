#include <cppystruct.h>

#include <catch.hpp>

#define REQUIRE_STATIC(x) REQUIRE(x); \
						  static_assert(x, #x);


template <typename F, typename S, typename F2, typename S2>
constexpr bool operator==(const std::pair<F, S>& lhs, const std::pair<F2, S2>& rhs)
{
	return (lhs.first == rhs.first) && (lhs.second == rhs.second);
}


TEST_CASE("Consume String", "[cppystruct::string]")
{
	REQUIRE_STATIC(pystruct::internal::consumeNumber("123", 0) == std::make_pair(123, 3));
	REQUIRE_STATIC(pystruct::internal::consumeNumber("c", 0) == std::make_pair(0, 0));
	REQUIRE_STATIC(pystruct::internal::consumeNumber("c12345c", 1) == std::make_pair(12345, 6));
}