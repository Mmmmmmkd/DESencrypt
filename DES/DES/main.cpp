//DES�����㷨
//���ߣ�M.kd
//���䣺1132269071@qq.com

#include "header.h"

int Z[64], N[64];//��ʼ�û������ʼ�û�

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

	init();//�����ʼ�û������ʼ�û�����

	cout << "��ѡ����ܻ����:\n0----���� 1----����" << endl;
	cin >> flag;
	cout << "������ʮ����������/����:" << endl;
	cin >> A16;
	A2 = o2B(A16);//����ת������

	for (i = 0; i < 64; i++) {
		B2[i] = A2[Z[i] - 1];
	}//��ʼ�û�

	cout << "\n������16λʮ��������Կ:" << endl;
	cin >> K16;
	Output = DES(B2, K16, flag);//�����㷨
	cout << "����/���ܽ��Ϊ:\n" << Output << endl;

	system("pause");
	return 0;
}
