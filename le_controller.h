#include<vector>
#include <QLowEnergyController>

class LEController {
	private:
		QLowEnergyController *peripheral, *central, *selected;

	public:
	LEController();

	QLowEnergyController* get();
	QLowEnergyController* setPeripheral(QLowEnergyController*);
	QLowEnergyController* setCentral(QLowEnergyController*);
	QLowEnergyController* selectPeripheral();
	QLowEnergyController* selectCentral();
	QLowEnergyController* switchRole();
};
