#pragma once
#ifndef _DE_AGENT_H_
#define _DE_AGENT_H_


#include <vector>


namespace de {

	class agent_bounds;

	//! \brief Représente un agent de l'évolution différentielle.
	//!
	//! \description Dans le vocabualire de l'évolution différentielle, un agent est une solution candidate. C'est à dire, une hypothèse de la problématique à résoudre. C'est l'un des constituant fondamentaux de l'évolution différentielle voir ce document (à faire). 
	//! Un agent possède :
	//!  - un ensemble de _n_ valeurs (_n_ > 0) correspondant à la position de la solution candidate dans l'espace de solutions.
	//!  - son résultat objectif
	//!  - son résultat de "fitness"
	//!
	//! Un agent est toujours créé et réinitialisé par un agent_bounds. Ce dernier détermine la taille du problème (la dimension de l'espace de solutions) et le domaine des valeurs pour chacune des dimensions.
	//! Les valeurs d'un agent peuvent être manipulées par un agent_bounds via la fonction randomize et plus spécifiquement par la classe principale differential_evolution. 
	//!
	//! Lors d'une simulation, la classe differential_evolution s'assure que les agents sont toujours adéquatement définis et gère les tâches suivantes :
	//!  -# initialisation
	//!  -# génération aléatoire
	//!  -# mutation - croisement - sélection
	//!  -# calcul des fonctions objective et de "fitness"
	//!  -# calculs statistiques
	//! 
	//! Ainsi, il est facile de consulter un agent pour toutes ses valeurs via ses accesseurs :
	//!  - is_valid() const
	//!  - size() const
	//!  - operator[](size_t)
    //!  - at(size_t)
	//!  - objective() const
	//!  - fitness() const
	//!
	//! Dans la mise en opération d'une solution, on utilise cette classe en lecture pour connaître les valeurs des meilleurs agents... à clarifier...
	class agent
	{
		friend class differential_evolution;

	public:
		agent();										//!< Constructeur par défaut. L'agent possède une dimension de 0 (aucun élément) et les valeurs objectives et de "fitness" sont mises à leur valeurs initiales. 
		agent(agent_bounds const & bounds);				//!< Constructeur avec initialisation par un agent_bounds. L'agent est initialisé de la même façon que la fonction setup.
		agent(agent const &) = default;					//!< Constructeur de copie.
		agent(agent &&) = default;						//!< Constructeur de déplacement.
		agent& operator=(agent const &) = default;		//!< Opérateur d'assignation de copie.
		agent& operator=(agent &&) = default;			//!< Opérateur d'assignation de déplacement.
		~agent() = default;								//!< Destructeur.

		bool is_valid() const;							//!< Retourne si un agent est valide. Un agent est considéré valide s'il n'a pas une taille de 0.
		void reset();									//!< Réinitialise les valeurs d'un agent. Cette réinitialisation considère une indétermination du problème à résoudre. Ainsi, il devient tel que défini par le constructeur par défaut.

		void setup(agent_bounds const & bounds);		//!< Initialise ou réinitialise un agent selon la détermination d'un agent_bounds. Cette fonction ne fait qu'initialiser la taille du vecteur de valeurs. Les valeurs sont mises à zéro sans initialisations aléatoires.
		void randomize(agent_bounds const & bounds);	//!< Si la taille de l'agent correspond à la taille de bounds, initialise toutes les valeurs de l'agent à une valeur aléatoire définie par bounds.

		size_t size() const;							//!< Retourne la taille de l'agent (la dimensionnalité du problème).
		double operator[](size_t pos) const;			//!< Retourne la \f$i^e\f$ valeur de l'agent. Aucune validation des bornes n'est réalisée.
		double & operator[](size_t pos);				//!< Retourne une référence à la \f$i^e\f$ valeur de l'agent. Aucune validation des bornes n'est réalisée.
		double at(size_t pos) const;					//!< Retourne la \f$i^e\f$ valeur de l'agent. La validation des bornes est réalisée. L'exception std::out_of_range est lancée si la position est à l'extérieur des bornes du vecteur.
		double & at(size_t pos);						//!< Retourne une référence à la \f$i^e\f$ valeur de l'agent. La validation des bornes est réalisée. L'exception std::out_of_range est lancée si la position est à l'extérieur des bornes du vecteur.

		double objective() const;						//!< Retourne la valeur de la fonction objective. Cette valeur n'est valide que si la classe differential_evolution a été utilisée adéquatement.
		double fitness() const;							//!< Retourne la valeur de la fonction de "fitness". Cette valeur n'est valide que si la classe differential_evolution a été utilisée adéquatement.

	private:
		std::vector<double> _data;
		double _objective;
		double _fitness;

		static double const default_objective_value;
		static double const default_fitness_value;
	};

}


#endif // _DE_AGENT_H_
