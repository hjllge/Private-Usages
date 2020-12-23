#include <iostream>
using namespace std;
#include "MPoint.h"

////이항연산자
//int main(void) {
//	MPoint aa(3, 5), bb(5), cc;
//	cc = aa + bb;	//지역으로 선언 시 cc = aa.operator +(bb)
//	cc.PrintPos();
//
//	cc = aa + 3;	//따로 정의하지 않으면 cc = aa.operator +(MPoint(3))으로 번역됨, 오브젝트가 나도 모르게 생성, 변환 생성자에 의해 생성
//	cc.PrintPos();
//	cc = aa - 3;
//	cc.PrintPos();
//
//	cc = 3 + aa;	//지역함수에서는 불가, 전역으로 만들어야함.
//	cc.PrintPos();
//
//	cout << cc << cc;
//}



//단항연산자
int main(void) {
	MPoint aa(3, 5), bb(5), cc;
	++aa;		//aa.operator ++(); 로 변환하기로 함	//또는 전역으로 operator ++(aa);
	cout << aa << endl;

	aa++;		//aa.operator ++(0);로 변환하기로 함	//또는 전역으로 operator ++(aa, 0); (int 하나)
	cout << aa++ << endl;
/*
	//아래가 안되는 것 처럼
	int n = 5;
	++n = 10;
	n++ = 10;

	//밑에도 안됨(const를 붙임으로써)
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
