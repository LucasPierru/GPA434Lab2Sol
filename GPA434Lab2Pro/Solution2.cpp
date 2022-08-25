#include "Solution2.h"

const QString Solution2::sDescription("Notre probleme consiste a trouver le prix minimum d'une piece avec un volume, et le prix des materiaux donnes");


Solution2::Solution2(QWidget * parent)
	: QDESolutionPanel(parent),
	mVisualizationLabel{ new QLabel }
{

	Height->setValue(30.0);
	Width->setValue(50.0);
	NbPoints->setValue(10);

	QLabel * title{ new QLabel(sDescription) };

	QFrame * sepFrame{ new QFrame };
	sepFrame->setFrameStyle(static_cast<int>(QFrame::HLine) | static_cast<int>(QFrame::Raised));

	mVisualizationLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	mVisualizationLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	QGroupBox * parameterGroupBox{ new QGroupBox("Dimensions et nombre de points") };
	QFormLayout * parameterLayout{ new QFormLayout };
	parameterLayout->addRow("Largeur", buildSpinBoxLayout(Width, 50.0));
	parameterLayout->addRow("Hauteur", buildSpinBoxLayout(Height, 30.0));
	parameterLayout->addRow("Nombre de points", buildSpinBoxLayout(NbPoints, 10));
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

QString Solution2::tabTitle() const
{
	return QString("Solution du plus grand cercle");
}

de::solution_strategy * Solution2::buildSolution() const
{
	Strategy2 *st2{ new Strategy2(Height->value(), Width->value(), NbPoints->value()) };

	return st2;
}

QHBoxLayout * Solution2::buildSpinBoxLayout(QSpinBox *& sb, double const def)
{
	const int min{ 0 };
	const int max{ 10000 };

	sb->setRange(min, max);
	sb->setValue(def);

	QLabel * label{ new QLabel(QString::number(def) + " by default") };

	connect(sb, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &QDESolutionPanel::parameterChanged);

	QHBoxLayout * layout{ new QHBoxLayout };
	layout->addWidget(sb);
	layout->addWidget(label);

	return layout;
}

void Solution2::updateVisualization(QDEAdapter const & de)
{
	const QColor boxColor(200, 2, 105);
	const QColor cornerColor(boxColor.lighter(125));
	const QColor backgroundColor(16, 24, 72);

	QSize labelImageSize(mVisualizationLabel->size().width() - 1, mVisualizationLabel->size().height() - 1);

	double bigOffset{ 100.0 };
	double smallOffset{ 0.5 };
	double smallGridCount{ std::ceil(std::sqrt(de.actualPopulation().size() - 1)) };
	double bigSmallRatio{ 100.0 };
	double hRatio{ (labelImageSize.width() - (smallGridCount + 1) * smallOffset) / smallGridCount };
	double vRatio{ (labelImageSize.height() - smallGridCount * smallOffset - 2.0 * bigOffset) / (smallGridCount + bigSmallRatio) };
	double imageSize{ std::min(hRatio, vRatio) };
	double bigImageSize{ imageSize * bigSmallRatio };

	double width{ static_cast<double>(Width->value()) };
	double height{ static_cast<double>(Height->value()) };

	QPointF bigImageCenter(labelImageSize.width() / 2.0, bigOffset + bigImageSize / 2.0);

	QPixmap pixmap(labelImageSize);
	pixmap.fill(backgroundColor);

	const int offsetText{ 8 };
	QPainter painter(&pixmap);
	QFont font(painter.font());
	font.setFamily("Courier new");
	font.setPointSize(12);
	font.setBold(true);
	QFontMetrics titleFontMetrics(font);
	painter.setFont(font);
	//painter.setPen(titleColor);
	font.setPointSize(10);
	font.setBold(false);
	font.setItalic(true);
	QFontMetrics subTitleFontMetrics(font);
	painter.setFont(font);
	//painter.setPen(subTitleColor);

	drawBox(painter, bigImageCenter, bigImageSize, boxColor, de);
	drawCircle(painter, bigImageCenter, bigImageSize, boxColor, de);

	mVisualizationLabel->setPixmap(pixmap);
	QSize s{ mVisualizationLabel->size() };

}

void Solution2::drawBox(QPainter & painter, QPointF const & boxCenterPos, double boxSize, QColor const & boxColor, QDEAdapter const & de)
{
	double width{ static_cast<double>(Width->value()) };
	double height{ static_cast<double>(Height->value()) };
	double radius{ de.actualPopulation()[0].objective() };

	double scale{ 1.9*boxSize / std::max(width, height) };

	QPen pen;

	pen.setColor(Qt::green);
	pen.setWidth(3);

	//QPainter painter(pixmap);
	QRectF box(boxCenterPos.x() - width / 2.0 * scale, boxCenterPos.y() - height / 2.0 * scale, width * scale, height * scale);
	painter.setPen(pen);
	//painter.setBrush(boxColor);
	painter.drawRect(box);
}

void Solution2::drawCircle(QPainter & painter, QPointF const & circleCenterPos, double circleSize, QColor const & circleColor, QDEAdapter const & de)
{

	double radius{ de.actualPopulation()[0].objective() };

	double width{ static_cast<double>(Width->value()) };
	double height{ static_cast<double>(Height->value()) };

	double x{ de.actualPopulation()[0][0] };
	double y{ de.actualPopulation()[0][1] };

	double scale{ 1.9*circleSize / std::max(width, height) };
	

	QPen pen;
	
	pen.setColor(Qt::green);
	pen.setWidth(3);

	QRectF circle(circleCenterPos.x() - ((width / 2.0) + radius-x) *scale , circleCenterPos.y() - ((height / 2.0) + radius-y) * scale ,2*radius*scale, 2*radius*scale);
	painter.setPen(pen);
	painter.drawEllipse(circle);

}

void Solution2::drawPoint(QPainter & painter, QPointF const & pointPos, double pointSize, QPointF const & pos, QColor const & pointColor, QDEAdapter const & de)
{	
	double width{ static_cast<double>(Width->value()) };
	double height{ static_cast<double>(Height->value()) };

	double scale{ 1.9 * pointSize / std::max(width, height) };

	QPen pen;

	pen.setColor(Qt::green);

	QPointF point (pointPos.x() - (width / 2.0-pos.x()) * scale, pointPos.y() - (width / 2.0-pos.y()) * scale);

	painter.setPen(pen);
	painter.drawPoint(point);
}

