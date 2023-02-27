//
// Created by michael.brunner on 27/02/2023.
//

#ifndef CWAPI_CPP_SAMPLES_CMYDIALOG_H
#define CWAPI_CPP_SAMPLES_CMYDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include "CwAPI3D_Plugin.h"

class CMyDialog : public QDialog
{
Q_OBJECT

private:

	QPushButton* mButton{nullptr};

	QLabel* mLabel{nullptr};

	CwAPI3D::ControllerFactory* mFactory{nullptr};

	CwAPI3D::Interfaces::ICwAPI3DElementIDList* mElementIds{nullptr};

	void dialogDesign();

private slots:

	void buttonClick();

public:
	explicit CMyDialog(CwAPI3D::ControllerFactory* aFactory, QWidget* parent = nullptr);

	~CMyDialog() override;
};

#endif //CWAPI_CPP_SAMPLES_CMYDIALOG_H
