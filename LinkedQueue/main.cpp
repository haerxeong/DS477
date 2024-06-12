#include "LinkedQueue.h"

int main()
{	
    LinkedQueue test;
    int item = 0;
	
	for (int i = 8; i > 0; i--)
		test.enqueue(i);
	test.display();
	
	item = test.peek();
	cout << "item = " << item << endl;
	
	for (int i = 0; i < 3; i++)
		test.dequeue();
	test.display();	
	
	test.enqueue(15);
	test.display();
	
	return 0;
}
