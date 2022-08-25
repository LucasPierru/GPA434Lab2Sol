#pragma once
#ifndef _DE_MIN_MAX_PEAK_FUNCTION_SOLUTION_H_
#define _DE_MIN_MAX_PEAK_FUNCTION_SOLUTION_H_


#include "peak_function_solution.h"


namespace de {

	class minmax_peak_function_solution : public peak_function_solution
	{
	public:
		minmax_peak_function_solution();
		minmax_peak_function_solution(minmax_peak_function_solution const &) = default;
		minmax_peak_function_solution(minmax_peak_function_solution &&) = default;
		minmax_peak_function_solution& operator=(minmax_peak_function_solution const &) = default;
		minmax_peak_function_solution& operator=(minmax_peak_function_solution &&) = default;
		~minmax_peak_function_solution() override = default;

		std::string to_string(de::agent const & ag) const override;

	protected:
		double process(de::agent const & ag) override;
	};

} // namespace de


#endif // _DE_MIN_MAX_PEAK_FUNCTION_SOLUTION_H_
