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

int partition(int* x, int lo, int hi)
{
	int pivot = x[lo];
	int i = lo;
	int j = hi;
	int tmp;
	while(true)
	{
		while(x[i] < pivot)
		{
			i++;
		}
		while(x[j] > pivot)
		{
			j--;
		}
		
		if(i >= j)
		{
			return j;
		} 
		tmp = x[i];
		x[i] = x[j];
		x[j] = tmp;
		i++;
		j--;
	}
}
void quicksort(int* x, int lo, int hi)
{
	if(lo < hi)
	{
		int p = partition(x,lo,hi);
		quicksort(x, lo, p);
		quicksort(x, p+1,hi);
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
	quicksort(x, 0, N-1);
	print(x,N);

	return 0;
}
