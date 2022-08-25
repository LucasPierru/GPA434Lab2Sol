#include "Fitness_Inverse.h"


double de::Fitness_Inverse::process(double value)
{
	if (value == 0) {
		return 0;
	}
	else {
		return 1 / value;
	}
}
