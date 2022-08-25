#include "QLab2.h"



QLab2::QLab2()
{
	mDESolutionTab->addSolutionPanel(ps); //On ajoute ici les "panel" des divers solutions
	mDESolutionTab->addSolutionPanel(ob);
	mDESolutionTab->addSolutionPanel(s1);
	mDESolutionTab->addSolutionPanel(s2);

	mpointeurDE = &mDE;

	connect(mDEEngineParameters, &QDEEngineParameters::parameterChanged,
		this, &QLab2::changeSimulationParameters);

	connect(mDEEngineParameters, &QDEEngineParameters::parameterChanged,
		qc, &QDEController::resetSimulation);

	connect(mDESolutionTab, &QDESolutionTab::parameterChanged,
		this, &QLab2::changeSimulationParameters);

	connect(mDESolutionTab, &QDESolutionTab::parameterChanged,
		qc, &QDEController::resetSimulation);

	connect(qc, &QDEController::evolutionRequired,
		mpointeurDE, &QDEAdapter::stepEvolution);

	connect(qc, &QDEController::resetRequired,
		mpointeurDE, &QDEAdapter::reset);

	connect(mpointeurDE, &QDEAdapter::stoppingCriteriaReached,
		qc, &QDEController::endSimulation);

	connect(mpointeurDE, &QDEAdapter::oneEvolutionStepped,
		hc1, &QDEHistoryChart::update);

	connect(mpointeurDE, &QDEAdapter::oneEvolutionStepped,
		br1, &QDEBestResult::update);

	connect(mpointeurDE, &QDEAdapter::oneEvolutionStepped,
		mDESolutionTab, &QDESolutionTab::updateVisualization);

	connect(mpointeurDE, &QDEAdapter::reseted,
		mDESolutionTab, &QDESolutionTab::updateVisualization);

	connect(mpointeurDE, &QDEAdapter::reseted,
		hc1, &QDEHistoryChart::reset);

	connect(mpointeurDE, &QDEAdapter::reseted,
		br1, &QDEBestResult::reset);

	changeSimulationParameters(); 
	qc->resetSimulation();
}


QLab2::~QLab2()
{
}

QDEEngineParameters * QLab2::getEngineParameter()
{
	return mDEEngineParameters;
}

QDESolutionTab * QLab2::getSolutionTab()
{
	return mDESolutionTab;
}

QDEHistoryChart * QLab2::getHistoryChart()
{
	return hc1;
}

QDEBestResult * QLab2::getBestResult()
{
	return br1;
}

QDEController * QLab2::getController()
{
	return qc;
}

QDEPeakSolution * QLab2::getPeakSolution()
{
	return ps;
}

QDEOpenBoxSolution * QLab2::getOpenBoxSolution()
{
	return ob;
}

QDEAdapter * QLab2::getAdapter()
{
	return mpointeurDE;
}

void QLab2::changeSimulationParameters()
{
	// mDE, mDEEngineParameters et mDESolutionTab indiquent les objets
	// des classe QDEAdapter, QDEEngineParameters et QDESolutionTab
	mDE.setup(mDEEngineParameters->parameters(),
		mDESolutionTab->newSolution());
}
