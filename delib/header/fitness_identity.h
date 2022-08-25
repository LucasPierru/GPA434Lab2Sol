#pragma once
#ifndef _DE_FITNESS_IDENTITY_H_
#define _DE_FITNESS_IDENTITY_H_


#include "fitness_strategy.h"


namespace de {

	class fitness_identity : public fitness_strategy
	{
	public:
		fitness_identity() = default;
		fitness_identity(fitness_identity const &) = default;
		fitness_identity(fitness_identity &&) = default;
		fitness_identity& operator=(fitness_identity const &) = default;
		fitness_identity& operator=(fitness_identity &&) = default;
		~fitness_identity() override = default;

		double process(double value) override;
	};

}


#endif // _DE_FITNESS_IDENTITY_H_
