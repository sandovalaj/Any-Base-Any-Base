#include <stdio.h>
#include <stdlib.h>

//DECIMAL TO ANY BASE

void decIntTAB();
void decFraTAB();
void printOut();

int main()
{
    printf("\t\t\t\t\tBASIC NUMBER CONVERSIONS\n\n");
    printf("Base Guide: \t\t2 - Binary \t\t8 - Octal \t\t10 - Decimal \t\t16 - Hexadecimal\n\n");

    char input[150];
    double temp;
    int base;

    printf("Input decimal: ");
    scanf("%s", input);
    printf("Convert to base: ");
    scanf("%d", &base);

    printf("\n\n");

    if(sscanf(input, "%lf", &temp)==1){
        if((int)temp-temp!=0){//integer input minus original input, if it is not 0, it is a float
            int decimalInt=(int)temp;
            double decimalFlt=temp-decimalInt;

            decIntTAB(decimalInt,base);
            printf(".");
            decFraTAB(decimalFlt, base);
        }else{ //integer
            int decimalInt=(int)temp;
            decIntTAB(decimalInt, base);
        }
    }else{
        printf("Invalid Input");
    }

    printf("\n\n");
    return 0;
}

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

    for(int a=(digit);a>=0;a--){//Prints out array
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

