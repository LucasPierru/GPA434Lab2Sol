#ifndef STRATEGY2_H
#define STRATEGY2_H

// Fichier : Strategy2.h
// GPA434 – Laboratoire 2
// Création :
// - 2019/11/20
// - - - - - - - - - - - - - - - - - - - - - - -
// Classe Strategy2.
// Calcul de la Strategy2

#include <iostream>
#include <iomanip>
#include <sstream>
#include "agent_bounds.h"
#include "fitness_strategy.h"
#include "solution_strategy.h"
#include "fitness_identity.h"
#include "optimization_maximization.h"
#include "engine_parameters.h"
#include <differential_evolution.h>

//La classe strategy2 effectue le calcul de notre fonction objective
//et permet d'afficher dans l'interface graphique les resultats de la simulation.
//La classe possède les attributs mWidth, mHeight, mNbPoints, mDistance, mPopulation.
//La fonction prepare effectue le calcul de la fonction objective.
//La focntion distance permet de calculer la distance entre 2 points.
//La fonction GetDistanceMur permet de calculer la distance entre un point et le mur.
//La fonction isInCanvas determiner si le cercle est dans le rectangle ou non.

class Strategy2 : public de::solution_strategy

{
private:
	double mWidth;
	double mHeight;
	double mNbPoints;
	double mDistance;
	de::population mPopulation;

protected:
	double process(de::agent const & ag) override;

public:
	void prepare(de::population const & population) override;
	std::string to_string(de::agent const & ag) const override;
	de::population getpopulation();
	de::agent getagent(int i);
	double distance(de::agent ag1, de::agent ag2);
	double GetDistanceMur(de::agent ag);
	bool isInCanvas(de::agent ag, double distance);
	Strategy2(double Height, double Width, double NbPoints);
	~Strategy2();
};

#endif // !STRATEGY2_H