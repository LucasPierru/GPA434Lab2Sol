#pragma once
#ifndef _DE_OPTIMIZATION_STRATEGY_H_
#define _DE_OPTIMIZATION_STRATEGY_H_


namespace de {

	class optimization_strategy
	{
	public:
		optimization_strategy() = default;
		optimization_strategy(optimization_strategy const &) = default;
		optimization_strategy(optimization_strategy &&) = default;
		optimization_strategy& operator=(optimization_strategy const &) = default;
		optimization_strategy& operator=(optimization_strategy &&) = default;
		virtual ~optimization_strategy() = default;

		virtual bool compare(double v1, double v2) const = 0;

	};

}


#endif // _DE_OPTIMIZATION_STRATEGY_H_