#pragma once
#ifndef _DE_MUTATION_STRATEGY_H_
#define _DE_MUTATION_STRATEGY_H_


#include <vector>
#include <random>


namespace de {

	class population;
	class agent;

	class mutation_strategy
	{
	public:
		mutation_strategy() = default;
		mutation_strategy(mutation_strategy const &) = default;
		mutation_strategy(mutation_strategy &&) = default;
		mutation_strategy& operator=(mutation_strategy const &) = default;
		mutation_strategy& operator=(mutation_strategy &&) = default;
		virtual ~mutation_strategy() = default;

		virtual void prepare(population const & actual_population, population & mutant_population);
		virtual void process(population const & actual_population, population & mutant_population) = 0;

	protected:
		using proxy_agent = std::vector<agent*>;
		proxy_agent _samples;

		void setup_samples(population const & source, size_t sample_count);
		void process_samples(size_t exclusion_index);
		void process_samples_without_best(size_t exclusion_index);

	private:
		proxy_agent _agent_proxy_sample;
		static std::default_random_engine _random_generator;
	};

}


#endif // _DE_MUTATION_STRATEGY_H_
