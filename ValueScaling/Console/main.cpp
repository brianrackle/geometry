// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include <string>
#include <regex>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <chrono>

template <class T>
T scaleRange(T lowestFrom, T highestFrom, T lowestTo, T highestTo, T value)
{
	//scale by half to account for negative and positive range being too large to represent
	const auto HLF = [](T v){ return v / 2; }; 

	double scaledOffsetResult = 
		((HLF(highestTo) - HLF(lowestTo)) * ((HLF(value) - HLF(lowestFrom)) 
		/ (HLF(highestFrom) - HLF(lowestFrom))));
	return scaledOffsetResult + lowestTo + scaledOffsetResult; //seperated to prevent overflow
}

int main()
{
	double lowestFrom = std::numeric_limits<double>::lowest();
	double highestFrom = std::numeric_limits<double>::max();

	double lowestTo = std::numeric_limits<double>::lowest();
	double highestTo = std::numeric_limits<double>::max();

	double value = 0;

	std::ofstream log("log.txt");
	size_t wrong = 0;

	std::chrono::high_resolution_clock timer;
	auto start = timer.now();
	for (size_t i = 0; i < 100000000; ++i)
	{
		auto result0 = scaleRange(lowestFrom, highestFrom, lowestTo, highestTo, value+i);
		if (result0 != value)
			++wrong;
	}
	auto elapsed = timer.now() - start;
	
	log << "Time: " << elapsed.count() << "\n";
	log << "Wrong: " << wrong;

	return 0;
}

