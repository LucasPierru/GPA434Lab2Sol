#pragma once

// Fichier : GPA434Lab2Pro.h
// GPA434 � Laboratoire 2
// Cr�ation :
// - 2019/11/20
// - - - - - - - - - - - - - - - - - - - - - - -
// Classe GPA434Lab2Pro.
// Affichage de la GPA434Lab2Pro.

#include <QtWidgets/QMainWindow>
#include "ui_GPA434Lab2Pro.h"
#include "QLab2.h"

//Dans cette classe, on impl�mentera l'interface graphique.

class GPA434Lab2Pro : public QMainWindow
{
	Q_OBJECT

public:
	GPA434Lab2Pro(QWidget *parent = Q_NULLPTR);

private:
	Ui::GPA434Lab2ProClass ui;

};
