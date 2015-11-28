#ifndef OR_OBJ
#define OR_OBJ

#include "logikElem.h"

class Or: public LogikElem {
public:
	Or(std::string name): LogikElem(name) { }
protected:
	bool operation(bool, bool);

};

#endif