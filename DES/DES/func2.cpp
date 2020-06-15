#include "header.h"

int sbox[8][4][16] = {
	// S1盒
	{
		{14, 4,	13,	 1,  2, 15, 11,  8,  3, 10,  6, 12,  5,  9,  0,  7},
		{0, 15,  7,  4, 14,  2, 13,  1, 10,  6, 12, 11,  9,  5,  3,  8},
		{4,  1, 14,  8, 13,  6,  2, 11, 15, 12,  9,  7,  3, 10,  5,  0},
		{15, 12,  8,  2,  4,  9,  1,  7,  5, 11,  3, 14, 10,  0,  6, 13}
	},
	// S2盒
	{
		{15,  1,  8, 14,  6, 11,  3,  4,  9,  7,  2, 13, 12,  0,  5, 10},
		{3, 13,  4,  7, 15,  2,  8, 14, 12,  0,  1, 10,  6,  9, 11,  5},
		{0, 14,  7, 11, 10,  4, 13,  1,  5,  8, 12,  6,  9,  3,  2, 15},
		{13,  8, 10,  1,  3, 15,  4,  2, 11,  6,  7, 12,  0,  5, 14,  9}
	},
	// S3盒
	{
		{10,  0,  9, 14,  6,  3, 15,  5,  1, 13, 12,  7, 11,  4,  2,  8},
		{13,  7,  0,  9,  3,  4,  6, 10,  2,  8,  5, 14, 12, 11, 15,  1},
		{13,  6,  4,  9,  8, 15,  3,  0, 11,  1,  2, 12,  5, 10, 14,  7},
		{1, 10, 13,  0,  6,  9,  8,  7,  4, 15, 14,  3, 11,  5,  2, 12}
	},
	// S4盒
	{
		{7, 13, 14,  3,  0,  6,  9, 10,  1,  2,  8,  5, 11, 12,  4, 15},
		{13,  8, 11,  5,  6, 15,  0,  3,  4,  7,  2, 12,  1, 10, 14,  9},
		{10,  6,  9,  0, 12, 11,  7, 13, 15,  1,  3, 14,  5,  2,  8,  4},
		{3, 15,  0,  6, 10,  1, 13,  8,  9,  4,  5, 11, 12,  7,  2, 14}
	},
	// S5盒
	{
		{2, 12,  4,  1,  7, 10, 11,  6,  8,  5,  3, 15, 13,  0, 14,  9},
		{14, 11,  2, 12,  4,  7, 13,  1,  5,  0, 15, 10,  3,  9,  8,  6},
		{4,  2,  1, 11, 10, 13,  7,  8, 15,  9, 12,  5,  6,  3,  0, 14},
		{11,  8, 12,  7,  1, 14,  2, 13,  6, 15,  0,  9, 10,  4,  5,  3}
	},
	// S6盒
	{
		{12,  1, 10, 15,  9,  2,  6,  8,  0, 13,  3,  4, 14,  7,  5, 11},
		{10, 15,  4,  2,  7, 12,  9,  5,  6,  1, 13, 14,  0, 11,  3,  8},
		{9, 14, 15,  5,  2,  8, 12,  3,  7,  0,  4, 10,  1, 13, 11,  6},
		{4,  3,  2, 12,  9,  5, 15, 10, 11, 14,  1,  7,  6,  0,  8, 13}
	},
	// S7盒
	{
		{4, 11,  2, 14, 15,  0,  8, 13,  3, 12,  9,  7,  5, 10,  6,  1},
		{13,  0, 11,  7,  4,  9,  1, 10, 14,  3,  5, 12,  2, 15,  8,  6},
		{1,  4, 11, 13, 12,  3,  7, 14, 10, 15,  6,  8,  0,  5,  9,  2},
		{6, 11, 13,  8,  1,  4, 10,  7,  9,  5,  0, 15, 14,  2,  3, 12}
	},
	// S8盒
	{
		{13,  2,  8,  4,  6, 15, 11,  1, 10,  9,  3, 14,  5,  0, 12,  7},
		{1, 15, 13,  8, 10,  3,  7,  4, 12,  5,  6, 11,  0, 14,  9,  2},
		{7, 11,  4,  1,  9, 12, 14,  2,  0,  6, 10, 13, 15,  3,  5,  8},
		{2,  1, 14,  7,  4, 10,  8, 13, 15, 12,  9,  0,  3,  5,  6, 11}
	}
};

int P[32] = {
	16, 7, 20, 21,
	29, 12, 28, 17,
	1, 15, 23, 26,
	5, 18, 31, 10,
	2, 8, 24, 14,
	32, 27, 3, 9,
	19, 13, 30, 6,
	22, 11, 4, 25
};

int* Extend(int* R) {//扩展运算
	int i;
	int* Rex;
	Rex = (int*)malloc(48 * sizeof(int));
	if (Rex) {
		for (i = 1; i < 47; i++) {
			if (i > 41) {
				Rex[i] = R[i - 15];
			}
			if (i > 35 && i <= 41) {
				Rex[i] = R[i - 13];
			}
			if (i > 29 && i <= 35) {
				Rex[i] = R[i - 11];
			}
			if (i > 23 && i <= 29) {
				Rex[i] = R[i - 9];
			}
			if (i > 17 && i <= 23) {
				Rex[i] = R[i - 7];
			}
			if (i > 11 && i <= 17) {
				Rex[i] = R[i - 5];
			}
			if (i > 5 && i <= 11) {
				Rex[i] = R[i - 3];
			}
			if (i <= 5) {
				Rex[i] = R[i - 1];
			}
		}

		Rex[0] = R[31];
		Rex[47] = R[0];
	}
	else {
		exit(1);
	}
	return Rex;
}

int* d2b(int A16) {//十进制转二进制
	int* A2;
	A2 = (int*)malloc(4 * sizeof(int));
	if (A2) {
		//
	}
	else {
		exit(1);
	}
	if (A16 == 0) {
		A2[0] = 0;
		A2[1] = 0;
		A2[2] = 0;
		A2[3] = 0;
	}
	if (A16 == 1) {
		A2[0] = 0;
		A2[1] = 0;
		A2[2] = 0;
		A2[3] = 1;
	}
	if (A16 == 2) {
		A2[0] = 0;
		A2[1] = 0;
		A2[2] = 1;
		A2[3] = 0;
	}
	if (A16 == 3) {
		A2[0] = 0;
		A2[1] = 0;
		A2[2] = 1;
		A2[3] = 1;
	}
	if (A16 == 4) {
		A2[0] = 0;
		A2[1] = 1;
		A2[2] = 0;
		A2[3] = 0;
	}
	if (A16 == 5) {
		A2[0] = 0;
		A2[1] = 1;
		A2[2] = 0;
		A2[3] = 1;
	}
	if (A16 == 6) {
		A2[0] = 0;
		A2[1] = 1;
		A2[2] = 1;
		A2[3] = 0;
	}
	if (A16 == 7) {
		A2[0] = 0;
		A2[1] = 1;
		A2[2] = 1;
		A2[3] = 1;
	}
	if (A16 == 8) {
		A2[0] = 1;
		A2[1] = 0;
		A2[2] = 0;
		A2[3] = 0;
	}
	if (A16 == 9) {
		A2[0] = 1;
		A2[1] = 0;
		A2[2] = 0;
		A2[3] = 1;
	}
	if (A16 == 10) {
		A2[0] = 1;
		A2[1] = 0;
		A2[2] = 1;
		A2[3] = 0;
	}
	if (A16 == 11) {
		A2[0] = 1;
		A2[1] = 0;
		A2[2] = 1;
		A2[3] = 1;
	}
	if (A16 == 12) {
		A2[0] = 1;
		A2[1] = 1;
		A2[2] = 0;
		A2[3] = 0;
	}
	if (A16 == 13) {
		A2[0] = 1;
		A2[1] = 1;
		A2[2] = 0;
		A2[3] = 1;
	}
	if (A16 == 14) {
		A2[0] = 1;
		A2[1] = 1;
		A2[2] = 1;
		A2[3] = 0;
	}
	if (A16 == 15) {
		A2[0] = 1;
		A2[1] = 1;
		A2[2] = 1;
		A2[3] = 1;
	}
	return A2;
}

int* Sboxcompress(int* M) {//S盒压缩
	int i;
	int* Z, * B;
	Z = (int*)malloc(32 * sizeof(int));
	B = (int*)malloc(4 * sizeof(int));

	if (Z) {
		for (i = 0; i < 8; i++) {
			B = d2b(sbox[i][M[i * 6] * 2 + M[i * 6 + 5]][M[i * 6 + 1] * 8 + M[i * 6 + 2] * 4 + M[i * 6 + 3] * 2 + M[i * 6 + 4]]);
			//d2b的参数是sbox[i][  M[i*6],M[i*6+5]转十进制  ][  M[i*6+1],M[i*6+2],M[i*6+3],M[i*6+4]转十进制  ]
			Z[4 * i] = B[0];
			Z[4 * i + 1] = B[1];
			Z[4 * i + 2] = B[2];
			Z[4 * i + 3] = B[3];
		}
	}
	else {
		exit(1);
	}

	return Z;
}

char* DES(int* P1, char* mkey, bool flag) {//参数为置换后明文和种子密钥,flag控制加密或解密
	int i, j;
	int* skey, * L0, * R0, * M, * Z, * ZP, * Rex;
	L0 = (int*)malloc(32 * sizeof(int));
	R0 = (int*)malloc(32 * sizeof(int));
	M = (int*)malloc(48 * sizeof(int));
	Z = (int*)malloc(32 * sizeof(int));
	ZP = (int*)malloc(32 * sizeof(int));

	skey = key(mkey);

	cout << "十六轮轮密钥为:" << endl;
	for (i = 0; i < 16 * 48; i++) {
		cout << skey[i];
		if (i % 4 == 3) {
			cout << " ";
		}
		if (i % 48 == 47) {
			cout << "" << endl;
		}
	}//展示二进制轮密钥
	
	if (L0) {
		for (i = 0; i < 32; i++) {
			L0[i] = P1[i];
		}
	}
	else {
		exit(1);
	}

	if(R0){
		for (i = 32; i < 64; i++) {
			R0[i - 32] = P1[i];
		}//初始化L0,R0;
	}
	else {
		exit(1);
	}

	if (M) {
		for (i = 0; i < 16; i++) {
			Rex = Extend(R0);//R0扩展运算

			if (flag != 1) {
				for (j = 0; j < 48; j++) {
					M[j] = Rex[j] ^ skey[i * 48 + j];//扩展运算结果和轮密钥异或
				}
			}
			else {
				for (j = 0; j < 48; j++) {
					M[j] = Rex[j] ^ skey[(15 - i) * 48 + j];//逆序输入轮密钥为解密
				}
			}

			Z = Sboxcompress(M);//通过S盒压缩
			if (ZP) {
				for (j = 0; j < 32; j++) {
					ZP[j] = Z[P[j] - 1];
				}//压缩结果P置换

				for (j = 0; j < 32; j++) {
					ZP[j] = ZP[j] ^ L0[j];
				}//置换结果和L0异或

				for (j = 0; j < 32; j++) {
					L0[j] = R0[j];
					R0[j] = ZP[j];
				}
			}
			//L0 = R0;不能用地址交换，指针指向会乱
			//R0 = ZP;下一轮（最后一轮手动调整）
		}
	}
	else {
		exit(1);
	}

	if (ZP) {
		for (i = 0; i < 32; i++) {
			ZP[i] = L0[i];
			L0[i] = R0[i];
			R0[i] = ZP[i];
		}
	}
	else {
		exit(1);
	}
	//ZP = L0;
	//L0 = R0;
	//R0 = ZP;
	//循环中多交换了一次，交换回来

	int* Output1, * Output2;
	char* Output3;
	Output1 = (int*)malloc(64 * sizeof(int));
	Output2 = (int*)malloc(64 * sizeof(int));
	Output3 = (char*)malloc(16 * sizeof(char));

	if (Output1 && Output2 && Output3) {
		for (i = 0; i < 64; i++) {
			Output1[i] = 0;
			Output2[i] = 0;
		}
		for (i = 0; i < 16; i++) {
			Output3[i] = '\0';
		}

		for (i = 0; i < 32; i++) {
			Output1[i] = L0[i];
		}
		for (i = 0; i < 32; i++) {
			Output1[i + 32] = R0[i];
		}

		for (i = 0; i < 64; i++) {
			Output2[i] = Output1[N[i] - 1];
		}//逆置换IP-1
	}
	else {
		exit(1);
	}

	Output3 = B2o(Output2);

	return Output3;
}//功能能运行之后记得优化释放内存
