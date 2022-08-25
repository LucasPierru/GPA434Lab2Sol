#include "QDEAdapter.h"


QDEAdapter::QDEAdapter(QObject *parent)
	: QObject(parent)
{
}

bool QDEAdapter::isReady()
{
	return mDE.is_ready();
}

size_t QDEAdapter::currentGeneration() const
{
	return mDE.current_generation();
}

bool QDEAdapter::isStoppingReached() const
{
	return mDE.is_stopping_reached();
}

bool QDEAdapter::setup(de::engine_parameters & engineParameters, de::solution_strategy * sol)
{
	return mDE.setup(engineParameters, sol);
}

de::solution_strategy const & QDEAdapter::solution()
{
	return mDE.solution();
}

QString QDEAdapter::bestSolutionInfo() const
{
	return QString::fromStdString(mDE.best_solution_info());
}

de::history const & QDEAdapter::statisticsHistory() const
{
	return mDE.statistics_history();
}

de::population QDEAdapter::actualPopulation() const
{
	return mDE.actual_population();
}

void QDEAdapter::stepEvolution()
{
	if (!mDE.is_stopping_reached()) {
		mDE.process_to_next_generation();
		emit oneEvolutionStepped(*this);
	}

	if (mDE.is_stopping_reached()) {
		emit stoppingCriteriaReached();
	}
}

void QDEAdapter::startEvolution()
{
	while (!mDE.is_stopping_reached()) {
		stepEvolution();
	}
}

void QDEAdapter::reset()
{
	mDE.reset();
	emit reseted(*this);
}


