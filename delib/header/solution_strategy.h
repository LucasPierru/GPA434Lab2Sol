#pragma once
#ifndef _DE_solution_strategy_H_
#define _DE_solution_strategy_H_


#include <memory>
#include "agent_bounds.h"
#include "optimization_strategy.h"
#include "fitness_strategy.h"


namespace de {

	class population;
	class agent;

	class solution_strategy
	{
		friend class differential_evolution;

	public:
		solution_strategy();
		solution_strategy(solution_strategy const &) = default;
		solution_strategy(solution_strategy &&) = default;
		solution_strategy& operator=(solution_strategy const &) = default;
		solution_strategy& operator=(solution_strategy &&) = default;
		virtual ~solution_strategy() = default;

		bool is_ready() const;

		virtual std::string to_string(de::agent const & ag) const = 0;

	protected:
		agent_bounds _agent_bounds;

		virtual void prepare(population const & population);
		virtual double process(agent const & ag) = 0;

		void set_optimization_strategy(optimization_strategy * strategy);
		void set_fitness_strategy(fitness_strategy * strategy);

	private:
		std::unique_ptr<optimization_strategy> _optimization_strategy;
		std::unique_ptr<fitness_strategy> _fitness_strategy;
	};

} // namespace de


#endif // _DE_solution_strategy_H_
