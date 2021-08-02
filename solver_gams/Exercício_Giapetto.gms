*SETS: Conjunto de dados ou variáveis. Os valores que a variável pode assumir;
*Na parte de produtos, o que vem depois da / representam os valores que a
*variável i pode assumir;
*O j abaixo é a mesma coisa.
SETS
i PRODUTOS / SOLDADOS, TRENS /
j RECURSOS / CARPINTARIA, ACABAMENTO /
;

*Parâmetros: tipo de variável que controla os valores dos produtos;
*O parâmetro passado para o LC, LC(parâmetro) são funcionalidades que controlam
*os valores do parâmetro, podendo ser produtos ou recursos.
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

*Tabela: relação de quantos recursos para cada produto;
TABLE R(I, J) Fabricação dos produtos i utilizando os recursos j
                 CARPINTARIA     ACABAMENTO
SOLDADOS         2               1
TRENS            1               1
;

VARIABLE
X(I) Define a equação do lucro
Z    Define a função objetivo (produção de cada produto)

positive variable X;

EQUATIONS
LUCRO            Define o valor máximo de lucro
CONS(J)          Define o quanto será consumido de cada recursos J
QTDESOLDADOS(I)  Define a quantidade de soldados a serem fabricados
;

*Os (..) fazem parte da sintaxe da linguagem;
*O parâmetro que vem primeiro dentro do SUM, indica qual produto vai ser
*utilizado para realizar as operações e o cálculo é feito com o que vem
*depois da vírgula (,);
*Quando foi colocado 'SOLDADOS' fixou-se a equação na variável soldados
*soldados <= 40.
LUCRO..  Z =E= SUM((I), LC(I)*X(I));
CONS(J).. SUM((I), R(I,J)*X(I)) =L= DISP(J);
QTDESOLDADOS('SOLDADOS')..  X('SOLDADOS') =L= 40;

MODEL Exercicio1 /ALL/;
SOLVE Exercicio1 USING LP MAXIMIZING Z;
DISPLAY Z.L, X.L, CONS.L, QTDESOLDADOS.L;