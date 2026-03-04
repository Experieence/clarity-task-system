#include <stdio.h>
#include <string.h>


/* 
Purpose of system: To simulate cognitive pressure 
and encourage action through constraint. 
Built: 27/02/2026-04/03/2026
Version: V1 
*/


int main ()
{
	int taskLoad = 0; 
	int clarity = 0; 
	char myArray[5][100];
	int currentSize = 0; 
	int nextAction[5] = {0};
	int definedActions = 0;
	
	while(1)
	{
		// the multiplier of 2 for task loading was
		// so that the tension created was moderate.  
		int taskLoading = taskLoad *2;
		int inp; 
		char task; 
		clarity = 10 - taskLoading + definedActions;
		if (clarity < 0) clarity = 0;
		if (clarity > 10) clarity = 10;
		printf("taskLoad: %d | clarity: %d | definedActions: %d\n\n", taskLoad, clarity, definedActions);
		printf("1. Add Task\n");
		printf("2. View Task\n");
		printf("3. Define next action\n");
		printf("4. Complete Task\n");
		printf("5. Exit\n");
		scanf("%d",&inp); 

		if(inp == 1)
		{
			if (currentSize>=5)
				{
					printf("Task lim reached!\n");
					continue; 
				}
			// a  forgiving threshold that forces the user to define 
			// or complete sturs me to action	
			if (clarity < 3) 
			{
				printf("Too many tasks. Define or Complete something!\n");
				continue;
			}
			printf("Write down your task: \n");
			scanf(" %99[^\n]",myArray[currentSize]);
			currentSize++;
			taskLoad++;
		}
		else if (inp == 2)
		{
			for (int i = 0; i < currentSize; i++)
			{
				printf("Task %d: %s\n", i+1 ,myArray[i]);
			}
		}
		else if (inp == 3)
		{
			if (currentSize <= 0)
			{
				printf("Add some items onto the list!\n");
				printf("current size: %d\n", currentSize);
				continue;
			}

			int flag; 
			for (int j = 0; j < currentSize; j++)
			{
				printf("%d:%s\n",j+1,myArray[j]);
			}
			printf("Choose which task to define: \n");
			scanf("%d",&flag);

			flag = flag - 1; 

			if (flag >= 0 && flag < currentSize)
			{
				if (nextAction[flag] == 0)
				{
					nextAction[flag]=1;
				    printf("Task '%s' marked as deifned!. \n", myArray[flag]);
				    definedActions++;
				}
				else
				{
					printf("Task already defined!\n");
					continue;
				}
			}
			else
			{
				printf("Invalid Action, Try again!\n");

			}

		}
		else if (inp == 4)
		{
			if (currentSize == 0)
			{
				printf("No task to complete!\n");
				continue;
			}

			for (int k = 0; k < currentSize; k++)
			{
				printf("%d: %s\n", k+1, myArray[k]);
			}

			printf("Choose which task to complete: \n");
			int flag2; 
			scanf("%d",&flag2); 

			flag2 = flag2 - 1; 

			if (flag2 >= 0 && flag2 < currentSize)
			{
				printf("Completing '%s'\n", myArray[flag2]);
				if (nextAction[flag2] == 1)
				{
				    definedActions--;
				}
			}

			for (int l = flag2; l < currentSize - 1; l++)
			{
				strcpy(myArray[l], myArray[l+1]);
				nextAction[l] = nextAction[l+1];
			}

			currentSize--;
			taskLoad--;

		}
		else if (inp == 5) 
		{
			printf("Closing..."); 
			break;
		}
		else
		{
			printf("Try again!");
			scanf("%d",&inp); 
		}
		// 
		clarity = 10 - taskLoading + definedActions;
		if (clarity < 0) clarity = 0;
		if (clarity > 10) clarity = 10;
		printf("taskLoad: %d | clarity: %d | definedActions: %d\n\n", taskLoad, clarity, definedActions);
	}

}