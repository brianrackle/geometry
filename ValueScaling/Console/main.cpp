// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include <limits>


//needs to handle different types for from and to
template <class _fT, class _tT>
_tT scaleRange(_fT value, _fT lowestFrom, _fT highestFrom, _tT lowestTo, _tT highestTo)
{
	//scale by half to account for negative and positive range being too large to represent
	const auto && fHLF = [](_fT v){ return v / 2; };
	const auto && tHLF = [](_fT v){ return v / 2; };

	_fT scaledOffsetResult =
		((tHLF(highestTo) - tHLF(lowestTo)) * ((fHLF(value) - fHLF(lowestFrom))
		/ (fHLF(highestFrom) - fHLF(lowestFrom))));
	return scaledOffsetResult + lowestTo + scaledOffsetResult; //seperated to prevent overflow
}

int main()
{
	double lowestFrom = std::numeric_limits<double>::lowest();
	double highestFrom = std::numeric_limits<double>::max();

	unsigned int lowestTo = std::numeric_limits<unsigned int>::lowest();
	unsigned int highestTo = std::numeric_limits<unsigned int>::max();

	double value = highestFrom;
	auto result = scaleRange(value, lowestFrom, highestFrom, lowestTo, highestTo);

	return 0;
}

