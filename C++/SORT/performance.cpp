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
	std::chrono::high_resolution_clock::time_point ts1, ts2, te1, te2;
	srand(time(NULL)); 
	int N = 200000;
	int* x = new int[N];
	int* y = new int[N];
	for(int i = 0; i < N; i++)
	{
		x[i] = rand()%10;
		y[i] = x[i];
	}
	//print(x,N);
	ts1 = chrono::high_resolution_clock::now();
	bubble_sort(x, N);
	te1 = chrono::high_resolution_clock::now();
	ts2 = chrono::high_resolution_clock::now();
	quicksort(y, 0, N-1);
	te2 = chrono::high_resolution_clock::now();
	
	auto duration1 = chrono::duration_cast<chrono::microseconds>( te1 - ts1 ).count();
	cout << "bubble sort: " << duration1/1e6 << " s"  << endl;

	auto duration2 = chrono::duration_cast<chrono::microseconds>( te2 - ts2 ).count();
	cout << "quicksort:   " << duration2/1e6 << " s"  << endl;

	int ok = 0;
	for(int i = 0; i < N; i++)
	{
		if(y[i] == x[i])
		{
			ok++;
		}
	}
	if(ok == N)
	{
		cout << "Result: OK!" << endl;
		cout << "QS " << duration1 / duration2 <<  " faster than BS" << endl;
	}
	else
	{
		cout << "Result: FAIL!" << endl;
	}
	//print(x,N);

	return 0;
}
