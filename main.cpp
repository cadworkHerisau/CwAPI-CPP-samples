#include <sstream>
#include "CwAPI3D_Plugin.h"
#include "CMyDialog.h"
#include <QDebug>

CwAPI3D::ControllerFactory* ControllerFactory;

bool plugin_x64_init(CwAPI3D::ControllerFactory* aFactory)
{
	ControllerFactory = aFactory;

	auto lUtilityController{aFactory->getUtilityController()};
	auto lAttributeController{aFactory->getAttributeController()};
	auto lElementController{aFactory->getElementController()};

	auto lActiveElementIds{lElementController->getActiveIdentifiableElementIDs()};

	for (int il{0}; il < lActiveElementIds->count(); il++) {
		CwAPI3D::Interfaces::ICwAPI3DString* lName{lAttributeController->getName(lActiveElementIds->at(il))};
		qDebug() << QString::fromStdWString(lName->data());
	}

	auto lHWND{lUtilityController->get3DHWND()};
	QWidget* lParWidget{dynamic_cast<QWidget*>(QWidget::find((WId) lHWND))};
	auto lDialog{new CMyDialog(ControllerFactory, lParWidget)};
	auto lRet = lDialog->exec();
	if (lRet == QDialog::Accepted) {
		qDebug() << "Accepted";
	} else {
		qDebug() << "Rejected";
	}
	return EXIT_SUCCESS;
}

