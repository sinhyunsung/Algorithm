#include <stdio.h>

int main(void)
{
	int numofscore, Maxscore;
	scanf("%i", &numofscore);

	int score[numofscore], sumofscore;
	double medium;

	sumofscore = 0;
	Maxscore = 0;

	for (int i = 0; i < numofscore; i++)
	{
		scanf("%i", &score[i]);
		sumofscore += score[i];
		if (score[i] > Maxscore)
		{
			Maxscore = score[i];
		}
	}


	medium = (double)sumofscore / (double)Maxscore * 100.0 / (double)numofscore;

	printf("%f", medium);

}