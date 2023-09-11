#pragma once
#include <iostream>
#include "Tile.h"

class TileCollection
{
private:
	static const int STARTSIZE = 8;  
	int size;
	Tile** tile_arr; 

public:
	//constructor and destructor
	TileCollection(int size = STARTSIZE);  
	~TileCollection();

    //Deep Copy
    TileCollection(const TileCollection& other);
   
	//equal overload
	TileCollection& operator=(const TileCollection& other);

	//get and set
	int get_size() const;
	Tile** get_tile_arr() const;
	friend std::ostream& operator<<(std::ostream& os, const TileCollection&);
};

