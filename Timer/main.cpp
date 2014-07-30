#include <chrono>

namespace timing
{
	using namespace std::chrono;

	template<class F>
	system_clock::duration time_it(F && f)
	{
		auto begin = high_resolution_clock::now();
		f();
		auto end = high_resolution_clock::now();
		return end - begin;
	}

	template<class T>
	void time_as(T t, std::chrono)
	{
		//converts duration
	}

	template<class T>
	void write_it(T && t)
	{
		//writes out duration to t
	}
}

int main()
{

}