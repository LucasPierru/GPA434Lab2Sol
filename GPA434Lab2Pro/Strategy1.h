#ifndef STRATEGY1_H
#define STRATEGY1_H

// Fichier : Strategy1.h
// GPA434 – Laboratoire 2
// Création :
// - 2019/11/20
// - - - - - - - - - - - - - - - - - - - - - - -
// Classe Strategy1.
// Calcul de la Strategy1

#include <sstream>
#include <iostream>
#include <iomanip>
#include "agent_bounds.h"
#include "optimization_maximization.h"
#include "engine_parameters.h"
#include "differential_evolution.h"
#include "Fitness_Inverse.h"

//La classe strategy1 effectue le calcul de notre fonction objective
//et affiche dans l'interface graphique les resultats de la simulation.
//La classe possède les attributs mWidth, mHeight, mDepth, mCM, mCP, mVol, mPWD.
//La fonction prepare effectue le calcul de la fonction objective.

class Strategy1 : public de::solution_strategy	
{
private:
	double mWidth; //largeur de la pièce
	double mHeight; //hauteur de la pièce
	double mDepth; //profondeur de la pièce
	double mCM; //coût des matériaux pour les murs
	double mCP; //coût des matériaux pour le plancher 
	double mVol; //Volume de la pièce
	double mPWD; //proportion entre la profondeur et la largeur

protected:
	double process(de::agent const & ag) override; //fonction qui calcule notre fonction objective

public:
	void prepare(de::population const & population) override;
	std::string to_string(de::agent const & ag) const override;
	Strategy1(double CM, double CP, double Vol, double PWD);
	~Strategy1();

};

#endif // !STRATEGY1_H