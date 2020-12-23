//#include <stdio.h>
////헤더파일에 저장
//struct st {
//	//멤버 변수
//private:
//	int no;
//	char ch;
//
//public:
//	//멤버 함수 (인수의 갯수가 줄어드는 효과)
//	void PrintStruct() const;
//	void InitStruct(int n, char c);
//};
//
////st에 해당하는 함수라 st::을 붙침 (구조체 멤버에 접근 가능)
//void st::PrintStruct() const {	//const : 읽기만 하는 용도의 함수다 라는 의미
//	printf("%d %c\n", no, ch);
//}
//
//void st::InitStruct(int n, char c) {
//	if (n % 2 == 0) n++;
//	no = n;
//	ch = c;
//}
//
///*
//선언문은 필요없게됨
//void InitStruct(struct st *aa, int n, char c);		//st에 담아올 용도
//void PrintStruct(const struct st *t);				//st를 읽기만 하는 용도, 가독성 up!
//*/
//int main(void) {
//	st aa;			//선언부도 struct 생략, 단순한 방식으로 바뀜(generalize)
//	//void InitStruct(struct st *aa, int n, char c);	//여기 선언도 가능(main에서만 불림)
//
//	printf("%d\n", sizeof(aa));
//	aa.InitStruct(5, 'A');
//	aa.PrintStruct();
//}


//#include <iostream>
//#include <iomanip>
//using namespace std;
//
//int main(void) {
//	int no = 10;
//	 
//	cout << "hello world." << endl;
//	cout << no << endl;
//	cout << hex << 10 << endl;
//	cout << left << setw(10) << "seoul" << "KOREA" << endl;				//왼쪽 정렬(?)
//	cout << fixed << setprecision(2) << 3.141592653589793238 << endl;	//소수 2자리까지 (fixed는 고정 소수점)
//}


//#include <iostream>
//using namespace std;
//
//int main(void)
//{
//	char name[10];
//	int age;
//	char addr[20];
//
//	cout << "Name:";
//	cin >> name;
//	cout << "Age:";
//	cin >> age; // scanf("%d", &age);
//	cout << "Addr:";
////	cin >> addr; // scanf("%[a-zA-Z0-9 ]s", addr);
//	cin.ignore();	//fflush()
//	cin.getline(addr, 20);
//	cout << name << '\t' << age << '\t' << addr << endl;
//}



//#include <iostream>
//using namespace std;
//
//int no = 10;
//
//int main(void) {
//	int no = 5;
//	cout << no << endl;
//	cout << ::no << endl;	//::(scope)을 붙여 전역변수 우선 접근, 동일한 지역 no가 존재하지 않더라도 전역을 접근할때는 ::을 붙이는게 좋다.
//
//}

//#include <stdio.h>
//#include <iostream>
//using namespace std;
//struct st {
//	int no;
//	void printf(void);
//};
//
//void st::printf(void) {
//	//cout << no << endl;
//	::printf("%d\n", no);	//::를 안붙이면 지역의 printf가 우선 -> ::를 붙여줘야함
//}
//
//int main(void) {
//	st aa;
//	aa.printf();
//}


//#include <iostream>
//using namespace std;
//
//int main(void) {
//	const int c = 5;	//초기값을 설정해야 컴파일 에러가 나오지 않는다.(논리적으로 더 맞음) 만약 volatile을 붙이면 최적화가 금지되어서 다시 변경 가능한 상수로 바뀜
//	char str[c];		//정말 c가 상수화 됨(컴파일 타임에 c는 5로 평가됨)
//
//	//const int *p = &c;		//c의 타입은 const integer니까 const int *
//	//*p = 10;				//p 선언 시 앞에 const가 붙었으므로 const변수에 대입 연산 불가 => 결국 c값을 바꿀 수 없다
//
//	int *p = (int *)&c;		//강제 변환
//	*p = 10;				//바꾸고야 말거야!
//	cout << c << endl;		//c는 그대로 5 출력(컴파일 타임에 c를 5로 치환시킴, c는 계속 5를 유지한다고 보면 됨)
//	cout << *p << endl;		//c는 바뀐게 맞음..(바꿨으니 의지대로 바뀜)
//}



//#include <iostream>
//using namespace std;
//
//int main(void) {
//	int n = 5, k = 6;
//	const int *p = &n;	//int *가 const (초기값 없어도 컴파일 에러는 x)
//	//*p = 10;			//불가
//
//	int * const q = &k;		//q가 const (반드시 초기값)
//	*q = 10;				//가능	(&q의 자료형 = int * const *)
//	//q = &n;					//불가
//}



//#include <iostream>
//#include <stdlib.h>
//using namespace std;
//
//void Swap(int *a, int *b);
//void Swap(double *a, double *b);
//void MemCpy(void *dst, const void *sou, size_t cnt);
//void Swap(void *a, void *b, size_t size);
//
//int main(void) {
//	int n = 5, k = 6;
//	Swap(&n, &k);
//	cout << n << " " << k << endl;
//	double d1 = 3.14;
//	double d2 = 2.54;
//	Swap(&d1, &d2);
//	cout << d1 << " " << d2 << endl;
//}
//
//void Swap(int *a, int *b) {
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//void Swap(double *a, double *b) {
//	double temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
//void MemCpy(void *dst, const void *sou, size_t cnt) {		//cnt = byte 수, byte단위로 복사됨
//	char *d = (char *)dst;
//	const char *s = (const char *)sou;
//	for (;cnt > 0;cnt--) {
//		*d++ = *s++;
//	}
//}
//void Swap(void *a, void *b, size_t size) {	//size 어쩔 수 없이 필요
//	void * temp = malloc(size);
////	temp = *a;	//void *형은 *연산, ++연산 등이 불가
//	MemCpy(temp, a, size);
//	MemCpy(a, b, size);
//	MemCpy(b, temp, size);
//	free(temp);
//}



//#include <iostream>
//#include <stdio.h>
//using namespace std;
//
//struct stream {
//	void printf(int n);
//	void printf(char c);
//	void printf(double d);
//	void printf(const char *str);
//};
//
//void stream::printf(int n) {
//	::printf("%d", n);
//}
//void stream::printf(char c) {
//	::printf("%c", c);
//}
//void stream::printf(double d) {
//	::printf("%lf", d);
//}
//void stream::printf(const char *str) {
//	::printf("%s", str);
//}
//
//int main(void) {
//	stream c;
//	c.printf(5);		//cout << 5 cout도 중복 정의가 되어있음
//	c.printf('A');		//
//	c.printf(3.14);		//
//	c.printf("seoul");	//
//}


///*디폴트 파라미터*/
//#include <iostream>
//using namespace std;
//
//void DisplayDate(int d, int m = 12, int y = 2020);	//디폴트 파라미터값을 오른쪽으로 배치하면 좋음
//int main(void) {
//	DisplayDate(24, 12);
//	DisplayDate(25);
//}
//
//void DisplayDate(int d, int m, int y) {				//디폴트 매개변수는 여기에는 적어주지 않음
//	cout << y << "/" << m << "/" << d << endl;
//}


////프로젝트 속성->문자집합을 (원래 멀티바이트에서) 유니코드로 바꿔야 가능
//#include <windows.h>
//
//int MessageBox(LPCWSTR text, LPCWSTR title, UINT nType = MB_OK);
//
//int main(void) {
//	MessageBox(TEXT("test"), TEXT("title"), MB_OKCANCEL);
//	MessageBox(TEXT("test"), TEXT("title"), MB_YESNO);
//	MessageBox(TEXT("test"), TEXT("title"));
//}
//
//int MessageBox(LPCWSTR text, LPCWSTR title, UINT nType) {
//	return MessageBox(NULL, text, title, nType);	//c함수라 중복 정의가 안되니까 이렇게 래핑에서 쓸 수 있다.
//}




#include <iostream>
using namespace std;

int main(void) {
	int n = 5;
	int &k = n;	//int &k는 안됨 (n이라는 공간에 대해 k로도 부를꺼야, 참조, 또다른 공간 할당이 아님!)
	//int *k = &n과 동작이 같으므로 어셈블리에서 똑같이 번역됨

	cout << k << endl;
	cout << &n << " " << &k << endl;
}



///*참조연산자*/
//#include <iostream>
//using namespace std;
//
//void subr(int &k);
//void subp(int *p);
//void sub(int k);
//
//int main(void) {
//	int n = 5;
//	sub(n);				//call by value
//	subp(&n);			//call by address(pointer)
//	subr(n);			//call by reference
//	cout << n << endl;
//}
//void subr(int &k) {		//int &k = n;
//	k = 0;
//}
//void subp(int *p) {		// int *p = &n;
//	*p = 100;
//}
//
//void sub(int k) {		//int k = n 혹은 int k(n)
//	k = 0;
//}



//#include <iostream>
//using namespace std;
//int &rsub(int &r);
//int *psub(int *p);
//int vsub(int k);
//
//int main(void) {
//	int n = 5;
//	vsub(n);
//	*psub(&n) = 0;
//	rsub(n) = 100; 
//	cout << n << endl;
//}
//
//int &rsub(int &r) {		//int &r = n;
//	return r;			//int &imsi = r;
//}
//int *psub(int *p) {		//int *p = &n;
//	return p;			//int *imsi = p;
//}
//int vsub(int k) {
//	return k;
//}


//#include <iostream>
//using namespace std;
//
//int main(void) {
//	int n = 5;
//	int &k = n;
//	const int &c = n;
//
//	const char *str = "seoul";	//char *str = "seoul"; *str = 'A'라고 하면 const 영역에 접근되므로 안됨
//	const char *&rstr = str;	//const char * 타입의 별명이므로 const char * &
//
//	char name[4] = "kim";		//4개 생략가능
//	char (& rname)[4] = name;	//4개 써줘야함
//
//	char names[][5] = { "kim", "park", "lee" };	//5개 써줘야함
//	char (&rnames)[3][5] = names;	//3개 써줘야함
//}



//#include <iostream>
//using namespace std;
//
//int main(void) {
//	long data = 0x12345678;
//
//	short &s = (short &)data;
//	cout << hex << s << endl;	//little endian이라 5678
//
//	short(&s2)[2] = (short(&)[2])data;	//{5678, 1234}
//	cout << hex << s2[1] << endl;
//
//	char(&b)[4] = (char(&)[4])data;
//	cout << hex << (int)b[2] << endl;	//34
//}



//#include <iostream>
//using namespace std;
//
//int main(void) {
//	int score;
//	char grade[] = "FFFFFFDCBAA";
//	do {
//		cout << "Score : ";
//		cin.clear();							//오류 bit 플래그 clear
//		cin.ignore(cin.rdbuf()->in_avail());	//중요한건 아닌데, C++에서 flush하는 방법
//		cin >> score;							//위 2개는 관용적으로 쓰임
//	} while (cin.fail() || score < 0 || score > 100);
//
//	cout << grade[score / 10] << endl;			//제어문을 쓰지 말자!
//}


/*1.12동적 메모리와 연산자*/
//#include <iostream>
//using namespace std;
//
//int main(void) {
//	int *np;
//	np = new int;		//new int하면 int *로 리턴 (malloc은 void *로 리턴, 자료형을 쓴다는 차이점)
//	cout << *(int *)((char *)np - 12) << endl;	//4 = sizeof(int) 만큼 사이즈 할당됨
//	delete np;			//free(np)
//
//
//	char *cp = new char[10];
//	delete [] cp;
//}


//포인터 배열(메모리 절약)
//#include <iostream>
//#include <string.h>
//using namespace std;
//
//int main(void) {
//	char temp[100];
//	char **str;
//	size_t len;
//	int cnt;
//
//	do {
//		cout << "Count : ";
//		cin.clear();
//		cin.ignore(cin.rdbuf()->in_avail());
//		cin >> cnt;
//	} while (cin.fail());
//
//	str = new char *[cnt];
//
//	for (int n = 0; n < cnt; n++) {
//		cout << "String : ";
//		cin.clear();
//		cin.ignore(cin.rdbuf()->in_avail());
//		cin.getline(temp, 100);
//		len = strlen(temp);
//		str[n] = new char[++len];
//		strcpy_s(str[n], len, temp);
//	}
//
//	for (int n = 0; n < cnt; n++) {
//		cout << str[n] << endl;
//	}
//	for (int n = 0; n < cnt; n++) {
//		delete [] str[n];			//new 오른쪽에 배열형태면 []를 붙이자!
//	}
//	delete [] str;					//new 오른쪽에 배열형태면 []를 붙이자!
//}



//#include <iostream>
//using namespace std;
//
////공간 이름(전역화 방지, 중복 이름 방지)
//namespace A {
//	int n = 5;
//	void sub(void) {
//		cout << n << endl;
//	}
//}
//
//namespace B {
//	int n = 10;
//	void sub(void) {
//		cout << n << endl;
//	}
//}
//
//int main(void) {
//	cout << A::n << endl;
//	B::sub();
//
//	using namespace A;		//A namespace에 있는 것 사용
//	sub();
//	cout << n << endl;
//
//	using namespace B;		//B namespace에 있는 것 사용
//	B::sub();				//A의 sub와 B의 sub를 구별 불가 (B::sub()해야함)
//}







//#include <time.h>
//#include <iostream>
//using namespace std;
//
//#define IsLeap(Y) ((!(Y % 4) && (Y % 100)) || !(Y % 400))	//윤년
//
//struct Date {
//private:
//	int year, month, day;
//	int week;
//	void CalcDate(void);
//public:
//	Date(void);
//	Date(int d, int m, int y = 2020);
//	void DisplayDate(void);
//};
//
//static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };	//각 달마다 날짜수
//
///*
//현재 컴퓨터의 날짜 얻어오기
//*/
//Date::Date(void)
//{
//	time_t lt;//long
//	struct tm cur;
//
//	::time(&lt);				//lnog 형태로 한번에 담아옴
//	::localtime_s(&cur, &lt);	//읽기 편한 구조체로 자름
//	year = cur.tm_year + 1900;
//	month = cur.tm_mon + 1;
//	day = cur.tm_mday;
//	week = cur.tm_wday;
//}
//
//Date::Date(int d, int m, int y)
//{
//	if (y < 1 || y > 4000) y = 1;
//	year = y;
//	if (IsLeap(year)) ::days[2] = 29;
//	else ::days[2] = 28;
//	if (m < 1 || m > 12) m = 1;
//	month = m;
//	if (d < 1 || d > ::days[month]) d = 1;
//	day = d;
//	CalcDate();
//}
//
//void Date::CalcDate(void)
//{
//	int y, sum;
//	y = year - 1;
//	sum = y * 365 + (y / 4) - (y / 100) + (y / 400);
//	for (int n = 1; n < month; n++) sum += ::days[n];
//	sum += day;
//	week = sum % 7;
//}
//
//void Date::DisplayDate(void)
//{
//	const char * strweek[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
//
//	cout << year << '/' << month << '/' << day << '/' << strweek[week] << endl;
//}
//
//int main(void)
//{
//	Date today;
//	today.DisplayDate();
//
//	Date someday(4, 11);
//	someday.DisplayDate();
//
//	Date *dp = new Date;
//	dp->DisplayDate();
//	delete dp;
//}




//#include <iostream>
//using namespace std;
//
//class A {
//	int no;
//	char ch;
//public:
//	A();
//	A(int n);
//	A(int n, char c);
//};
//
//A::A() {
//	cout << "default constructor" << endl;
//	no = 0;
//	ch = 'A';
//}
//A::A(int n) {
//	A::no = n;
//	cout << "int constructor" << endl;
//}
//A::A(int n, char c) {
//	A::no = n;
//	A::ch = c;
//	cout << "int, char constructor" << endl;
//}
//int main(void) {
//	//A aa;			//A aa();라고 쓰면 A를 리턴하는 aa함수의 선언으로 혼동 ==> 디폴트 생성자는 괄호를 아예 사용하면 안됨!
//	//A bb(5);
//	//A cc(5, 'A');	//A cc = A(5, 'A');의 축약형
//
///*
//	A aa[3];								//각각 생성자 함수 호출
//	A aa[3] = { 10, 20, 30 };				//각각 int 생성자 함수 호출
//	A aa[] = { A(), A(5), A(5, 'A') };		//각각 해당하는 생성자 함수 호출
//*/
///*
//	A *ap = new A;								// malloc을 쓴다면 생성자 함수를 실행할 수 없음
//	cout << *(int *)((char *)ap - 12) << endl;	//A의 size정보가 잘 들어있음
//	delete ap;
//*/
///*
//	//A *ap = new A[3];
//	A *ap = new A[3]{ A(), A(5), A(5, 'A') };	//예전엔 사용할 수 없었음
//	cout << *(int *)((char *)ap - 12) << endl;
//	delete [] ap;					//배열을 할당했으므로 []를 붙이기로!!(이 경우, 안붙여도 상관없음)
//*/
//	A *ap[] = { new A, new A(5), new A(5, 'A'), new A[2] };
//	for (int n = 0; n < 3; n++) {
//		delete ap[n];
//	}
//	delete[] ap[3];
//}




//#include <iostream>
//using namespace std;
//
//class A {
//	int no;
//public :
//	A();
//	A(int n);
//	~A();
//};
//
//A::A() {
//	cout << "default constructor" << endl;
//}
//A::A(int n) {
//	cout << "int constructor" << endl;
//}
//A::~A() {
//	cout << "destructor" << endl;
//}
//
//int main(void) {
//	A aa;	//A aa = A();
//	A * ap;
//	ap = new A(5);
//	cout << *(int *)((char *)ap - 12) << endl;
//	delete ap;
//
//	ap = new A[3];
//	cout << *(int *)((char *)ap - 16) << endl;
//	delete[] ap;			//여기서는 [] 반드시 써야함 !(안쓰면 runtime 오류 발생)
//
//	cout << "end main..." << endl;
//}



///*생성자와 소멸자를 이용하여 코드를 간단하게 바꾸기*/
//#include <iostream>
//#include <iomanip>
//using namespace std;
//
//#define ScoreRng(S) (((S >= 0) && (S <= 100)) ? (S) : (0))
//
//class Score {
//private:
//	char * name;
//	int kor, eng, mat, tot;
//	double ave;
//	void CalcScore(void);
//public:
//	Score(void);
//	Score(const char * irum, int k, int e, int m);
//	void PrintScore(void);
//	~Score(void);
//};
//
//Score::Score(void)
//{
//	char temp[20];
//	size_t len;
//
//	do {
//		cout << "Name:";
//		cin.clear();
//		cin.ignore(cin.rdbuf()->in_avail());
//		cin.getline(temp, 20);
//	} while (cin.fail());
//	len = ::strlen(temp);
//	name = new char[len + 1];
//	::strcpy_s(name, len + 1, temp);
//
//	do {
//		cout << "Score(K, E, M):";
//		cin.clear();
//		cin.ignore(cin.rdbuf()->in_avail());
//		cin >> kor >> eng >> mat;
//	} while (cin.fail() || !ScoreRng(kor) || !ScoreRng(eng) || !ScoreRng(mat));
//
//	CalcScore();
//}
//
//Score::Score(const char * irum, int k, int e, int m)
//{
//	size_t len;
//
//	len = ::strlen(irum);
//	name = new char[len + 1];
//	::strcpy_s(name, len + 1, irum);
//	kor = ScoreRng(k), eng = ScoreRng(e), mat = ScoreRng(m);
//
//	CalcScore();
//}
//
//void Score::CalcScore(void)
//{
//	tot = kor + eng + mat;
//	ave = tot / 3.0;
//}
//
//void Score::PrintScore(void)
//{
//	static char ch[] = "FFFFFFDCBAA";
//
//	cout << std::setw(10) << std::left << name
//		<< setw(3) << ch[kor / 10] << setw(3) << ch[eng / 10] << setw(3) << ch[mat / 10]
//		<< setw(5) << tot << setw(8) << std::fixed << std::setprecision(2) << ave << endl;
//}
//
//Score::~Score(void)
//{
//	delete[] name;
//}
//
//void main(void)
//{
//	unsigned int cnt, n;
//	Score * pScore;
//
//	cout << "Count:";
//	cin >> cnt;
//	pScore = new Score[cnt];
//
//	for (n = 0; n < cnt; n++) {
//		pScore[n].PrintScore();
//	}
//
//	delete[] pScore;
//}




///*RAII 디자인 패턴 테크닉*/
//#include <stdio.h>
//
//class MFile {
//	FILE *m_fp;
//	char m_buf[133];
//public:
//	MFile() {}
//	MFile(const char *fname, const char *mode = "r");
//	~MFile();
//	char *Read(void);
//	char *GetBuf();
//	void Print(void);
//};
//MFile::MFile(const char *fname, const char *mode) {	//여기서 const char *mode = "r" 이렇게 하면 안되네(?)
//	::fopen_s(&m_fp, fname, mode);
//}
//MFile::~MFile() {
//	::fclose(m_fp);
//}
//char *MFile::Read(void) {
//	return fgets(m_buf, 133, m_fp);
//}
//char *MFile::GetBuf(void) {
//	return MFile::m_buf;
//}
//void MFile::Print(void) {
//	while (Read()) {
//		printf("%s", GetBuf());
//	}
//}
//
//int main(void) {
//	MFile file("main2.cpp");
//	file.Print();
//}



///*this 예제1*/
//#include <iostream>
//using namespace std;
//class A {
//	int no;
//	char ch;
//public :
//	A() {}
//	A(int n, char c);
//	void sub(int dummy);
//};
//
//A::A(int n, char c) {
//	this->no = n;			//this의 자료형은 A *
//	this->ch = c;
//	cout << this << endl;
//}
//void __thiscall A::sub(int dummy) {							//__thiscall 설명 못들음
//	cout << hex << *(int *)((char *)&dummy - 16) << endl;	//this는 16번지에 추가됨
////	*(int *)((char *)&dummy - 16) = 0;						//this값을 바꾸면 안되지만 바뀌어짐
//	cout << this << endl;
//}
//
//int main(void) {
//	A aa(5, 'A');
//	cout << &aa << endl;
//	aa.sub(0);
//}



//#include <iostream>
//using namespace std;
//
//class A {
//	int no;
//public :
//	A() {}
//	A(int n);
//	~A();
//	A *sub(void);
//	A &func(void);
//};
//A::A(int n) {
//	this->no = n;
//	(*this).no = n;
//}
//A::~A() {
//	cout << "destructor" << endl;
//}
//A *A::sub(void) {
//	return this;
//}
//A A::func(void) {
//	return *this;		// A imsi = *this	리턴 시 결국 임시공간에 this와 똑같은 오브젝트를 만듬
//}
//A &A::func(void) {
//	return *this;		// &를 쓰면 오브젝트를 새로 만들지 않고 계속 작업 할 수 있음 대신 .으로 연결
//}
//
//int main(void) {
//	A aa(5);
//	aa.sub()->func().sub()->sub();
//	aa.func();
//}


//#include <iostream>
//#include <stdio.h>
//using namespace std;
//
//struct stream {
//	stream &printf(int n);
//	stream &printf(char c);
//	stream &printf(double d);
//	stream &printf(const char *str);
//};
//
//stream &stream::printf(int n) {
//	::printf("%d", n);
//	return *this;
//}
//stream &stream::printf(char c) {
//	::printf("%c", c);
//	return *this;
//}
//stream &stream::printf(double d) {
//	::printf("%lf", d);
//	return *this;
//}
//stream &stream::printf(const char *str) {
//	::printf("%s", str);
//	return *this;
//}
//
//int main(void) {
//	stream c;
//	c.printf(5);		//cout << 5 cout도 중복 정의가 되어있음
//	c.printf('A');		//
//	c.printf(3.14);		//
//	c.printf("seoul");	//
//	c.printf(5).printf('A').printf(3.14).printf("seoul");
//}