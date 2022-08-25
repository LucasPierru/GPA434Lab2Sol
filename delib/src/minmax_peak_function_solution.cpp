#include "minmax_peak_function_solution.h"


#include <sstream>
#include <iomanip>
#include "agent.h"
#include "optimization_maximization.h"
#include "fitness_identity.h"


namespace de {

	minmax_peak_function_solution::minmax_peak_function_solution()
	{
		_agent_bounds.resize(4);
		_agent_bounds.set(-3.0, 3.0);
		set_optimization_strategy(new de::optimization_maximization);
		set_fitness_strategy(new de::fitness_identity);
	}
	
	std::string de::minmax_peak_function_solution::to_string(de::agent const & ag) const
	{
		std::stringstream sStream;

		sStream << std::setprecision(sPrecision)
				<< peak_function_solution::to_string(ag)
				<< "Maximum coordinate value : " << std::endl
				<< sTitle << std::endl
				<< "    - x : " << ag[0] << std::endl
				<< "    - y : " << ag[1] << std::endl
				<< "    - z : " << peak(ag[0], ag[1]) << std::endl
				<< std::endl
				<< "Minimum coordinate value : " << std::endl
				<< sTitle << std::endl
				<< "    - x : " << ag[2] << std::endl
				<< "    - y : " << ag[3] << std::endl
				<< "    - z : " << peak(ag[2], ag[3]) << std::endl
				<< std::endl;

		return sStream.str();
	}

	double de::minmax_peak_function_solution::process(de::agent const & ag)
	{
		return peak(ag[0], ag[1]) - peak(ag[2], ag[3]);
	}

}
