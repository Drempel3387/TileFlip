#include "Game.h"
#include <cstdlib>
#include <iostream>
#include <chrono>
#include <thread>
//gm
const int TWOMORE = 2;
const int ZERO = 0;
const int STARTVAL = -1;
const int SLEEPTIME = 3000;
void Game::play_game(TileCollection& tile_collection)
{
	int num_flipped = 0;
	Tile* curr_first = nullptr, * curr_second = nullptr; //currently flipped tiles
	while (num_flipped != tile_collection.get_size() * tile_collection.get_size())
	{
		//get and flip the first tile
		curr_first = Game::get_tile_from_user(tile_collection);
		curr_first->set_is_flipped(true);
		std::cout << "\n";

		//get and flip the second tile
		curr_second = Game::get_tile_from_user(tile_collection);
		curr_second->set_is_flipped(true);
		std::cout << "\n";
		std::cout << tile_collection;

		if (Game::check_tiles(curr_first, curr_second))//the tiles have the same symbol
		{
			num_flipped += TWOMORE;
			std::cout << "Match!\n";

		}
		else
		{
			curr_first->set_is_flipped(false);
			curr_second->set_is_flipped(false);
			std::cout << "No match!\nPlease keep trying\n";
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(SLEEPTIME));//sleep for three seconds   
		std::system("cls"); //clear the console. "memory" portion of the game, the player must memorize positions of different symbols
	}
	std::cout << "You win, congratulations!!!\n";
}

void Game::get_coord(int* ret, std::string msg, std::string err_msg, int min, int max)
{
	int num;
	std::cout << msg;
	while (!(std::cin >> num) || num > max || num < min)
	{
		if (std::cin.fail())
		{
			std::cin.clear();  //clear the error
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  //clear input buffer
			std::cout << "Incorrect input, please try again\n";
			std::cout << msg;//attempt to read again
		}
		else
		{
			std::cout << err_msg << "\n";
			std::cout << msg;//attempt to read again
		}
	}
	*ret = num;
}

Tile* Game::get_tile_from_user(TileCollection& tile_collection)
{
	int x_coord = STARTVAL, y_coord = STARTVAL;
	do
	{
		if (x_coord != STARTVAL || y_coord != STARTVAL)
		{
			std::cout << "Please choose a tile which is not flipped\n";
		}
		std::cout << tile_collection;


		Game::get_coord(&x_coord, "Please enter the x coordinate of the tile you would like to flip: ", "X coordinate is either too big or too small, please try again\n", ZERO, tile_collection.get_size());
		Game::get_coord(&y_coord, "Please enter the y coordinate of the tile you would like to flip: ", "Y coordinate is either too big or too small, please try again\n", ZERO, tile_collection.get_size());
	} while ((tile_collection.get_tile_arr()[y_coord] + x_coord)->get_is_flipped());

	return ((tile_collection.get_tile_arr()[y_coord] + x_coord));
}
bool Game::flip_tile(Tile* tile)
{
	if (tile->get_is_flipped())
		return false;
	tile->set_is_flipped(true);
	return true;
}
bool Game::check_tiles(Tile* first, Tile* second)
{
	return (*first == *second);
}