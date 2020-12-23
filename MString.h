#pragma once
#ifndef _MString_
#define _MString_
class MString {
	char *m_str;
public:
	MString();
	MString(const char *str);
	~MString();
	const char *GetString(void) const { return m_str; }		//앞에 const를 써서 m_str이 바뀌는 것을 못하게끔 강제
};

#endif