#ifndef HEURISTIC_H
#define HEURISTIC_H

#include "Grid.h"
#include <unordered_map>

class Heuristic {
public:
	Heuristic(Grid* g);
	int find(const Point& a, const Point& b);
private:
	int hash(const Point& a, const Point& b);
	void init();
	
	unordered_map<int, int> lookup_table;
	Grid*	grid;
};

#endif //HEURISTIC_H