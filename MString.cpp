#include <string.h>
#include "MString.h"

MString::MString() {
	m_str = (char *)"";	//�ʿ���!
}

MString::MString(const char *str) {
	size_t len;
	len = ::strlen(str);
	if (len == 0) {
		m_str = (char *)"";	//= NULL���� ����(null���� �Ź� üũ�ؾ��ϹǷ�), "" = {'\0'}
	}
	else {
		m_str = new char[++len];
		::strcpy_s(m_str, len, str);
	}
}

MString::~MString() {
	if (*m_str != '\0') {
		delete[] m_str;
	}
}