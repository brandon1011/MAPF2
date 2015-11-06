#include "Bfs.h"
#include <limits>

#include <iostream>
using namespace std;

Bfs::Bfs(Grid* g, Point init, Point goal): grid(g), goal(goal) {
	open_list.push_back(Node(init,0));
	search();
}

void Bfs::search() {
	while (!open_list.empty()) {
		auto select = open_list.front();
		open_list.pop_front();

		auto adj_arr = grid->adj(select.pos);

		closed_list.insert(grid->hash(select.pos));	/* Add selected node to closed list */

		/*cout << "Expanding point (" << select.pos.x << "," << select.pos.y << ")"
			<< "Cost = " << select.cost << endl;*/

		if (select.pos == goal) {
			soln_cost = select.cost;
			return;
		}

		for (int i=0; i<DIM; i++) {
			auto move_i = select.pos.move(i);
			int  hash = grid->hash(move_i);

			if (adj_arr[i] && closed_list.find(hash) == closed_list.end()) {
				open_list.push_back(Node(move_i, select.cost + 1));
			}
		}
	}
	/* No solution */
	soln_cost = std::numeric_limits<int>::max();
}