#include "le_controller.h"
#include<iostream>
#include <QTextStream>

LEController::LEController(){
    peripheral = QLowEnergyController::createPeripheral();
}

QLowEnergyController* LEController::get(){
	return selected;
}

QLowEnergyController* LEController::switchRole(){
	if (selected == peripheral){
		selected = central;
		QTextStream(stderr) << "selected: central"<<endl;
	}
	else{
		selected = peripheral;
		QTextStream(stderr) << "selected: central"<<endl;
	}

	if (selected != nullptr)
		return selected;

    QTextStream(stderr) << "LEControllerError: null value"<<Qt::endl;
	return nullptr;
}

QLowEnergyController* LEController::setPeripheral(QLowEnergyController* leController){
	peripheral = leController;
	return leController;
}

QLowEnergyController* LEController::setCentral(QLowEnergyController* leController){
	central = leController;
	return leController;
}


QLowEnergyController* LEController::selectPeripheral(){
	selected = peripheral;
	return selected;
}

QLowEnergyController* LEController::selectCentral(){
	selected = central;
	return selected;
}
