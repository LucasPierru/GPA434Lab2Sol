#pragma once
#ifndef _DE_SELECTION_BEST_FITNESS_H_
#define _DE_SELECTION_BEST_FITNESS_H_


#include "selection_strategy.h"


namespace de {

	class selection_best_fitness : public selection_strategy
	{
	public:
		selection_best_fitness() = default;
		selection_best_fitness(selection_best_fitness const &) = default;
		selection_best_fitness(selection_best_fitness &&) = default;
		selection_best_fitness& operator=(selection_best_fitness const &) = default;
		selection_best_fitness& operator=(selection_best_fitness &&) = default;
		~selection_best_fitness() = default;

		void process(optimization_strategy const & opt_strategy, population & actual_population, population & trial_population) override;
	};

}

#endif // _DE_SELECTION_BEST_FITNESS_H_
