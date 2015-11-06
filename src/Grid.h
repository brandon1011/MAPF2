/* Written by Brandon Wu */
#ifndef GRID_H
#define GRID_H

#define DIM 8	/* Num of possible moves (N, S, E, W, ...) */

#include <string>
#include <memory>

using namespace std;
enum Card {	NORTH, SOUTH, EAST, WEST, NE, NW, SE, SW, WAIT};

struct Point {
	int x;
	int y;
	Point(int posx, int posy): x(posx), y(posy) {}
	Point(): x(0),y(0) {};

	bool operator==(const Point& lhs) {
		return (this->x == lhs.x && this->y == lhs.y);
	};

	Point move(int dir);
};

class Grid {
public:
	unique_ptr<bool[]>	adj(const Point& pos) const;
	bool	clear(const Point& pos) const;
	int		hash(const Point& p);
	Point	unhash(int hash);	
	void	display(void);
	Point	dim(void);	// Dimension of the grid

	Grid(string pathname);
	~Grid();

private:
	bool**	grid;
	int	dimX;
	int	dimY;	
};

inline
int Grid::hash(const Point& p) {
	return (p.x)*dimY + p.y;
}
inline
Point Grid::dim(void) {
	return Point(dimX, dimY);
}
inline
bool Grid::clear(const Point& pos) const {
	return (pos.x>=0 && pos.x<dimX && pos.y>=0 && 
		pos.y<dimY && grid[pos.x][pos.y]);

}
inline
Point Grid::unhash(int hash) {
	return Point((hash/dimY),(hash%dimY));
}

#endif //GRID_H
