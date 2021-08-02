SETS
i PRODUTOS / PRODUTO_A, PRODUTO_B, PRODUTO_C /
j RECURSOS / CORTE, DOBRA, EMPACOTAMENTO /
;

PARAMETERS
LC(I)
/
         PRODUTO_A 1.0
         PRODUTO_B 1.5
         PRODUTO_C 2.0
/

DISP(J)
/
         CORTE 120
         DOBRA 400
         EMPACOTAMENTO 80
/
;

TABLE R(J, I)

                 PRODUTO_A       PRODUTO_B       PRODUTO_C
CORTE            8.0             5.0             2.0
DOBRA            5.0             10.0            4.0
EMPACOTAMENTO    0.7             1.0             2.0
;

VARIABLE
X(I)
Z

positive variable X;

EQUATIONS
LUCRO
CONS(J)
;

LUCRO.. Z =E= SUM((I), LC(I)*X(I));
CONS(J).. SUM((I), R(J, I)*X(I)) =L= DISP(J);

MODEL Untitled_3 /ALL/;
SOLVE Untitled_3 USING LP MAXIMIZING Z;
DISPLAY Z.L, X.L, CONS.L;
