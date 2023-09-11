#pragma once
#include "TileCollection.h" 

namespace Game
{
	void play_game(TileCollection&);
	bool all_flipped(TileCollection&);
	void get_coord(int*, std::string, std::string, int, int);
	Tile* get_tile_from_user(TileCollection&);
	bool flip_tile(Tile*);
	bool check_tiles(Tile*, Tile*);
}
