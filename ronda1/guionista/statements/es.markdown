# Guionista

## Historia

Un guionista trabaja para una revista de programación que está preparando una nueva edición de su publicación.

Durante la revisión final, el comité editorial decidió cambiar el formato de muchas palabras: algunas deben aparecer en negrita para resaltar conceptos importantes, otras en cursiva para indicar términos especiales, y algunas deben usar ambos estilos al mismo tiempo.

El problema es que el editor de texto que utiliza la revista es bastante antiguo. En lugar de permitir modificar palabras individualmente, cada cambio debe aplicarse sobre exactamente $k$ **palabras consecutivas**. Además, en cada operación solo se puede alternar la negrita o la cursiva en todo el segmento seleccionado.

El guionista quiere saber si es posible transformar el documento actual en el documento deseado y, en caso afirmativo, cuál es el mínimo número de operaciones necesarias.

## Problema

Se te dan dos arreglos $a$ y $b$, ambas de tamaño $N$.

Cada posición representa el formato de una palabra:

- `1` = normal
- `2` = negrita
- `3` = cursiva
- `4` = negrita y cursiva

En una operación puedes:

1. Elegir un **segmento** $[l, r]$ de longitud exactamente $k \ (r - l + 1 = k)$ con $(1 \leq l \leq r \leq N)$.
2. Aplicar una de las siguientes acciones sobre todas las palabras del segmento:
    - alternar negrita.
    - alternar cursiva.

Alternar un estilo significa agregarlo si no está presente o quitarlo si ya estaba presente.

Determina el mínimo número de operaciones necesarias para transformar $a$ en $b$. Si no es posible, imprime $-1$.

## Entrada

La primera línea contiene dos enteros $N$ y $K$.

La segunda línea contiene $N$ enteros $a_1, a_2, \dots, a_N$

La segunda línea contiene $N$ enteros $b_1, b_2, \dots, b_N$

## Salida

Imprime un solo entero: el mínimo número de operaciones necesarias para que el documento alcance el formato objetivo, o $-1$ si la transformación es imposible.

## Ejemplos

||input
6 3
1 1 1 1 1 1
2 2 2 3 3 3

||output
2

||description
Basta con aplicar dos operaciones:

- alternar la negrita en el segmento $[1, 3]$
- alternar la cursiva en el segmento $[4, 6]$

||input
5 1
1 1 1 1 1
4 4 4 4 4

||output
10

||description
Cada palabra debe pasar de formato normal a negrita y cursiva.

Como $k = 1$, cada operación afecta exactamente una sola palabra.

Para cada posición se necesitan dos cambios:

- uno para activar la negrita;
- uno para activar la cursiva.

En total, se requieren $5 \times 2 = 10$ operaciones.

||input
3 2
1 1 1
2 1 1

||output
-1

||description
Las únicas operaciones posibles afectan los segmentos $[1, 2]$ y $[2, 3]$.

No existe una secuencia de operaciones que cambie solo la primera palabra sin afectar otra posición de manera incompatible, así que la transformación es imposible.
||end

## Límites

- $1 \leq N \leq 2 \times 10^5$
- $1 \leq K \leq N$
- $1 \leq a_i, b_i \leq 4$

## Subtareas

- Subtarea 1 (20 puntos): $K = 1$
- Subtarea 2 (15 puntos): $K = N$
- Subtarea 3 (25 puntos): $N \leq 2000$
- Subtarea 4 (40 puntos): Sin restricciones adicionales
