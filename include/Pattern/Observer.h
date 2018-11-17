// code taken from Dr. Joey Paquet's code posted on website
#pragma once

class Observer {
public:
	~Observer();
	virtual void Update() = 0;
protected:
	Observer();
};
