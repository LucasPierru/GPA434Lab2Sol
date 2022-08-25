#pragma once
#ifndef _DE_CROSSOVER_EXPONENTIAL_H_
#define _DE_CROSSOVER_EXPONENTIAL_H_


#include "crossover_strategy.h"


namespace de {

	class population;

	class crossover_exponential : public crossover_strategy
	{
	public:
		crossover_exponential(double Cr = 0.5);
		crossover_exponential(crossover_exponential const &) = default;
		crossover_exponential(crossover_exponential &&) = default;
		crossover_exponential& operator=(crossover_exponential const &) = default;
		crossover_exponential& operator=(crossover_exponential &&) = default;
		virtual ~crossover_exponential() = default;

		void prepare(population const & trial_population) override;
		void process(population const & actual_population, population const & mutant_population, population & trial_population)  override;

	private:
		std::uniform_int_distribution<size_t> _agent_first_distribution;
		std::geometric_distribution<size_t>_agent_count_distribution;
	};

}


#endif // _DE_CROSSOVER_EXPONENTIAL_H_
