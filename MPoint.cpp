#include <iostream>
using namespace std;
#include "MPoint.h"


MPoint::MPoint(int x, int y) {	//�ݷ��ʱ�ȭ�� �ᵵ ������ ��ӿ����� �ݷ��ʱ�ȭ�� �ȵ�
	this->x = x;
	this->y = y;
}
MPoint::MPoint(int n) {
	x = y = n;
}
void MPoint:: PrintPos(void) const {
	cout << x << " " << y << endl;
}

MPoint MPoint::operator +(const MPoint &pt) const {	//������Ʈ ���� ������ ���� &, &���� �ӽð�ü�� �ޱ� ���ؼ� const�� �޾ƾ���
	MPoint temp(this->x + pt.x, this->y + pt.y);
	return temp;
}
MPoint MPoint::operator -(const MPoint &pt) const {	//������Ʈ ���� ������ ���� &, &���� const�� �޾ƾ���
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
//	MPoint temp(n + pt.x, n + pt.y);		//x, y�� ���ٺҰ� (friend�� �����ϸ� ����)
//	return temp;
	return pt + n;
}




ostream &operator <<(ostream &c, const MPoint &pt) {	//ostream c��� �� �� ����(ostream�� ������ ������)
	pt.PrintPos();
	return c;
}





MPoint &MPoint::operator ++(void) {		//��������(ȣ���� �� ��ü�� �Ǿ���)
	this->x++;	//this��������
	this->y++;	//this��������
	return *this;
}
const MPoint MPoint::operator ++(int dummy) {		//��������(�̰Ŵ� value�� ������!)
	this->x++;	//this��������
	this->y++;	//this��������
	return *this - 1;
}

MPoint &MPoint::operator --(void) {		//��������(ȣ���� �� ��ü�� �Ǿ���)
	this->x--;	//this��������
	this->y--;	//this��������
	return *this;
}
const MPoint MPoint::operator --(int dummy) {		//��������(�̰Ŵ� value�� ������!)
	this->x--;	//this��������
	this->y--;	//this��������
	return *this + 1;
}

/*
//inlineȭ �ϱ� ���� ������Ͽ� ����
bool MPoint::operator ==(const MPoint &pt) {
	return (bool)(x == pt.x && y == pt.y);
}
bool MPoint::operator !=(const MPoint &pt) {
	//return (bool)!(*this == pt);
	return (bool)!(operator ==(pt));	//������� �̷���
}
*/