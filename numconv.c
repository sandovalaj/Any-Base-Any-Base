#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//TODO
//convert base 10 to base 2 input 1212 prints out decimal point

//TODO
//do not print out zeroes/double when input is only integer

char again[] = "y";
long int deciInt;
long double deciFra;

void abtab(char input[], int base1, int base2, int n);
void decitab(long int deciII, long double deciFI, int base);
long double abtdeci(char input[], int base, int n);
int toint(char input);
void outtab (int x);

int main()
{
	
while (strcmp(again, "n"))
{
	deciInt = 0;
	deciFra = 0.0;
	
    int base1, base2;
    char *ptr;

    ptr = (char*) malloc(50 * sizeof(char));
    if(ptr == NULL)
    {
        printf("Error!");
        exit(0);
    }

    printf("\nConvert from base: ");
    scanf("%u", &base1);
    printf("Convert to base: ");
    scanf("%u", &base2);
    printf("Input: ");
    scanf("%s", ptr);
    

    int n = strlen(ptr);
    char input[n];

    strcpy(input, ptr);
    free(ptr);

    if (base1 == 10)
    {
        decitab((atoi(input)), (atof(input)), base2);
    }
    else if (base1 == 2 || base1 == 8  || base1 == 16 )
    {
        if (base2 == 10)
        {
        	//TODO 
        	//add option to adjust fractional precision without rounding up
			printf("\n%.8Lf", abtdeci(input, base1, n));	
		}   
        else
        {
        	abtab(input, base1, base2, n);
		}    
    }
    else
    {
    	printf("Invalid base.");
	}
	
	printf("\n\nConvert again? y/n: ");
	scanf("%s", again);
}
    return 0;
}

//Any Base to Any Base (any base to decimal - decimal to any base)
void abtab(char input[], int base1, int base2, int n)
{
	abtdeci(input, base1, n);
	decitab(deciInt, deciFra, base2); 	
}

//Decimal to Any Base
void decitab(long int deciII, long double deciFI, int base)
{
	int digit = 0, nega = 0;
	
	if (deciII < 0)
    {
        nega = 1;
    }
    
    deciII = abs(deciII);
    deciFI = fabs(deciFI);
    
    long int temp = deciII;
    
    while(temp > 0)
	{
        temp = temp / base;
        digit++;
    }
    
    int dtemp = digit;
    int intout[digit];
    
    while(deciII > 0)
	{
        intout[digit - 1] = deciII % base;
        deciII = deciII / base;
        digit--;
    }
    
    printf("\n");
    
    if (nega == 1)
    {
    	printf("-");
	}
    	
    	
    for (int i = 0; i < dtemp; i++)
    {
    	outtab(intout[i]);
	}
    	
    if (deciFI > 0.0)
    {
    	printf(".");
    	while (deciFI > 0)
		{
        	deciFI = deciFI * base;
        	int Ftemp = (int)deciFI;
        	outtab(Ftemp);
        	deciFI = deciFI - Ftemp;
    	}
	}
}

//Any Base to Decimal
long double abtdeci(char input[], int base, int n)
{
    long int *i = &deciInt;
    long double *f = &deciFra;
    int a = 0;
    int nega;

    if (input[0] == '-')
    {
        a = 1;
        nega = 1;
    }

    while (input[a] != '.' && input[a] != '\0')
    {
        *i *= base;
        *i += toint(input[a]);
        a++;
    }

    if (input[a] == '.')
    {
        a = n - 1;

        while (input[a] != '.')
        {
            *f += (double)toint(input[a]);
            *f /= (double)base;
            a--;
        }
    }
	
	if (nega == 1)
	{
		deciInt *= -1;
    	deciFra *= -1;
	}
         
	//printf("%ld %Lf\n", deciInt, deciFra);
    long double final = *i + *f;
    
    return final;
}

//Converts input (char) to integer; including letters A - F for hexadecimal input
int toint(char input)
{
    if (!(input >= 'A' && input <= 'F'))
    {
        //printf("INPUT is %c\n", input);
        //printf("return %d\n", ((int)input - '0'));
        return ((int)input - '0');
    }

    char hex[] = {"ABCDEF"};
    int equi = 10;

    for (int a = 0; a < 6; a++)
    {
        if (input == hex[a])
        {
            return equi;
        }
        else
        {
            equi++;
        }
    }
}

//Prints out output; including conversion of numbers 10 - 15 for hexadecimal output
void outtab (int x)
{
    char hex[6] = "ABCDEF";
    int hexCheck = 10;

    if (x > 9)
	{
        for (int n = 0; n <= 6; n++)
		{
            if (x == hexCheck)
			{
                printf("%c", hex[n]);
                break;
            }
			else
                hexCheck++;
        }
    }
	else
        printf("%d", x);
    
}
