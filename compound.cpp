#include <cmath>
#include "functions.h"

using namespace std;

double compound(double value, double realInterest)
{
	value *= realInterest;  // find the interest compoundly
    return value; 
}
