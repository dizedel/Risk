// parts of code taken from Dr. Joey Paquet's code posted on website
#include "pattern/Subject.h"
#include "pattern/Observer.h"

Subject::Subject(){
	//_observers = new list<Observer*>;
}
Subject::~Subject(){ 
	//delete _observers;
}
void Subject::Attach(Observer* o){
  _observers.push_back(o);
};
void Subject::Detach(Observer* o){
  _observers.remove(o);
};
void Subject::Notify(){
  list<Observer *>::iterator i = _observers.begin();
  for (; i != _observers.end(); ++i)
	(*i)->Update(); 
};