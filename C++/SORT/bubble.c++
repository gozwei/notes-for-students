#include <iostream>

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

void quicksort(int* x, int lewy, int prawy)
{
	if(prawy <= lewy)
	{
		return;
	}
	int i = lewy;
	int j = prawy;
	int tmp;
	int pivot = x[(lewy+prawy)/2];
	int step = 0;
	while(true)
	{
		while(x[i]<pivot)
		{
			i++;
		}
		while(x[j]>pivot)
		{
			j--;
		}
		if(i<=j)
		{
			tmp 	= x[i];
			x[i] 	= x[j];
			x[j] 	= tmp;
			i++;
			j--;
		}
		else
		{
			break;
		}
		step++;
		if(step > 10)
			break;
	}
	if(lewy < j)
	{
		quicksort(x, lewy, j);
	}
	if(prawy > i)
	{
		quicksort(x, i, prawy);
	}
}

int main()
{
	std::chrono::high_resolution_clock::time_point ts1, ts2, te1, te2;
	srand(time(NULL)); 
	int N = 2000;
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
	cout << "bubble sort: " << duration1 << endl;

	auto duration2 = chrono::duration_cast<chrono::microseconds>( te2 - ts2 ).count();
	cout << "quicksort:   " << duration2 << endl;

	int ok = 0;
	for(int i = 0; i < N; i++)
	{
		if(y[i] == x[i])
		{
			ok++;
		}
	}
	cout << ok << endl;

	//print(x,N);

	return 0;
}