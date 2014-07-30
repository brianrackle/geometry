#include <chrono>

namespace timing
{
	template<class D, class F>
	D time_it(F && f)
	{
		using hrc = std::chrono::high_resolution_clock;

		auto begin = hrc::now();
		f();
		auto end = hrc::now();
		return std::chrono::duration_cast<D>(end - begin);
	}
}

int main()
{
	auto result = timing::time_it<std::chrono::seconds>
		([]{ for (size_t i = 0; i < 100000 * 1000; ++i) std::pow(i, 2); });
}