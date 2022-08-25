#include "QDESolutionTab.h"
#include "QDESolutionPanel.h"


QDESolutionTab::QDESolutionTab(QWidget *parent)
	: QTabWidget(parent)
{
	connect(this, &QTabWidget::currentChanged, this, &QDESolutionTab::parameterChanged);
}

de::solution_strategy * QDESolutionTab::newSolution() const
{
	return static_cast<QDESolutionPanel*>(currentWidget())->buildSolution();
}

void QDESolutionTab::addSolutionPanel(QDESolutionPanel * dESolutionPanel)
{
	int index{ addTab(dESolutionPanel, dESolutionPanel->tabTitle()) };

	connect(dESolutionPanel, &QDESolutionPanel::parameterChanged, this, &QDESolutionTab::parameterChanged);

	setCurrentIndex(index);
}

void QDESolutionTab::updateVisualization(QDEAdapter const & de)
{
	static_cast<QDESolutionPanel*>(currentWidget())->updateVisualization(de);
}

