# Ordenacao-do-RGM

Este projeto implementa e compara três algoritmos de ordenação simples em linguagem C aplicados ao meu RGM (12345678) e a vetores aleatórios de tamanhos maiores.

## Objetivo
Ordenar os dígitos do RGM e comparar desempenho (tempo e passos) de três métodos de ordenação:

- **Bubble Sort**
- **Selection Sort**
- **Insertion Sort**

# 1. Por que escolhi esses três métodos?

## 1. Bubble Sort
Bubble Sort é o algoritmo mais fácil de todos.  
Ele simplesmente compara dois elementos vizinhos e troca se estiverem na ordem errada.  
Isso se repete várias vezes até que o vetor esteja ordenado.

**Por que é bom para iniciantes?**
- A lógica é muito simples.
- É fácil visualizar mentalmente.
- Ajuda a entender comparação e troca.

---

## 2. Selection Sort
O Selection Sort procura o **menor elemento do vetor** e coloca na primeira posição.  
Depois procura o segundo menor, depois o terceiro, e assim por diante.

**Por que é bom para iniciantes?**
- Tem passos bem definidos.
- Ensina a ideia de “procurar o mínimo”.
- Muito simples de implementar.

---

## 3. Insertion Sort
O Insertion Sort funciona como quando você organiza cartas na mão:  
Ele coloca cada elemento na posição certa, deslocando os outros.

**Por que é bom para iniciantes?**
- É intuitivo (parece com coisas da vida real).
- Funciona muito bem para listas quase ordenadas.
- Ensina lógica de deslocamento e inserção.

---

## Entradas utilizadas
### **1. RGM**
- RGM como string: `"12345678"`
- Convertido para vetor: `[1,2,3,4,5,6,7,8]`

### **2. Vetores aleatórios**
- Três tamanhos:  
  - **N = 100**  
  - **N = 1000**  
  - **N = 10000**

Cada método ordena esses vetores e gera métricas.

---

## Métricas coletadas
Para cada algoritmo foram registradas:

- **Passos de comparação** (cada vez que o algoritmo compara dois valores)
- **Passos de troca** (cada vez que uma posição do vetor é alterada)
- **Tempo em milissegundos** medido com `clock()`

Política usada:
- 1 passo por comparação  
- 1 passo por troca  

# 4. Estrutura do projeto:

ordenacao-rgm/
|- src/
|- main.c
|- sorts.c
|- sorts.h
|- README.md

### O que cada arquivo faz?

#### `sorts.h`
Declara as funções e a estrutura de métricas.  
Serve para o `main.c` conseguir usar os algoritmos.

#### `sorts.c`
Aqui estão os algoritmos implementados.

#### `main.c`
Arquivo principal:
- lê o RGM  
- roda os 3 métodos  
- mede tempo e passos  
- imprime tudo em formato CSV  

---

# 5. Como compilar

Você pode compilar pelo terminal do Linux, Windows (MinGW), GitHub Codespaces ou Replit.

Comando:

gcc -O1 -std=c11 src/*.c -o ordena

E para rodar:

./ordena

---

# 6. Saída (CSV)

O programa imprime algo assim:

bubble,8,rgm,28,3,0.010
selection,8,rgm,28,7,0.005
insertion,8,rgm,7,5,0.004
bubble,100,aleatorio,...
selection,100,aleatorio,...
insertion,100,aleatorio,...

Cada coluna significa:

metodo,N,caso,comparacoes,trocas,tempo_ms

## Resultados obtidos no Replit (CSV)

bubble,8,rgm,28,0,0.002
selection,8,rgm,28,7,0.001
insertion,8,rgm,7,0,0.001
bubble,100,aleatorio,4950,2378,0.014
selection,100,aleatorio,4950,99,0.012
insertion,100,aleatorio,2474,2378,0.005
bubble,1000,aleatorio,499500,255696,0.788
selection,1000,aleatorio,499500,999,1.082
insertion,1000,aleatorio,256687,255696,0.271
bubble,10000,aleatorio,49995000,24947062,54.787
selection,10000,aleatorio,49995000,9999,106.796
insertion,10000,aleatorio,24957050,24947062,24.098

---

# 7. Análise e discussão

## Computabilidade
Todos os algoritmos funcionaram corretamente para ordenar:
- Os dígitos do RGM
- Os vetores aleatórios de tamanhos maiores

## Escalabilidade
Todos os três têm complexidade O(n²), então:
- Funcionam bem para vetores pequenos
- Ficam lentos em vetores de 10.000 elementos (como esperado)

## Comparação prática

### Bubble Sort
- É o mais simples, mas o **mais lento**
- Faz muitas trocas desnecessárias
- Ruim quando o vetor é grande

### Selection Sort
- Faz poucas trocas  
- Mas faz **muitas comparações**, mesmo que o vetor já esteja quase ordenado  
- Tempo fica parecido com Bubble Sort em vetores grandes

### Insertion Sort (o melhor dos três)
- Mais rápido para vetores parcialmente ordenados
- Muito eficiente para o RGM
- Menos comparações e trocas em casos favoráveis
 

