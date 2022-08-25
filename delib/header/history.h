#pragma once
#ifndef _DE_HISTORY_H_
#define _DE_HISTORY_H_


#include <vector>
#include "statistics.h"


namespace de {

    //! \brief Représente l'historique des statistiques tout au long de l'évolution.
    //!
    //! \description Cette classe permet de maintenir un résumé des données obtenue lors de l'évolution. En fait, une copie des statistiques de la population est ajoutée dans l'historique. Ainsi, il est possible d'avoir une vue d'ensemble du comportement de l'algorithme. 
	class history
	{
		friend class differential_evolution;

	public:
		history() = default;                                //!< Constructeur par défaut. L'historique est vide.
        history(history const &) = default;                 //!< Constructeur de copie.
        history(history &&) = default;                      //!< Constructeur de déplacement.
        history& operator=(history const &) = default;      //!< Opérateur d'assignation de copie.
        history& operator=(history &&) = default;           //!< Opérateur d'assignation de déplacement.
        ~history() = default;                               //!< Destructeur.

		size_t size() const;                                //!< Retourne la taille de l'historique.
        statistics const & operator[](size_t pos) const;    //!< Retourne l'historique à la position indiquée. Aucune validation des bornes n'est réalisée. 
		statistics const & last() const;                    //!< Fonction utilitaire retournant le dernier historique.

		void get_range(double & x_min, double & x_max, double & y_min, double & y_max) const; //!< Fonction permettant de retournée les limites des données incluses dans l'historique. \f$x\f$ représentant le temps alors que \f$y\f$ les valeurs de fitness observées. Cette fonction peut être pratique lors de la peprésentation des limites de l'historique pour un affichage graphique par exemple.

	private:
		std::vector<statistics> _statistics;
		statistics _stat_on_minimum;
		statistics _stat_on_maximum;

		void clear();
		void add(statistics const & stat);
	};

}

#endif // _DE_HISTORY_H_
