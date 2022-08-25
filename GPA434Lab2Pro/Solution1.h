#ifndef SOLUTION1_H
#define SOLUTION1_H

// Fichier : Solution1.h
// GPA434 – Laboratoire 2
// Création :
// - 2019/11/20
// - - - - - - - - - - - - - - - - - - - - - - -
// Classe Solution1.
// Affichage de la solution1

#include <QtDataVisualization>
#include <QGroupBox>
#include <qspinbox.h>
#include <QFrame>
#include <QGroupBox>
#include <QLabel>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QPainter>
#include "QDESolutionPanel.h"
#include "Fitness_Inverse.h"
#include "Strategy1.h"

namespace QtDV = QtDataVisualization;

class Strategy1;

// La classe Solution1 va nous servir à afficher les résultats de notre strategie.
// Cette classe nous permettra construire l'affichage graphique dans le solutionPanel
// La classe possède les attributs CoutMur, CoutPlancher, Volume et PWD
// Elle possède les fonction buildsolution et tabtitle permettant de construire notre strategie et d'afficher le titre de notre solution
// Nous avons également les fonction BuildSpinBoxLayout pour construire les layout où nous selectionerons nos valeurs
// et Drawbox pour contruire notre boite graphique

class Solution1 : public QDESolutionPanel
{
	Q_OBJECT

public:
	Solution1(QWidget * parent = nullptr);
	Solution1(Solution1 const &) = default;
	Solution1(Solution1 &&) = default;
	Solution1& operator=(Solution1 const &) = default;
	Solution1& operator=(Solution1 &&) = default;
	~Solution1() override = default;

	QString tabTitle() const override;
	de::solution_strategy * buildSolution() const override;

public slots:
	void updateVisualization(QDEAdapter const & de) override;

private:
	QSpinBox * CoutMur{ new QSpinBox };
	QSpinBox * CoutPlancher{ new QSpinBox };
	QSpinBox * Volume{ new QSpinBox };
	QSpinBox * PWD{ new QSpinBox };

	QHBoxLayout * buildSpinBoxLayout(QSpinBox *& sb, double const def);

	void drawBox(QPainter & painter, QPointF const & boxCenterPos, double boxSize, QColor const & boxColor, QDEAdapter const & de,double x, double y);

	QLabel * mVisualizationLabel;

	static const QString sDescription;

};

#endif // !SOLUTION1_H


