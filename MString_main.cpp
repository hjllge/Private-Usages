#include <iostream>
using namespace std;
#include "MString.h"

int main(void) {
	MString aa("seoul"), bb;
	bb = aa;
	cout << bb.GetString() << endl;
	//�̷��� �ϸ� ��Ÿ�� ������(�ߺ����� �Ҹ��ڿ��� ����� �ǹǷ�)
}