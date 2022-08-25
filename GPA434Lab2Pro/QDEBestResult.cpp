#include "QDEBestResult.h"



QDEBestResult::QDEBestResult(QWidget *parent)
	: QPlainTextEdit(parent)
{
	setReadOnly(true);

	QFont font{ document()->defaultFont() };
	font.setFamily("Courier New");
	document()->setDefaultFont(font);

	setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
}

void QDEBestResult::update(QDEAdapter const & de)
{
	setPlainText(de.bestSolutionInfo());
}

void QDEBestResult::reset()
{
	setPlainText("- no result -");
}
