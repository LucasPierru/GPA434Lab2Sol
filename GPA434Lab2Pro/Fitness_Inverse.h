#pragma once
#ifndef _DE_FINTESS_INVERSE_H_
#define _DE_FINTESS_INVERSE_H_

#include "fitness_strategy.h"

namespace de {

	class Fitness_Inverse : public fitness_strategy
	{
	public:
		Fitness_Inverse() = default;
		Fitness_Inverse(Fitness_Inverse const &) = default;
		Fitness_Inverse(Fitness_Inverse &&) = default;
		Fitness_Inverse& operator=(Fitness_Inverse const &) = default;
		Fitness_Inverse& operator=(Fitness_Inverse &&) = default;
		~Fitness_Inverse() override = default;

		double process(double value) override;
	};

}

#endif // _DE_FINTESS_INVERSE_H_