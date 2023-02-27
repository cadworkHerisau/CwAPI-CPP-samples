//
// Created by michael.brunner on 27/02/2023.
//

#ifndef CWAPI_CPP_SAMPLES_CWAPI3D_PLUGIN_H
#define CWAPI_CPP_SAMPLES_CWAPI3D_PLUGIN_H


#define CWAPI3D_PLUGIN_NAME L"CWAPI3D Plugin"
#define CWAPI3D_AUTHOR_NAME L"Cadwork Holz AG"
#define CWAPI3D_AUTHOR_EMAIL L"brunner@cadwork.swiss"

#include "CwAPI3D.h"

CWAPI3D_PLUGIN bool plugin_x64_init(CwAPI3D::ControllerFactory* aFactory);

#endif //CWAPI_CPP_SAMPLES_CWAPI3D_PLUGIN_H
