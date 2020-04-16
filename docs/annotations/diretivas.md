# Diferença entre as Diretivas atomic e critical

## Sintaxe

### Atomic

```c
#pragma omp atomic
  expression
```

### Critical

Você pode definir um nome opcional para identificar o código critical. Esse nome deve estar entre parênteses.

```c
#pragma omp critical [(name)]
{
  code_block
}
```

## Exemplo

```c
#pragma omp atomic
count++;
#pragma omp critical
count++;
```

O efeito ocorrido na variável count é o mesmo, porém como ele irão funcionar é o que diferenciar as cláusulas.

A diretiva **critical** do OpenMP é totalmente genérica, ou seja, pode cercar qualquer bloco arbitrátio de código. Ao passo que a diretiva **atomic** existe um única expressão.

Além disso, no OpenMP uma diretiva **critical** sem nome, as seções críticas são consideradas idênticas, de mode que se uma Thread estiver em uma seção critical (sem nome), nenhuma outra Thread pode executar essa seção crítica. Para contornar isso podemos utilizar seções críticas nomeadas.

Uma operação **atomic** tem uma sobrecarga muito menor. A diferença entre as duas é que a **atomic** tenta utilizar recursos do hardware para ser mais eficiente. Por exemplo, uma operação de incremento atômico.

As consturções **critical** e **atomic** servem para dizer que o que estiver dentro do escopo dessas diretivas, deve ser executado somente por uma Thread, num determinado instante de tempo.

# Diretiva single

A diretiva **single** especifica que um bloco de código deve ser executado por apenas uma das Threads.

## Sintaxe

```c
#pragma omp single [clauses]
{
 code_block
}
```

Essa diretiva suporta as cláusulas:

* copyprivate
* firstprivate
* nowait
* private
