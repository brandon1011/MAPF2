#include "../src/Grid.h"
#include "../src/Bfs.h"
#include "../src/Heuristic.h"

#include <iostream>
using namespace std;

int main() {

	Point x(2,0);
	Point y(1,2);

	cout << ((x == y) ? "True\n" : "False\n");

	cout << "Hello World\n";

	Grid g("grids/grid_test1.txt");

	auto adj_ptr = g.adj(x);

	for (int i=0; i<DIM; i++) {
		cout << ((adj_ptr[i]) ? "True" : "False") << endl;
	}

	Bfs bfs(&g, Point(0,0), Point(0,3));
	cout << "Bfs cost " << bfs.cost() << endl;

	cout << "Starting preprocessing step\n";
	Heuristic h(&g);
	cout << "Finished preprocessing step\n";

	cout << "Heuristic value for (0,0)-->(5,2) = " << h.find(Point(0,0), Point(5,2)) << endl;
	cout << "Heuristic value for (5,2)-->(0,0) = " << h.find(Point(5,2), Point(0,0)) << endl;

	return 0;
}
