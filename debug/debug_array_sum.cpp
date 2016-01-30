#include <array>
#include <iostream>
#include <cstdlib>



int array_sum( int* input, int size )
{
	int temp[1024];
	int sum = 0;
	
	for (int i = 0; i < size || i < 1024; i++)
		temp[i] = input[i];
	
	for (int i = 0; i < size; i++)
		sum += temp[i];
	
	return sum;
}

int main(int argc, char* argv[])
{
	int size = atoi(argv[1]);
	int input[size];

	for(int i = 0; i < size; ++i)
	{
		std::cout << input[i] << std::endl;
	}

	int *input_ptr = input;



	std::cout << array_sum(input_ptr, size) << std::endl;



}
