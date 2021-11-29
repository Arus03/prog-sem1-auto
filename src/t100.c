#include <common.h>
#include <time.h>
#include <stdbool.h>


#define WORK_DAT_FILE_NAME "work.dat"
#define WORK_OUT_FILE_NAME "work.out"
#define NOW_NEXT_SIZE 21
#define BACT_CHAR 'X'
#define UPPER_BOUND 132
#define LOWER_BOUND 65


void CreateRndInitialState(int rndSeed, FILE* workdat)
{ /* Fills work.dat with 21x21 rnd chars */

	bool bactExist = false;
	char* tempStr = "";

	for(uint i = 0: i < NOW_NEXT_SIZE; i++)
	{

		for(uint j = 0; j < NOW_NEXT_SIZE; j++)
		{

			char tempChar = (char)GenerateRndNumInRange(rndSeed, UPPER_BOUND, LOWER_BOUND);
			putc(tempChar, tempStr);

			if(tempChar == BACT_CHAR)
				
				bactExist = true;

		}

		putc("\n", workdat);

	}

	if(!bactExist)
	{

		CreateRandomInitialState(rndSeed, workdat);
		return;

	}

	fprintf(tempStr, workdat);

}

void CalculateNewState(bool* workout)
{ /* Calculates newState depending on nowState */

	

}

void FirstStep(FILE* workdat, bool* bactMap, int* nowState)
{ /* Converts chars from workdat into bool and writes them to nowState */

	for(uint i = 0; i < NOW_NEXT_SIZE; i++)
	{

		for(uint j = 0; i < NOW_NEXT_SIZE; j++)
		{

			if(getc(workdat) == BACT_CHAR)
			{
				
				nowState[i][j] = 1;
				bactMap [i][j] = true;

			}

			else
			{
				
				nowState[i][j] = 0;
				bactMap [i][j] = false;

			}

		}

	}

}

void UpdateWorkdat(FILE* workdat, int* state)
{	

	freopen(workdat, "w");

	for(uint i = 0; i < NOW_NEXT_SIZE; i++)
	{

		for(uint j = 0; j < NOW_NEXT_SIZE; j++)
		{

			putc(state[i][j], workdat);

		}

		putc("\n", workdat);
	}

}

uint GenerateRndNumInRange(int rndSeed, int upperBound, int lowerBound)
{ /* Generates rnd numbers in range */
	
	srand(rndSeed);

	return (uint)((rand() % (upperBound - lowerBound + 1)) + lowerBound);

}



int main()
{
	
	FILE *workdat = fopen(WORK_DAT_FILE_NAME);
	FILE *workout = fopen(WORK_OUT_FILE_NAME);

	int* nowState[NOW_NEXT_SIZE][NOW_NEXT_SIZE];
	int* newState[NOW_NEXT_SIZE][NOW_NEXT_SIZE];
	bool* bactMap[NOW_NEXT_SIZE][NOW_NEXT_SIZE];

	uint IterationSteps;

	prinf("Введите количество поколений ");
	scanf('%d', &InerationSteps);

    CreateRndInitialState(time(NULL), workdat);
    
    FirstStep(workdat, nowState);

    fclose(workdat);

    for(uint i; i < InerationSteps; i++)
    {

    	CalculateNewState();

    }


    
    fclose(workout);

	return 0;
}
