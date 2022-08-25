#pragma once
#ifndef _DE_FITNESS_STRATEGY_H_
#define _DE_FITNESS_STRATEGY_H_


namespace de {

	class population;

	class fitness_strategy
	{
	public:
		fitness_strategy() = default;
		fitness_strategy(fitness_strategy const &) = default;
		fitness_strategy(fitness_strategy &&) = default;
		fitness_strategy& operator=(fitness_strategy const &) = default;
		fitness_strategy& operator=(fitness_strategy &&) = default;
		virtual ~fitness_strategy() = default;

		virtual void prepare(population const & population) {}
		virtual double process(double value) = 0;
	};

}



#endif // _DE_FITNESS_STRATEGY_H_
