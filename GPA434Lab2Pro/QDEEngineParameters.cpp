#include "QDEEngineParameters.h"


#include <QSpinBox>
#include <QComboBox>
#include <QFormLayout>

#include <engine_parameters.h>
#include <mutation_rand_1.h>
#include <mutation_best_1.h>
#include <crossover_binomial.h>
#include <crossover_exponential.h>
#include <selection_best_fitness.h>


QDEEngineParameters::QDEEngineParameters(QWidget * parent)
	:	QGroupBox(parent),
		mPopulationSize{ new QSpinBox },
		mGenerationCount{ new QSpinBox },
		mMutationStrategy{ new QComboBox },
		mCrossoverStrategy{ new QComboBox },
		mSelectionStrategy{ new QComboBox },
		mStoppingCriteria{ new QComboBox }
{
	mPopulationSize->setRange(de::engine_parameters::minimum_population_size(), de::engine_parameters::maximum_population_size());
	mPopulationSize->setValue(de::engine_parameters::default_population_size());
	mPopulationSize->setToolTip(QString("Détermine la taille de la population [" + QString::number(de::engine_parameters::minimum_population_size()) + ", " + QString::number(de::engine_parameters::maximum_population_size()) + "]."));

	mGenerationCount->setRange(de::engine_parameters::minimum_generation_count(), de::engine_parameters::maximum_generation_count());
	mGenerationCount->setValue(de::engine_parameters::default_generation_count());
	mGenerationCount->setToolTip(QString("Détermine le nombre maximum de génération pour la simulation [" + QString::number(de::engine_parameters::minimum_generation_count()) + ", " + QString::number(de::engine_parameters::maximum_generation_count()) + "]."));

	mMutationStrategy->addItem("Rand1 : aléatoire", 0);
	mMutationStrategy->addItem("Best1 : meilleur", 1);
	mMutationStrategy->setToolTip("Détermine la stratégie de mutation à utiliser pour la simulation.");

	mCrossoverStrategy->addItem("Bin : binomial", 0);
	mCrossoverStrategy->addItem("Exp : exponentiel", 1);
	mCrossoverStrategy->setToolTip("Détermine la stratégie de croisement à utiliser pour la simulation.");

	mSelectionStrategy->addItem("BestFit : meilleure 'fitness'", 0);
	mSelectionStrategy->setToolTip("Détermine la stratégie de sélection à utiliser pour la simulation.");

	mStoppingCriteria->setEnabled(false);
	mStoppingCriteria->setToolTip("...not implemented yet...");

	QFormLayout * formLayout{ new QFormLayout };
	formLayout->addRow("Taille de la population", mPopulationSize);
	formLayout->addRow("Nombre maximum de génération", mGenerationCount);
	formLayout->addRow("Stratégie de mutation", mMutationStrategy);
	formLayout->addRow("Stratégie de croisement", mCrossoverStrategy);
	formLayout->addRow("Stratégie de sélection", mSelectionStrategy);
	formLayout->addRow("Critères d'arrêt", mStoppingCriteria);

	setTitle("Paramètres de l'engin d'évolution différentielle");
	setLayout(formLayout);
	
	connect(mPopulationSize, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &QDEEngineParameters::changeParameters);
	connect(mGenerationCount, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &QDEEngineParameters::changeParameters);
	connect(mMutationStrategy,  static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &QDEEngineParameters::changeParameters);
	connect(mCrossoverStrategy, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &QDEEngineParameters::changeParameters);
	connect(mSelectionStrategy, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &QDEEngineParameters::changeParameters);
}

de::engine_parameters QDEEngineParameters::parameters() const
{
	de::engine_parameters param;

	param.set_population_size(mPopulationSize->value());
	param.set_max_generation(mGenerationCount->value());

	switch (mMutationStrategy->currentData().toInt()) {
		case 0: // Rand1
			param.set_mutation_strategy(new de::mutation_rand_1);
			break;
		case 1: // Best1
			param.set_mutation_strategy(new de::mutation_best_1);
			break;
	}
	switch (mCrossoverStrategy->currentData().toInt()) {
		case 0: // Bin
			param.set_crossover_strategy(new de::crossover_binomial);
			break;
		case 1: // Exp
			param.set_crossover_strategy(new de::crossover_exponential);
			break;
	}
	switch (mSelectionStrategy->currentData().toInt()) {
		case 0: // Best_fit
			param.set_selection_strategy(new de::selection_best_fitness);
			break;
	}

	return param;
}

void QDEEngineParameters::changeParameters()
{
	emit parameterChanged();
}


