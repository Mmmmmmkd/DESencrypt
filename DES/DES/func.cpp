#include "header.h"

void init() {
	Z[0] = 58;
	Z[32] = 57;
	N[0] = 40;
	N[1] = 8;
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 8; j++) {
			Z[8 * i + j] = Z[0] - 8 * j + 2 * i;
		}
	}
	for (i = 4; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			Z[8 * i + j] = Z[32] - 8 * j + 2 * (i - 4);
		}
	}//��ʼ��IP

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j = j + 2) {
			N[8 * i + j] = N[0] - i + 4 * j;
		}
		for (j = 1; j < 8; j = j + 2) {
			N[8 * i + j] = N[1] - i + 4 * (j - 1);
		}
	}//��ʼ����IP
}

int* o2B(char* A16) {//ʮ������ת������;
	int i;
	int* A2;
	A2 = (int*)malloc(64 * sizeof(int));

	for (i = 0; i < 64; i++) {
		A2[i] = '0';
	}

	for (i = 0; i < 16; i++) {
		if (A16[i] == '0') {
			A2[4 * i] = 0;
			A2[4 * i + 1] = 0;
			A2[4 * i + 2] = 0;
			A2[4 * i + 3] = 0;
		}
		if (A16[i] == '1') {
			A2[4 * i] = 0;
			A2[4 * i + 1] = 0;
			A2[4 * i + 2] = 0;
			A2[4 * i + 3] = 1;
		}
		if (A16[i] == '2') {
			A2[4 * i] = 0;
			A2[4 * i + 1] = 0;
			A2[4 * i + 2] = 1;
			A2[4 * i + 3] = 0;
		}
		if (A16[i] == '3') {
			A2[4 * i] = 0;
			A2[4 * i + 1] = 0;
			A2[4 * i + 2] = 1;
			A2[4 * i + 3] = 1;
		}
		if (A16[i] == '4') {
			A2[4 * i] = 0;
			A2[4 * i + 1] = 1;
			A2[4 * i + 2] = 0;
			A2[4 * i + 3] = 0;
		}
		if (A16[i] == '5') {
			A2[4 * i] = 0;
			A2[4 * i + 1] = 1;
			A2[4 * i + 2] = 0;
			A2[4 * i + 3] = 1;
		}
		if (A16[i] == '6') {
			A2[4 * i] = 0;
			A2[4 * i + 1] = 1;
			A2[4 * i + 2] = 1;
			A2[4 * i + 3] = 0;
		}
		if (A16[i] == '7') {
			A2[4 * i] = 0;
			A2[4 * i + 1] = 1;
			A2[4 * i + 2] = 1;
			A2[4 * i + 3] = 1;
		}
		if (A16[i] == '8') {
			A2[4 * i] = 1;
			A2[4 * i + 1] = 0;
			A2[4 * i + 2] = 0;
			A2[4 * i + 3] = 0;
		}
		if (A16[i] == '9') {
			A2[4 * i] = 1;
			A2[4 * i + 1] = 0;
			A2[4 * i + 2] = 0;
			A2[4 * i + 3] = 1;
		}
		if (A16[i] == 'a' || A16[i] == 'A') {
			A2[4 * i] = 1;
			A2[4 * i + 1] = 0;
			A2[4 * i + 2] = 1;
			A2[4 * i + 3] = 0;
		}
		if (A16[i] == 'b' || A16[i] == 'B') {
			A2[4 * i] = 1;
			A2[4 * i + 1] = 0;
			A2[4 * i + 2] = 1;
			A2[4 * i + 3] = 1;
		}
		if (A16[i] == 'c' || A16[i] == 'C') {
			A2[4 * i] = 1;
			A2[4 * i + 1] = 1;
			A2[4 * i + 2] = 0;
			A2[4 * i + 3] = 0;
		}
		if (A16[i] == 'd' || A16[i] == 'D') {
			A2[4 * i] = 1;
			A2[4 * i + 1] = 1;
			A2[4 * i + 2] = 0;
			A2[4 * i + 3] = 1;
		}
		if (A16[i] == 'e' || A16[i] == 'E') {
			A2[4 * i] = 1;
			A2[4 * i + 1] = 1;
			A2[4 * i + 2] = 1;
			A2[4 * i + 3] = 0;
		}
		if (A16[i] == 'f' || A16[i] == 'F') {
			A2[4 * i] = 1;
			A2[4 * i + 1] = 1;
			A2[4 * i + 2] = 1;
			A2[4 * i + 3] = 1;
		}
	}

	return A2;
}

char* B2o(int* A2) {//������תʮ������;
	int i;
	char* A16;
	A16 = (char*)malloc(17 * sizeof(char));

	for (i = 0; i < 17; i++) {
		A16[i] = '\0';
	}

	for (i = 0; i < 16; i++) {
		if (A2[4 * i] == 0 &&
			A2[4 * i + 1] == 0 &&
			A2[4 * i + 2] == 0 &&
			A2[4 * i + 3] == 0)
			A16[i] = '0';
		if (A2[4 * i] == 0 &&
			A2[4 * i + 1] == 0 &&
			A2[4 * i + 2] == 0 &&
			A2[4 * i + 3] == 1)
			A16[i] = '1';
		if (A2[4 * i] == 0 &&
			A2[4 * i + 1] == 0 &&
			A2[4 * i + 2] == 1 &&
			A2[4 * i + 3] == 0)
			A16[i] = '2';
		if (A2[4 * i] == 0 &&
			A2[4 * i + 1] == 0 &&
			A2[4 * i + 2] == 1 &&
			A2[4 * i + 3] == 1)
			A16[i] = '3';
		if (A2[4 * i] == 0 &&
			A2[4 * i + 1] == 1 &&
			A2[4 * i + 2] == 0 &&
			A2[4 * i + 3] == 0)
			A16[i] = '4';
		if (A2[4 * i] == 0 &&
			A2[4 * i + 1] == 1 &&
			A2[4 * i + 2] == 0 &&
			A2[4 * i + 3] == 1)
			A16[i] = '5';
		if (A2[4 * i] == 0 &&
			A2[4 * i + 1] == 1 &&
			A2[4 * i + 2] == 1 &&
			A2[4 * i + 3] == 0)
			A16[i] = '6';
		if (A2[4 * i] == 0 &&
			A2[4 * i + 1] == 1 &&
			A2[4 * i + 2] == 1 &&
			A2[4 * i + 3] == 1)
			A16[i] = '7';
		if (A2[4 * i] == 1 &&
			A2[4 * i + 1] == 0 &&
			A2[4 * i + 2] == 0 &&
			A2[4 * i + 3] == 0)
			A16[i] = '8';
		if (A2[4 * i] == 1 &&
			A2[4 * i + 1] == 0 &&
			A2[4 * i + 2] == 0 &&
			A2[4 * i + 3] == 1)
			A16[i] = '9';
		if (A2[4 * i] == 1 &&
			A2[4 * i + 1] == 0 &&
			A2[4 * i + 2] == 1 &&
			A2[4 * i + 3] == 0)
			A16[i] = 'A';
		if (A2[4 * i] == 1 &&
			A2[4 * i + 1] == 0 &&
			A2[4 * i + 2] == 1 &&
			A2[4 * i + 3] == 1)
			A16[i] = 'B';
		if (A2[4 * i] == 1 &&
			A2[4 * i + 1] == 1 &&
			A2[4 * i + 2] == 0 &&
			A2[4 * i + 3] == 0)
			A16[i] = 'C';
		if (A2[4 * i] == 1 &&
			A2[4 * i + 1] == 1 &&
			A2[4 * i + 2] == 0 &&
			A2[4 * i + 3] == 1)
			A16[i] = 'D';
		if (A2[4 * i] == 1 &&
			A2[4 * i + 1] == 1 &&
			A2[4 * i + 2] == 1 &&
			A2[4 * i + 3] == 0)
			A16[i] = 'E';
		if (A2[4 * i] == 1 &&
			A2[4 * i + 1] == 1 &&
			A2[4 * i + 2] == 1 &&
			A2[4 * i + 3] == 1)
			A16[i] = 'F';
	}

	return A16;
}

void loop(int* arr) {//28λ����ѭ������1λ����
	int i, a;
	a = arr[0];
	for (i = 0; i < 28; i++) {
		arr[i] = arr[i + 1];
	}
	arr[27] = a;
}

int* key(char* okey) {//�˸�����Կ˳��洢�����ص�һ������Կͷ��ַ
	int i, j, * bkey, * C0, * D0;
	C0 = (int*)malloc(28 * sizeof(int));
	D0 = (int*)malloc(28 * sizeof(int));
	int C[28] = {
		57, 49, 41, 33, 25, 17, 9,
		1, 58, 50, 42, 34, 26, 18,
		10, 2, 59, 51, 43, 35, 27,
		19, 11, 3, 60, 52, 44, 36
	};
	int D[28] = {
		63, 55, 47, 39, 31, 33, 15,
		7, 62, 54, 46, 38, 30, 22,
		14, 6, 61, 53, 45, 37, 29,
		21, 13, 5, 28, 20, 12, 4
	};//�û�ѡ��1
	int K[48] = {
		14, 17, 11, 24, 1, 5,
		3, 28, 15, 6, 21, 10,
		23, 19, 12, 4, 26, 8,
		16, 7, 27, 20, 13, 2,
		41, 52, 31, 37, 47, 55,
		30, 40, 51, 45, 33, 48,
		44, 49, 39, 56, 34, 53,
		46, 42, 50, 36, 29, 32
	};//�û�ѡ��2
	int* skey;
	skey = (int*)malloc(16 * 48 * sizeof(int));
	bkey = o2B(okey);

	for (i = 0; i < 28; i++) {
		C0[i] = bkey[C[i] - 1];
		D0[i] = bkey[D[i] - 1];
	}//��C0,D0��ֵ

	bkey = NULL;

	for (i = 0; i < 16; i++) {
		loop(C0);
		loop(D0);
		if (i != 0 && i != 1 && i != 8 && i != 15) {
			loop(C0);
			loop(D0);
		}//����1,2,9,16�ֶ���������λ
		for (j = 0; j < 48; j++) {
			if (K[j] < 29) {
				skey[48 * i + j] = C0[K[j] - 1];
			}
			else {
				skey[48 * i + j] = D0[K[j] - 29];
			}
		}
	}

	return skey;
}
