#pragma once


#include <QWidget>
#include <solution_strategy.h>
#include "QDEAdapter.h"


class QDESolutionPanel : public QWidget
{
	Q_OBJECT

public:
	QDESolutionPanel(QWidget * parent = nullptr);
	QDESolutionPanel(QDESolutionPanel const &) = default;
	QDESolutionPanel(QDESolutionPanel &&) = default;
	QDESolutionPanel& operator=(QDESolutionPanel const &) = default;
	QDESolutionPanel& operator=(QDESolutionPanel &&) = default;
	~QDESolutionPanel() override = default;

	virtual QString tabTitle() const = 0;
	virtual de::solution_strategy * buildSolution() const = 0;

signals:
	void parameterChanged();

public slots:
	virtual void updateVisualization(QDEAdapter const & de);

};
