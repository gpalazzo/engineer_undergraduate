/*
Calculate the amount of cars sold and the comission received.
Considers 3 sellers in total.
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main ()
{
    int arr_amount_car_sold[10];
    float arr_amount_money_sold[10], salary, final_salary;
    
    for ( int i = 0; i < 3; i++ )
{
    printf ("[Seller %d] How many cars sold?", i);
    scanf ("%d", &arr_amount_car_sold[i]);
    fflush (stdin);
    printf ("\n [Seller %d] Total amount of money considering all sales?", i);
    scanf ("%f", &arr_amount_money_sold[i]);
    fflush (stdin);
    printf ("\n ====================================== \n");
}
    system ("CLS");
    
    for ( int i = 0; i < 3; i++ )
{
    fflush (stdin);
    printf ("\n [Seller %d] Cars sold = %d", i, arr_amount_car_sold[i]);
    fflush (stdin);
    printf ("\n [Seller %d] Total amount sales = %.2f", i, arr_amount_money_sold[i]);
    fflush (stdin);
    salary = ( 6000 + (arr_amount_car_sold[i]*500) + (arr_amount_money_sold[i]*0.05) );
    printf ("\n [Seller %d] Total comission = %.2f", i, (arr_amount_car_sold[i]*500));
    printf ("\n ======================================= \n");

    if ( salary <= 10000 )
    final_salary = salary-(salary*0.09);
    else if ( salary <= 15000 )
    final_salary = salary-(salary*0.10);
    else
    final_salary = salary-(salary*0.12);
    
    printf ("\n Total money to be received: %.2f", final_salary);
    printf ("\n");
    getche();
}
}
