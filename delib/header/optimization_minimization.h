#pragma once
#ifndef _DE_OPTIMIZATION_MINIMIZATION_H_
#define _DE_OPTIMIZATION_MINIMIZATION_H_


#include "optimization_strategy.h"


namespace de {

	class optimization_minimization : public optimization_strategy
	{
	public:
		optimization_minimization() = default;
		optimization_minimization(optimization_minimization const &) = default;
		optimization_minimization(optimization_minimization &&) = default;
		optimization_minimization& operator=(optimization_minimization const &) = default;
		optimization_minimization& operator=(optimization_minimization &&) = default;
		~optimization_minimization() override = default;

		bool compare(double v1, double v2) const override;
	};

}


#endif //_DE_OPTIMIZATION_MINIMIZATION_H_