#pragma once
#ifndef _DE_STOPPING_CRITERIA_GENERATION_H_
#define _DE_STOPPING_CRITERIA_GENERATION_H_


#include "stopping_criteria_strategy.h"


namespace de {

	class stopping_criteria_max_generation : public stopping_criteria_strategy
	{
	public:
		stopping_criteria_max_generation() = default;
		stopping_criteria_max_generation(size_t max_generation);
		stopping_criteria_max_generation(stopping_criteria_max_generation const &) = default;
		stopping_criteria_max_generation(stopping_criteria_max_generation &&) = default;
		stopping_criteria_max_generation& operator=(stopping_criteria_max_generation const &) = default;
		stopping_criteria_max_generation& operator=(stopping_criteria_max_generation &&) = default;
		~stopping_criteria_max_generation() = default;

		size_t max_generation() const;
		void set_max_generation(size_t max_generation);

		std::string name() const override;
		bool is_stopping(differential_evolution const & de) const override;

	private:
		size_t _max_generation{ 250 };
	};

}


#endif // _DE_STOPPING_CRITERIA_GENERATION_H_
