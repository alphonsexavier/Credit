#include <cs50.h>
#include <stdio.h>

int check=0;
long original_number;

//Function prototypes
void check_visa(long number);
void check_amex(long number);
void check_mastercard(long number);
void check_sum(long number);

int main(void)
{
    long number = get_long("Number: ");
    original_number = number;

    check_sum(number);

    if(check==0)
    {
        printf("INVALID\n");
    }
   else
    {
        check_visa(number); //calls check_visa function if it is a valid number
    }
}

void check_sum(long number)
{
    int sum=0, temp, count=1;

    for(int i=0;number!=0;i++)
    {
        if(count%2==0) //to locate every second digit number
        {
            temp=(number%10)*2;
            if(temp/10==0) //checks if the result of the above multiplication is a 2-digit number (or) a single digit number
            {
                sum=sum+temp;
                temp=0;
            }
            else
            {
                sum=sum+(temp/10)+(temp%10); //splits the 2-digit number into single digits
                temp=0;
            }
        }
        number=number/10;
        ++count;
    }

    count=1;
    number=original_number;

    for(int i=0;number!=0;i++)
    {
        if(count%2==1)
        {
            sum=sum+(number%10); //adds the sum to every other digit one by one
        }
        number=number/10;
        ++count;
    }

    if(sum%10==0) //checks if its passes check sum criteria
    {
        check=1;
    }
    else
    {
        check=0;
    }
}

void check_visa(long number)
{
    int count=0;
    number = number/10;

    if(number==4) //checks if the first digit of the number is 4
    {
        int i=0;
        for (long j=original_number;j!=0;i++)
        {
            ++count;
            j=j/10;

        }
        if(count==13 || count==16) //checks if the length of the number is 13 or 16
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }

    }
    else if(number==0)
    {
       check_amex(original_number); //if none of the above conditions satisfy, calls check_amex() function
    }
    else
    {
        check_visa(number);
    }
}

void check_amex(long number)
{
    int count=0;
    number = number/10;

    if(number==34||number==37) //checks if the first two digits of the number is 34 or 37
    {
        int i=0;
        for (long j=original_number;j!=0;i++)
        {
            ++count;
            j=j/10;

        }
        if(count==15) //checks if the length of the number is 15
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if(number==0)
    {
       check_mastercard(original_number); //if none of the above conditions satisfy, calls check_mastercard() function
    }
    else
    {
        check_amex(number);
    }
}

void check_mastercard(long number)
{
    int count=0;
    number = number/10;

    if(number==51||number==52||number==53||number==54||number==55) //checks if the first two digit of the number is 51/52/53/54/55
    {
        int i=0;
        for (long j=original_number;j!=0;i++)
        {
            ++count;
            j=j/10;

        }
        if(count==16) //checks if the length of the number is 16
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if(number==0)
    {
       printf("INVALID\n"); //if none of the above conditions satisfy, then it is an invalid number
    }
    else
    {
        check_mastercard(number);
    }
}