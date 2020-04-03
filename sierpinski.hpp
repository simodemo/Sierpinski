#include <iostream>
#include <math.h>
#include <stdio.h>
#define clear() printf("\033[H\033[J")

using namespace std;

char triang[128][128];



void clearScreen()
{
	clear();
}



void presentation()
{
	cout << endl;
	cout << "Sierpinski Triangle in C++" << endl;
	cout << "Created : 15/03/2010" << endl;
	cout << "Author  : Simone DELLA MONICA" << endl << endl;
}



void question(char &reply)
{
	cout << "Do you want to create a Sierpinsky Triangle (Y) or (N) : " << endl;
	cin >> reply;
	while (reply != 'Y' and reply != 'y' and reply != 'N' and reply != 'n')
	{
		cout << "Error - Please enter : 'N' for no or 'Y' for yes " << endl << endl;
		cin >> reply;
	}
}




bool tester(int N)
{
	bool test = false;
	if(N==1)
	{
		cout << "You choose to print only one triangle" << endl << endl;
		cout << "#" << endl << endl;
		return test;
	}
	else 
	{
		if (N>128)
		{
			return test;
		}
		else
		{
			for(int i=1; i<128; i++)
			{
				if(pow(2, i) == N)
				{
					test = true;
					break;
				}
				else 
				{
					;
				}
			}
			return test;
		}
	}
}



void triangle(int x, int y, int N) 
{
	if(N == 1)
	{
		triang[x][y]  = '#';
	}
	else 
	{
		triangle(x, y, N>>1);
		triangle(x + (N>>1), y, N>>1);
		triangle(x, y + (N>>1), N>>1);
	}
}



void print(int N)
{
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			triang[i][j] = ' ';
		}
	}
	triangle(0, 0, N);
	for(int i=0; i<N; i++)
	{
		int n = N;
		for(int j=N-1; j>=0; --j) 
		{
			if(triang[i][j] == ' ')
			{
				n--;
			}
			else 
			{
				break;
			}
		}
		for(int j = 0; j<n; j++)
		{
			cout << triang[i][j];
		}
		cout << endl;
	}
}



void triangleCounterByLivel(int N)
{
	double nbtriangles = 0;
	double save = 0;
	int cpt = 0;
	int j = N;

	while(j!=1)
	{
		j=j/2;
		cpt++;
	}

	for(int i=0; i<cpt+1; ++i)
	{
		nbtriangles = save + pow(3,i);
		save = nbtriangles;
	}
	cout << "We have : " << save << " internal triangles " << endl;
}
