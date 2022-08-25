#pragma once
#ifndef _DE_STOPPING_CRITERIA_STRATEGY_H_
#define _DE_STOPPING_CRITERIA_STRATEGY_H_


#include <string>


namespace de {


	class differential_evolution;


	class stopping_criteria_strategy
	{
	public:
		stopping_criteria_strategy() = default;
		stopping_criteria_strategy(stopping_criteria_strategy const &) = default;
		stopping_criteria_strategy(stopping_criteria_strategy &&) = default;
		stopping_criteria_strategy& operator=(stopping_criteria_strategy const &) = default;
		stopping_criteria_strategy& operator=(stopping_criteria_strategy &&) = default;
		virtual ~stopping_criteria_strategy() = default;

		virtual std::string name() const = 0;
		virtual bool is_stopping(differential_evolution const & de) const = 0;
	};

}



#endif // _DE_STOPPING_CRITERIA_STRATEGY_H_
