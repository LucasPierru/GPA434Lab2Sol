#pragma once
#ifndef _DE_INTERVAL_H_
#define _DE_INTERVAL_H_


#include <random>


namespace de {

    //! \brief Représente le concept mathématique d'un interval dans \f$\mathbb{R}\f$.
    //!
    //! \description Un interval est l'ensemble des nombres disponibles entre deux nombres déterminant les limites de cette plage. On nomme les limites, les bornes. Au sens mathématique, les bornes peuvent être incluses ou excluses de l'interval. 
    //!
    //! Cette implémentation considère les bornes toujours incluses. Ainsi, on peut dire que le nombre \f$x\f$ satisfait l'interval si \f$l \leq x \leq u\f$ où \f$l\f$ et \f$u\f$ sont les bornes inférieures et supérieures respectivement.
    //!
    //! L'interval est valide en tout temps. C'est à dire que les bornes ne peuvent être inversées. Si l'utilisateur tente d'inverser les bornes, une exception sera levée.
	class interval
	{
	public:
		interval();                                         //!< Constructeur par défaut. Les bornes sont au maximum de leur valeurs possibles.
		interval(double lower, double upper);               //!< Constructeur avec initialisation des bornes.
		interval(interval const &) = default;               //!< Constructeur de copie.
		interval(interval &&) = default;                    //!< Constructeur de déplacement.
        interval& operator=(interval const &) = default;    //!< Opérateur d'assignation de copie.
        interval& operator=(interval &&) = default;         //!< Opérateur d'assignation de déplacement.
        ~interval() = default;                              //!< Destructeur.

		double lower() const;                               //!< Retourne la borne inférieure.
		double upper() const;                               //!< Retourne la borne supérieure.
                                                            
		void set_lower(double lower);                       //!< Détermine la borne inférieure. Cette fonction lance une exception si la valeur est supérieure à la borne supérieure.
		void set_upper(double upper);                       //!< Détermine la borne supérieure. Cette fonction lance une exception si la valeur est inférieure à la borne inférieure.
		void set(double lower, double upper);               //!< Détermine les bornes inférieure et supérieure. Cette fonction lance une exception si les valeurs sont croisées.
		void reset();                                       //!< Réinitialise l'interval aux valeurs maximume. Comme le fait le constructeur par défaut.

		double generate() const;                            //!< Génère un nombre aléatoire entre les bornes selon une distribution uniforme.

	private:
		std::uniform_real_distribution<double> _rand_distribution;
		static std::default_random_engine _rand_engine;
	};

}


#endif // _DE_INTERVAL_H_
