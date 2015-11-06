#ifndef BFS_H
#define BFS_H

#include "Grid.h"

#include <unordered_set>
#include <list>


class Bfs {
public:
	Bfs(Grid* g, Point init, Point goal);
	int cost();		/* Get the solution cost to goal, if exists*/

private:
	struct Node {
		Point	pos;
		int 	cost;
		Node(Point p, int c): pos(p), cost(c) {}
	};

	list<Node> 			open_list;
	unordered_set<int>	closed_list;
	Grid*	grid;
	Point	goal;
	int 	soln_cost;

	void	search();	/* Find solution cost to goal */


};

inline
int Bfs::cost() {
	return soln_cost;
}

#endif //BFS_H