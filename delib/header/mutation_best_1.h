#pragma once
#ifndef _DE_MUTATION_BEST_1_H_
#define _DE_MUTATION_BEST_1_H_


#include "mutation_strategy.h"


namespace de {

	class mutation_best_1 : public mutation_strategy
	{
	public:
		mutation_best_1(double F = 1.0);
		mutation_best_1(mutation_best_1 const &) = default;
		mutation_best_1(mutation_best_1 &&) = default;
		mutation_best_1& operator=(mutation_best_1 const &) = default;
		mutation_best_1& operator=(mutation_best_1 &&) = default;
		~mutation_best_1() = default;

		virtual void prepare(population const & actual_population, population & mutant_population) override;
		void process(population const & actual_population, population & mutant_population) override;

		double F() const;
		void set_F(double F);

	private:
		double _F{};
	};

}


#endif // _DE_mutation_best_1_H_
