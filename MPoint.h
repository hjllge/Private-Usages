#pragma once
#ifndef _MPOINT_H_
#define _MPOINT_H_

class MPoint {
	long x, y;
public:
	MPoint() {}
	MPoint(int x, int y);
	MPoint(int n);					//인수 하나만 받는 생성자를 변환 생성자라고 한다, explicit을 붙이면 명시적인 호출만 허용한다. (+3불가)
	void PrintPos(void) const;
	MPoint operator +(const MPoint &pt) const;		//소속 MPoint:: 안써줌, x, y가 바뀌지 않으므로 const
	MPoint operator -(const MPoint &pt) const;
	MPoint operator +(const int n) const;
	MPoint operator -(const int n) const;

	friend MPoint operator +(int n, const MPoint &pt);	//관련은 있지만 멤버함수는 아니야! => friend
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