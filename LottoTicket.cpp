// File Name: LottoTicket.cpp
// Author: Zainab Alaweel
// Date: 09/18/ 2018
// Compiler Used: Default compiler (MSVC)
//<This file is the implementation of LottoTicket class, which include functions' definition>

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "LottoTicket.h"
#include"pch.h"

using namespace std;

LottoTicket::LottoTicket()
{
};
LottoTicket::LottoTicket(int a)
{
	player = a;
}
int generateRandom(int m, int n)
{
	int x = n - 9;
	return m + rand() % x;
}
void LottoTicket::generateLotto(int a, int b)
{
	for (int m = 0; m < 15; m++)
	{
		int v = b - 9;
		Slot[m] = a + rand() % v;		
	}
	
}

bool LottoTicket::play(int z)
{
	Lotto = z;

	for (int f = 0; f < 15; f++) {
		if (Slot[f] == Lotto) {
			Slot[f] = -1;
			count++;
			break;
		}
	}
	if (count == 15) {
		return true;
	}
	else {
		return false;
	}
}

int LottoTicket::getLottosWonCount()
{
	return count; 
}

int LottoTicket::getId()
{
	return player;
}

ostream & operator <<(ostream & os, const LottoTicket & t)
{

	os << "Player # " << t.player << "   ";
	for (int j = 0; j < 15; j++) {
		os << t.Slot[j] << "    ";
	}
	os << "\n";
	
	return os;
}

