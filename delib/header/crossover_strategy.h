#pragma once
#ifndef _DE_CROSSOVER_STRATEGY_H_
#define _DE_CROSSOVER_STRATEGY_H_


#include <random>


namespace de {

	class population;

	class crossover_strategy
	{
	public:
		crossover_strategy(double Cr = 0.5);
		crossover_strategy(crossover_strategy const &) = default;
		crossover_strategy(crossover_strategy &&) = default;
		crossover_strategy& operator=(crossover_strategy const &) = default;
		crossover_strategy& operator=(crossover_strategy &&) = default;
		virtual ~crossover_strategy() = default;

		double Cr() const;
		void set_Cr(double Cr);

		virtual void prepare(population const & trial_population);
		virtual void process(population const & actual_population, population const & mutant_population, population & trial_population) = 0;

	protected:
		bool is_crossing_over() const;
		std::bernoulli_distribution _bernouilli_distribution;
		static std::default_random_engine _random_generator;
	};

}


#endif // _DE_CROSSOVER_STRATEGY_H_
