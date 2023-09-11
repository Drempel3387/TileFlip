#pragma once
class Tile
{
private:
	char symbol;
	bool is_flipped;
public:
	//constructors
	Tile();
	Tile(char);

	//get and set
	char get_symbol() const;
	bool get_is_flipped() const;
	void set_symbol(char);
	void set_is_flipped(bool);

	friend bool operator==(const Tile first, const Tile second);
};