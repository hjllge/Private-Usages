//3일차 코드

//#include <iostream>
//using namespace std;
//
//class A {
//	int no;
//public:
//	A() {					//B가 만들어짐에 따라 A도 만들어지므로 디폴트 생성자가 반드시 있어야함
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
////B::B() :aa(){		//:aa()를 쓰지 않아도 암묵적으로 생성됨(명시적으로 직접 써도됨) A의 생성자가 먼저 실행!, 기본적으로 디폴트 생성자가 실행됨, 멤버변수에 선언된 순서대로 초기화
////	cout << "B constructor" << endl;
////}
////B::B(char c, int n) :aa() {
////
////}
//
//B::B() : aa(5) {		//명시적으로 aa(5)를 쓰면 해당 생성자가 먼저 실행
//	cout << "B constructor" << endl;
//}
//B::B(char c, int n) : aa(n) {//마찬가지
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
//	int &ro;		//참조형과
//	const int co;	//const형은 선언과 동시에 초기화 필요!
//public:
//	A();
//	A(int n);
//};
//
//A::A() : ro(go), co(0) {		//반드시 ro, co는 콜론 초기화를 이용하여 초기화해야함.
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
//	cout << sizeof(aa) << endl;		//내부적으로 참조형은 컴파일러에 의해 포인터로 번역됨 따라서 ro도 4바이트 공간 할당
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
//void A::sub(void) const {	//const없으면 일반 멤버함수 호출(aa.sub()) 불가!
//	cout << no << " " << ch << endl;
//	//no = 10;				//const함수에서 값 대입 연산 불가(당연히)
//	//func();				//const함수에서는 일반 함수 호출 불가!(또다른 const함수 호출은 가능)
//	//this->func();			//위에줄과 동일한 표현, this의 자료형은 const A *(A *가 아님!)
//	((A *)this)->func();	//이렇게 쓰면 위험하지만 func가 불려서 no가 0으로 바뀜 => 바뀌지 않게 하기 위해 func함수를 const함수를 중복정의해서 no = 0;만 빼고 재 정의해서 쓰는 것을 추천하심
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
//	bb.sub();			//일반 오브젝트도 const함수 호출 가능!
//	bb.func();
//}



//#include <iostream>
//using namespace std;
//class A {
//public:
//	int no;
//	A(int n = 0) : no(n) {}		//디폴트 파라메터로 0을 넣기 때문에 디폴트 생성자 불필요
//	const int *sub(void) const;
//	const int &subr(void) const;
//	const A *func(void) const;
//	const A &funcr(void) const;
//};
//
//const int *A::sub(void) const {	//멤버 데이터의 주소를 리턴할때(밖에서 바꾸지 못하게 할때)는 리턴 타입에 const를 붙여야한다.
//	return &no;
//}
//
//const int &A::subr(void) const {//멤버 데이터의 참조를 리턴할때(밖에서 바꾸지 못하게 할때)는 리턴 타입에 const를 붙여야한다.
//	return no;
//}
//
//const A *A::func(void) const {	//오브젝트의 주소를 리턴할때(밖에서 바꾸지 못하게 할때)는 리턴 타입에 const를 붙여야한다.
//	return this;
//}
//
//const A &A::funcr(void) const {	//오브젝트의 참조를 리턴할때(밖에서 바꾸지 못하게 할때)는 리턴 타입에 const를 붙여야한다.
//	return *this;
//}
//
//int main(void) {
//	A aa;
//	//*aa.sub() = 10;			//그래서 no값 변경 불가
//	//aa.subr() = 10;			//그래서 no값 변경 불가
//	//aa.func()->no = 10;		//그래서 no값 변경 불가
//	//aa.funcr().no = 10;		//그래서 no값 변경 불가
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
//const char * const *A::GetPP(void) const {	//char * const q = &p; q는 p만 가리킴
//	return &p;
//}
//
//int main(void) {
//	A aa;
//	*aa.GetP() = 'B';				//만약 진짜 ch를 'B'로 바꾸고 싶다면 GetP의 리턴에 const를 쓰지 않으면 됌
//	//*aa.GetPP() = 0;				//뒤에 const에 의해 불가
//	//**aa.GetPP() = 'A';			//앞의 const에 의해 불가
//}



//#include <iostream>
//using namespace std;
//
//class A {
//	int no;
//	static int sum;	//private에 넣어도 전역에서 접근 가능, 그러나 main에선 접근 불가, 보호를 위해 private에 선언 권장
//public:
//	static int sum;
//};
//
//int A::sum = 0;		//어디에 만들건지를 알려줘야함, 여기서 초기값, 안쓰면 기본값으로 설정
//
//int main(void) {
//	cout << A::sum << endl;		//전역이기때문에 aa가 생성되기 전에 이미 공간이 생성됨
//	A aa;
//	cout << sizeof(aa) << endl;	//sum은 멤버이지만 전역 변수임
//	aa.sum = 100;				//마치 aa만의 sum처럼 보이기 때문에 이러한 표현은 지양, A::sum = 100으로 권장
//	A bb;
//	cout << bb.sum << endl;		//당연히 100 출력, A::sum = 100으로 권장
//}


///*위의 예제 연장(static 멤버 함수)*/
//#include <iostream>
//using namespace std;
//
//class A {
//	int no;
//	static int sum;				//static은 선언부에서만 언급
//public:
//	static int GetSum(void);	//static은 선언부에서만 언급
//	static void SetSum(int s);
//};
//
//int A::sum = 0;			//어디에 만들건지를 알려줘야함, 여기서 초기값, 안쓰면 기본값으로 설정, 정의문에서는 static 쓰지 않음
//int A::GetSum(void) {	//정의문에서는 static 쓰지 않음
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
//	CMainFrame() { cout << "Create Window..." << endl; }	//생성자를 쓰지 못하게 함
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
//		delete this;			//여기서 자신을 제거하므로
//	}
//};
//CMainFrame *CMainFrame::CreateObject(void) {
//	return new CMainFrame;
//}
//int main(void) {
//	//CMainFrame frame;	//이렇게 하면 항상 오브젝트가 머물러있음
//	CMainFrame *pFrame;
//	pFrame = CMainFrame::CreateObject();	//new를 쓰면 delete를 까먹기 때문에 스택에 선언하는 방식을 쓰는 개발자들을 막기 위해 강제로 이러한 방식을 씀
//
//	pFrame->ShowWindow();
//	pFrame->OnClose();						//여기서 저절로 반환됨
//}


///*fiend 함수1*/
//#include <iostream>
//using namespace std;
//
//class A {
//	int no;
//public:
//	A(int n = 0) : no(n) {}
//	int GetNo(void) const { return no; }
//	friend void Gsub(const A &ra);	//friend 권한을 접근하기 위함보다도 A와 관련된 함수라는 것을 표현하기 위해 사용
//};
//
//void Gsub(const A &ra) {					//A & ra = A(5)는 안되고 const A & ra = A(5)는 가능하므로 임시오브젝트도 가능해짐
//	cout << ra.GetNo() << endl;		//private 멤버 no 접근 가능
//}
//
//int main(void) {
//	A aa(5);
//	Gsub(aa);
//
//	Gsub(A(5));	//임시 오브젝트를 &에 둘수 없다, const A &ra로 쓰면 가능해짐
//	
//
//}



///*fiend 함수2*/
//#include <iostream>
//using namespace std;
//
//class A;		//밑에 A를 못알아보므로 전방선언
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
//	friend void B::Bsub(const A *ap);		//B클래스와 연관의 의미
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



