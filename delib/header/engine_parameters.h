#pragma once
#ifndef _DE_ENGINE_PARAMETERS_H_
#define _DE_ENGINE_PARAMETERS_H_


#include <memory>
#include <list>
#include "mutation_strategy.h"
#include "crossover_strategy.h"
#include "selection_strategy.h"
#include "stopping_criteria_strategy.h"

#include "stopping_criteria_max_generation.h"


namespace de {


    //! \brief Classe déterminant les paramètres de l'algorithme de l'évolution différentielle.
    //!
    //! \description Quoique incomplète, `delib` permet une large paramétrisation des constituants de l'algorithme de l'évolution différentielle. 
    //! 
    //| engine_parameters détermine exclusivement les paramètres de l'engin de résolution differential_evolution. C'est la classe objective_strategy qui spécifie le problème à résoudre.
    //!
    //! Les paramètres actuellement supportés sont : 
    //!     - la taille de la population
    //!     - le nombre maximum de génération permise
    //!     - la stratégie de mutation (via la classe mutation_strategy)
    //!     - la stratégie de croisement (via la classe crossover_strategy)
    //!     - la stratégie de sélection (via la classe selection_strategy)
    //!     - les critères d'arrêt (via la class stopping_criteria_strategy)
    //!
    //! differential_evolution utilise tous ces paramêtres pour contrôler le déroulement de l'évolution. 
    //! 
    //! Le tableau suivant présente un résumé de ces paramètres
    //!     | Paramètre                     | Description                                                       | Valeur par défaut         | Commentaires  |
    //!     | :---------------------------: | :---------------------------------------------------------------- | :-----------------------: | :-----------  |
    //!     | Taille de la population       | Nombre de solutions candidates.                                   | 25                        | La taille de la population est limitée par les constantes minimum_population_size (5) et maximum_population_size (1000). |
    //!     | Nombre de génération maximum  | Le nombre d'itération maximum autorisé l'arrêt de l'évolution.    | 150                       | Le nombre maximum de génération est limitée par les constantes minimum_generation_count (10) et maximum_generation_count (100000). |
    //!     | Stratégie de mutation         | Algorithme utilisé pour l'étape de mutation.                      | mutation_rand_1           | ... |
    //!     | Stratégie de croisement       | Algorithme utilisé pour l'étape de croisement.                    | crossover_binomial        | ... |
    //!     | Stratégie de sélection        | Algorithme utilisé pour l'étape de sélection.                     | selection_best_fitness    | ... |
    //!     | Critères d'arrêt              | Algorithmes utilisés pour évaluer si l'algorithme termine les évolutions. | aucun supplémentaire \n voir détail plus bas | ... |
    //!  
    //! On remarque que plusieurs critères d'arrêt peuvent être utilisés simultanément. Ainsi, il est possible de préciser plusieurs conditions où l'algorithme termine l'évolution. Il existe cependant un critère d'arrêt implicite à l'algorithme et c'est le nombre de génération maximum. Formellement, le nombre de génération maximum est un critère d'arrêt et est géré comme tel par l'algorithme. Toutefois, il est obligatoire de définir sa valeur et il est impossible de retirer ce critère. Il est donc possible de n'avoir aucun autre critère d'arrêt supplémentaire et c'est l'implémentation par défaut.
    //! 
	class engine_parameters
	{
		friend class differential_evolution;

	public:
		engine_parameters();                                                //!< Constructeur par défaut. Tous les paramètres sont à leur valeur par défaut.
        engine_parameters(engine_parameters const &) = delete;              //!< Constructeur de copie interdit.
        engine_parameters(engine_parameters &&) = default;                  //!< Constructeur de déplacement.
        engine_parameters& operator=(engine_parameters const &) = delete;   //!< Opérateur d'assignation de copie interdit.
        engine_parameters& operator=(engine_parameters &&) = default;       //!< Opérateur d'assignation de déplacement.
        ~engine_parameters() = default;                                     //!< Destructeur.

		static size_t minimum_population_size();                            //!< Retourne la taille de population minimum permise.
		static size_t maximum_population_size();                            //!< Retourne la taille de population maximum permise.
		static size_t default_population_size();                            //!< Retourne la taille de population par défaut.
        static size_t minimum_generation_count();                           //!< Retourne le nombre de génération minimum permis.
        static size_t maximum_generation_count();                           //!< Retourne le nombre de génération maximum permis.
        static size_t default_generation_count();                           //!< Retourne le nombre de génération par défaut.

		size_t population_size() const;                                     //!< Retourne la taille de la population définie.
		size_t maximum_generation() const;                                  //!< Retourne le nombre de génération maximum défini.
		size_t stopping_criteria_size() const;                              //!< Retourne le nombre de critère d'arrêt effectif. Cet actuateur exclue du compte le critère d'arrêt lié au nombre de générations maximum. Il retourne ceux qui ont été ajouté.

		void set_population_size(size_t size);                              //!< Mutateur permettant de définir la taille de la population. Si la taille indiquée est à l'extérieur des valeurs minimum et maximum permises, la valeur est mise à la limite la plus près.
		void set_max_generation(size_t count);                              //!< Mutateur permettant de définir le nombre de génération maximum. Si la taille indiquée est à l'extérieur des valeurs minimum et maximum permises, la valeur est mise à la limite la plus près.

		void set_mutation_strategy(mutation_strategy * strategy);           //!< Mutateur définissant la stratégie de mutation. L'objet passé en paramètre doit être alloué dynamiquement et un transfert de propriété est donne à cette classe. Ainsi, le propriétaire de cet objet devient la classe engine_parameter et il est déconseillé d'y accéder sans passer par celle-ci.
		void set_crossover_strategy(crossover_strategy * strategy);         //!< Mutateur définissant la stratégie de croisement. L'objet passé en paramètre doit être alloué dynamiquement et un transfert de propriété est donne à cette classe. Ainsi, le propriétaire de cet objet devient la classe engine_parameter et il est déconseillé d'y accéder sans passer par celle-ci.
		void set_selection_strategy(selection_strategy * strategy);         //!< Mutateur définissant la stratégie de sélection.  L'objet passé en paramètre doit être alloué dynamiquement et un transfert de propriété est donne à cette classe. Ainsi, le propriétaire de cet objet devient la classe engine_parameter et il est déconseillé d'y accéder sans passer par celle-ci.

		bool add_stopping_critera_strategy(stopping_criteria_strategy * strategy);  //!< Fonction utilitaire permettant d'ajouter un critère d'arrêt. L'objet passé en paramètre doit être alloué dynamiquement et un transfert de propriété est donne à cette classe. Ainsi, le propriétaire de cet objet devient la classe engine_parameter et il est déconseillé d'y accéder sans passer par celle-ci.
		void clear_stopping_critera_strategy();                             //!< Vide tous les critères d'arrêts. À la fin de cette fonction, il n'existe que le critère d'arrêt déterminer par le nombre de génération maximum.

		bool is_ready() const;                                              //!< Retourne vrai si tous les paramètres sont définis conformément à l'usage de differential_evolution.
		void reset();                                                       //!< Remet en place tous les paramètres par défaut.

		bool is_stopping_criteria_met(differential_evolution const & de) const; //!< Détermine si tous les critères d'arrêt sont satisfaits (incluant le critère d'arrêt lié au nombre de génération maximum). 
	
	private:
		size_t _population_size;
		std::unique_ptr<mutation_strategy>  _mutation_strategy;
		std::unique_ptr<crossover_strategy> _crossover_strategy;
		std::unique_ptr<selection_strategy> _selection_strategy;
		std::list<std::unique_ptr<stopping_criteria_strategy>> _stopping_criteria_strategies;
		stopping_criteria_max_generation _stopping_criteria_max_generation;

		static const size_t _minimum_population_size;
		static const size_t _maximum_population_size;
		static const size_t _default_population_size;
		static const size_t _minimum_generation_count;
		static const size_t _maximum_generation_count;
		static const size_t _default_generation_count;
	};

}

#endif // _DE_ENGINE_PARAMETERS_H_
