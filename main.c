#include <stdio.h>
#include <stdlib.h>

int fibonacci(int position)
{
    if (position <= 1)
    {
        return position;
    }
    else
    {
        int fibSeq[3] = {0, 1, 1};

        for (int i = 2; i < position; i++)
        {
            fibSeq[2] = fibSeq[0] + fibSeq[1];
            fibSeq[0] = fibSeq[1];
            fibSeq[1] = fibSeq[2];
        };

        return fibSeq[2];
    }
}

int main()
{
    const char *fibPosition = getenv("FIB_POSITION");

    if (fibPosition == NULL)
    {
        printf("FIB_POSITION environment variable not set\n");
        return 1;
    }

    int fibPositionInt = atoi(fibPosition);
    int fibValue = fibonacci(fibPositionInt);

    if (fibPositionInt < 0)
    {
        printf("Provide a positive integer for FIB_POSITION\n");
        return 1;
    }
    printf("Fibonacci value at position %d is %d\n", fibPositionInt, fibValue);

    return 0;
}
