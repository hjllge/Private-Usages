#pragma once		//�������� �ʴ� �����Ϸ��� ���� �� ����
#ifndef _SCORE_H_
#define _SCORE_H_	//���� �̷� �������� ��

enum BOOL { FALSE, TRUE };
#define ScoreRng(S) (((S >= 0) && (S <= 100)) ? (S) : (0))

class Score {
private:
	char * name;
	int kor, eng, mat, tot;
	double ave;
	void CalcScore(void);
public:
	Score(void);
	Score(const char * irum, int k, int e, int m);
	void PrintScore(void);
	~Score(void);
private:
	static Score * pScore;	//static �����
	static int cnt;			//��������� �ƴ�
	static int classtot;	//cpp��!
public:
	static Score * SetCount(int cnt = 0);
	static int GetCount(void);
	static void PrintReport(BOOL delflag = TRUE);
};

#endif