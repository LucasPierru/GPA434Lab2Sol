#pragma once
#ifndef _DE_POPUPLATION_H_
#define _DE_POPUPLATION_H_


#include "agent.h"
#include "statistics.h"


namespace de {


	class optimization_strategy;

    //! \brief Représente une population de l'évolution différentielle.
    //!
    //! \description Une population est un ensemble de _n_ agents (_n_ solutions candidates). 
    //!
    //! En fait, la classe population est une classe utilitaire encapsulant les opérations à la gestions de _n_ agents. Ainsi, `population` est le conteneur des `agent` et donne accès à plusieurs fonctions utilitaires.
    //!
    //! Les agents d'une population sont manipulés différemment selon le rôle de la population. En fait, l'implémentation courante utilise trois populations simultanées pour les calculs internes : 
    //!  - la population courante
    //!  - les mutants
    //!  - les tests
    //!
    //! La classe population offre aussi accès aux statistiques de la population via la classe statistics disponible par la fonction population::stat.
	class population
	{
		friend class differential_evolution;
		friend class mutation_strategy;

	public:
        population() = default;                                     //!< Constructeur par défaut. La population est vide et aucun agent n'existe.
        population(size_t size, agent_bounds const & bounds);       //!< Constructeur avec initialisation. Appelle la fonction population::setup.
        population(population const &) = default;                   //!< Constructeur de copie.
        population(population &&) = default;                        //!< Constructeur de déplacement.
        population& operator=(population const &) = default;        //!< Opérateur d'assignation de copie.
        population& operator=(population &&) = default;             //!< Opérateur d'assignation de déplacement.
        ~population() = default;                                    //!< Destructeur.

		size_t size() const;                                        //!< Retourne la taille de la population (le nombre d'agents).
        agent const & operator[](size_t pos) const;                 //!< Retourne le \f$i^e\f$ agent. Aucune validation des bornes n'est réalisée. 
        agent & operator[](size_t pos);                             //!< Retourne une référence au \f$i^e\f$ agent. Aucune validation des bornes n'est réalisée. 
        agent const & at(size_t pos) const;                         //!< Retourne le \f$i^e\f$ agent. La validation des bornes est réalisée. L'exception std::out_of_range est lancée si la position est à l'extérieur des bornes du vecteur. 
        agent & at(size_t pos);                                     //!< Retourne une référence au \f$i^e\f$ agent. La validation des bornes est réalisée. L'exception std::out_of_range est lancée si la position est à l'extérieur des bornes du vecteur. 
		statistics const & stat() const;                            //!< Retoure un accès aux statistiques de la population. 

		void setup(size_t size, agent_bounds const & bounds);       //!< Effectue l'initialisation de la population. Si la population possède au préalable des agents, ils sont remplacés. La population possède _size_ agents initialisés par _bounds_. L'initialisation détermine la taille des agents sans initialiser leurs valeurs (comme le fait la fonction agent::setup).
		void randomize(agent_bounds const & bounds);                //!< Détermine une valeur aléatoire pour tous les agents. 

	private:
		std::vector<agent> _agents;
		statistics _statistics;

		void sort(optimization_strategy & strategy);
		void process_statistics(); // le sort doit être fait avant...
	};

}


#endif // _DE_POPUPLATION_H_
