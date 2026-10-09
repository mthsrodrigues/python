# Estatística introdutória

Exercício de estimação de parâmetros usando os dados de tempo de decaimento do arquivo `decay.txt`.

Foram usados Python, NumPy, SciPy e Matplotlib.

## Problema 1

Os dados apresentam a forma esperada para tempos de decaimento: muitos eventos em tempos pequenos e uma cauda para tempos maiores.

Para o histograma foi usada a regra de Freedman-Diaconis. A ideia é evitar tanto um número muito pequeno de bins, que esconderia a forma da distribuição, quanto um número muito grande, que deixaria o histograma dominado pelas flutuações estatísticas.

Uma distribuição exponencial é adequada para descrever os dados, pois o tempo de decaimento de um sistema instável com taxa de decaimento constante é descrito por

f(t; tau) = (1/tau) exp(-t/tau).

O parâmetro tau representa o tempo de vida médio.

## Problema 2

Foram comparadas distribuições exponenciais para tau = 0.5 s, 1.0 s e 2.0 s.

Quanto maior tau, mais lentamente a distribuição decai e mais longa fica sua cauda.

Para tau = 2 s,

P(t <= 1 s) = 1 - exp(-1/2)

e o valor obtido foi aproximadamente

P(t <= 1 s) = 0.3935.

## Problema 3

Para N medidas independentes, a likelihood é

L(tau) = (1/tau)^N exp[-sum(t_i)/tau].

O máximo da likelihood fornece a estimativa do tempo de vida médio.

Para uma única observação t = 1 s, a likelihood tem máximo em

tau = 1 s.

Para um número grande de eventos, calcular diretamente o produto das probabilidades pode levar a underflow numérico. Por isso é mais conveniente trabalhar com a log-likelihood.

## Problema 4

Foi construída a função -2 ln L usando diretamente os 10000 valores individuais de `decay.txt`.

O estimador obtido foi

tau_hat = 1.2532 s.

As incertezas correspondentes a Delta(-2 ln L) = 1 foram aproximadamente

sigma inferior = 0.01245 s

sigma superior = 0.01262 s.

Portanto, o resultado pode ser escrito aproximadamente como

tau = 1.253 +/- 0.013 s.

Esse é um ajuste unbinned, pois os valores individuais dos tempos de decaimento são usados diretamente no cálculo da likelihood, sem utilizar os bins do histograma.

## Problema 5

Também foi realizada a minimização numérica de -2 ln L.

O resultado numérico reproduziu o valor obtido analiticamente:

tau_hat aproximadamente 1.2532 s.

A vantagem do método numérico é que ele também pode ser aplicado em casos mais complicados nos quais não existe uma solução analítica simples.

## Problema 6

Foram desenhadas distribuições Gaussianas para diferentes valores de mu e sigma.

O parâmetro mu desloca o centro da distribuição, enquanto sigma controla sua largura.

Para

mu = 200 GeV

sigma = 2 GeV

a probabilidade de observar massa maior ou igual a 205 GeV foi

P(m >= 205 GeV) aproximadamente 0.00621,

ou aproximadamente 0.62%.

Para duas partículas independentes com massas acima de 203 GeV,

P aproximadamente 0.00446,

ou aproximadamente 0.45%.

## Problema 7

Foi realizado um experimento de Monte Carlo usando médias de variáveis aleatórias com distribuição exponencial.

Para N = 3 a distribuição ainda apresenta uma assimetria evidente e não se parece muito com uma Gaussiana.

À medida que N aumenta, a distribuição da média se torna progressivamente mais próxima de uma distribuição Gaussiana.

Nos testes com N = 30, 60 e 100 essa aproximação fica cada vez mais evidente. A partir de aproximadamente N = 30 a forma já começa a lembrar uma Gaussiana, embora a aproximação continue melhorando para valores maiores de N.

Esse comportamento ilustra o Teorema Central do Limite.
