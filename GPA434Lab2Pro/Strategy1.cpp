#include "Strategy1.h"

Strategy1::Strategy1(double CM, double CP, double Vol, double PWD)
	: mCM{ CM }, mCP{ CP },mVol{Vol}, mPWD{PWD}
{
	_agent_bounds.resize(1);
	_agent_bounds.set(0.0, 10.0);

	set_optimization_strategy(new de::optimization_maximization);
	set_fitness_strategy(new de::Fitness_Inverse);
}


Strategy1::~Strategy1()
{

}


double Strategy1::process(de::agent const & ag)
{
	double prix;
	mWidth = ag[0];
	mHeight = mVol/(mPWD*pow(ag[0],2));
	mDepth = mPWD * ag[0];

	double volume = mWidth * mHeight * mDepth;

	if ((volume <= mVol+1) && (volume >= mVol-1) && ag[0] > 0 ) {
		prix = 2 * mCM * mWidth * mHeight + 2 * mCM * mDepth * mHeight + mCP * mWidth * mDepth;
		return prix; 
	}
		
	return 0.0;
}

void Strategy1::prepare(de::population const & population)
{
}

std::string Strategy1::to_string(de::agent const & ag) const
{
	std::stringstream sStream;
	sStream << "Prix optimal   : " << std::setprecision(6) << std::fixed << ag.objective() << std::endl
		<< "Largeur de la piece : " << std::setprecision(6) << std::fixed << ag[0] << std::endl
		<< "Hauteur de la piece : " << std::setprecision(6) << std::fixed << mVol / (mPWD*pow(ag[0], 2)) << std::endl
		<< "Profondeur de la piece : " << std::setprecision(6) << std::fixed << mPWD * ag[0]<< std::endl
		<< "Volume de la boite : " << std::setprecision(6) << std::fixed << mVol;

	return sStream.str();
}
