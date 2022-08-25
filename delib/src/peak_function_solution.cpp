#include "peak_function_solution.h"


#include <cmath>
#include <sstream>
#include <iomanip>
#include "agent.h"
#include "optimization_minimization.h"
#include "optimization_maximization.h"
#include "fitness_identity.h"


namespace de {

	const std::string peak_function_solution::sTitle(30, '-');
	const size_t peak_function_solution::sPrecision{ 12 };

	std::string peak_function_solution::to_string(de::agent const & ag) const 
	{

		std::stringstream sStream;
		sStream << std::fixed << std::setprecision(sPrecision) 
				<< "Best objective : " << std::endl
				<< sTitle << std::endl
				<< ag.objective() << std::endl
				<< std::endl
				<< "Best fitness : " << std::endl
				<< sTitle << std::endl
				<< ag.fitness() << std::endl
				<< std::endl;

		return sStream.str();
	}

	double peak_function_solution::peak(double x, double y)
	{
		return	3.0 * pow(1.0 - x, 2.0) * exp(-(x * x + pow(y + 1, 2.0)))
				- 10.0 * (x / 5.0 - pow(x, 3.0) - pow(y, 5.0)) * exp(-(x * x + y * y))
				- 1.0 / 3.0 * exp(-(pow(x + 1, 2.0) + y * y));
	}


}
