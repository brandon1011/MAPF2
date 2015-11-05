#include "../src/Grid.h"
#include <iostream>
using namespace std;

int main() {

	Point x(1,2);
	Point y(1,2);

	cout << ((x == y) ? "True\n" : "False\n");

	cout << "Hello World\n";

	Grid g("grids/grid_test1.txt");
	
	return 0;
}
