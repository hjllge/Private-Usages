//#include <stdio.h>
//
//struct st {
//	int no;
//	char ch;
//};
//
//
//void InitStruct(struct st *t, int n, char c);		//st�� ��ƿ� �뵵
//void PrintStruct(const struct st *t);				//st�� �б⸸ �ϴ� �뵵, ������ up!
//
//int main(void) {
//	struct st aa;
////	void InitStruct(struct st *aa, int n, char c);	//���� ���� ����(main������ �Ҹ�)
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
//	const int c = 5;	//�ݵ�� �ʱⰪ�� �����ؾ��Ѵ�! (���൵ �������� �Ǵµ� ���� �ʴ�)
//	//char str[c];		//�������µ�, c�����Ϸ��� �����Ϸ� ���� c�� ����� ���� �ʴ´ٴ� �ǹ�
//
//	int *p = &c;
//	*p = 10;
//	printf("%d\n", c);	//10���� �ٲ�(c�� const�� �Ϻ����� �ʴ�, �׳� ����� �ƴ� �ٲ���� �ִ� read only ����)
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
//	printf("%d\n", *(int*)((char *)p - 12));	//-12������ size �����
//	printf("%d\n", _msize(p));					//���� ���̶� ������ ����
//	free(p);	//size��ŭ �Ҵ��� ���� �˰� �����Ƿ� size��ŭ �����Ѵٰ� ���ص� ��
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