#pragma once		//지원되지 않는 컴파일러가 있을 수 있음
#ifndef _SCORE_H_
#define _SCORE_H_	//보통 이런 형식으로 씀

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
	static Score * pScore;	//static 멤버는
	static int cnt;			//헤더파일이 아닌
	static int classtot;	//cpp에!
public:
	static Score * SetCount(int cnt = 0);
	static int GetCount(void);
	static void PrintReport(BOOL delflag = TRUE);
};

#endif