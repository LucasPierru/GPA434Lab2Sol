#include "Strategy2.h"


Strategy2::Strategy2(double Height, double Width, double NbPoints)
	: mHeight{ Height }, mWidth{ Width }, mNbPoints{ NbPoints }
{
	_agent_bounds.resize(2);
	_agent_bounds[0].set(0.0, mWidth);
	_agent_bounds[1].set(0.0, mHeight);


	set_optimization_strategy(new de::optimization_maximization);
	set_fitness_strategy(new de::fitness_identity);

	mPopulation.setup(mNbPoints, _agent_bounds);
	mPopulation.randomize(_agent_bounds);
}

Strategy2::~Strategy2()
{
}

double Strategy2::process(de::agent const & ag)
{
	double min = mHeight + mWidth;
	de::population population = getpopulation();
	int j{};
	double mdistance;

	for (size_t i{}; i < population.size(); ++i)
	{
		mdistance = distance(ag, getagent(i));


		//La distance est optimale
		if (min > mdistance)
		{
			min = mdistance;
			j = i;
		}
	}

	//Ajuster le rayon d'un cercle qui sors du Canvas
	if (!isInCanvas(ag, min)) {
		min = GetDistanceMur(ag);
	}

	return min;
}

void Strategy2::prepare(de::population const & population)
{
}

std::string Strategy2::to_string(de::agent const & ag) const
{
	std::stringstream sStream;
	sStream << "Plus grand rayon d'un cercle : " << std::setprecision(6) << std::fixed << ag.objective() << std::endl
		<< "Largeur du rectangle : " << std::setprecision(6) << std::fixed << mWidth << std::endl
		<< "Hauteur du rectangle : " << std::setprecision(6) << std::fixed << mHeight << std::endl
		<< "Nombre de points : " << std::setprecision(6) << std::fixed << mNbPoints << std::endl
		<< "Centre du cercle :  x = " << std::setprecision(6) <<std::fixed << ag[0]<<" y = " <<std::setprecision(6) <<std::fixed <<ag[1];

	return sStream.str();
}

de::population Strategy2::getpopulation()
{
	return mPopulation;
}

de::agent Strategy2::getagent(int i)
{
	return mPopulation[i];
}

double Strategy2::distance(de::agent ag1, de::agent ag2)
{
	return sqrt(pow(ag1[0] - ag2[0], 2) + pow(ag1[1] - ag2[1], 2));
}

double Strategy2::GetDistanceMur(de::agent ag)
{
	double distanceMur = mWidth + mHeight;
	//Verification de la distance en X
	if (ag[0] < (mWidth / 2)) {
		distanceMur = ag[0];
	}
	else {
		distanceMur = (mWidth - ag[0]);
	}
	//Verification de la distance en Y
	if (distanceMur > ag[1]) {
		distanceMur = ag[1];
	}
	if (distanceMur > (mHeight - ag[1])) {
		distanceMur = (mHeight - ag[1]);
	}

	return distanceMur;
}

bool Strategy2::isInCanvas(de::agent ag, double distance)
{
	if ((ag[0] - distance) >= 0 && (distance + ag[0]) <= mWidth && (ag[1] - distance) >= 0 && (ag[1] + distance) <= mHeight)
	{
		return true;
	}
	else
	{
		return false;
	}
}

