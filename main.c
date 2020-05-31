#include <stdio.h>
#include <stdlib.h>
//A program used to solve quadratic equations using the quadratic formula
float cansolve (float a, float b, float c);//Finds determinant
float absolute (float s);//To help square root
float squareroot (float d);//Gets square root
float solution1 (float d, float b, float a);//Finds first x value
float solution2 (float d, float b, float a);//Finds second x value


int main()
{
/* Defining integers as 0 at start helps m=with calculations */
    float a,b,c;
    float d,answer1,answer2;

/* Gaining input from the user and using it in calculations. */
    printf("Please enter the value in front of x^2 :");
    scanf ("%f",&a);//Need the & sign to help scanf

    printf("Please enter the value before x :");
    scanf ("%f",&b);//Not sure how to do all on one line yet

    printf("Please enter the last number in the equation:");
    scanf ("%f",&c);


    printf("a = %.1f\nb = %.1f\nc = %.1f\n",a,b,c);//To prove a,b and c values were correct

    d = cansolve (a,b,c);//Uses cansolve function to find determinant

    if (d > 0)//if determinant is above zero then quadratic is solvable
    {
        answer1 = solution1 (d, b, a);//Uses values in solution1 function
        answer2 = solution2 (d, b, a);//Uses d,b and a values for solution2 function
        printf("\n\n x = %.1f or x = %.1f\n",answer1,answer2);//Prints x values

    }
    else//If determinant is negative equation can't be solved
    {
        printf("Quadratic can not be solved\n");
    }
    return 0;//Needed at end of every main function
}

float cansolve(float a, float b, float c)//Function used to find determinant
{
    float determinant;//Need a local float besides a,b and c

    determinant =(b*b)-(4*(a*c));//Calculates determinant, as in quadratic formula

    return determinant;//returns value to give the answer
}

float absolute(float s)//Function to find absolute value (used for square root function)
{
    if (s<0)//If s is negative then multiply by -1
    {
        s = (s*(-1));//Can define new parameter but on't need to
    }

    return s;//return s as the output
}

float squareroot(float d)//Function that finds the square root used in functions challenge
{
//Local variables defined purely for this function
    float guess = 1.0;
    float constant = .00001;

//Makes a guess at what is squared to make d and keeps going until value is less than 0.00001
   while (absolute(guess*guess - d)>=constant)
    {
        guess = (d/guess + guess)/2.0;//creates a new guess by adding a small value to guess and test again
    }

    return guess;//Guess is the square root
}

float solution1 (float d,float a, float b)
{
    float solution;//define new value so not mixed up with d,a or b

    solution = (((-1)*b)+ squareroot(d))/(2*a);//need d, a and b for the solution

    return solution;//Returns value to answer
}

float solution2 (float d,float a, float b)
{
    float solution;//Can have same name as local to function

    solution = (((-1)*b)- squareroot(d))/(2*a);//Same formula but with - not +

    return solution;//Returns x value solution
}
