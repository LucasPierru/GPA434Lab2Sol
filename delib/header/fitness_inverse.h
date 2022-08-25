#pragma once
#ifndef _DE_FITNESS_INVERSE_H_
#define _DE_FITNESS_INVERSE_H_


#include "fitness_strategy.h"


namespace de {

	class fitness_inverse : public fitness_strategy
	{
	public:
		fitness_inverse() = default;
		fitness_inverse(double substitution);
		fitness_inverse(fitness_inverse const &) = default;
		fitness_inverse(fitness_inverse &&) = default;
		fitness_inverse& operator=(fitness_inverse const &) = default;
		fitness_inverse& operator=(fitness_inverse &&) = default;
		~fitness_inverse() override = default;

		double substitution() const;
		void set_substitution(double substitution);

		double process(double value) override;

	private:
		double _substitution{};
	};

}


#endif // _DE_FITNESS_INVERSE_H_
