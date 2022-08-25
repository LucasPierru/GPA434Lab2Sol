#pragma once
#ifndef _DE_STATISTICS_H_
#define _DE_STATISTICS_H_


#include "agent.h"


namespace de {


    //! \brief Représente des données statistiques simples.
    //!
    //! \description Cette classe permet de construire et de maintenir des statistiques de base sur une population ou sur l'évolution. 
    //!
    //! On retrouve d'abord ces données représentant une synthèse des résultats observés par la fonction de fitness :
    //!     - le nombre de valeurs observées    
    //!     - la valeur minimum observée        
    //!     - la valeur maximum observée        
    //!     - la somme des valeurs observées    
    //!     - la moyenne des valeurs observées  
    //!     - l'écart type des valeurs observées
    //! 
    //! Ensuite, on retroue une copie des trois agents suivants :
    //!     - le meilleur agent
    //!     - l'agent médian
    //!     - le pire agent
	class statistics
	{
		friend class population;
		friend class history;

	public:
		statistics() = default;                                 //!< Constructeur par défaut. Les statistiques sont initialisées comme le fait la fonction reset.
		statistics(statistics const &) = default;               //!< Constructeur de copie.
        statistics(statistics &&) = default;                    //!< Constructeur de déplacement.
        statistics& operator=(statistics const &) = default;    //!< Opérateur d'assignation de copie.
        statistics& operator=(statistics &&) = default;         //!< Opérateur d'assignation de déplacement.
        ~statistics() = default;                                //!< Destructeur.

		size_t count() const;                                   //!< Retourne le nombre de données utilisées pour construire les statistiques disponibles.
		double minimum() const;                                 //!< Retourne la valeur de fitnesse la plus basse.
		double maximum() const;                                 //!< Retourne la valeur de fitnesse la plus élevée.
		double sum() const;                                     //!< Retourne la somme des fitness.
		double average() const;                                 //!< Retourne la moyenne des fitness.
		double stdev() const;                                   //!< Retourne l'écart type des fitness.

		agent const & best_agent() const;                       //!< Retourne une copie du meilleur agent.
		agent const & median_agent() const;                     //!< Retourne une copie de l'agent médian.
		agent const & worst_agent() const;                      //!< Retourne une copie du pire agent.
                                                                 
		void reset();                                           //!< Réinitialise les statistiques. 

	private:
		// approche naïve (peu stable numériquement)... à améliorer.
		size_t _count;				
		double _minimum{};
		double _maximum{};
		double _sum{};
		double _sum2{};
		double _average{};
		double _variance{};
		double _stdev{};

		agent _best_agent;
		agent _median_agent;
		agent _worst_agent;

		void build(double value);	// ajoute une valeur sans faire les calculs de moyenne et d'écart type.
		void add(double value);		// ajoute une valeur et réalise les calculs de moyenne et d'écart type.
		void process();				// réalise les calculs de moyenne et d'écart type.
	};

}

#endif // _DE_STATISTICS_H_
