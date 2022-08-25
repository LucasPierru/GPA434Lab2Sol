#pragma once
#ifndef _DE_SELECTION_STRATEGY_H_
#define _DE_SELECTION_STRATEGY_H_


namespace de {


	class population;
	class optimization_strategy;


	class selection_strategy
	{
	public:
		selection_strategy() = default;
		selection_strategy(selection_strategy const &) = default;
		selection_strategy(selection_strategy &&) = default;
		selection_strategy& operator=(selection_strategy const &) = default;
		selection_strategy& operator=(selection_strategy &&) = default;
		virtual ~selection_strategy() = default;

		virtual void prepare(population const & actual_population);
		virtual void process(optimization_strategy const & opt_strategy, population & actual_population, population & trial_population) = 0;
	};

}


#endif // _DE_SELECTION_STRATEGY_H_
