#include <iomanip>
#include <iostream>	//header파일이 만들어진 순서가 원칙
using namespace std;//iostream 바로 밑에 이거 있어야함
#include "Score.h"

Score * Score::pScore;
int Score::cnt;
int Score::classtot;

Score * Score::SetCount(int cnt)
{
	Score::cnt = cnt;
	if (Score::cnt <= 0 || Score::cnt > 100) {
		do {
			cout << "Count :";
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cin >> Score::cnt;
		} while (cin.fail() || Score::cnt < 1 || Score::cnt > 100);
	}
	Score::pScore = new Score[Score::cnt];
	return Score::pScore;
}

int Score::GetCount(void)	//const 쓸 수 없음(static 이라(?))
{
	return Score::cnt;
}

void Score::PrintReport(BOOL delflag)
{
	cout << endl;
	cout << "====================================" << endl;
	cout << std::setw(10) << std::left << "Name"
		<< setw(4) << "KOR" << setw(4) << "ENG" << setw(4) << "MAT"
		<< setw(5) << "TOT" << setw(7) << "AVE" << endl;
	cout << "====================================" << endl;
	for (int n = 0; n < Score::cnt; n++) {
		Score::pScore[n].PrintScore();
	}
	cout << "====================================" << endl;
	cout << "Class AVE : " << Score::classtot / (Score::cnt * 3.0) << endl;
	cout << "====================================" << endl;

	if (delflag == TRUE) delete[] Score::pScore;
}

Score::Score(void)
{
	char temp[20];
	size_t len;

	do {
		cout << "Name:";
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(temp, 20);
	} while (cin.fail());
	len = ::strlen(temp);
	if (len == 0) name = (char *)"";	//""는 const char *
	else {
		name = new char[++len];
		::strcpy_s(name, len, temp);
	}

	do {
		cout << "Score(K, E, M):";
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cin >> kor >> eng >> mat;
	} while (cin.fail() || !ScoreRng(kor) || !ScoreRng(eng) || !ScoreRng(mat));

	CalcScore();
}

Score::Score(const char * irum, int k, int e, int m)
{
	size_t len;

	len = ::strlen(irum);
	if (len == 0) name = (char *)"";
	else {
		name = new char[++len];
		::strcpy_s(name, len, irum);
	}
	kor = ScoreRng(k), eng = ScoreRng(e), mat = ScoreRng(m);

	CalcScore();
}

void Score::CalcScore(void)
{
	tot = kor + eng + mat;
	ave = tot / 3.0;
	Score::classtot += tot;
}

void Score::PrintScore(void)
{
	static char ch[] = "FFFFFFDCBAA";

	cout << std::setw(10) << std::left << name
		<< setw(4) << ch[kor / 10] << setw(4) << ch[eng / 10] << setw(4) << ch[mat / 10]
		<< setw(5) << tot << setw(7) << std::fixed << std::setprecision(2) << ave << endl;
}

Score::~Score(void)
{
	if (*name != '\0') delete[] name;
}