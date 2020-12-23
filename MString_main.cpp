#include <iostream>
using namespace std;
#include "MString.h"

int main(void) {
	MString aa("seoul"), bb;
	bb = aa;
	cout << bb.GetString() << endl;
	//이렇게 하면 런타임 오류남(중복으로 소멸자에서 지우게 되므로)
}