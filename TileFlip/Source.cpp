#include "TileCollection.h"
#include "Game.h"

//levels of difficulty
const int MINDIF = 1;
const int MAXDIF = 3;
const int arr[] = { 4, 6, 8 };

int main(void)
{
	std::cout << "Welcome to the TileFlip game!\n"; 
	std::cout << "This is a memory game where you must flip tiles and memorize the symbols at specific positions.\n";
	std::cout << "Once two of the same tiles have been flipped sucessively, a match has been found, and these tiles will stay unflipped.\n";
	std::cout << "If a match has not been found, you will have three seconds to memorize the symbols, and the tiles will flip back.\n";
	std::cout << "unflipped tiles are denoted by a \"X\"\n";
	std::cout << "Once all tile have been flipped, you have won the game.\nGood Luck!\n\n";

	std::cout << "Now that you understand the rules, lets get started.\n";
	
	
	int difficulty;
	Game::get_coord(&difficulty,"Please choose your level of difficulty:\n1: Easy\n2: Medium\n3: Hard\n", "Input values must be between one and three\n", MINDIF, MAXDIF);
	TileCollection T = TileCollection(arr[difficulty - 1]);
	std::system("cls");

	Game::play_game(T);  
	return 0;
}