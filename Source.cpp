#include "Tree.h"
using namespace std;

int main() {
	shared_ptr<Tree<int>> t = make_shared<Tree<int>>();
	t->add(3);
	t->add(2);
	t->add(4);
	t->add(6);
	t->add(7);
	t->Print();
	cout << endl;
	cout << t->search(2);
	cout << t->getDiameter();
}