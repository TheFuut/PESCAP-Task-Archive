# Último Dígito

## Descripción

María encontró una libreta vieja con tres números escritos en la primera página, siempre en el mismo orden:

$$8, 4, 5$$

Intrigada, decidió continuar la secuencia con una regla muy particular:

Cada minuto observa los **últimos tres números** que aparecen en la lista, los suma, duplica el resultado y luego toma el residuo al dividir entre 9. El número obtenido lo escribe al final de la lista.

Es decir, si los últimos tres números son $a, b, c$, el siguiente número que se añade es:

$$ \ ( 2 × (a + b + c) ) \ mod \ 9$$

Con el paso del tiempo, la lista crece indefinidamente.

María hizo varias preguntas: para distintos valores de minutos transcurridos, quiere saber cuál es el **último número de la lista** en ese momento.

Ayuda a María a responder todas sus preguntas.

## Entrada

- La primera línea contiene un número $N$, el número de preguntas que María anotó en su libreta.
- En las siguientes $N$ líneas aparece un número $M$, que representa la cantidad de minutos transcurridos desde el inicio.

## Salida

Debes escribir $N$ líneas, una por cada pregunta. La línea debe contener un entero que representa el último número de la lista después de $M$ minutos.

## Ejemplo

||input
3
1
33
2026

||output
7
4
8

||description
En el primer caso de prueba, el último dígito es $7$, porque si sumas los tres últimos números que hay en ese momento obtienes $8 + 4 + 5 = 17$, y cuando divides $34$ entre $9$, el residuo de la división es $7$.

En el segundo caso, después de $33$ minutos el último número es $4$.

En el tercer caso, después de $2026$ minutos el último número es $8$.
||end

## Nota

Se considera que en el minuto $0$ la lista es exactamente: $8, 4, 5$

## Límites

- $1 \leq N \leq 10^4$
- $1 \leq M \leq 10^{18}$

## Subtareas

- **(10 puntos)** $N = 1$, $M = 8$
- **(25 puntos)** $N, M \leq 100$
- **(25 puntos)** $M \leq 10^8$
- **(40 puntos)** Sin restricciones adicionales
