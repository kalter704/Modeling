#include "LogikElem.h"

void LogikElem::addInput(bool* input) {
	//std::cout << "in qwasfas = " << *input << std::endl;

	if(inputs == NULL) {
		inputs = new bool*[++countInputs];
		inputs[0] = input;
		return;
	}
	
	bool** temp = new bool*[++countInputs];
	for(int i = 0; i < countInputs - 1; ++i) {
		temp[i] = inputs[i];
	}
	temp[countInputs - 1] = input;
	delete[] inputs;
	inputs = temp;
}

void LogikElem::execute() {
	bool result = *(inputs[0]);
	for(int i = 1; i < countInputs; ++i) {
		result = operation(result, *(inputs[i]));
	}
	*_output = (!invertor? result : !result);
}

