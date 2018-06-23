// BlackJack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;
int main()
{
	srand((int)time(0));
	int Bet;
	int Money = 500;
	string Solution;
	cout << "Hello! Welcome to Black Jack!\nYou have 500 Cash." << endl;
	cout << "Write \"Hit\" to get a card, or write \"Pass\" to finish the game.\n";
	do {
		cout << "Chose your bet : ";
		cin >> Bet;
		cout << "Your bet is " << Bet << endl;
		int Point = 0;
		int Dealer = 0;
		cin >> Solution;
		do
		{
			if (Solution == "Hit")//Âûäà÷à êàðò èãðîêà
			{
				int Card = rand() % 10 + 1;
				cout << (Point += Card) << endl;
				getline(cin, Solution);
			}
			else if (Solution == "Pass" || Point == 21)//Ïåðåõîä ê ñðàâíåíèþ êàðò ñ äèëåðîì 
			{
				cout << "Your score is " << Point << endl;
				do
				{
					int Card = rand() % 10 + 1;
					cout << "Dealer's card " << (Dealer += Card) << endl; //Âûäà÷à êàðò äèëåðà
				} while (Dealer < 17);
				if (Dealer < Point && Point < 22) {//Óñëîâèå ïîáåäû
					int Total = Money + Bet * 1.5;
					cout << "You win!" << endl;
					cout << "Your Cash is " << Total << endl;
				}
				else if (Dealer > Point && Dealer <= 21)//Óñëîâèå ïðîèãðûøà
				{
					int Total = Money - Bet;
					cout << "You lose!" << endl;
					cout << "Your Cash is " << Total << endl;
				}
				else if (Dealer == Point) {// Íè÷üÿ
					cout << "Smooth!" << endl;
					cout << "Your Cash is " << Money << endl;
				}
				break;
			}
			if (Point > 21) {//Ïåðåáîð
				cout << "You lose!" << endl;
				cout << "Your Cash is " << (Money -= Bet) << endl;
			}
			cin >> Solution;
		} while (Point < 21);
	} while (Money > 0);
	system("pause");
	return 0;
}
