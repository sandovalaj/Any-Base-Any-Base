#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char again[3] = "y\n";

//DECIMAL TO ANY BASE

void printOut(int x){//PRINTS OUT ALL DIGITS; INCLUDES HEXADECIMAL CONVERT; input INTEGER to print
    char hex[6]="ABCDEF";
    int hexCheck=10;

    if(x>9){//if answer is 10 above print as ABCDEF
        for(int n=0;n<=6;n++){
            if(x==hexCheck){
                printf("%c", hex[n]);
                break;
            }else{
                hexCheck++;
            }
        }
    }else{
        printf("%d", x);//if answer is 9 below print as is
    }
}

void decIntTAB(int input, int base){ //performs decimal integer to any base; input INPUT and BASE
    int rem;
    int array[200];
    int digit=0;
    //MATH PROCESS

    while(input>0){
        rem=input%base;
        array[digit]=rem;
        input=input/base;
        digit++;
    }

    for(int a=(digit-1);a>=0;a--){//Prints out array
        printOut(array[a]);
    }
}

void decFraTAB(double input, int base){
    while (input>0){
        input=input*base;
        int temp=(int)input;
        printOut(temp);
        input=input-temp;//sets input to be input(in fractional form) minus temp(input's integer value) to isolate fractional value
    }

}

int main()
{
    printf("\t\t\t\t\tBASIC NUMBER CONVERSIONS\n\n");
    printf("Base Guide: \t\t2 - Binary \t\t8 - Octal \t\t10 - Decimal \t\t16 - Hexadecimal\n");

while (strcmp(again, "n"))
{
    double input, fract, integ;
    int base, iInteg;

    printf("\nInput decimal: ");
    scanf("%lf", &input);
    printf("Convert to base: ");
    scanf("%u", &base);

    printf("\n");

    if (base==2 || base==8|| base==10 || base==16){//ensures base is only 2,8,10,16
    	if (input < 0)
    	{
    		printf("-");
    		input = fabs(input);
		}
		
        fract=modf(input, &integ);
        iInteg=integ;

        if(fract==0){
            decIntTAB(iInteg, base);
        }else{
            decIntTAB(iInteg, base);
            printf(".");
            decFraTAB(fract, base);
        }
    }else{
        printf("Invalid Input");
        }
        
	printf("\nConvert again? y/n: ");
    scanf("%s", &again);
    
}

    return 0;
}




