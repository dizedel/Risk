// parts of code taken from Dr. Joey Paquet's code posted on website
#pragma once
#include "pattern/Observer.h"
#include <list>
using namespace std;

//Needs to have a forward reference due to 
//circular reference between Observer and Subject
class Observer;

class Subject {
  public:
	virtual void Attach(Observer* o);
	virtual void Detach(Observer* o);
	virtual void Notify();
	Subject();
	~Subject();
  private:
	list<Observer*> *_observers;
};
