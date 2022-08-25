#pragma once
#ifndef _DE_AGENT_BOUNDS_H_
#define _DE_AGENT_BOUNDS_H_


#include "interval.h"
#include <vector>


namespace de {

	//! \brief Représente les limites du problème.
	//!
	//! \description agent_bounds correspond à l'ensemble des intervals définis pour chacune des dimensions du problème.
    //!
    //! L'évolution différentielle définie deux vecteurs \f$l\f$ et \f$u\f$ représentant le domaine de validité de chacune des dimensions du problème. La classe agent_bounds représente ces informations via un vecteur d'interval. 
	//! Le vecteur d'interval est de la même dimension que le problème à résoudre. Les valeurs \f$l_i\f$ et \f$u_i\f$ sont stockées au \f$i^e\f$ interval du vecteur.
	//!
	//! Il est important de noter que cette implémentation de la librairie utilise les vecteur \f$l\f$ et \f$u\f$ seulement lors de la définition du problème et à l'initialisation de la simulation. La validation des intervals n'est pas faite lors de l'évolution elle-même. Par conséquent, il est possible que la simulation donne des résultats à l'extérieure de ces intervals. 
	class agent_bounds
	{
	public:
		agent_bounds() = default;										//!< Constructeur par défaut.
		agent_bounds(size_t size);										//!< Constructeur avec taille d'initialisation.
		agent_bounds(size_t size, double lower, double upper);			//!< Constructeur avec taille et bornes d'initialisation.
		agent_bounds(agent_bounds const &) = default;					//!< Constructeur de copie.
		agent_bounds(agent_bounds &&) = default;						//!< Constructeur de déplacement.
		agent_bounds& operator=(agent_bounds const &) = default;		//!< Opérateur d'assignation de copie.
		agent_bounds& operator=(agent_bounds &&) = default;				//!< Opérateur d'assignation de déplacement.
		~agent_bounds() = default;										//!< Destructeur.

		size_t size() const;											//!< Retourne la taille du vecteur d'interval (la taille du problème à résoudre).
		interval const & operator[](size_t pos) const;					//!< Retourne le ie interval. Aucune validation des bornes n'est réalisée.
		interval & operator[](size_t pos);								//!< Retourne une référence au ie interval. Aucune validation des bornes n'est réalisée.
		interval at(size_t pos) const;									//!< Retourne le ie interval. La validation des bornes est réalisée. L'exception std::out_of_range est lancée si la position est à l'extérieur des bornes du vecteur.
		interval & at(size_t pos);										//!< Retourne une référence au ie interval. La validation des bornes est réalisée. L'exception std::out_of_range est lancée si la position est à l'extérieur des bornes du vecteur.

		void resize(size_t size);										//!< Redimensionne la taille du problème. Chacune des bornes étant réinitialisées selon la classe interval. 
		void resize(size_t size, double lower, double upper);			//!< Redimensionne la taille du problème. Chacune des bornes est fixées aux même valeurs déterminées par lower et higher.

		void set(double lower, double upper);							//!< Assigne, pour chacun des intervals, les mêmes valeurs lower et higher.
		void reset();													//!< Assigne, pour chacun des intervals, les valeurs par défaut telles que définies par la classe interval.

	private:
		std::vector<interval> _bounds;
	};

}


#endif // _DE_AGENT_BOUNDS_H_
