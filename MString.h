#pragma once
#ifndef _MString_
#define _MString_
class MString {
	char *m_str;
public:
	MString();
	MString(const char *str);
	~MString();
	const char *GetString(void) const { return m_str; }		//�տ� const�� �Ἥ m_str�� �ٲ�� ���� ���ϰԲ� ����
};

#endif