//
// Created by michael.brunner on 27/02/2023.
//

#include "CMyDialog.h"

void CMyDialog::dialogDesign()
{
	resize(400, 300);
	mButton->setGeometry(70, 200, 75, 23);
	mButton->setText("OK");

	mLabel->setGeometry(70, 100, 250, 30);
	QFont font;
	font.setPointSize(14);
	mLabel->setFont(font);
}

void CMyDialog::buttonClick()
{
	if (mElementIds->count() == 0) {
		mLabel->setText("No active elements");
		return;
	}
	mLabel->setText(QString("%1 active elements").arg(mElementIds->count()));
}

CMyDialog::~CMyDialog()
{
	delete mButton;
	mButton = {nullptr};
	delete mLabel;
	mLabel = {nullptr};
}

CMyDialog::CMyDialog(CwAPI3D::ControllerFactory* aFactory, QWidget* parent)
		: QDialog(parent)
		  , mButton{new QPushButton(this)}
		  , mLabel{new QLabel(this)}
		  , mFactory{aFactory}
{
	dialogDesign();
	connect(mButton, &QAbstractButton::clicked, this, &CMyDialog::buttonClick);
	mElementIds = {mFactory->getElementController()->getActiveIdentifiableElementIDs()};
}
