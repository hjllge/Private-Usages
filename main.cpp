#include <iostream>
using namespace std;
#include "MPoint.h"

////���׿�����
//int main(void) {
//	MPoint aa(3, 5), bb(5), cc;
//	cc = aa + bb;	//�������� ���� �� cc = aa.operator +(bb)
//	cc.PrintPos();
//
//	cc = aa + 3;	//���� �������� ������ cc = aa.operator +(MPoint(3))���� ������, ������Ʈ�� ���� �𸣰� ����, ��ȯ �����ڿ� ���� ����
//	cc.PrintPos();
//	cc = aa - 3;
//	cc.PrintPos();
//
//	cc = 3 + aa;	//�����Լ������� �Ұ�, �������� ��������.
//	cc.PrintPos();
//
//	cout << cc << cc;
//}



//���׿�����
int main(void) {
	MPoint aa(3, 5), bb(5), cc;
	++aa;		//aa.operator ++(); �� ��ȯ�ϱ�� ��	//�Ǵ� �������� operator ++(aa);
	cout << aa << endl;

	aa++;		//aa.operator ++(0);�� ��ȯ�ϱ�� ��	//�Ǵ� �������� operator ++(aa, 0); (int �ϳ�)
	cout << aa++ << endl;
/*
	//�Ʒ��� �ȵǴ� �� ó��
	int n = 5;
	++n = 10;
	n++ = 10;

	//�ؿ��� �ȵ�(const�� �������ν�)
	++aa - bb;
	aa++ = bb;
*/

	if (aa == bb) {
		cout << "equal" << endl;
	}
	if (aa != bb) {
		cout << "not equal" << endl;
	}
}
