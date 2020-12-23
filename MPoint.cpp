#include <iostream>
using namespace std;
#include "MPoint.h"


MPoint::MPoint(int x, int y) {	//콜론초기화를 써도 되지만 상속에서는 콜론초기화가 안됨
	this->x = x;
	this->y = y;
}
MPoint::MPoint(int n) {
	x = y = n;
}
void MPoint:: PrintPos(void) const {
	cout << x << " " << y << endl;
}

MPoint MPoint::operator +(const MPoint &pt) const {	//오브젝트 생성 방지를 위해 &, &쓰면 임시객체도 받기 위해서 const로 받아야함
	MPoint temp(this->x + pt.x, this->y + pt.y);
	return temp;
}
MPoint MPoint::operator -(const MPoint &pt) const {	//오브젝트 생성 방지를 위해 &, &쓰면 const로 받아야함
	MPoint temp(this->x - pt.x, this->y - pt.y);
	return temp;
}
MPoint MPoint::operator +(const int n) const {
	MPoint temp(this->x + n, this->y + n);
	return temp;
}
MPoint MPoint::operator -(const int n) const {
	MPoint temp(this->x - n, this->y - n);
	return temp;
}

MPoint operator +(int n, const MPoint &pt) {
//	MPoint temp(n + pt.x, n + pt.y);		//x, y는 접근불가 (friend로 선언하면 가능)
//	return temp;
	return pt + n;
}




ostream &operator <<(ostream &c, const MPoint &pt) {	//ostream c라고 할 수 없음(ostream은 삭제된 생성자)
	pt.PrintPos();
	return c;
}





MPoint &MPoint::operator ++(void) {		//전위연산(호출한 그 자체가 되야함)
	this->x++;	//this생략가능
	this->y++;	//this생략가능
	return *this;
}
const MPoint MPoint::operator ++(int dummy) {		//후위연산(이거는 value로 가야함!)
	this->x++;	//this생략가능
	this->y++;	//this생략가능
	return *this - 1;
}

MPoint &MPoint::operator --(void) {		//전위연산(호출한 그 자체가 되야함)
	this->x--;	//this생략가능
	this->y--;	//this생략가능
	return *this;
}
const MPoint MPoint::operator --(int dummy) {		//후위연산(이거는 value로 가야함!)
	this->x--;	//this생략가능
	this->y--;	//this생략가능
	return *this + 1;
}

/*
//inline화 하기 위해 헤더파일에 선언
bool MPoint::operator ==(const MPoint &pt) {
	return (bool)(x == pt.x && y == pt.y);
}
bool MPoint::operator !=(const MPoint &pt) {
	//return (bool)!(*this == pt);
	return (bool)!(operator ==(pt));	//강사님은 이렇게
}
*/