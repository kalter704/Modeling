#ifndef AND_OBJ
#define AND_OBJ

#include <string>
#include "logikElem.h"

class And: public LogikElem {
public:
	And(std::string name): LogikElem(name) { }
protected:
	bool operation(bool, bool);

};

#endif