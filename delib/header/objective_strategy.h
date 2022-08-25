#pragma once
#ifndef _DE_OBJECTIVE_STRATEGY_H_
#define _DE_OBJECTIVE_STRATEGY_H_


namespace de {

	class population;
	class agent;

	class objective_strategy
	{
	public:
		objective_strategy() = default;
		objective_strategy(objective_strategy const &) = default;
		objective_strategy(objective_strategy &&) = default;
		objective_strategy& operator=(objective_strategy const &) = default;
		objective_strategy& operator=(objective_strategy &&) = default;
		virtual ~objective_strategy() = default;

		virtual void prepare(population const & population) {}
		virtual double process(agent const & ag) = 0;
	};

}


#endif // _DE_OBJECTIVE_STRATEGY_H_
