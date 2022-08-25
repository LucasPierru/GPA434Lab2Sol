#pragma once
#ifndef _DE_OPTIMIZATION_MAXIMIZATION_H_
#define _DE_OPTIMIZATION_MAXIMIZATION_H_


#include "optimization_strategy.h"


namespace de {

	class optimization_maximization : public optimization_strategy
	{
	public:
		optimization_maximization() = default;
		optimization_maximization(optimization_maximization const &) = default;
		optimization_maximization(optimization_maximization &&) = default;
		optimization_maximization& operator=(optimization_maximization const &) = default;
		optimization_maximization& operator=(optimization_maximization &&) = default;
		~optimization_maximization() override = default;

		bool compare(double v1, double v2) const override;
	};

}


#endif //_DE_OPTIMIZATION_MAXIMIZATION_H_