*SETS: Conjunto de dados ou vari�veis. Os valores que a vari�vel pode assumir;
*Na parte de produtos, o que vem depois da / representam os valores que a
*vari�vel i pode assumir;
*O j abaixo � a mesma coisa.
SETS
i PRODUTOS / SOLDADOS, TRENS /
j RECURSOS / CARPINTARIA, ACABAMENTO /
;

*Par�metros: tipo de vari�vel que controla os valores dos produtos;
*O par�metro passado para o LC, LC(par�metro) s�o funcionalidades que controlam
*os valores do par�metro, podendo ser produtos ou recursos.
PARAMETERS
LC(I) Lucro de cada produto
/
         SOLDADOS 3
         TRENS 2
/

DISP(J) Disponibilidade dos recursos
/
         CARPINTARIA 80
         ACABAMENTO 100
/
;

*Tabela: rela��o de quantos recursos para cada produto;
TABLE R(I, J) Fabrica��o dos produtos i utilizando os recursos j
                 CARPINTARIA     ACABAMENTO
SOLDADOS         2               1
TRENS            1               1
;

VARIABLE
X(I) Define a equa��o do lucro
Z    Define a fun��o objetivo (produ��o de cada produto)

positive variable X;

EQUATIONS
LUCRO            Define o valor m�ximo de lucro
CONS(J)          Define o quanto ser� consumido de cada recursos J
QTDESOLDADOS(I)  Define a quantidade de soldados a serem fabricados
;

*Os (..) fazem parte da sintaxe da linguagem;
*O par�metro que vem primeiro dentro do SUM, indica qual produto vai ser
*utilizado para realizar as opera��es e o c�lculo � feito com o que vem
*depois da v�rgula (,);
*Quando foi colocado 'SOLDADOS' fixou-se a equa��o na vari�vel soldados
*soldados <= 40.
LUCRO..  Z =E= SUM((I), LC(I)*X(I));
CONS(J).. SUM((I), R(I,J)*X(I)) =L= DISP(J);
QTDESOLDADOS('SOLDADOS')..  X('SOLDADOS') =L= 40;

MODEL Exercicio1 /ALL/;
SOLVE Exercicio1 USING LP MAXIMIZING Z;
DISPLAY Z.L, X.L, CONS.L, QTDESOLDADOS.L;