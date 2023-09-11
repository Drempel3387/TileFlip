#include "TileCollection.h"
#include <string>
#include <algorithm> 
#include <ctime>
std::string symbols = "!@#$%^&*()-=<>?";   
//constructor that will create a randomized collection of tiles
TileCollection::TileCollection(int Size) : size(Size), tile_arr(new Tile* [size])
{
    //calculate the number of symbols needed for the collection
    int total_symbols = size * size;

    //create a symbol pool with an equal number of each symbol
    std::string symbol_pool;
    for (int i = 0; i < size; i++) 
    {
        symbol_pool += std::string(size, symbols[i]);//add "n" (size) symbols of each type to the collection   
    }

    //shuffle the symbol pool to randomize the order of symbols
    std::random_shuffle(symbol_pool.begin(), symbol_pool.end());

    //initialize the tile_arr with symbols from the shuffled pool
    for (int i = 0; i < size; i++)
    {
        tile_arr[i] = new Tile[size];
        for (int j = 0; j < size; j++)
        {
            char random_symbol = symbol_pool.back();//get the last element in the pool
            symbol_pool.pop_back();//pop the last element
            tile_arr[i][j].set_symbol(random_symbol);
        }
    }
}

TileCollection::TileCollection(const TileCollection& other)//deep copy constructor
{
    this->size = other.size;  
    this->tile_arr = new Tile * [size];

    for (int i = 0; i < size; ++i)
    {
        if (other.tile_arr[i] != nullptr)
        {
            this->tile_arr[i] = new Tile(*(other.tile_arr[i])); //deep copy each Tile
        }
        else
        {
            this->tile_arr[i] = nullptr;
        }
    }
}
TileCollection::~TileCollection() 
{
    for (int i = 0; i < size; i++) 
    {
        delete[] tile_arr[i]; //delete each row of Tile objects 
    }
    delete[] tile_arr; //delete the array of rows 
}

TileCollection& TileCollection::operator=(const TileCollection& other)
{
    if (this == &other) //self-assignment check
    {
        return *this;
    }

    //create a temporary TileCollection using the copy constructor
    TileCollection temp(other); 

    //swap the contents of the temporary object with the current object 
    std::swap(size, temp.size); 
    std::swap(tile_arr, temp.tile_arr); 

    return *this; 
}
//get and set
int TileCollection::get_size() const { return size; } 
Tile** TileCollection::get_tile_arr() const { return tile_arr; } 

std::ostream& operator<<(std::ostream& os, const TileCollection& tile_collection)
{
    int size = tile_collection.get_size();

    //column numbers
    os << "  ";
    for (int col = 0; col < size; col++) {
        os << col << " ";
    }
    os << "\n";

    for (int i = 0; i < size; i++)
    {
        // Print row number
        os << i << " ";

        for (int j = 0; j < size; j++)
        {
            if (!tile_collection.get_tile_arr()[i][j].get_is_flipped()) //if not flipped, print an X
                os << "X ";
            else
                os << tile_collection.get_tile_arr()[i][j].get_symbol() << " ";//if flipped, print the symbol
        }
        os << "\n";
    }
    return os;
}
