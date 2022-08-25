#pragma once
#ifndef _DE_FITNESS_OPPOSITE_H_
#define _DE_FITNESS_OPPOSITE_H_


#include "fitness_strategy.h"


namespace de {

	class fitness_opposite : public fitness_strategy
	{
	public:
		fitness_opposite() = default;
		fitness_opposite(fitness_opposite const &) = default;
		fitness_opposite(fitness_opposite &&) = default;
		fitness_opposite& operator=(fitness_opposite const &) = default;
		fitness_opposite& operator=(fitness_opposite &&) = default;
		~fitness_opposite() override = default;

		double process(double value) override;
	};

}


#endif // _DE_FITNESS_OPPOSITE_H_
