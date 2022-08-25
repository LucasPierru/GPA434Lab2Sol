#ifndef SOLUTION2_H
#define SOLUTION2_H

// Fichier : Solution2.h
// GPA434 – Laboratoire 2
// Création :
// - 2019/11/20
// - - - - - - - - - - - - - - - - - - - - - - -
// Classe Strategy2.
// Affichage de la solution2.

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
#include "Strategy2.h"

namespace QtDV = QtDataVisualization;

class Strategy2;

// La classe Solution2 va nous servir à afficher les résultats de la strategie du cercle le plus grand.
// Cette classe nous permettra construire l'affichage graphique dans le solutionPanel
// La classe possède les attributs Height, width, Nbpoints.
// Elle possède les fonction buildsolution et tabtitle permettant de construire notre strategie et d'afficher le titre de notre solution
// Nous avons également les fonction BuildSpinBoxLayout pour construire les layout où nous selectionerons nos valeurs
// Drawbox pour contruire notre boite graphique, DrawCircle pour afficher le plus grand cercle 
// et DrawPoint pour afficher les points (non fonctionnelle ici).

class Solution2 : public QDESolutionPanel
{
	Q_OBJECT

public:
	Solution2(QWidget * parent = nullptr);
	Solution2(Solution2 const &) = default;
	Solution2(Solution2 &&) = default;
	Solution2& operator=(Solution2 const &) = default;
	Solution2& operator=(Solution2 &&) = default;
	~Solution2() override = default;

	QString tabTitle() const override;
	de::solution_strategy * buildSolution() const override;

public slots:
	void updateVisualization(QDEAdapter const & de) override;

private:
	QSpinBox * Height{ new QSpinBox };
	QSpinBox * Width{ new QSpinBox };
	QSpinBox * NbPoints{ new QSpinBox };

	QHBoxLayout * buildSpinBoxLayout(QSpinBox *& sb, double const def);

	void drawBox(QPainter & painter, QPointF const & boxCenterPos, double boxSize, QColor const & boxColor, QDEAdapter const & de);
	void drawCircle(QPainter & painter, QPointF const & circleCenterPos, double circleSize, QColor const & circleColor, QDEAdapter const & de);
	void drawPoint(QPainter & painter, QPointF const & pointPos,double pointSize, QPointF const & pos, QColor const & pointColor, QDEAdapter const & de);

	QLabel * mVisualizationLabel;

	static const QString sDescription;

};

#endif // !SOLUTION1_H




