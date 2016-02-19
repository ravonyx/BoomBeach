#include "Army.h"



Army::Army()
{
}


void Army::CreateUnit(unitType type)
{
	_unitArray.push_back(Unit(type));
}

void Army::DestroyUnit(unitType type, int level)
{
	for (size_t i = 0; i < _unitArray.size(); i++)
	{
		int unitIndex = -1;
		if (_unitArray[i].getName() == type && _unitArray[i].getLevel() == level) {
			unitIndex = 1;
			break;
		}
		if (unitIndex != -1) {
			_unitArray.erase(_unitArray.begin() + unitIndex);
		}
	}
}

Army::~Army()
{
}
