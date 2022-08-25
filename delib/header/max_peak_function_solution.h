#pragma once
#ifndef _DE_MAX_PEAK_FUNCTION_SOLUTION_H_
#define _DE_MAX_PEAK_FUNCTION_SOLUTION_H_


#include "peak_function_solution.h"


namespace de {

	class max_peak_function_solution : public peak_function_solution
	{
	public:
		max_peak_function_solution();
		max_peak_function_solution(max_peak_function_solution const &) = default;
		max_peak_function_solution(max_peak_function_solution &&) = default;
		max_peak_function_solution& operator=(max_peak_function_solution const &) = default;
		max_peak_function_solution& operator=(max_peak_function_solution &&) = default;
		~max_peak_function_solution() override = default;

		std::string to_string(de::agent const & ag) const override;

	protected:
		double process(de::agent const & ag) override;
	};

} // namespace de


#endif // _DE_MAX_PEAK_FUNCTION_SOLUTION_H_
