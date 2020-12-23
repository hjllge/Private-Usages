//#include <stdio.h>
//
//struct st {
//	int no;
//	char ch;
//};
//
//
//void InitStruct(struct st *t, int n, char c);		//st에 담아올 용도
//void PrintStruct(const struct st *t);				//st를 읽기만 하는 용도, 가독성 up!
//
//int main(void) {
//	struct st aa;
////	void InitStruct(struct st *aa, int n, char c);	//여기 선언도 가능(main에서만 불림)
//
//	printf("%d\n", sizeof(aa));
//	InitStruct(&aa, 5, 'A');
//	PrintStruct(&aa);
//}
//
//void PrintStruct(const struct st *t) {
//	printf("%d %c\n", t->no, t->ch);
//}
//
//void InitStruct(struct st *t, int n, char c) {
//	t->no = n;
//	t->ch = c;
//}


//#include <stdio.h>
//int main(void) {
//	int n = 5, k = 6;
//	const int c = 5;	//반드시 초기값을 설정해야한다! (안줘도 컴파일은 되는데 옳지 않다)
//	//char str[c];		//에러나는데, c컴파일러는 컴파일러 조차 c를 상수로 보지 않는다는 의미
//
//	int *p = &c;
//	*p = 10;
//	printf("%d\n", c);	//10으로 바뀜(c의 const는 완벽하지 않다, 그냥 상수가 아닌 바뀔수도 있는 read only 역할)
//}



//#define _CRT_SECURE_NO_WARNINGS
//#include <stdlib.h>
//#include <stdio.h>
//
//int main(void) {
//	int size;
//	int *p;
//	printf("Size : ");
//	scanf("%d", &size);
//
//	p = (int *)malloc(size);
//	printf("%d\n", *(int*)((char *)p - 12));	//-12번지에 size 저장됨
//	printf("%d\n", _msize(p));					//위에 줄이랑 동일한 역할
//	free(p);	//size만큼 할당한 것을 알고 있으므로 size만큼 해제한다고 안해도 됨
//}



//#include <stdio.h>
//
//int main(void) {
//	FILE *fp;
//	char buf[133];
//	fopen_s(&fp, "main2.cpp", "r");
//
//	while (fgets(buf, 133, fp)) {
//		printf("%s", buf);
//	}
//
//	fclose(fp);
//}