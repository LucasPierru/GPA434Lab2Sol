#pragma once
#ifndef _DE_DIFFERENTIAL_EVOLUTION_H_
#define _DE_DIFFERENTIAL_EVOLUTION_H_


#include <memory>
#include "engine_parameters.h"
#include "solution_strategy.h"
#include "population.h"
#include "history.h"


namespace de {
	
	class differential_evolution
	{
	public:
		differential_evolution() = default;
		~differential_evolution() = default;

		bool is_ready() const;
		size_t current_generation() const;
		population const & actual_population() const;
		engine_parameters const & engine_param() const;
		solution_strategy const & solution() const; // this function will throw if _solution is not defined

		bool setup(engine_parameters & engine_param, solution_strategy * sol);
		void reset();
		void clear();

		void process_to_next_generation();
		bool is_stopping_reached() const;
		void process();

		history const & statistics_history() const;
		std::string best_solution_info() const;

	private:
		size_t _current_generation{};
		engine_parameters _engine_parameters;
		std::unique_ptr<solution_strategy> _solution;
		population _actual;
		population _mutant;
		population _trial;
		history _history;

		void process_fitness(population & agents);
	};
}


#endif // _DE_DIFFERENTIAL_EVOLUTION_H_
