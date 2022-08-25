#include "Solution1.h"

const QString Solution1::sDescription("Notre probleme consiste a trouver le prix minimum d'une piece avec un volume, et le prix des materiaux donnes");


Solution1::Solution1(QWidget * parent)
	: QDESolutionPanel(parent),
	mVisualizationLabel{ new QLabel }
{

	CoutMur->setValue(30.0);
	CoutPlancher->setValue(50.0);
	Volume->setValue(150.0);
	PWD->setValue(2);

	QLabel * title{ new QLabel(sDescription) };

	QFrame * sepFrame{ new QFrame };
	sepFrame->setFrameStyle(static_cast<int>(QFrame::HLine) | static_cast<int>(QFrame::Raised));

	mVisualizationLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	mVisualizationLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	QGroupBox * parameterGroupBox{ new QGroupBox("Couts et Volume") };
	QFormLayout * parameterLayout{ new QFormLayout };
	parameterLayout->addRow("Volume", buildSpinBoxLayout(Volume, 150.0));
	parameterLayout->addRow("Proportion largeur/profondeur", buildSpinBoxLayout(PWD, 2));
	parameterLayout->addRow("Cout Mur", buildSpinBoxLayout(CoutMur,30.0));
	parameterLayout->addRow("Cout Plancher", buildSpinBoxLayout(CoutPlancher,50.0));
	parameterGroupBox->setLayout(parameterLayout);

	QWidget * inputWidget{ new QWidget };
	QVBoxLayout * inputLayout{ new QVBoxLayout };
	inputLayout->addWidget(parameterGroupBox);
	inputLayout->addStretch();
	inputWidget->setLayout(inputLayout);

	QGroupBox * visualizationGroupBox{ new QGroupBox("Visualisation") };
	QVBoxLayout * visualizationLayout{ new QVBoxLayout };
	visualizationLayout->addWidget(mVisualizationLabel);
	visualizationGroupBox->setLayout(visualizationLayout);

	QWidget * ioWidget{ new QWidget };
	QHBoxLayout * ioLayout{ new QHBoxLayout };
	ioLayout->addWidget(parameterGroupBox);
	ioLayout->addWidget(visualizationGroupBox);
	ioWidget->setLayout(ioLayout);

	QVBoxLayout * mainLayout{ new QVBoxLayout };
	mainLayout->addWidget(title);
	mainLayout->addWidget(sepFrame);
	mainLayout->addWidget(ioWidget);

	setLayout(mainLayout);
}

QString Solution1::tabTitle() const
{
	return QString("Notre solution");
}

de::solution_strategy * Solution1::buildSolution() const
{
	return new Strategy1(CoutMur->value(),CoutPlancher->value(),Volume->value(),PWD->value());
}

QHBoxLayout * Solution1::buildSpinBoxLayout(QSpinBox *& sb, double const def)
{
	const int min{ 0 };
	const int max{ 10000 };

	sb->setRange(min, max);
	sb->setValue(def);

	QLabel * label{ new QLabel(QString::number(def)+" by default") };

	connect(sb, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &QDESolutionPanel::parameterChanged);

	QHBoxLayout * layout{ new QHBoxLayout };
	layout->addWidget(sb);
	layout->addWidget(label);

	return layout;
}

void Solution1::updateVisualization(QDEAdapter const & de)
{

	double width{ static_cast<double>(de.actualPopulation()[0][0]) };
	double height{ static_cast<double>(Volume->value() / (PWD->value()*pow(de.actualPopulation()[0][0], 2))) };
	double depth{ static_cast<double>(PWD->value()*(de.actualPopulation()[0][0])) };

	const QColor boxColor(255, 255, 255);
	const QColor titleColor(boxColor);
	const QColor backgroundColor(0, 0, 0);
	const QString title("Representation vue de face et de cote");

	QSize labelImageSize(mVisualizationLabel->size().width() - 1, mVisualizationLabel->size().height() - 1);

	double bigOffset{ 100.0 };
	double smallOffset{ 10.0 };
	double smallGridCount{ std::ceil(std::sqrt(de.actualPopulation().size() - 1)) };
	double bigSmallRatio{ 3.0 };
	double hRatio{ (labelImageSize.width() - (smallGridCount + 1) * smallOffset) / smallGridCount };
	double vRatio{ (labelImageSize.height() - smallGridCount * smallOffset - 2.0 * bigOffset) / (smallGridCount + bigSmallRatio) };
	double imageSize{ std::min(hRatio, vRatio) };
	double bigImageSize{ imageSize * bigSmallRatio };

	QPointF bigImageCenter(labelImageSize.width() / 4, bigOffset + bigImageSize / 2.0);
	QPointF bigImageCenter2(labelImageSize.width()/ 4 + (labelImageSize.width() / 2.0), bigOffset + bigImageSize / 2.0);

	QPixmap pixmap(labelImageSize);
	pixmap.fill(backgroundColor);

	const int offsetText{ 15 };
	QPainter painter(&pixmap);
	QFont font(painter.font());
	font.setFamily("Courier new");
	font.setPointSize(12);
	font.setBold(true);
	QFontMetrics titleFontMetrics(font);
	painter.setFont(font);
	painter.setPen(titleColor); 
	painter.drawText(QPoint(offsetText, offsetText + titleFontMetrics.height()), title);

	drawBox(painter, bigImageCenter, bigImageSize, boxColor, de, width, height);
	drawBox(painter, bigImageCenter2, bigImageSize, boxColor, de, depth, height);

	mVisualizationLabel->setPixmap(pixmap);
	QSize s{ mVisualizationLabel->size() };

}

void Solution1::drawBox(QPainter & painter, QPointF const & boxCenterPos, double boxSize, QColor const & boxColor, QDEAdapter const & de, double x,double y)
{
	double width{ static_cast<double>(de.actualPopulation()[0][0]) };
	double height{ static_cast<double>(Volume->value() / (PWD->value()*pow(de.actualPopulation()[0][0], 2))) };

	double scale{ 2*boxSize / std::max(width, height) };

	//QPainter painter(pixmap);
	QRectF box(boxCenterPos.x() - x / 2.0 * scale, boxCenterPos.y() - y / 2.0 * scale, x * scale, y * scale);
	painter.setPen(Qt::NoPen);
	painter.setBrush(boxColor);
	painter.drawRect(box);
}
