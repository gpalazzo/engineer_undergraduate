SETS
i ALIMENTOS / MAIONESE, SALSA, MACA, AIPO /
j NUTRIENTES / SODIO, PROTEINAS, CARBOIDRATO, GORDURA, ACUCAR /
;

PARAMETERS
CUSTO_UNITARIO(I)
/
         MAIONESE        20
         SALSA           10
         MACA            15
         AIPO            30
/

QTD_MIN_NUTRIENTES(J)
/
         SODIO           17
         PROTEINAS       32
         CARBOIDRATO     9
         GORDURA         2
         ACUCAR          0.5
/
;

TABLE R(I, J)
                 SODIO     PROTEINAS     CARBOIDRATO     GORDURA     ACUCAR
     MAIONESE      0.5          0.8             0.4         0.7       0.01
     SALSA         0.6          0.7            0.32        0.44      0.005
     MACA          0.1          0.2            0.12        0.26      0.002
     AIPO         0.05          0.6            0.21        0.39       0.03
;

VARIABLES
X(I)
Z

POSITIVE VARIABLE X;

EQUATIONS
QTD_NUTRIENTES
CUSTO
;

QTD_NUTRIENTES(J).. SUM((I), R(I,J)*X(I)) =G= QTD_MIN_NUTRIENTES(J);
CUSTO.. Z =E= SUM((I), CUSTO_UNITARIO(I)*X(I));

MODEL DIETA /ALL/;
SOLVE DIETA USING LP MINIMIZING Z;
DISPLAY Z.L, X.L, QTD_NUTRIENTES.L;

