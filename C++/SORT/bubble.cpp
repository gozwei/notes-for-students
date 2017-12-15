#include <iostream>
#include <chrono>

using namespace std;

void print(int* x, int N)
{
	for(int i = 0; i < N; i++)
	{
		cout << x[i] << "  ";
	}
	cout << endl;
}

void bubble_sort(int* x, int N)
{
	int tmp;
	while(true)
	{
		int swaps = 0;
		for(int i=0; i<N-1; i++)
		{
			if(x[i]>x[i+1])
			{
				tmp 	= x[i];
				x[i] 	= x[i+1];
				x[i+1] 	= tmp;
				swaps++;
			}
		}
		//print(x,N);
		if(swaps == 0)
		{
			break;
		}
	}
}

int main()
{
	int N = 20;
	int* x = new int[N];
	for(int i = 0; i < N; i++)
	{
		x[i] = rand()%10;
	}
	

	print(x,N);

	bubble_sort(x, N);
	
	print(x,N);

	return 0;
}
