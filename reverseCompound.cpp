#include <cmath>
#include "functions.h"

using namespace std;

double compoundReverse(double value, double realInterest)
{
	value /= realInterest;  // find the interest compoundly
    return round(value * 100.0) / 100.0; 
}
