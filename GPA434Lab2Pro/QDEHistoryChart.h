#pragma once


#include <QChartView>
#include <QChart>
#include <QLineSeries>

class QDEAdapter;


class QDEHistoryChart : public QtCharts::QChartView
{
	Q_OBJECT

public:
	QDEHistoryChart(QWidget * parent = nullptr);
	QDEHistoryChart(QDEHistoryChart const &) = default;
	QDEHistoryChart(QDEHistoryChart &&) = default;
	QDEHistoryChart& operator=(QDEHistoryChart const &) = default;
	QDEHistoryChart& operator=(QDEHistoryChart &&) = default;
	~QDEHistoryChart() override = default;

public slots:
	void update(QDEAdapter const & de);
	void reset();

private:
	QtCharts::QChart * mChart{};
	QtCharts::QLineSeries * mBestData{};
	QtCharts::QLineSeries * mMedianData{};
	QtCharts::QLineSeries * mWorstData{};
};
