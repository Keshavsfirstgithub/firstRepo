#include <iostream>
#include "Classes.cpp"
using namespace std;
#include "solution.h"

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		printReversed(head);
		cout << endl;
	}
	return 0;
}