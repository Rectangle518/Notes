#include <iostream>
#include <thread>

typedef struct {
	int N;
	int terms;
	float* x;
	float* y;
} my_args;

void sinx(int N, int terms, float* x, float* y) 
{
	for (int i = 0; i < N; i++) 
	{
		float value = x[i];
		float numer = x[i] * x[i] * x[i];
		int denom = 6;
		int sign = -1;
		
		for (int j = 1; j <= terms; j++) 
		{
			value += sign * numer / denom;
			numer *= x[i] * x[i];
			sign *= -1;
			denom *= (2*i+2) * (2*i+3);
		}
		
		y[i] = value;
	}
}

void my_thread_func(my_args* args) 
{
	sinx(args->N, args->terms, args->x, args->y);
}

void parallel_sinx(int N, int terms, float* x, float* y) 
{
	std::thread my_thread;
	my_args args;
	
	args.N = N / 2;
	args.terms = terms;
	args.x = x; 
	args.y = y;
	
	my_thread = std::thread(my_thread_func, &args);
	sinx(N-args.N, terms, x, y);
	my_thread.join();
}

















