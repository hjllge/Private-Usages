//#include <stdio.h>
////������Ͽ� ����
//struct st {
//	//��� ����
//private:
//	int no;
//	char ch;
//
//public:
//	//��� �Լ� (�μ��� ������ �پ��� ȿ��)
//	void PrintStruct() const;
//	void InitStruct(int n, char c);
//};
//
////st�� �ش��ϴ� �Լ��� st::�� ��ħ (����ü ����� ���� ����)
//void st::PrintStruct() const {	//const : �б⸸ �ϴ� �뵵�� �Լ��� ��� �ǹ�
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
//������ �ʿ���Ե�
//void InitStruct(struct st *aa, int n, char c);		//st�� ��ƿ� �뵵
//void PrintStruct(const struct st *t);				//st�� �б⸸ �ϴ� �뵵, ������ up!
//*/
//int main(void) {
//	st aa;			//����ε� struct ����, �ܼ��� ������� �ٲ�(generalize)
//	//void InitStruct(struct st *aa, int n, char c);	//���� ���� ����(main������ �Ҹ�)
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
//	cout << left << setw(10) << "seoul" << "KOREA" << endl;				//���� ����(?)
//	cout << fixed << setprecision(2) << 3.141592653589793238 << endl;	//�Ҽ� 2�ڸ����� (fixed�� ���� �Ҽ���)
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
//	cout << ::no << endl;	//::(scope)�� �ٿ� �������� �켱 ����, ������ ���� no�� �������� �ʴ��� ������ �����Ҷ��� ::�� ���̴°� ����.
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
//	::printf("%d\n", no);	//::�� �Ⱥ��̸� ������ printf�� �켱 -> ::�� �ٿ������
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
//	const int c = 5;	//�ʱⰪ�� �����ؾ� ������ ������ ������ �ʴ´�.(�������� �� ����) ���� volatile�� ���̸� ����ȭ�� �����Ǿ �ٽ� ���� ������ ����� �ٲ�
//	char str[c];		//���� c�� ���ȭ ��(������ Ÿ�ӿ� c�� 5�� �򰡵�)
//
//	//const int *p = &c;		//c�� Ÿ���� const integer�ϱ� const int *
//	//*p = 10;				//p ���� �� �տ� const�� �پ����Ƿ� const������ ���� ���� �Ұ� => �ᱹ c���� �ٲ� �� ����
//
//	int *p = (int *)&c;		//���� ��ȯ
//	*p = 10;				//�ٲٰ�� ���ž�!
//	cout << c << endl;		//c�� �״�� 5 ���(������ Ÿ�ӿ� c�� 5�� ġȯ��Ŵ, c�� ��� 5�� �����Ѵٰ� ���� ��)
//	cout << *p << endl;		//c�� �ٲ�� ����..(�ٲ����� ������� �ٲ�)
//}



//#include <iostream>
//using namespace std;
//
//int main(void) {
//	int n = 5, k = 6;
//	const int *p = &n;	//int *�� const (�ʱⰪ ��� ������ ������ x)
//	//*p = 10;			//�Ұ�
//
//	int * const q = &k;		//q�� const (�ݵ�� �ʱⰪ)
//	*q = 10;				//����	(&q�� �ڷ��� = int * const *)
//	//q = &n;					//�Ұ�
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
//void MemCpy(void *dst, const void *sou, size_t cnt) {		//cnt = byte ��, byte������ �����
//	char *d = (char *)dst;
//	const char *s = (const char *)sou;
//	for (;cnt > 0;cnt--) {
//		*d++ = *s++;
//	}
//}
//void Swap(void *a, void *b, size_t size) {	//size ��¿ �� ���� �ʿ�
//	void * temp = malloc(size);
////	temp = *a;	//void *���� *����, ++���� ���� �Ұ�
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
//	c.printf(5);		//cout << 5 cout�� �ߺ� ���ǰ� �Ǿ�����
//	c.printf('A');		//
//	c.printf(3.14);		//
//	c.printf("seoul");	//
//}


///*����Ʈ �Ķ����*/
//#include <iostream>
//using namespace std;
//
//void DisplayDate(int d, int m = 12, int y = 2020);	//����Ʈ �Ķ���Ͱ��� ���������� ��ġ�ϸ� ����
//int main(void) {
//	DisplayDate(24, 12);
//	DisplayDate(25);
//}
//
//void DisplayDate(int d, int m, int y) {				//����Ʈ �Ű������� ���⿡�� �������� ����
//	cout << y << "/" << m << "/" << d << endl;
//}


////������Ʈ �Ӽ�->���������� (���� ��Ƽ����Ʈ����) �����ڵ�� �ٲ�� ����
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
//	return MessageBox(NULL, text, title, nType);	//c�Լ��� �ߺ� ���ǰ� �ȵǴϱ� �̷��� ���ο��� �� �� �ִ�.
//}




#include <iostream>
using namespace std;

int main(void) {
	int n = 5;
	int &k = n;	//int &k�� �ȵ� (n�̶�� ������ ���� k�ε� �θ�����, ����, �Ǵٸ� ���� �Ҵ��� �ƴ�!)
	//int *k = &n�� ������ �����Ƿ� ��������� �Ȱ��� ������

	cout << k << endl;
	cout << &n << " " << &k << endl;
}



///*����������*/
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
//void sub(int k) {		//int k = n Ȥ�� int k(n)
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
//	const char *str = "seoul";	//char *str = "seoul"; *str = 'A'��� �ϸ� const ������ ���ٵǹǷ� �ȵ�
//	const char *&rstr = str;	//const char * Ÿ���� �����̹Ƿ� const char * &
//
//	char name[4] = "kim";		//4�� ��������
//	char (& rname)[4] = name;	//4�� �������
//
//	char names[][5] = { "kim", "park", "lee" };	//5�� �������
//	char (&rnames)[3][5] = names;	//3�� �������
//}



//#include <iostream>
//using namespace std;
//
//int main(void) {
//	long data = 0x12345678;
//
//	short &s = (short &)data;
//	cout << hex << s << endl;	//little endian�̶� 5678
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
//		cin.clear();							//���� bit �÷��� clear
//		cin.ignore(cin.rdbuf()->in_avail());	//�߿��Ѱ� �ƴѵ�, C++���� flush�ϴ� ���
//		cin >> score;							//�� 2���� ���������� ����
//	} while (cin.fail() || score < 0 || score > 100);
//
//	cout << grade[score / 10] << endl;			//����� ���� ����!
//}


/*1.12���� �޸𸮿� ������*/
//#include <iostream>
//using namespace std;
//
//int main(void) {
//	int *np;
//	np = new int;		//new int�ϸ� int *�� ���� (malloc�� void *�� ����, �ڷ����� ���ٴ� ������)
//	cout << *(int *)((char *)np - 12) << endl;	//4 = sizeof(int) ��ŭ ������ �Ҵ��
//	delete np;			//free(np)
//
//
//	char *cp = new char[10];
//	delete [] cp;
//}


//������ �迭(�޸� ����)
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
//		delete [] str[n];			//new �����ʿ� �迭���¸� []�� ������!
//	}
//	delete [] str;					//new �����ʿ� �迭���¸� []�� ������!
//}



//#include <iostream>
//using namespace std;
//
////���� �̸�(����ȭ ����, �ߺ� �̸� ����)
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
//	using namespace A;		//A namespace�� �ִ� �� ���
//	sub();
//	cout << n << endl;
//
//	using namespace B;		//B namespace�� �ִ� �� ���
//	B::sub();				//A�� sub�� B�� sub�� ���� �Ұ� (B::sub()�ؾ���)
//}







//#include <time.h>
//#include <iostream>
//using namespace std;
//
//#define IsLeap(Y) ((!(Y % 4) && (Y % 100)) || !(Y % 400))	//����
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
//static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };	//�� �޸��� ��¥��
//
///*
//���� ��ǻ���� ��¥ ������
//*/
//Date::Date(void)
//{
//	time_t lt;//long
//	struct tm cur;
//
//	::time(&lt);				//lnog ���·� �ѹ��� ��ƿ�
//	::localtime_s(&cur, &lt);	//�б� ���� ����ü�� �ڸ�
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
//	//A aa;			//A aa();��� ���� A�� �����ϴ� aa�Լ��� �������� ȥ�� ==> ����Ʈ �����ڴ� ��ȣ�� �ƿ� ����ϸ� �ȵ�!
//	//A bb(5);
//	//A cc(5, 'A');	//A cc = A(5, 'A');�� �����
//
///*
//	A aa[3];								//���� ������ �Լ� ȣ��
//	A aa[3] = { 10, 20, 30 };				//���� int ������ �Լ� ȣ��
//	A aa[] = { A(), A(5), A(5, 'A') };		//���� �ش��ϴ� ������ �Լ� ȣ��
//*/
///*
//	A *ap = new A;								// malloc�� ���ٸ� ������ �Լ��� ������ �� ����
//	cout << *(int *)((char *)ap - 12) << endl;	//A�� size������ �� �������
//	delete ap;
//*/
///*
//	//A *ap = new A[3];
//	A *ap = new A[3]{ A(), A(5), A(5, 'A') };	//������ ����� �� ������
//	cout << *(int *)((char *)ap - 12) << endl;
//	delete [] ap;					//�迭�� �Ҵ������Ƿ� []�� ���̱��!!(�� ���, �Ⱥٿ��� �������)
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
//	delete[] ap;			//���⼭�� [] �ݵ�� ����� !(�Ⱦ��� runtime ���� �߻�)
//
//	cout << "end main..." << endl;
//}



///*�����ڿ� �Ҹ��ڸ� �̿��Ͽ� �ڵ带 �����ϰ� �ٲٱ�*/
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




///*RAII ������ ���� ��ũ��*/
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
//MFile::MFile(const char *fname, const char *mode) {	//���⼭ const char *mode = "r" �̷��� �ϸ� �ȵǳ�(?)
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



///*this ����1*/
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
//	this->no = n;			//this�� �ڷ����� A *
//	this->ch = c;
//	cout << this << endl;
//}
//void __thiscall A::sub(int dummy) {							//__thiscall ���� ������
//	cout << hex << *(int *)((char *)&dummy - 16) << endl;	//this�� 16������ �߰���
////	*(int *)((char *)&dummy - 16) = 0;						//this���� �ٲٸ� �ȵ����� �ٲ����
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
//	return *this;		// A imsi = *this	���� �� �ᱹ �ӽð����� this�� �Ȱ��� ������Ʈ�� ����
//}
//A &A::func(void) {
//	return *this;		// &�� ���� ������Ʈ�� ���� ������ �ʰ� ��� �۾� �� �� ���� ��� .���� ����
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
//	c.printf(5);		//cout << 5 cout�� �ߺ� ���ǰ� �Ǿ�����
//	c.printf('A');		//
//	c.printf(3.14);		//
//	c.printf("seoul");	//
//	c.printf(5).printf('A').printf(3.14).printf("seoul");
//}