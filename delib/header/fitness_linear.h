#pragma once
#ifndef _DE_FITNESS_LINEAR_H_
#define _DE_FITNESS_LINEAR_H_


#include "fitness_strategy.h"


namespace de {

	class fitness_linear : public fitness_strategy
	{
	public:
		fitness_linear() = default;
		fitness_linear(double a, double b);
		fitness_linear(fitness_linear const &) = default;
		fitness_linear(fitness_linear &&) = default;
		fitness_linear& operator=(fitness_linear const &) = default;
		fitness_linear& operator=(fitness_linear &&) = default;
		~fitness_linear() override = default;

		double a() const;
		double b() const;
		void set(double a, double b);
		void reset();

		double process(double value) override;

	private:
		double _a{ 1.0 }, _b{ 0.0 };
	};

}


#endif // _DE_FITNESS_LINEAR_H_
