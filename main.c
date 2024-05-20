#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void BMI(void);
void pressure(void);
void ERICE(void);

int main(void)
{
    void (*f[3])() = {BMI, pressure, ERICE};
   	int input;
    
    do
    {
    	printf("Enter a number from 1 to 3 to calculate BMI, blood pressure, or ERICE respectively: ");
   		scanf("%d", &input);while(getchar()!='\n'){}
   		 if(input < 1 || input > 3)
			printf("Invalid choice\n");
		 else 
			(*f[input - 1])();

    }while(input < 1 || input > 3);

	return 0;
}

void pressure(void)
{
	int readings[5][2] = {0};
	int systolic, diastolic, result;

	for(int i = 0; i < 5; i++)
	{		
		printf("Enter your systolic  reading %d: ", i+1);
		result = scanf("%d", &systolic);while(getchar()!='\n'){}

		if (result != 1) 
		{
            printf("Invalid input. Please enter a number.\n");
            i--; // Decrement i to repeat the current iteration
            continue; // Skip the rest of the loop body
        }
        readings[i][0] = systolic;
    }
	
	result = 0;printf("\n");

	for(int i = 0; i < 5; i++)
	{			
		printf("Enter your diastolic reading %d: ", i+1);
		result = scanf("%d", &diastolic);while(getchar()!='\n'){}
			
		if (result != 1) 
		{
            printf("Invalid input. Please enter a number.\n");
            i--; // Decrement i to repeat the current iteration
            continue; // Skip the rest of the loop body
        }
        readings[i][1] = diastolic;
     }

	double avg_systolic=0, avg_diastolic=0;

	for(int i = 0, j=0; i < 5; i++)
	{
		avg_systolic += readings[i][j];
	}
	for(int i = 0, j=1; i < 5; i++)
	{
		avg_diastolic += readings[i][j];
	}
	printf("\n");

	avg_systolic /= 5; avg_diastolic/= 5;
	if(avg_systolic >= 140 ||  avg_diastolic >= 90)
	printf("You have high blood pressure");
	else if(avg_systolic >= 120 ||  avg_diastolic >= 80)
	printf("You have pre-high blood pressure");
	else if(avg_systolic >= 90 ||  avg_diastolic >= 60)
	printf("You have ideal blood pressure");
	else
	printf("You have low blood pressure");
}

void BMI(void)
{
	double weight, height,bmi, result;
	
	while(result != 1)
	{		
		printf("Enter your weight in kilograms: ");
		result = scanf("%lf", &weight);while(getchar()!='\n'){}

		if (result != 1) 
		{
			system("cls");
            printf("Invalid input. Please enter a number.\n");
            continue; // Skip the rest of the loop body
        }
    }
    result = 0;
    while(result != 1)
	{		
		printf("Enter your height in meters: ");
		result = scanf("%lf", &height);while(getchar()!='\n'){}

		if (result != 1) 
		{
			system("cls");
            printf("Invalid input. Please enter a number.\n");
            continue; // Skip the rest of the loop body
        }
    }

	bmi = weight / (height * height);
	if(bmi < 18.5)
	printf("You are underweight");
	else if(bmi <= 24.9)
	printf("You are normal weight");
	else if(bmi <=29.9 )
	printf("You are overweight");
	else
	printf("You are obese");
}

void ERICE(void)
{
	char gender[2], diabetics[2], smoker[2];
	int age, result; double cholestrol, avg_systolic;

	 while (1) 
	{
        printf("Are you a male or a female? (Enter M/F): ");
        scanf("%1s", gender);while(getchar()!='\n'){}

        // Check if the user entered "M" or "F"
        if (!strcmp(gender, "M") || !strcmp(gender, "F")) 
        break; // Exit the loop if the input is "M" or "F"
        else 
        printf("Invalid input. Please enter either 'M' or 'F'.\n");
        
    }
    
    while(result != 1)
	{		
		printf("Enter your age: ");
		result = scanf("%d", &age);while(getchar()!='\n'){}

		if (result != 1) 
		{
			system("cls");
            printf("Invalid input. Please enter a number.\n");
            continue; // Skip the rest of the loop body
        }
    }
	
	result = 0;

	while (1) 
	{
        printf("Are you a smoker? (Enter Y/N): ");
        scanf("%1s", smoker);while(getchar()!='\n'){}

        // Check if the user entered "M" or "F"
        if (!strcmp(smoker, "Y") || !strcmp(smoker, "N")) 
        break; // Exit the loop if the input is "M" or "F"
        else 
        printf("Invalid input. Please enter either 'Y' or 'N'.\n");
        
    }

    while (1) 
	{
        printf("Do you have diabetes? (Enter Y/N): ");
        scanf("%1s", diabetics);while(getchar()!='\n'){}

        // Check if the user entered "M" or "F"
        if (!strcmp(diabetics, "Y") || !strcmp(diabetics, "N")) 
        break; // Exit the loop if the input is "M" or "F"
        else 
        printf("Invalid input. Please enter either 'Y' or 'N'.\n");
        
    }

    while(result != 1)
	{		
		printf("Enter your cholestrol level: ");
		result = scanf("%lf", &cholestrol);while(getchar()!='\n'){}

		if (result != 1) 
		{
			system("cls");
            printf("Invalid input. Please enter a number.\n");
            continue; // Skip the rest of the loop body
        }
    }

    result = 0;

    while(result != 1)
	{		
		printf("Enter your average systolic pressure: ");
		result = scanf("%lf", &avg_systolic);while(getchar()!='\n'){}

		if (result != 1) 
		{
			system("cls");
            printf("Invalid input. Please enter a number.\n");
            continue; // Skip the rest of the loop body
        }
    }
	

	switch(gender[0])
	{
	case 'M': 
		if(age>=80)
		printf("You have a VERY HIGH risk for a cardiovascular attack >= 30%%!!");
		else if(age >= 70)
		{
			if(avg_systolic >= 140)
			{
				if(!strcmp(smoker ,"N") && !strcmp(diabetics, "N"))
				printf("You have a HIGH risk for a cardiovascular attack between 20%% ~ 29%%!!");
				else
				printf("You have a VERY HIGH risk for a cardiovascular attack >= 30%%!!");	
			}
			else
			{
				if(!strcmp(smoker ,"N") && !strcmp(diabetics, "N"))
				printf("You have a MODERATE-HIGH risk for a cardiovascular attack 15%% ~ 19%%!!");	
				else
				printf("You have a HIGH risk for a cardiovascular attack between 20%% ~ 29%%!!");
			}
		}
		else if(age >= 60)
		{
			if(avg_systolic >= 140)
			{
				if(!strcmp(smoker ,"N") && !strcmp(diabetics, "N"))
				printf("You have a MODERATE-HIGH risk for a cardiovascular attack 15%% ~ 19%%!!");	
				else if(!strcmp(smoker, "Y") && avg_systolic >= 180)
				printf("You have a VERY HIGH risk for a cardiovascular attack >= 30%%!!");
				else if(!strcmp(smoker, "Y") && cholestrol >= 6.5)
				printf("You have a VERY HIGH risk for a cardiovascular attack >= 30%%!!");	
				else
				printf("You have a HIGH risk for a cardiovascular attack between 20%% ~ 29%%!!");
			}
			else
			{
				if(!strcmp(smoker ,"N") && !strcmp(diabetics, "N") || !strcmp(diabetics, "N") && cholestrol < 5.2 || !strcmp(diabetics, "Y") && cholestrol < 5.2 && !strcmp(smoker ,"N"))
				printf("You have a MODERATE risk for a cardiovascular attack 10%% ~ 14%%!!");	
				else
				printf("You have a MODERATE-HIGH risk for a cardiovascular attack 15%% ~ 19%%!!");
			}	
		}
		else if(age >= 50)
		{
			if(!strcmp(smoker ,"N") && !strcmp(diabetics, "N"))
			{
				if(cholestrol >= 5.2)	
				printf("You have a MODERATE risk for a cardiovascular attack 10%% ~ 14%%!!");	
				else
				printf("You have a MILD risk for a cardiovascular attack 5%% ~ 9%%!!");
			}
			else if(avg_systolic >= 140)
			{
				if(!strcmp(smoker ,"Y") && avg_systolic >=160)
				printf("You have a MODERATE-HIGH risk for a cardiovascular attack 15%% ~ 19%%!!");
				else
				printf("You have a MODERATE risk for a cardiovascular attack 10%% ~ 14%%!!");	
			}
			else
			{
				if(!strcmp(smoker ,"Y") && cholestrol>=5.2 && cholestrol < 7.8)
				printf("You have a MODERATE risk for a cardiovascular attack 10%% ~ 14%%!!");	
				else
				printf("You have a MILD risk for a cardiovascular attack 5%% ~ 9%%!!");
			}
		}
		else if(age>=40)
		{
			if(avg_systolic < 140 || !strcmp(smoker ,"N") && !strcmp(diabetics, "N") || avg_systolic <=160 && !strcmp(diabetics, "N") && !strcmp(smoker ,"N")|| !strcmp(diabetics, "Y") && !strcmp(smoker ,"N") && cholestrol <= 6.4 || !strcmp(diabetics, "N") && !strcmp(smoker ,"Y") && cholestrol < 5.2 || !strcmp(diabetics, "N") && !strcmp(smoker ,"Y") && avg_systolic < 180)
			printf("You have a LOW risk for a cardiovascular attack <5%%!!");
			else
			printf("You have a MILD risk for a cardivascular attack 5%% ~ 9%%!!");
		}
		else
		printf("You have a LOW risk for a cardiovascular attack <5%%!!");
		break;
	default:
		if(age >= 80)
		printf("You have a VERY HIGH risk for a cardiovascular attack >= 30%%!!");
		else if(age >= 70)
		{
			if(avg_systolic >= 180)
			{
				if(!strcmp(smoker ,"N") && !strcmp(diabetics, "N"))
				printf("You have a HIGH risk for a cardiovascular attack between 20%% ~ 29%%!!");
				else
				printf("You have a VERY HIGH risk for a cardiovascular attack >= 30%%!!");
			}
			else
			{
				if(!strcmp(diabetics, "Y") && !strcmp(smoker ,"N") || !strcmp(diabetics, "N") && !strcmp(smoker ,"Y"))
				printf("You have a HIGH risk for a cardiovascular attack between 20%% ~ 29%%!!");
				else if(!strcmp(smoker ,"N") && !strcmp(diabetics, "N"))
				printf("You have a MODERATE-HIGH risk for a cardiovascular attack 15%% ~ 19%%!!");
				else
				printf("You have a VERY HIGH risk for a cardiovascular attack >= 30%%!!");
			}
		}
		else if(age >= 60)
		{
			if(avg_systolic >= 180)
			{
				if(!strcmp(smoker ,"N") && !strcmp(diabetics, "N"))
				printf("You have a MODERATE risk for a cardiovascular attack 10%% ~ 14%%!!");	
				else
				printf("You have a HIGH risk for a cardiovascular attack between 20%% ~ 29%%!!");
			}
			else if(!strcmp(diabetics, "Y") && !strcmp(smoker ,"N") || !strcmp(diabetics, "N") && !strcmp(smoker ,"Y"))
			printf("You have a MODERATE risk for a cardiovascular attack 10%% ~ 14%%!!");	
			else if(!strcmp(smoker ,"N") && !strcmp(diabetics, "N"))
			printf("You have a MILD risk for a cardivascular attack 5%% ~ 9%%!!");
			else
			printf("You have a MODERATE-HIGH risk for a cardiovascular attack 15%% ~ 19%%!!");
		}
		else if(age >= 50)
		{
			if(avg_systolic >= 180)
			{
				if(!strcmp(smoker ,"N") && !strcmp(diabetics, "N"))
				printf("You have a MILD risk for a cardivascular attack 5%% ~ 9%%!!");
				if(!strcmp(smoker ,"Y") && !strcmp(diabetics, "Y"))
				printf("You have a MODERATE-HIGH risk for a cardiovascular attack 15%% ~ 19%%!!");
				else
				printf("You have a MODERATE risk for a cardiovascular attack 10%% ~ 14%%!!");	
			}
			else if(!strcmp(smoker ,"Y") && !strcmp(diabetics, "Y"))
			printf("You have a MODERATE risk for a cardiovascular attack 10%% ~ 14%%!!");	
			else
			printf("You have a MILD risk for a cardivascular attack 5%% ~ 9%%!!");
		}
		else
		printf("You have a LOW risk for a cardiovascular attack <5%%!!");
		break;

	}
}

