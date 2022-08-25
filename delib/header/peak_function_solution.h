#pragma once
#ifndef _DE_PEAK_FUNCTION_SOLUTION_H_
#define _DE_PEAK_FUNCTION_SOLUTION_H_


#include "solution_strategy.h"


namespace de {

	class peak_function_solution : public solution_strategy
	{
	public:
		peak_function_solution() = default;
		peak_function_solution(peak_function_solution const &) = default;
		peak_function_solution(peak_function_solution &&) = default;
		peak_function_solution& operator=(peak_function_solution const &) = default;
		peak_function_solution& operator=(peak_function_solution &&) = default;
		~peak_function_solution() override = default;

		std::string to_string(de::agent const & ag) const override;

		static double peak(double x, double y);

	protected:
		static const size_t sPrecision;
		static const std::string sTitle;
	};

} // namespace de

#endif // _DE_PEAK_FUNCTION_SOLUTION_H_