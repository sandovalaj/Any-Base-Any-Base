#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void abtab(char input[], int base1, int base2, int n);
void decitab(long int deciII, long double deciFI, int base);
long double abtdeci(char input[], int base, int n);
int toint(char input);
void outtab (int x);

int main()
{
    int base1, base2;
    char *ptr;

    ptr = (char*) malloc(50 * sizeof(char));
    if(ptr == NULL)
    {
        printf("Error!");
        exit(0);
    }

    printf("Input base to convert from: ");
    scanf("%u", &base1);
    printf("Input: ");
    scanf("%s", ptr);
    printf("Convert to base: ");
    scanf("%u", &base2);

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
        	printf("\n%.8Lf\n", abtdeci(input, base1, n));
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
        
    return 0;
}

void abtab(char input[], int base1, int base2, int n)
{
	printf("\n%.8Lf\n", abtdeci(input, base1, n));  
   	
}

void decitab(long int deciII, long double deciFI, int base)
{
	
	int digit = 0, nega = 0;
	
	if (deciII < 0)
    {
        nega = 1;
    }
    
    deciII = abs(deciII);
    deciFI = fabs(deciFI) - deciII;
    
    printf("%ld %Lf", deciII, deciFI);
    
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

long double abtdeci(char input[], int base, int n)
{
    long int deciInt = 0;
    long double deciFra = 0.0;
    int a = 0;
    int nega;

    if (input[0] == '-')
    {
        a = 1;
        nega = 1;
    }

    while (input[a] != '.' && input[a] != '\0')
    {
        //printf("%ld * %u is ", deciInt, base);
        deciInt *= base;
        //printf("%ld\n", deciInt);
        //printf("%ld + %d is ", deciInt, toint(input[a]));
        deciInt += toint(input[a]);
        //printf("%ld\n", deciInt);
        a++;
    }

    //printf("\n");

    if (input[a] == '.')
    {
        a = n - 1;

        while (input[a] != '.')
        {
            deciFra += (double)toint(input[a]);
            deciFra /= (double)base;
            //printf("%Lf henlo\n", deciFra);
            a--;
        }
    }

    long double decimal = deciInt + deciFra;
    if (nega == 1)
       decimal *= -1;
    
    return decimal;
}

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
