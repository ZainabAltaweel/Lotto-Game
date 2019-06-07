// File Name: LottoTicket.h
// Author: Zainab Alaweel
// Date: 09/18/ 2018
// Compiler Used: Default compiler (MSVC)
//<This file is the header, which is the class definition, the header file include functions prototype and data representation>
#pragma once
#include<iostream>
#include <string>

using namespace std;
extern int generateRandom(int m, int n);
class LottoTicket
{
public:
	LottoTicket();
	LottoTicket(int);
	void generateLotto(int, int);
	bool play(int a);
	int getLottosWonCount();
	int getId();
	friend ostream &operator<<(ostream &output, const LottoTicket &t);
	
private:
	int Slot[15];
	int count = 0;
	int player;
	int	Lotto;
};

