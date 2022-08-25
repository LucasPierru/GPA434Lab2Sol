#pragma once


#include <QObject>
#include <differential_evolution.h>
#include <engine_parameters.h>


class QDEAdapter : public QObject
{
	Q_OBJECT

public:
	QDEAdapter(QObject * parent = nullptr);
	QDEAdapter(QDEAdapter const &) = default;
	QDEAdapter(QDEAdapter &&) = default;
	QDEAdapter& operator=(QDEAdapter const &) = default;
	QDEAdapter& operator=(QDEAdapter &&) = default;
	~QDEAdapter() override = default;

	bool isReady();
	size_t currentGeneration() const;
	bool isStoppingReached() const;

	bool setup(de::engine_parameters & engineParameters, de::solution_strategy * sol);
	de::solution_strategy const & solution(); // this function will throw if solution is not defined

	QString bestSolutionInfo() const;
	de::history const & statisticsHistory() const;

	de::population actualPopulation() const;

public slots:
	void stepEvolution();
	void startEvolution();
	void reset();

signals:
	void oneEvolutionStepped(QDEAdapter const & de);
	void reseted(QDEAdapter const & de);
	void stoppingCriteriaReached();

private:
	de::differential_evolution mDE;

};
