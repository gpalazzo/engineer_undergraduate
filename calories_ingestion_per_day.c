/*
Calculate how many calories a person should ingest in a day. Criteria:
1. Weight;
2. Height;
3. Age;
4. Gender;
5. Exercise level.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char gender;
int age, height, exercise_level;
float weight, basal_metab_rate, calories;

main () {

     printf ("Weight in kg: \n");
     scanf ("%f", &weight);
     printf ("Height in cm: \n");
     scanf ("%d", &height);
     printf ("Age: \n");
     scanf ("%d", &age);
     printf ("Gender (M or F): \n");
     gender = getche();

     if ( gender == 'M' )
          basal_metab_rate = 66 + (15.7*weight) + (5*height) - (6.8*age);
     else
          basal_metab_rate = 655 + (9.6*weight) + (1.8*height) - (4.7*age);

     printf ("\n");
     printf ("How many days in a week do you exercise?: \n");
     scanf ("%d", &exercise_level);

     if ( exercise_level == 0 ) {
          calories = (basal_metab_rate*1.2);
          printf ("Exercise level classification: Sedentary\n");
     } else if ( exercise_level < 3 ) {
          calories = (basal_metab_rate*1.37);
          printf ("Exercise level classification: Physically Active Level 1\n");
     } else if ( exercise_level <= 5 ) {
          calories = (basal_metab_rate*1.55);
          printf ("Exercise level classification: Physically Active Level 2\n");
     } else {
          calories = (basal_metab_rate*1.9);
          printf ("Exercise level classification: Physically Active Level 3\n");
     }

     printf ("Calories to be ingested: %.2f\n", calories);

     system ("pause");

}
