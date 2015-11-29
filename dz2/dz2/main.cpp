#include <iostream>
#include <string>
#include <locale>
#include "LogikElem.h"
#include "And.h"
#include "Or.h"

void outputVec(int v, bool* mas) {
	std::cout << "V" << v << ": ";
	for(int i = 0; i < 7; ++i) {
		std::cout << " " << mas[i];
	}
	std::cout << std::endl;
}

int main() {
	setlocale(LC_ALL, "");
	//               a     b     c     d   
 	bool inp[4];// = { true, true, true, true};

	//               e      f      g      h      n      m      l
	bool per[] = { false, false, false, false, false, false, false };
	bool** per2; 
	per2 = new bool*[7];

	std::cout << "¬ведите входные значени€ a, b, c, d: " << std::endl;

	std::cout << "a = ";
	std::cin >> inp[0];

	std::cout << "b = ";
	std::cin >> inp[1];

	std::cout << "c = ";
	std::cin >> inp[2];

	std::cout << "d = ";
	std::cin >> inp[3];

	LogikElem* elem0 = new And("e");
	LogikElem* elem1 = new And("f");
	LogikElem* elem2 = new And("g");
	LogikElem* elem3 = new Or("h");
	LogikElem* elem4 = new Or("n");
	LogikElem* elem5 = new Or("m");
	LogikElem* elem6 = new Or("l");

	elem0->setInvertor();
	elem1->setInvertor();
	elem4->setInvertor();
	elem5->setInvertor();

	elem0->addInput(&inp[0]);
	elem0->addInput(&inp[1]);
	elem0->addInput(&per[4]);

	elem1->addInput(&inp[2]);
	elem1->addInput(&inp[3]);

	elem2->addInput(&per[0]);
	elem2->addInput(&per[1]);

	elem3->addInput(&per[1]);
	elem3->addInput(&inp[3]);

	elem4->addInput(&per[2]);
	elem4->addInput(&per[3]);

	elem5->addInput(&per[3]);

	elem6->addInput(&per[4]);
	elem6->addInput(&per[5]);

	per2[0] = *(elem0->connectToInput());
	per2[1] = *(elem1->connectToInput());
	per2[2] = *(elem2->connectToInput());
	per2[3] = *(elem3->connectToInput());
	per2[4] = *(elem4->connectToInput());
	per2[5] = *(elem5->connectToInput());
	per2[6] = *(elem6->connectToInput());

	LogikElem** elems = new LogikElem*[7];
	elems[0] = elem0;
	elems[1] = elem1;
	elems[2] = elem2;
	elems[3] = elem3;
	elems[4] = elem4;
	elems[5] = elem5;
	elems[6] = elem6;

	int maxNumIter = 20;
	int i = 0;
	bool same = false;

	for( ; i < maxNumIter; ++i) {
		outputVec(i, per);
		for(int j = 0; j < 7; ++j) {
			elems[j]->execute();
		}
		for(int j = 0; j < 7; ++j) {
			if(per[j] == *(per2[j])) {
				same = true;
			} else {
				break;
			}
		}
		for(int j = 0; j < 7; ++j) {
			per[j] = *(per2[j]);
		}
		if(same) {
			break;
		}
	}
	++i;
	outputVec(i, per);

	delete[] elems;
	system("pause");
	return 0;
}









	///////////////////////////////////////

	//bool in1[] = { false, false, false};
	//bool in2[] = { false, true,  };
	//bool in3[] = { true, false };
	//bool in4[] = { true, true };

	//int count = 3;

	//Or andEl1("d");
	//for(int i = 0; i < count; ++i) {
	//	andEl1.addInput(&(in1[i]));
	//}
	//std::cout << andEl1.getOutputName() << " = " << andEl1.output();
	//std::cout << std::endl;

	//Or andEl2("d");
	//for(int i = 0; i < count; ++i) {
	//	andEl2.addInput(&(in2[i]));
	//}
	//std::cout << andEl2.getOutputName() << " = " << andEl2.output();
	//std::cout << std::endl;

	//Or andEl3("d");
	//for(int i = 0; i < count; ++i) {
	//	andEl3.addInput(&(in3[i]));
	//}
	//std::cout << andEl3.getOutputName() << " = " << andEl3.output();
	//std::cout << std::endl;

	//Or andEl4("d");
	//for(int i = 0; i < count; ++i) {
	//	andEl4.addInput(&(in4[i]));
	//}
	//std::cout << andEl4.getOutputName() << " = " << andEl4.output();
	//std::cout << std::endl;

	//andEl

	///////////////////////////////////////////////////



	///////////////
	//               a     b     c     d     e      f      g      h      n      m      l
 //	bool inp[] = { true, true, true, true, false, false, false, false, false, false, false};
	//And and0("g");
	//Or or1("r");

	//and0.addInput(&inp[0]);
	//and0.addInput(&inp[1]);
	//
	//or1.addInput(&inp[2]);
	//or1.addInput(*(and0.connectToInput()));
	//
	//and0.execute();
	//or1.execute();

	//std::cout << and0.getOutputName() << " = " << and0.output() << std::endl;
	//std::cout << or1.getOutputName() << " = " << or1.output() << std::endl;







	//bool** tabl = new bool*[16];

	//for(int i = 0; i < 16; ++i) {
	//	tabl[i] = new bool[4];
	//}

	//int col = 8;
	//bool isFalse = true;
	//for(int i = 0; i < 4; ++i) {
	//	for(int j = 0; j < 16; ++j) {
	//		isFalse = !(j % col) ? !isFalse : isFalse;
	//		if(!isFalse) {
	//			tabl[j][i] = false; 
	//		} else {
	//			tabl[j][i] = true;
	//		}
	//	}
	//	isFalse = true;
	//	col /= 2;
	//}

	//VivodTabl(tabl);

	//for(int i = 0; i < 16; ++i) {
	//	And andEl("d");
	//	//andEl.setInvertor();
	//	for(int j = 0; j < 4; ++j) {
	//		andEl.addInput(&(tabl[i][j]));
	//	}
	//	andEl.execute();
	//	std::cout << andEl.getOutputName() << " = " << andEl.output();
	//	std::cout << std::endl;
	//}


	//
	//std::cout << std::endl;
	//std::cout << std::endl;


//void vivMas2(bool** mas) {
//	for(int i = 0; i < 7; ++i) {
//		std::cout << " " << *(mas[i]);
//	}
//	std::cout << std::endl;
//}
//
//void VivodTabl(bool** t) {
//	for(int i = 0; i < 16; ++i) {
//		for(int j = 0; j < 4; ++j) {
//			std::cout << " " << t[i][j];
//		}
//		std::cout << std::endl;
//	}
//}