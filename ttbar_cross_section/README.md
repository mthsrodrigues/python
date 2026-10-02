# Exercício 7 - Seção de choque de produção de ttbar

Neste exercício calculei a seção de choque do processo de produção de pares top-antitop em colisões pp a 13 TeV usando o Pythia8 e o MadGraph5_aMC@NLO.

## Pythia8

No Pythia8 foram gerados 10000 eventos usando apenas o canal

qqbar -> ttbar

com a opção:

Top:qqbar2ttbar = on

O resultado obtido foi:

sigma = 65.72 +- 0.3431 pb

A PDF usada foi a padrão indicada no exercício, NNPDF2.3 QCD+QED LO.

Mantive apenas o canal qqbar -> ttbar no Pythia, como pedido inicialmente no enunciado. O canal gg -> ttbar não foi ativado nessa execução.

## MadGraph5_aMC@NLO

No MadGraph o processo usado foi:

generate p p > t t~

Também foram gerados 10000 eventos. A execução foi feita apenas em nível de partons, sem Pythia8 para shower/hadronização e sem Delphes.

O resultado foi:

sigma = 504.8 +- 0.7522 pb

A PDF usada foi:

NNPDF23_lo_as_0130_qed

com LHAPDF ID 230000.

As escalas de renormalização e fatoração ficaram na configuração dinâmica padrão do MadGraph.

## Comparação dos resultados

| Gerador | Seção de choque (pb) | Incerteza (pb) |
|---|---:|---:|
| Pythia8 | 65.72 | 0.3431 |
| MadGraph5_aMC@NLO | 504.8 | 0.7522 |

Os dois valores não concordam dentro das incertezas estatísticas.

A diferença principal é que no Pythia foi considerado apenas o canal qqbar -> ttbar, enquanto o comando usado no MadGraph inclui os subprocessos partônicos possíveis para produzir ttbar, incluindo gg -> ttbar.

Como o canal gg tem uma contribuição importante na produção de ttbar no LHC, o valor obtido no MadGraph ficou bem maior.

Também podem existir diferenças por causa das PDFs usadas, das escolhas das escalas de renormalização e fatoração, do valor de alpha_s e de outros parâmetros adotados por cada gerador.

Se o parton shower do Pythia8 fosse ativado depois da geração no MadGraph, ele modificaria a evolução e a estrutura final dos eventos, mas não o valor da seção de choque do processo duro calculado inicialmente.
