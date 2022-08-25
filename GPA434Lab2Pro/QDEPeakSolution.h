#pragma once


#include "QDESolutionPanel.h"
#include <QtDataVisualization>
#include <Q3DSurface>

namespace QtDV = QtDataVisualization;

class QRadioButton;


class QDEPeakSolution : public QDESolutionPanel
{
	Q_OBJECT

public:
	QDEPeakSolution(QWidget * parent = nullptr);
	QDEPeakSolution(QDEPeakSolution const &) = default;
	QDEPeakSolution(QDEPeakSolution &&) = default;
	QDEPeakSolution& operator=(QDEPeakSolution const &) = default;
	QDEPeakSolution& operator=(QDEPeakSolution &&) = default;
	~QDEPeakSolution() override = default;

	QString tabTitle() const override;
	de::solution_strategy * buildSolution() const override;

	enum PeakMode { Minimum, Maximum, MinMax };
	PeakMode currentMode() const;

public slots:
	void updateVisualization(QDEAdapter const & de) override;

private:
	QRadioButton * mMinPeakRadio{};
	QRadioButton * mMaxPeakRadio{};
	QRadioButton * mMinMaxPeakRadio{};

	QtDV::Q3DSurface * mSurface{};
	QWidget * mSurfaceWidget{};
	QString mMeshFileName;
	bool mMeshAvailable;
	QImage mMinColor;
	QImage mMaxColor;

	static const size_t sXRes, sZRes;
	static const qreal sXMin, sXMax, sZMin, sZMax;
	static const QString sInternalResourceMeshFileName;
	static const QString sExternalResourceMeshFileName;
	static const QString sDescription, sParametersTitle, sVisualizationTitle;
	static const QColor sMinColor, sMaxColor;
	static const qreal sMeshOffset;
	static const qreal sMeshScale;

	void addPoint(qreal x, qreal z, bool maximumPoint);
	void addPoint(qreal x, qreal y, qreal z, bool maximumPoint);
};
