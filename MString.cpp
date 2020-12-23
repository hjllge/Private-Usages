#include <string.h>
#include "MString.h"

MString::MString() {
	m_str = (char *)"";	//필요함!
}

MString::MString(const char *str) {
	size_t len;
	len = ::strlen(str);
	if (len == 0) {
		m_str = (char *)"";	//= NULL보다 좋음(null인지 매번 체크해야하므로), "" = {'\0'}
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