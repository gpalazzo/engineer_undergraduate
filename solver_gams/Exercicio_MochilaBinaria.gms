SCALAR
         PESO_MOCHILA / 100 /
;

SETS
i PRODUTOS / 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 /
;

PARAMETERS
PESO(I)
/
         1  70.40
         2  1.40
         3  50.10
         4  0.30
         5  1.60
         6  43.80
         7  6.90
         8  11.40
         9  8.30
         10 0.40
         11 2.60
         12 16.70
         13 14.00
         14 34.50
         15 2.20
/

IMPORTANCIA(I)
/
         1  12.70
         2  6.50
         3  2.60
         4  12.20
         5  8.50
         6  4.10
         7  9.00
         8  1.90
         9  10.30
         10 6.00
         11 7.80
         12 15.80
         13 15.40
         14 7.00
         15 5.00
/
;

VARIABLES
X(I)
Z

binary variable X        Mochila Binária
;

EQUATIONS
CAP
IMP
;

IMP.. Z =E= SUM((I), IMPORTANCIA(I)*X(I));
CAP.. SUM((I), X(I)*PESO(I)) =L= PESO_MOCHILA;

MODEL Untitled_1 /ALL/;
* MIP porque é binária, se fosse inteira seria LP
SOLVE Untitled_1 USING MIP MAXIMIZING Z;
DISPLAY X.L, Z.L, CAP.L;


