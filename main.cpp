#include "sierpinski.hpp"


int main()
{
	int N;
	char reply; 

	presentation();
	
	do 
	{
		question(reply);
		if (reply == 'Y' or reply == 'y')
		{
			cout << "Enter a value ' N' which is a power of 2 (1, 2, 4, 8, 16, 32, 64, 128 ...) :";
			cin >> N;
			clearScreen();
			if (tester(N))
			{
				cout << endl;
				print(N);
				triangleCounterByLivel(N);
			}
			else
			{
				cout << "N must be a power of 2. Retry" << endl;
			}
		}
		cout << endl;
	}
	while (reply != 'N' and reply != 'n');
	
	cout << endl;	
	cout << "See you soon ! " << endl << endl;
	
	return 0;
}
