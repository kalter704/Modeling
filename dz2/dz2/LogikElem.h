#ifndef LOGIKELEM
#define LOGIKELEM

#include <iostream>
#include <string>

class LogikElem {
public:
	LogikElem(std::string _name): countInputs(0), invertor(false), inputs(NULL) {
		this->name = _name;
		_output = new bool[1];
		*(_output) = false;
	}

	~LogikElem() {
		delete _output;
		delete[] inputs;
	}
	
	std::string getOutputName() { return name; }
	void setOutputName(std::string name) { this->name = name; }
	
	void addInput(bool* input);

	bool output() {
		//*_output = execute();
		return *_output;
	}

	void execute();

	bool** connectToInput() {
		//std::cout << "qwfawfdaw = " << *_output << std::endl;
		return &(_output);
	}

	void setInvertor() { invertor = true; }
	void removeInvertor() { invertor = false; }

protected:
	virtual bool operation(bool a, bool b) = 0;
	
protected:
	std::string name;
	bool** inputs;
	bool* _output;
	int countInputs;
	bool invertor;
};

#endif