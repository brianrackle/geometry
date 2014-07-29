// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include <string>
#include <regex>
#include <algorithm>
#include <numeric>

double scaleRangeExpanded(double lowestFrom, double highestFrom, double lowestTo, double highestTo, double value)
{
	double toRange = highestTo / 2 - lowestTo / 2;

	double scaledLowestFrom = lowestFrom / 2;
	double scaledHighestFrom = highestFrom / 2;
	double scaledValue = value / 2;

	double fromRange = scaledHighestFrom - scaledLowestFrom;
	double valueScale = (scaledValue - scaledLowestFrom) / fromRange;
	double scaledOffsetResult = (toRange * valueScale);
	return scaledOffsetResult + lowestTo + scaledOffsetResult; //because toRange * valueScale * 2 overflows double max
}

double scaleRangeSimplified(double lowestFrom, double highestFrom, double lowestTo, double highestTo, double value)
{
	double toRange = highestTo / 2 - lowestTo / 2;

	lowestFrom /= toRange;
	highestFrom /= toRange;
	value /= toRange;
	double scaledOffsetResult = (toRange * (value - lowestFrom) / (highestFrom - lowestFrom));
	return scaledOffsetResult + lowestTo + scaledOffsetResult;
}

int main()
{
	double lowestFrom = std::numeric_limits<double>::lowest();
	double highestFrom = std::numeric_limits<double>::max();

	double lowestTo = 0;
	double highestTo = 100;

	double value = 1000;

	auto result0 = scaleRangeExpanded(lowestFrom, highestFrom, lowestTo, highestTo, value);
	auto result1 = scaleRangeSimplified(lowestFrom, highestFrom, lowestTo, highestTo, value);

	return 0;
}

