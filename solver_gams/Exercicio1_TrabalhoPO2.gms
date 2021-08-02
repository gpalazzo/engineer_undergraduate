SCALAR
QTD_CLIENTE_VIP / 150 /
MAX_FARINHA_ANIMAL / 500 /
MAX_FARINHA_VEGETAL / 800 /
;

SETS
f FARINHA / SANGUE, OSSO, ARROZ, SOJA, FOLHA /
m MISTURA / MISTURA1, MISTURA2, MISTURA3, MISTURA4 /
k COMPONENTES / COMPONENTE1, COMPONENTE2, COMPONENTE3 /
;

PARAMETERS
VENDA(M)
/
         MISTURA1 72.0
         MISTURA2 75.0
         MISTURA3 72.0
         MISTURA4 78.0
/

CUSTO(F)
/
         SANGUE 30.0
         OSSO 20.0
         ARROZ 20.0
         SOJA 27.0
         FOLHA 15.0
/
;

TABLE FARINHA_COMPONENTE(F,K)
                 COMPONENTE1     COMPONENTE2     COMPONENTE3
SANGUE           12.0            8.0             7.0
OSSO             2.0             3.0             1.0
ARROZ            18.0            2.0             0.0
SOJA             3.0             8.0             10.0
FOLHA            2.0             1.0             2.0
;

TABLE MISTURA_COMPONENTE_MIN(M,K)
                 COMPONENTE1     COMPONENTE2     COMPONENTE3
MISTURA1         4.0             2.0             1.0
MISTURA2         1.0             1.0             2.0
MISTURA3         3.0             2.0             3.0
MISTURA4         2.0             3.0             1.0
;

TABLE MISTURA_COMPONENTE_MAX(M,K)
                 COMPONENTE1     COMPONENTE2     COMPONENTE3
MISTURA1         17.0            15.0            12.0
MISTURA2         26.0            38.0            1000000.0
MISTURA3         8.0             17.0            15.0
MISTURA4         10.0            1000000.0       1000000.0
;

VARIABLE
X(M)
Y(F)
Z

POSITIVE VARIABLE X, Y;

EQUATIONS
LUCRO
MIN_CLIENTE_VIP(M)
QTD_MAX_FARINHA_MISTURA (M, K)
QTD_MIN_FARINHA_MISTURA (M, K)
MAX_FARINHA_A(F)
MAX_FARINHA_V(F)
;

LUCRO.. Z =E= SUM((M, F), VENDA(M)*X(M) - CUSTO(F)*Y(F));
QTD_MAX_FARINHA_MISTURA(M, K).. SUM(F, FARINHA_COMPONENTE(F,K)*Y(F)) =L= MISTURA_COMPONENTE_MAX(M,K);
QTD_MIN_FARINHA_MISTURA(M, K).. SUM(F, FARINHA_COMPONENTE(F,K)*Y(F)) =G= MISTURA_COMPONENTE_MIN(M,K);
MIN_CLIENTE_VIP(M).. X(M) =G= QTD_CLIENTE_VIP;
MAX_FARINHA_A(F).. Y('SANGUE') + Y('OSSO') =L= MAX_FARINHA_ANIMAL;
MAX_FARINHA_V(F).. Y('ARROZ') + Y('SOJA') + Y('FOLHA') =L= MAX_FARINHA_VEGETAL;

MODEL Exercicio1_TrabalhoPO2 /ALL/;
SOLVE Exercicio1_TrabalhoPO2 USING LP MAXIMIZING Z;
DISPLAY Z.L, X.L, Y.L, MIN_CLIENTE_VIP.L, QTD_MAX_FARINHA_MISTURA.L, QTD_MIN_FARINHA_MISTURA.L, MAX_FARINHA_A.L, MAX_FARINHA_V.L;





