# CPU Extinction

**CPU Extinction** é uma ferramenta de *stress test* que realiza operações de benchmark para avaliação de desempenho de unidades de processamento central (CPU).

## Objetivo

O principal objetivo deste projeto é submeter a CPU a uma carga de trabalho intensiva por meio de algoritmos computacionalmente exigentes. O programa executa diferentes tipos de operações matemáticas e computacionais para simular cenários de alta demanda de processamento.

## Descrição

As operações implementadas incluem:

- **Cálculo de PI utilizando o algoritmo BBP (Bailey–Borwein–Plouffe);**
- **Cálculo de fatoriais de alta magnitude;**
- **Cálculos exponenciais com iterações massivas;**
- **Multiplicação de matrizes de grande porte;**
- **Contagem de números primos em intervalos extensos.**

Após a execução de cada tarefa, o tempo de processamento é registrado e avaliado com base em *thresholds* previamente definidos. O desempenho de cada operação é classificado como **"BOM"** ou **"RUIM"**, de acordo com os tempos de execução observados.

Além disso, o programa gera logs com informações detalhadas das operações, facilitando o acompanhamento e análise posterior.

---

Se quiser, dá pra acrescentar uma seção de **Requisitos**, **Compilação**, ou **Como Usar** no README. Exemplo:

```markdown
## Como compilar

```bash
gcc -o cpu_extinction cpu_extinction.c -lm
```

## Como executar

```bash
./cpu_extinction
```
## Executando

```
root@DESKTOP-0Q0GS8B:/mnt/c/Users/untw0/Desktop/program# ./cpu_extinction
PI calculado (BBP): 3.141592653589793 em 0.13 segundos.
Fatorial calculado (170!): 7257415615307994045399635715589591467896184117242257803405544211755693246215271577444614997868077640013184176271985826801597743247247979077995336619429980685793285768053360886112149825437081356365699043287884614002788490694530469661753007801896962563721104619242357348735986883814984039817295623520648167424 em 0.00 segundos.
Exponenciais calculado: 50000015000000.00 em 0.14 segundos.
Multiplicação de Matrizes concluída em 0.48 segundos.
Primos encontrados: 664579 em 4.40 segundos.

Teste finalizado! Logs salvos em 'cpu_result.log'
```

## Arquivo de log gerado

```
[Mon Mar 10 21:28:57 2025] ==== INICIANDO TESTE PESADO DE CPU ====
[Mon Mar 10 21:28:57 2025] Calculando PI (BBP)...
[Mon Mar 10 21:28:57 2025] Desempenho PI BBP: BOM
[Mon Mar 10 21:28:57 2025] Calculando Fatorial Iterativo...
[Mon Mar 10 21:28:57 2025] Desempenho Fatorial: BOM
[Mon Mar 10 21:28:57 2025] Calculando Exponenciais...
[Mon Mar 10 21:28:57 2025] Desempenho Exponenciais: BOM
[Mon Mar 10 21:28:57 2025] Multiplicando Matrizes 500x500...
[Mon Mar 10 21:28:58 2025] Desempenho Matrizes: BOM
[Mon Mar 10 21:28:58 2025] Contando Primos até 10 milhões...
[Mon Mar 10 21:29:02 2025] Desempenho Primos: BOM
[Mon Mar 10 21:29:02 2025] ==== FIM DO TESTE PESADO ====
```
