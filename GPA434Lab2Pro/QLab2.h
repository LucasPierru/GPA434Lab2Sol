#ifndef QLAB2_H
#define QLAB2_H

// Fichier : QLab.h
// GPA434 – Laboratoire 2
// Création :
// - 2019/11/20
// - - - - - - - - - - - - - - - - - - - - - - -
// Classe QLab2.
// Application Principale

#include <QWidget>
#include <QScrollBar>
#include <QLabel>
#include <QHBoxLayout>
#include <QMainWindow>
#include <QSplitter>
#include "QDEAdapter.h"
#include "QDEEngineParameters.h"
#include "QDESolutionTab.h"
#include "QDEController.h"
#include "QDEBestResult.h"
#include "QDEHistorychart.h"
#include "QDEPeakSolution.h"
#include "QDEOpenBoxSolution.h"
#include "Solution1.h"
#include "Solution2.h"

// La classe QLab2 représente notre application principale, c'est dans celle-ci que l'on effectue tous les connects
// La classe possède les attributs mDEEngineParameters, mDESolutionTab, mDE, mpointeurDE, qc, hc1,br1,ps,ob,s1,s2
// - ces accesseurs :
//		getEngineParameter();
//		getSolutionTab();
//		getHistoryChart();
//		getBestResult();
//		getController();
//		getPeakSolution();
//		getOpenBoxSolution();
//		getAdapter();
// - ces slots :
//		changeSimulationParameters();

class QLab2 : public QMainWindow
{
private: 

	QDEEngineParameters *mDEEngineParameters{ new QDEEngineParameters };
	QDESolutionTab *mDESolutionTab{new QDESolutionTab};
	QDEAdapter mDE;
	QDEAdapter *mpointeurDE{new QDEAdapter};
	QDEController *qc{ new QDEController(mDE) };
	QDEHistoryChart *hc1{ new QDEHistoryChart };
	QDEBestResult *br1{ new QDEBestResult };
	QDEPeakSolution *ps{ new QDEPeakSolution };
	QDEOpenBoxSolution *ob{ new QDEOpenBoxSolution };
	Solution1 *s1{ new Solution1 };
	Solution2 *s2{ new Solution2 };

public:

	QLab2();
	~QLab2();
	QDEEngineParameters* getEngineParameter();
	QDESolutionTab* getSolutionTab();
	QDEHistoryChart* getHistoryChart();
	QDEBestResult* getBestResult();
	QDEController* getController();
	QDEPeakSolution* getPeakSolution();
	QDEOpenBoxSolution* getOpenBoxSolution();
	QDEAdapter* getAdapter();

public slots:

	void changeSimulationParameters();

};

#endif //!QLAB2_H

