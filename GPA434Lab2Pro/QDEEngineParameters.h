#pragma once


#include <QGroupBox>
#include <engine_parameters.h>
class QSpinBox;
class QComboBox;


class QDEEngineParameters : public QGroupBox
{
	Q_OBJECT

public:
	QDEEngineParameters(QWidget * parent = nullptr);
	QDEEngineParameters(QDEEngineParameters const &) = default;
	QDEEngineParameters(QDEEngineParameters &&) = default;
	QDEEngineParameters& operator=(QDEEngineParameters const &) = default;
	QDEEngineParameters& operator=(QDEEngineParameters &&) = default;
	~QDEEngineParameters() override = default;

	de::engine_parameters parameters() const;

signals:
	void parameterChanged();

private slots:
	void changeParameters();

private:
	QSpinBox * mPopulationSize{};
	QSpinBox * mGenerationCount{};
	QComboBox * mMutationStrategy{};
	QComboBox * mCrossoverStrategy{};
	QComboBox * mSelectionStrategy{};
	QComboBox * mStoppingCriteria{};
};

