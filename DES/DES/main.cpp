//DES加密算法
//作者：M.kd
//邮箱：1132269071@qq.com

#include "header.h"

int Z[64], N[64];//初始置换和逆初始置换

int main()
{
	int i;
	bool flag;
	char* A16, * B16, * K16, * Output;
	int* A2, * B2;
	A16 = (char*)malloc(16 * sizeof(char));
	B2 = (int*)malloc(64 * sizeof(int));
	B16 = (char*)malloc(16 * sizeof(char));
	K16 = (char*)malloc(16 * sizeof(char));

	for (i = 0; i < 16; i++) {
		A16[i] = '\0';
	}
	for (i = 0; i < 64; i++) {
		B2[i] = 0;
	}
	for (i = 0; i < 16; i++) {
		B16[i] = '\0';
	}

	init();//计算初始置换和逆初始置换矩阵

	cout << "请选择加密或解密:\n0----加密 1----解密" << endl;
	cin >> flag;
	cout << "请输入十六进制明文/密文:" << endl;
	cin >> A16;
	A2 = o2B(A16);//明文转二进制

	for (i = 0; i < 64; i++) {
		B2[i] = A2[Z[i] - 1];
	}//初始置换

	cout << "\n请输入16位十六进制密钥:" << endl;
	cin >> K16;
	Output = DES(B2, K16, flag);//加密算法
	cout << "加密/解密结果为:\n" << Output << endl;

	system("pause");
	return 0;
}
