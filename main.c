#include <stdio.h>
#include <math.h>
#include <string.h>
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
    /*
                                        -------|
                                        |      |  bit is 1
                                    (B) v      |
                 bit is 1          |------|    |
              |------------------->| odd  |-----
           (A)|                    |------|
          |-------|                    |
       -> | even  |---        <--------| bit is 0
          |_______|  |
               ^     | bit is 0
               |     |
                ------

    */
    int length = strlen(binaryInput);
    int evenNum = 1;    // Intital state is 1, if it is odd then state is 0
    for (int i = 0; i < length; i++)
    {
        if (evenNum == 1){
            if (binaryInput[i] == '0')
            {
                printf("Bit is even, state accepted!\n");
                evenNum = 1;
            }
            else
            {
                printf("Bit is odd, state rejected and passed to node B!\n");
                evenNum = 0;
            }
        }
        else
        {
            if (binaryInput[i] == '1')
            {
                printf("Bit is odd, state accepted!\n");
                evenNum = 0;
            }
            else
            {
                printf("Bit is even, state rejected and passed to node A!\n");
                evenNum = 1;
            }
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


int main()
{
    printf("Enter a binary number: \n");
    char binaryInput[32];
    scanf("%s", binaryInput,32);

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

