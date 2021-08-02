Sets

P  Conjunto de produtos /A,B,C/
R  Conjunto de recursos /torno,fresa,furadeira/;

Parameters
 LucUnit(P)  Lucro Unitario do Produto P
 / A   20.00
   B   15.00
   C   18.00  /

 Demanda(P)  Demanda semanal do produto P
 / A   40.00
   B   50.00
   C   20.00  /

 HDisp(R)  Numero de Maquinas do recurso R
 / torno      400
   fresa      500
   furadeira  300 /;

Table Cons(R,P)  Consumo do recurso R no produto
            A      B    C
torno      5.0   3.0   5.0
fresa      8.0   4.0   0.0
furadeira  2.0   5.0   3.0 ;

Variables
 X(P) Producao semanal do produto P
 LT   Lucro Total;

Positive Variables  X;

Equations
 FO      Equação que define o lucro total
 Dem(P) Restricao de demanda semanal do produto
 Cap(R) Restricao de disponibilidade do produto;

 FO     ..  LT =E= SUM(P,LucUnit(P) * X(P));
 Dem(P) ..  X(P) =L= Demanda(P);
 Cap(R) ..  SUM(P,Cons(R,P)*X(P)) =L= HDisp(R);

 Model Producao /All/;
 Solve Producao Maximizing LT Using MIP;

