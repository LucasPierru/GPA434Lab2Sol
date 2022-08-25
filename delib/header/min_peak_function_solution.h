#pragma once
#ifndef _DE_MIN_PEAK_FUNCTION_SOLUTION_H_
#define _DE_MIN_PEAK_FUNCTION_SOLUTION_H_


#include "peak_function_solution.h"


namespace de {

	class min_peak_function_solution : public peak_function_solution
	{
	public:
		min_peak_function_solution();
		min_peak_function_solution(min_peak_function_solution const &) = default;
		min_peak_function_solution(min_peak_function_solution &&) = default;
		min_peak_function_solution& operator=(min_peak_function_solution const &) = default;
		min_peak_function_solution& operator=(min_peak_function_solution &&) = default;
		~min_peak_function_solution() override = default;

		std::string to_string(de::agent const & ag) const override;

	protected:
		double process(de::agent const & ag) override;
	};

} // namespace de


#endif // _DE_MIN_PEAK_FUNCTION_SOLUTION_H_
