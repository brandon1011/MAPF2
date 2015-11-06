#include "Heuristic.h"
#include "Bfs.h"
#include <limits>

Heuristic::Heuristic(Grid* g): grid(g) {

}

int Heuristic::find(const Point& a, const Point& b) {
	int key = hash(a,b);
	auto it = lookup_table.find(key);

	if (it == lookup_table.end()) 
		return std::numeric_limits<int>::max();

	return it->second;
}

int Heuristic::hash(const Point&a, const Point& b) {
	int dimX = grid->dim().x;
	int dimY = grid->dim().y;

	return grid->hash(a)*dimX*dimY + grid->hash(b);
}

void Heuristic::init() {
	int dimX = grid->dim().x;
	int dimY = grid->dim().y;

	for (int ia=0; ia<dimX; ia++) {
		for (int ja=0; ja<dimY; ja++) {
			Point a(ia, ja);

			for (int ib=ia; ib<dimX; ib++) {
				for (int jb=ja; jb<dimY; jb++) {
					Point b(ja, jb);
					
					if (grid->clear(a) && grid->clear(b)) {
						Bfs bfs(grid,a,b);
						lookup_table.emplace(hash(a,b), bfs.cost());
					}	
				}
			}
		}
	}
}