SETS
i PRODUTOS / PRODUTO_A, PRODUTO_B, PRODUTO_C /
j RECURSOS / TORNO, FRESA, FURADEIRA /
;

PARAMETERS
LC(I)
/
         PRODUTO_A 20
         PRODUTO_B 15
         PRODUTO_C 18
/

DISP(J)
/
         TORNO 400
         FRESA 500
         FURADEIRA 300
/

DEMANDA(I)
/
         PRODUTO_A 40
         PRODUTO_B 50
         PRODUTO_C 20
/
;

TABLE R(J, I)

                 PRODUTO_A       PRODUTO_B       PRODUTO_C
TORNO            5               3               5
FRESA            8               4               0
FURADEIRA        2               5               3
;

VARIABLE
X(I)
Z

positive variable X;

EQUATIONS
LUCRO
CONS(J)
DEM(I)
;

LUCRO.. Z =E= SUM((I), LC(I)*X(I));
CONS(J).. SUM((I), R(J, I)*X(I)) =L= DISP(J);
DEM(I).. X(I) =L= DEMANDA(I);

MODEL Untitled_2 /ALL/;
SOLVE Untitled_2 USING LP MAXIMIZING Z;
DISPLAY Z.L, X.L, CONS.L, DEM.L;
