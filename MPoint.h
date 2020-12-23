#pragma once
#ifndef _MPOINT_H_
#define _MPOINT_H_

class MPoint {
	long x, y;
public:
	MPoint() {}
	MPoint(int x, int y);
	MPoint(int n);					//�μ� �ϳ��� �޴� �����ڸ� ��ȯ �����ڶ�� �Ѵ�, explicit�� ���̸� ������� ȣ�⸸ ����Ѵ�. (+3�Ұ�)
	void PrintPos(void) const;
	MPoint operator +(const MPoint &pt) const;		//�Ҽ� MPoint:: �Ƚ���, x, y�� �ٲ��� �����Ƿ� const
	MPoint operator -(const MPoint &pt) const;
	MPoint operator +(const int n) const;
	MPoint operator -(const int n) const;

	friend MPoint operator +(int n, const MPoint &pt);	//������ ������ ����Լ��� �ƴϾ�! => friend
	friend ostream &operator <<(ostream &c, const MPoint &pt);

	MPoint &operator ++(void);
	const MPoint operator ++(int dummy);
	MPoint &operator --(void);
	const MPoint operator --(int dummy);
/*
	bool operator ==(const MPoint &pt);
	bool operator !=(const MPoint &pt);
*/

	inline bool operator ==(const MPoint &pt) const
	{ return (bool)(x == pt.x && y == pt.y);}
	inline bool operator !=(const MPoint &pt) const
	{ return (bool)!(operator ==(pt)); }
};

#endif