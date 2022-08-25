#include "GPA434Lab2Pro.h"

GPA434Lab2Pro::GPA434Lab2Pro(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//Ici on paramètres l'affichage de l'interface graphique

	QLab2 *mLab{new QLab2};

	QVBoxLayout * Layout1{ new QVBoxLayout };	//Le layout1 représente la partie en haut à gauche de l'interface

	Layout1->addWidget(mLab->getEngineParameter());
	Layout1->addWidget(mLab->getController());
	QWidget * Widget1{ new QWidget };
	Widget1->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
	Widget1->setLayout(Layout1);

	QSplitter *Splitter1{ new QSplitter };	//Ce layout représente la partie en haut à droite
	Splitter1->addWidget(mLab->getHistoryChart());
	Splitter1->addWidget(mLab->getBestResult());

	QHBoxLayout * Layout2{ new QHBoxLayout }; //Ce layout représente la partie du haut de l'interface graphique
	Layout2->addWidget(Widget1);
	Layout2->addWidget(Splitter1);

	QWidget * Widget2{ new QWidget };
	Widget2->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
	Widget2->setLayout(Layout2);

	QVBoxLayout * Layout3{ new QVBoxLayout }; //Ce layout représente l'interface graphique générale
	Layout3->addWidget(Widget2);
	mLab->getSolutionTab()->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
	Layout3->addWidget(mLab->getSolutionTab());

	QWidget * centralWidget{ new QWidget };
	centralWidget->setLayout(Layout3);

	setCentralWidget(centralWidget); 
}
