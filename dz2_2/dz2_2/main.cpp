#include <iostream>
#include <locale>

namespace for3 {
	const int tablAnd[3][3] = {
		{ 0, 0, 0 },
		{ 0, 1, 2 },
		{ 0, 2, 2 }
	};

	const int tablOr[3][3] = {
		{ 0, 1, 2 }, 
		{ 1, 1, 1 },
		{ 2, 1, 2 }
	};

	const int tablInver[] = { 1, 0, 2 };

	int oAnd(int x, int y) {
		return tablAnd[x][y];
	}

	int oOr(int x, int y) {
		return tablOr[x][y];
	}

	int oInver(int x) {
		return tablInver[x];
	}

	int getPer(int x, int y) {
		if(x == 0 && y == 0) return 0;
		if((x == 0 && y == 1) || (x == 1 && y == 0)) return 2;
		if(x == 1 && y == 1) return 1;
	}

	void output(int tabl[11][3]) {
		for(int i = 0; i < 11; ++i) {
			for(int j = 0; j < 3; ++j) {
				std::cout << " " << tabl[i][j];
			}	
			if(i > 3) {
				if(tabl[i][1] == 2) {
					if((tabl[i][0] == 0 && tabl[i][2] == 0) || 
						(tabl[i][0] == 1 && tabl[i][2] == 1)) {
							std::cout << " - ñ.ğ.ñ";
					}
					//if((tabl[i][0] == 0 && tabl[i][2] == 1) ||
					//	(tabl[i][0] == 1 && tabl[i][2] == 0)) {
					//		std::cout << " - ä.ğ.ñ";
					//}
				}
			}
			std::cout << std::endl;
		}
	}

	void execute(int inp[4][2]) {
		int tabl[11][3];

		tabl[0][0] = inp[0][0];
		tabl[0][2] = inp[0][1];
		tabl[0][1] = getPer(tabl[0][0], tabl[0][2]);

		tabl[1][0] = inp[1][0];
		tabl[1][2] = inp[1][1];
		tabl[1][1] = getPer(tabl[1][0], tabl[1][2]);

		tabl[2][0] = inp[2][0];
		tabl[2][2] = inp[2][1];
		tabl[2][1] = getPer(tabl[2][0], tabl[2][2]);

		tabl[3][0] = inp[3][0];
		tabl[3][2] = inp[3][1];
		tabl[3][1] = getPer(tabl[3][0], tabl[3][2]);

		tabl[4][0] = oInver(oAnd(tabl[0][0], tabl[1][0]));
		tabl[4][2] = oInver(oAnd(tabl[0][2], tabl[1][2]));
		tabl[4][1] = oInver(oAnd(tabl[0][1], tabl[1][1]));

		tabl[5][0] = oInver(oAnd(tabl[1][0], tabl[2][0]));
		tabl[5][2] = oInver(oAnd(tabl[1][2], tabl[2][2]));
		tabl[5][1] = oInver(oAnd(tabl[1][1], tabl[2][1]));
		
		tabl[6][0] = oAnd(tabl[4][0], tabl[5][0]);
		tabl[6][2] = oAnd(tabl[4][2], tabl[5][2]);
		tabl[6][1] = oAnd(tabl[4][1], tabl[5][1]);

		tabl[7][0] = oOr(tabl[3][0], tabl[5][0]);
		tabl[7][2] = oOr(tabl[3][2], tabl[5][2]);
		tabl[7][1] = oOr(tabl[3][1], tabl[5][1]);
		
		tabl[8][0] = oInver(oOr(tabl[6][0], tabl[7][0]));
		tabl[8][2] = oInver(oOr(tabl[6][2], tabl[7][2]));
		tabl[8][1] = oInver(oOr(tabl[6][1], tabl[7][1]));
		
		tabl[9][0] = oInver(tabl[7][0]);
		tabl[9][2] = oInver(tabl[7][2]);
		tabl[9][1] = oInver(tabl[7][1]);

		tabl[10][0] = oOr(tabl[8][0], tabl[9][0]);
		tabl[10][2] = oOr(tabl[8][2], tabl[9][2]);
		tabl[10][1] = oOr(tabl[8][1], tabl[9][1]);

		std::cout << "a = " << inp[0][0] << " - " << inp[0][1] << std::endl;
		std::cout << "b = " << inp[1][0] << " - " << inp[1][1] << std::endl;
		std::cout << "c = " << inp[2][0] << " - " << inp[2][1] << std::endl;
		std::cout << "d = " << inp[3][0] << " - " << inp[3][1] << std::endl;

		output(tabl);
	}
}

namespace for5 {
	const int tablAnd[5][5] = {
		{ 0, 0, 0, 0, 0 },
		{ 0, 1, 2, 3, 4 },
		{ 0, 2, 2, 2, 2 },
		{ 0, 3, 2, 3, 2 },
		{ 0, 4, 2, 2, 4 }
	};

	const int tablOr[5][5] = {
		{ 0, 1, 2, 3, 4 }, 
		{ 1, 1, 1, 1, 1 },
		{ 2, 1, 2, 2, 2 },
		{ 3, 1, 2, 3, 2 },
		{ 4, 1, 2, 2, 4 }
	};

	const int tablInver[] = { 1, 0, 2, 4, 3 };

	int oAnd(int x, int y) {
		return tablAnd[x][y];
	}

	int oOr(int x, int y) {
		return tablOr[x][y];
	}

	int oInver(int x) {
		return tablInver[x];
	}

	int getPer(int x, int y) {
		if(x == 0 && y == 0) return 0;
		if(x == 1 && y == 1) return 1;
		if(x == 0 && y == 1) return 3;
		if(x == 1 && y == 0) return 4;
	}

	void output(int tabl[11][3]) {
		for(int i = 0; i < 11; ++i) {
			for(int j = 0; j < 3; ++j) {
				std::cout << " " << tabl[i][j];
			}	
			if(i > 3) {
				if(tabl[i][1] == 2) {
					if((tabl[i][0] == 0 && tabl[i][2] == 0) || 
						(tabl[i][0] == 1 && tabl[i][2] == 1)) {
							std::cout << " - ñ.ğ.ñ";
					}
					if((tabl[i][0] == 0 && tabl[i][2] == 1) ||
						(tabl[i][0] == 1 && tabl[i][2] == 0)) {
							std::cout << " - ä.ğ.ñ";
					}
				}
			}
			std::cout << std::endl;
		}
	}

	void execute(int inp[4][2]) {
		int tabl[11][3];

		tabl[0][0] = inp[0][0];
		tabl[0][2] = inp[0][1];
		tabl[0][1] = getPer(tabl[0][0], tabl[0][2]);

		tabl[1][0] = inp[1][0];
		tabl[1][2] = inp[1][1];
		tabl[1][1] = getPer(tabl[1][0], tabl[1][2]);

		tabl[2][0] = inp[2][0];
		tabl[2][2] = inp[2][1];
		tabl[2][1] = getPer(tabl[2][0], tabl[2][2]);

		tabl[3][0] = inp[3][0];
		tabl[3][2] = inp[3][1];
		tabl[3][1] = getPer(tabl[3][0], tabl[3][2]);

		tabl[4][0] = oInver(oAnd(tabl[0][0], tabl[1][0]));
		tabl[4][2] = oInver(oAnd(tabl[0][2], tabl[1][2]));
		tabl[4][1] = oInver(oAnd(tabl[0][1], tabl[1][1]));

		tabl[5][0] = oInver(oAnd(tabl[1][0], tabl[2][0]));
		tabl[5][2] = oInver(oAnd(tabl[1][2], tabl[2][2]));
		tabl[5][1] = oInver(oAnd(tabl[1][1], tabl[2][1]));
		
		tabl[6][0] = oAnd(tabl[4][0], tabl[5][0]);
		tabl[6][2] = oAnd(tabl[4][2], tabl[5][2]);
		tabl[6][1] = oAnd(tabl[4][1], tabl[5][1]);

		tabl[7][0] = oOr(tabl[3][0], tabl[5][0]);
		tabl[7][2] = oOr(tabl[3][2], tabl[5][2]);
		tabl[7][1] = oOr(tabl[3][1], tabl[5][1]);
		
		tabl[8][0] = oInver(oOr(tabl[6][0], tabl[7][0]));
		tabl[8][2] = oInver(oOr(tabl[6][2], tabl[7][2]));
		tabl[8][1] = oInver(oOr(tabl[6][1], tabl[7][1]));
		
		tabl[9][0] = oInver(tabl[7][0]);
		tabl[9][2] = oInver(tabl[7][2]);
		tabl[9][1] = oInver(tabl[7][1]);

		tabl[10][0] = oOr(tabl[8][0], tabl[9][0]);
		tabl[10][2] = oOr(tabl[8][2], tabl[9][2]);
		tabl[10][1] = oOr(tabl[8][1], tabl[9][1]);

		std::cout << "a = " << inp[0][0] << " - " << inp[0][1] << std::endl;
		std::cout << "b = " << inp[1][0] << " - " << inp[1][1] << std::endl;
		std::cout << "c = " << inp[2][0] << " - " << inp[2][1] << std::endl;
		std::cout << "d = " << inp[3][0] << " - " << inp[3][1] << std::endl;

		output(tabl);
	}
}

int main() {
	setlocale(LC_ALL, "");	
	int inp[4][2] = {
		/* a */	{ 1, 1 },
		/* b */ { 1, 0 },
		/* c */	{ 0, 1 },
		/* d */ { 0, 1 }
	};

	for3::execute(inp);
	std::cout << std::endl;
	for5::execute(inp);

	system("pause");
	return 0;
}