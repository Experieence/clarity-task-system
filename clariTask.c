#include <stdio.h>
#include <string.h>


/* 
Purpose of system: To simulate cognitive pressure 
and encourage action through constraint. 
Built: 27/02/2026-04/03/2026
Refractored: 04/03/2026
Version: V2 
*/

void clariTask()
{
	printf("--- Hi Welcome to ClariTask ----\n");
}

void stats(int taskLoad, int clarity, int definedActions)
{
	printf("taskLoad: %d | clarity: %d | definedActions: %d\n\n", taskLoad, clarity, definedActions);
}

void menu()
{
		printf("1. Add Task\n");
		printf("2. View Task\n");
		printf("3. Define next action\n");
		printf("4. Complete Task\n");
		printf("5. Exit\n\n");
}

void taskMsg()
{
	printf("Write down your task: \n");
}

void inpMsg()
{
	printf("Enter a number between 1-5: \n");
}

void defineMsg()
{
	printf("Choose which task to define: \n");
}

void completeMsg()
{
	printf("Choose which task to complete: \n");
}

int calcClarity(int taskLoad, int definedActions)
{
	int clarity = 10 - (taskLoad *2) + definedActions;
	if (clarity < 0) clarity = 0;
	if (clarity > 10) clarity = 10;

	return clarity;
}


void getInp(int *inp)
{
	scanf("%d",inp);
}	


void viewTask(char myArray[5][100], int currentSize)
{
	for (int i = 0; i < currentSize; i++)
	{
	// ---- presentation ----
		printf("Task %d: %s\n", i+1 ,myArray[i]);
	}
}

void addTask(char myArray[5][100], int *currentSize, int *taskLoad, int clarity)
{
	// currently messy 
	if (*currentSize>=5)
	{
		printf("Task lim reached!\n");
		return;
	}
	// a  forgiving threshold that forces the user to define 
	// or complete sturs me to action	
	if (clarity < 3) 
	{
		printf("Too many tasks. Define or Complete something!\n");
		return;
	}
	// ---- (Presentaion) ----
	taskMsg();
	// ---- (input hadling) ---
	scanf(" %99[^\n]",myArray[*currentSize]);
	(*currentSize)++;
	// ---- System ----
	(*taskLoad)++;
}


void defineTask(char myArray[5][100], int currentSize, int nextAction[5], int *definedActions)
{
	// currently messy 
	if (currentSize <= 0)
	{
	// ---- presentation ----
		printf("Add some items onto the list!\n");
		printf("current size: %d\n", currentSize);
		return;
	}
	int flag; 
	for (int j = 0; j < currentSize; j++)
	{
		printf("%d:%s\n",j+1,myArray[j]);
	}
	defineMsg();
	scanf("%d",&flag);
	flag = flag - 1; 
	if (flag >= 0 && flag < currentSize)
	{
		if (nextAction[flag] == 0)
		{
		// ---- system ----
			nextAction[flag]=1;
			// ---- presentation ----
			printf("Task '%s' marked as deifned!. \n", myArray[flag]);
			// ---- system ----
			(*definedActions)++;
		}
		else
		{
			printf("Task already defined!\n");
			return;
		}
	}
	else
	{
		printf("Invalid Action, Try again!\n");
	}
}

void completeTask(char myArray[5][100], int *currentSize, int nextAction[5], int *definedActions, int *taskLoad)
{
	if (*currentSize == 0)
	{
		printf("No task to complete!\n");
		return;
	}
	for (int k = 0; k < *currentSize; k++)
	{
		printf("%d: %s\n", k+1, myArray[k]);
	}
	
	int flag2;
	completeMsg(); 
	scanf("%d",&flag2); 
	flag2 = flag2 - 1; 
	if (flag2 >= 0 && flag2 < *currentSize)
	{
		printf("Completing '%s'\n", myArray[flag2]);
		if (nextAction[flag2] == 1)
		{
			*(definedActions)--;
		}
		for (int l = flag2; l < *currentSize - 1; l++)
		{
			strcpy(myArray[l], myArray[l+1]);
			nextAction[l] = nextAction[l+1];
		}
		(*currentSize)--;
		(*taskLoad)--;
	}
}

int main ()
{
	int taskLoad = 0; 
	char myArray[5][100];
	int currentSize = 0;
	int nextAction[5] = {0};
	int definedActions = 0;
	int clarity;
	
	clariTask();
	while(1)
	{
		clarity = calcClarity(taskLoad, definedActions);
		int inp;  
		// ---- printing the stats (Presentaion) ---- 
		stats(taskLoad,clarity,definedActions);
		
		// ---- printing the menu (Presentaion) ----
		menu();
		inpMsg();
		// ---- handle input (input hadling) ----
		getInp(&inp);  
		// ---- task logic ----
		switch(inp)
		{
		case 1:
			addTask(myArray,&currentSize,&taskLoad,clarity);
			break;
		case 2:
			viewTask(myArray,currentSize);
			break;
		case 3:
			defineTask(myArray,currentSize,nextAction,&definedActions);
			break;
		case 4:
			completeTask(myArray,&currentSize,nextAction,&definedActions,&taskLoad);
			break;
		case 5:
			printf("Closing..."); 
			return 0;
		default:
			printf("Try again!");
			getInp(&inp); 
			break;
		}		
	}
}