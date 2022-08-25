#pragma once
#ifndef _DE_CROSSOVER_BINOMIAL_H_
#define _DE_CROSSOVER_BINOMIAL_H_


#include "crossover_strategy.h"


namespace de {

	class population;

	class crossover_binomial : public crossover_strategy
	{
	public:
		crossover_binomial(double Cr = 0.5);
		crossover_binomial(crossover_binomial const &) = default;
		crossover_binomial(crossover_binomial &&) = default;
		crossover_binomial& operator=(crossover_binomial const &) = default;
		crossover_binomial& operator=(crossover_binomial &&) = default;
		virtual ~crossover_binomial() = default;

		void prepare(population const & trial_population) override;
		void process(population const & actual_population, population const & mutant_population, population & trial_population)  override;

	private:
		std::uniform_int_distribution<size_t> _agent_position_distribution;
	};

}


#endif // _DE_CROSSOVER_BINOMIAL_H_
