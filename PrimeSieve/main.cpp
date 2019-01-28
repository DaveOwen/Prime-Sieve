//Written by: David Owen

#include <iostream>
#include <Windows.h>
#include <bitset>
#include <math.h>

#define RUNS 10000  // How many times the code will run. I use run each section of code a set number of times, divide by that number
// to get the average. I had to to this because the program was running too fast for the GetTickCount() to get a speed.
#define RANGE 100000 // What number of primes to search up to
#define R2 RANGE/2
#define BRUNS 100000


int main()
{
	//Set up varibles
	int count;
	char primes[RANGE];
	int searchRange = sqrt(R2) + 1;
	DWORD startTime, endTime;

	//############################ SIEV #################################
	startTime = GetTickCount();

	for (int k = 0; k < RUNS; ++k)
	{
		count = 0;
		memset(primes, 0, R2);
		for (int i = 0; i < searchRange; ++i)
		{
			if (primes[i] == 0)
			{
				for (int j = (i << 1)*i + (i << 2) + (i << 1) + 3; j < R2; j += i * 4 + 6)
				{
					primes[j] = 1;
					primes[j + i * 2 + 3] = 1;
				}
			}
		}
	}
	endTime = GetTickCount();
	for (int i = 0; i < R2; i++) if (primes[i] == 0) count++;

	float totalOp = ((float)endTime - startTime) / (1000 * RUNS);
	//#####################################################################



	//#################### MEMSET FUNCTION TIMING TEST ####################
	// Here I am timing how long the memset function takes, so I can take that off the time for the sieve

	float totalMemset = ((float)endTime - startTime) / (1000 * RUNS);
	//#####################################################################




	//####################  OUTPUT TIME AND PRIMES  ######################
	std::cout << "Optimised Sieve Time:  ";
	std::cout << totalOp;
	std::cout << "\nPrimes Found: ";
	std::cout << count + 1;
	//#####################################################################
	return 0;
}
