#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    printf("Enter a binary number: \n");
    char binaryInput[32];
    scanf_s("%s", binaryInput,32);

    if (isValidBinary(binaryInput) != 0)
    {
        int numState = isEven(binaryInput);
        if (numState == 1)
        {
            printf("%s", binaryInput);
            printf(" is an even binary number");
        }
        else
        {
            printf("%s", binaryInput);
            printf(" is an odd binary number");
        }
        printf(", its decimal value is: ");
        printf("%d", toDeci(binaryInput));
    }
}

int isValidBinary(char binaryInput[])
{
    int length = strlen(binaryInput);
    for (int i = 0; i < length; i++)
    {
        if (binaryInput[i] == '1' || binaryInput[i] == '0')
        {
            continue;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}


int isEven(char binaryInput[])
{
    int length = strlen(binaryInput);
    int evenNum = 1;    // Intital state is 1, if it is odd then state is 0
    for (int i = 0; i < length; i++)
    {
        if (binaryInput[i] == '1')
        {
            evenNum = 0;
        }
        else
        {
            evenNum = 1;
        }
    }
    return evenNum;
}

int toDeci(char binaryInput[])
{
    int deciVal = 0;
    int length = strlen(binaryInput);
    for (int  i = 0; i <length; i++)
    {
        if (binaryInput[i] == '1') 
        {
            deciVal += pow(2, length-i-1);
        }
    }
    return deciVal;
}