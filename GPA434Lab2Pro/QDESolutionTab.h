#pragma once


#include <QTabWidget>
#include <solution_strategy.h>

class QDESolutionPanel;


#include "QDEAdapter.h"


class QDESolutionTab : public QTabWidget
{
	Q_OBJECT

public:
	QDESolutionTab(QWidget * parent = nullptr);
	QDESolutionTab(QDESolutionTab const &) = default;
	QDESolutionTab(QDESolutionTab &&) = default;
	QDESolutionTab& operator=(QDESolutionTab const &) = default;
	QDESolutionTab& operator=(QDESolutionTab &&) = default;
	~QDESolutionTab() = default;

	de::solution_strategy * newSolution() const; // need at least one panel - otherwise it will crash.

	void addSolutionPanel(QDESolutionPanel * dESolutionPanel);

signals:
	void parameterChanged();

public slots:
	void updateVisualization(QDEAdapter const & de);

private:
	using QTabWidget::addTab;
};
