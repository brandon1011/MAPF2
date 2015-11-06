#include "../src/Grid.h"
#include "../src/Bfs.h"

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

	return 0;
}
