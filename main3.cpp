//3���� �ڵ�

//#include <iostream>
//using namespace std;
//
//class A {
//	int no;
//public:
//	A() {					//B�� ��������� ���� A�� ��������Ƿ� ����Ʈ �����ڰ� �ݵ�� �־����
//		cout << "A constructor" << endl;
//	}
//	A(int n) {
//		no = n;
//	}
//	~A() {}
//};
//
//class B {
//	char ch;
//	A aa;
//public:
//	B();
//	B(char c, int n);
//	~B() {}
//};
//
////B::B() :aa(){		//:aa()�� ���� �ʾƵ� �Ϲ������� ������(��������� ���� �ᵵ��) A�� �����ڰ� ���� ����!, �⺻������ ����Ʈ �����ڰ� �����, ��������� ����� ������� �ʱ�ȭ
////	cout << "B constructor" << endl;
////}
////B::B(char c, int n) :aa() {
////
////}
//
//B::B() : aa(5) {		//��������� aa(5)�� ���� �ش� �����ڰ� ���� ����
//	cout << "B constructor" << endl;
//}
//B::B(char c, int n) : aa(n) {//��������
//	ch = c;
//}
//
//int main(void) {
//	B bb;
//}



//#include <iostream>
//using namespace std;
//
//int go = 5;
//class A {
//	int no;
//	int &ro;		//��������
//	const int co;	//const���� ����� ���ÿ� �ʱ�ȭ �ʿ�!
//public:
//	A();
//	A(int n);
//};
//
//A::A() : ro(go), co(0) {		//�ݵ�� ro, co�� �ݷ� �ʱ�ȭ�� �̿��Ͽ� �ʱ�ȭ�ؾ���.
//	//ro = go;
//	//co = 0;
//}
//A::A(int n) : ro(no), co(5), no(n) {
//
//}
//
//int main(void) {
//	A aa;
//	A bb(5);
//	cout << sizeof(aa) << endl;		//���������� �������� �����Ϸ��� ���� �����ͷ� ������ ���� ro�� 4����Ʈ ���� �Ҵ�
//	
//}


//#include <iostream>
//using namespace std;
//
//class A {
//	int no;
//	char ch;
//public:
//	A() {}
//	A(int n, char c) : no(n), ch(c) {}
//	void sub(void) const;
//	void func(void);
//};
//
//void A::sub(void) const {	//const������ �Ϲ� ����Լ� ȣ��(aa.sub()) �Ұ�!
//	cout << no << " " << ch << endl;
//	//no = 10;				//const�Լ����� �� ���� ���� �Ұ�(�翬��)
//	//func();				//const�Լ������� �Ϲ� �Լ� ȣ�� �Ұ�!(�Ǵٸ� const�Լ� ȣ���� ����)
//	//this->func();			//�����ٰ� ������ ǥ��, this�� �ڷ����� const A *(A *�� �ƴ�!)
//	((A *)this)->func();	//�̷��� ���� ���������� func�� �ҷ��� no�� 0���� �ٲ� => �ٲ��� �ʰ� �ϱ� ���� func�Լ��� const�Լ��� �ߺ������ؼ� no = 0;�� ���� �� �����ؼ� ���� ���� ��õ�Ͻ�
//}
//void A::func(void) {
//	no = 0;
//	cout << no << " " << ch << endl;
//}
//
//int main(void) {
//	const A aa(5, 'A');
//	A bb(10, 'B');
//	aa.sub();
//	bb.sub();			//�Ϲ� ������Ʈ�� const�Լ� ȣ�� ����!
//	bb.func();
//}



//#include <iostream>
//using namespace std;
//class A {
//public:
//	int no;
//	A(int n = 0) : no(n) {}		//����Ʈ �Ķ���ͷ� 0�� �ֱ� ������ ����Ʈ ������ ���ʿ�
//	const int *sub(void) const;
//	const int &subr(void) const;
//	const A *func(void) const;
//	const A &funcr(void) const;
//};
//
//const int *A::sub(void) const {	//��� �������� �ּҸ� �����Ҷ�(�ۿ��� �ٲ��� ���ϰ� �Ҷ�)�� ���� Ÿ�Կ� const�� �ٿ����Ѵ�.
//	return &no;
//}
//
//const int &A::subr(void) const {//��� �������� ������ �����Ҷ�(�ۿ��� �ٲ��� ���ϰ� �Ҷ�)�� ���� Ÿ�Կ� const�� �ٿ����Ѵ�.
//	return no;
//}
//
//const A *A::func(void) const {	//������Ʈ�� �ּҸ� �����Ҷ�(�ۿ��� �ٲ��� ���ϰ� �Ҷ�)�� ���� Ÿ�Կ� const�� �ٿ����Ѵ�.
//	return this;
//}
//
//const A &A::funcr(void) const {	//������Ʈ�� ������ �����Ҷ�(�ۿ��� �ٲ��� ���ϰ� �Ҷ�)�� ���� Ÿ�Կ� const�� �ٿ����Ѵ�.
//	return *this;
//}
//
//int main(void) {
//	A aa;
//	//*aa.sub() = 10;			//�׷��� no�� ���� �Ұ�
//	//aa.subr() = 10;			//�׷��� no�� ���� �Ұ�
//	//aa.func()->no = 10;		//�׷��� no�� ���� �Ұ�
//	//aa.funcr().no = 10;		//�׷��� no�� ���� �Ұ�
//}


//#include <iostream>
//using namespace std;
//
//class A {
//	char ch;
//	char *p;
//public:
//	A(char c = 'A') : ch(c), p(&ch) {}
//	char *GetP(void) const;
//	const char * const *GetPP(void) const;
//};
//char *A::GetP(void) const {
//	return p;
//}
//
//const char * const *A::GetPP(void) const {	//char * const q = &p; q�� p�� ����Ŵ
//	return &p;
//}
//
//int main(void) {
//	A aa;
//	*aa.GetP() = 'B';				//���� ��¥ ch�� 'B'�� �ٲٰ� �ʹٸ� GetP�� ���Ͽ� const�� ���� ������ ��
//	//*aa.GetPP() = 0;				//�ڿ� const�� ���� �Ұ�
//	//**aa.GetPP() = 'A';			//���� const�� ���� �Ұ�
//}



//#include <iostream>
//using namespace std;
//
//class A {
//	int no;
//	static int sum;	//private�� �־ �������� ���� ����, �׷��� main���� ���� �Ұ�, ��ȣ�� ���� private�� ���� ����
//public:
//	static int sum;
//};
//
//int A::sum = 0;		//��� ��������� �˷������, ���⼭ �ʱⰪ, �Ⱦ��� �⺻������ ����
//
//int main(void) {
//	cout << A::sum << endl;		//�����̱⶧���� aa�� �����Ǳ� ���� �̹� ������ ������
//	A aa;
//	cout << sizeof(aa) << endl;	//sum�� ��������� ���� ������
//	aa.sum = 100;				//��ġ aa���� sumó�� ���̱� ������ �̷��� ǥ���� ����, A::sum = 100���� ����
//	A bb;
//	cout << bb.sum << endl;		//�翬�� 100 ���, A::sum = 100���� ����
//}


///*���� ���� ����(static ��� �Լ�)*/
//#include <iostream>
//using namespace std;
//
//class A {
//	int no;
//	static int sum;				//static�� ����ο����� ���
//public:
//	static int GetSum(void);	//static�� ����ο����� ���
//	static void SetSum(int s);
//};
//
//int A::sum = 0;			//��� ��������� �˷������, ���⼭ �ʱⰪ, �Ⱦ��� �⺻������ ����, ���ǹ������� static ���� ����
//int A::GetSum(void) {	//���ǹ������� static ���� ����
//	return A::sum;
//}
//void A::SetSum(int s) {
//	A::sum = s;
//}
//int main(void) {
//	A::SetSum(100);
//	cout << A::GetSum() << endl;
//}



//#include <iostream>
//using namespace std;
//
//class CMainFrame {
//	CMainFrame() { cout << "Create Window..." << endl; }	//�����ڸ� ���� ���ϰ� ��
//public:
//	static CMainFrame *CreateObject(void);
//	~CMainFrame() { cout << "End Window..." << endl; }
//	void ShowWindow(void) { cout << "Show Window..." << endl; }
//	void OnClose(void) {
//		cout << "Close Window..." << endl; 
//		DestroyWindow();
//	}
//	void DestroyWindow(void) {
//		cout << "Destroy Window..." << endl;
//		delete this;			//���⼭ �ڽ��� �����ϹǷ�
//	}
//};
//CMainFrame *CMainFrame::CreateObject(void) {
//	return new CMainFrame;
//}
//int main(void) {
//	//CMainFrame frame;	//�̷��� �ϸ� �׻� ������Ʈ�� �ӹ�������
//	CMainFrame *pFrame;
//	pFrame = CMainFrame::CreateObject();	//new�� ���� delete�� ��Ա� ������ ���ÿ� �����ϴ� ����� ���� �����ڵ��� ���� ���� ������ �̷��� ����� ��
//
//	pFrame->ShowWindow();
//	pFrame->OnClose();						//���⼭ ������ ��ȯ��
//}


///*fiend �Լ�1*/
//#include <iostream>
//using namespace std;
//
//class A {
//	int no;
//public:
//	A(int n = 0) : no(n) {}
//	int GetNo(void) const { return no; }
//	friend void Gsub(const A &ra);	//friend ������ �����ϱ� ���Ժ��ٵ� A�� ���õ� �Լ���� ���� ǥ���ϱ� ���� ���
//};
//
//void Gsub(const A &ra) {					//A & ra = A(5)�� �ȵǰ� const A & ra = A(5)�� �����ϹǷ� �ӽÿ�����Ʈ�� ��������
//	cout << ra.GetNo() << endl;		//private ��� no ���� ����
//}
//
//int main(void) {
//	A aa(5);
//	Gsub(aa);
//
//	Gsub(A(5));	//�ӽ� ������Ʈ�� &�� �Ѽ� ����, const A &ra�� ���� ��������
//	
//
//}



///*fiend �Լ�2*/
//#include <iostream>
//using namespace std;
//
//class A;		//�ؿ� A�� ���˾ƺ��Ƿ� ���漱��
//
//class B {
//public:
//	void Bsub(const A *ap);
//};
//class A {
//	int no;
//public:
//	A(int n = 0) : no(n) {}
//	int GetNo(void) const { return no; }
//	friend void Gsub(const A &ra);
//	friend void B::Bsub(const A *ap);		//BŬ������ ������ �ǹ�
//};
//
//
//void Gsub(const A &ra) {
//	cout << ra.GetNo() << endl;
//}
//
//void B::Bsub(const A *ap) {
//	cout << ap->GetNo() << endl;
//}
//
//int main(void) {
//	A aa(5);
//	Gsub(aa);
//
//	Gsub(A(5));
//}



