// File Name: Lotto.cpp
// Author: Zainab Alaweel
// Date: 09/18/ 2018
// Compiler Used: Default compiler (MSVC)
// Lotto.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "LottoTicket.h"

using namespace std;


int main() {
	int num_of_players = 5; 
	LottoTicket players[5];  
	int min = 0; 
	int max = 0; 
	int max_rounds = 0;  
	int winner = -1;  
	bool gameover;
	string filename = "output.txt";   
	ofstream fout;    
	srand(time(NULL));     
	cout << "Enter the output filename: ";  
	cin >> filename;   
	cout << "Enter the minimum number: ";  
	cin >> min;  
	cout << "Enter the maximum number: "; 
	cin >> max; 
	cout << "Enter the number of rounds to be played: "; 
	cin >> max_rounds;  
	fout.open(filename, ofstream::app);  
	int i = 0;   
	while (i != num_of_players) { 
		LottoTicket player1(i);    
		player1.generateLotto(min, max);    
		players[i] = player1;    
		i++;
	}        
	cout << "\nGenerating Lottos for all players.....\n\n";   
	fout << "************************************************";
	fout << "\nGenerating Lottos for all players.....\n\n"; 
	for (LottoTicket lotto : players) 
	{
		cout << lotto;     
		fout << lotto;
	}

	i = 0;    
	cout << "\n";    
	cout << "------------------------------------------------";  
	cout << "\nGame is starting" << endl;  
	cout << "Round# \tLotto\tP#0\tP#1\tP#2\tP#3\tP#4" << endl;   
	fout << "\n"; 
	fout << "-----------------------------------------------";   
	fout << "\nGame is starting" << endl;  
	fout << "Round# \tLotto\tP#0\tP#1\tP#2\tP#3\tP#4" << endl;

	for (int j = 0; j < max_rounds; j++) 
	{
		int current_lotto = generateRandom(min, max);  
		cout << j << "\t" << current_lotto << "\t"; 
		fout << j << "\t" << current_lotto << "\t"; 
		for (LottoTicket &lotto : players) 
		{
			gameover = lotto.play(current_lotto); 
			cout << lotto.getLottosWonCount() << "\t";    
			fout << lotto.getLottosWonCount() << "\t";      
			if (gameover) {
				winner = lotto.getId();          
			break;
			} 
		}     
		cout << endl;  
		fout << endl; 
		if (gameover)
		{ 
			break;
		} 
	}   
	cout << "-------------------------------------------------";   
	cout << "\n\tRESULT: \t";  
	fout << "-------------------------------------------------";   
	fout << "\n\tRESULT: \t"; 
	if (winner >= 0) 
	{
		cout << "Winner is: Player " << winner << endl;  
		fout << "Winner is: Player " << winner << endl; 
	}
	else 
	{ 
		cout << "This game is a draw" << endl; 
		fout << "This game is a draw" << endl;
	}        
	return 0;
}

