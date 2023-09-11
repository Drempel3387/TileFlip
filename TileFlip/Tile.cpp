#include "Tile.h"

//constructors
Tile::Tile() : symbol(0), is_flipped(false) {};

Tile::Tile(char Symbol) : symbol(Symbol), is_flipped(false) {};

//get and set
char Tile::get_symbol() const { return symbol; }
bool Tile::get_is_flipped() const { return is_flipped; }
void Tile::set_symbol(char symbol) { this->symbol = symbol; }
void Tile::set_is_flipped(bool is_flipped) { this->is_flipped = is_flipped; } 



bool operator==(const Tile first, const Tile second)
{
	return (first.get_symbol() == second.get_symbol());
}