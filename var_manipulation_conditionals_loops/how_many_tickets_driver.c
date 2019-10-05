//Calculate the amount of tickets a person has based on tickets category: 2, 3, 5 or 7 points.

#include <stdio.h>
#include <stdlib.h>

int m1,m2,m3,m4,m5,points2,points3,points5,points7;

main() {

	printf("\nPoints for the first ticket:\n");
	scanf("%d",&m1);
	printf("\nPoints for the second ticket:\n");
	scanf("%d",&m2);
	printf("\nPoints for the third ticket:\n");
	scanf("%d",&m3);
	printf("\nPoints for the fourth ticket:\n");
	scanf("%d",&m4);
	printf("\nPoints for the fifth ticket:\n");
	scanf("%d",&m5);
	
	points2=0;
	points3=0;
	points5=0;
	points7=0;
	
	
	if (m1==2)
	points2++;
	else if (m1==3)
	points3++;
	else if (m1==5)
	points5++;
	else if (m1==7)
	points7++;
	
	
	if (m2==2)
	points2++;
	else if (m2==3)
	points3++;
	else if (m2==5)
	points5++;
	else if (m2==7)
	points7++;
	
	if (m3==2)
	points2++;
	else if (m3==3)
	points3++;
	else if (m3==5)
	points5++;
	else if (m3==7)
	points7++;

	if (m4==2)
	points2++;
	else if (m4==3)
	points3++;
	else if (m4==5)
	points5++;
	else if (m4==7)
	points7++;
	
	if (m5==2)
	points2++;
	else if (m5==3)
	points3++;
	else if (m5==5)
	points5++;
	else if (m5==7)
	points7++;
	
	printf("\nTotal tickets in 2 points category: %.2d\n", points2);
	printf("\nTotal tickets in 3 points category: %.2d\n", points3);
	printf("\nTotal tickets in 5 points category: %.2d\n", points5);
	printf("\nTotal tickets in 7 points category: %.2d\n", points7);
	
	system("pause");
	
}


