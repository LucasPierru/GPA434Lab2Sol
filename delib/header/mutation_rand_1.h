#pragma once
#ifndef _DE_MUTATION_RAND_1_H_
#define _DE_MUTATION_RAND_1_H_


#include "mutation_strategy.h"


namespace de {

	class mutation_rand_1 : public mutation_strategy
	{
	public:
		mutation_rand_1(double F = 1.0);
		mutation_rand_1(mutation_rand_1 const &) = default;
		mutation_rand_1(mutation_rand_1 &&) = default;
		mutation_rand_1& operator=(mutation_rand_1 const &) = default;
		mutation_rand_1& operator=(mutation_rand_1 &&) = default;
		~mutation_rand_1() = default;

		virtual void prepare(population const & actual_population, population & mutant_population) override;
		void process(population const & actual_population, population & mutant_population) override;

		double F() const;
		void set_F(double F);

	private:
		double _F{};
	};

}


#endif // _DE_MUTATION_RAND_1_H_
