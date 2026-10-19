# Entrenamiento

## Historia

Leo es un olímpico extremadamente ambicioso que participa en concursos de programación, matemáticas, inteligencia artificial, ciberseguridad y cualquier otra competencia que encuentre en internet. Sin embargo, hay un pequeño problema: a Leo no le gusta entrenar demasiado.

Como tampoco le gusta perder tiempo organizando horarios, decidió seguir una rutina muy simple. Elegirá un día inicial $s$ y un intervalo $d$, y a partir de ahí entrenará en los días $s,\ s+d,\ s+2d,\ s+3d$, y así sucesivamente.

Cada sesión de entrenamiento la dedica a prepararse para el primer concurso que ocurra en un día mayor o igual al de la sesión. Como Leo quiere entrenar lo menos posible, desea elegir los valores de $s$ y $d$ de manera que todos sus concursos reciban al menos una sesión de entrenamiento, utilizando la menor cantidad posible de entrenamientos. Además, como constantemente encuentra nuevos concursos interesantes, a veces agrega uno más a su calendario y vuelve a preguntarse cuál es la mínima cantidad de entrenamientos que necesita.

## Problema

Inicialmente, Leo tiene $N$ concursos en días estrictamente crecientes $c_1, c_2, \dots, c_N$.

Se te darán $Q$ consultas de dos tipos:

- $1$ — Imprimir la mínima cantidad de entrenamientos que Leo necesita actualmente.
- $2 \ x$ — Agregar un nuevo concurso en el día $x$. No deberás imprimir nada
en este caso.

Para responder una consulta de tipo $1$, Leo puede elegir una rutina periódica de entrenamiento definida por un día inicial $s$ y una diferencia $d$, con $1 \leq s, d$.

La rutina genera entrenamientos en los días:

$$s,\ s+d,\ s+2d,\ s+3d, \dots$$

Cada sesión en el día $x$ se asocia al primer concurso cuyo día sea mayor o igual que $x$.

- Una sesión sólo puede cubrir un concurso.
- Un concurso puede recibir varias sesiones, pero basta con que reciba al menos una para quedar cubierto.

La rutina termina en el momento en que el último concurso recibe una sesión asociada. Los entrenamientos posteriores no se consideran parte de la rutina ni cuentan en la respuesta.

El objetivo de Leo es cubrir todos sus concursos utilizando la menor cantidad posible de entrenamientos.

Cada consulta de tipo $1$ debe resolverse de manera independiente: Leo puede elegir cualquier par $(s, d)$, sin importar los usados en consultas anteriores.

Al agregar un nuevo concurso, éste debe insertarse en la posición correspondiente para mantener el orden creciente de los días.

## Entrada

La primera línea contiene dos enteros $N$ y $Q$, donde $N$ es la cantidad inicial de concursos y $Q$ es el número de consultas.

La segunda línea contiene $N$ enteros estrictamente crecientes $c_1, c_2, \dots, c_N$, que representan los días de los concursos iniciales.

Cada una de las siguientes $Q$ líneas corresponde a una consulta.

## Salida

Por cada consulta de tipo $1$, imprime en una nueva línea un entero: la mínima cantidad de entrenamientos que Leo necesita con los concursos actuales.

## Ejemplos

||input
2 3
10 20
1
2 15
1

||output
2
3

||description
Antes de agregar el concurso del día $15$, una rutina óptima puede usar dos entrenamientos.

Después de agregarlo, la mínima cantidad de entrenamientos pasa a ser $3$.

||input
3 1
5 10 15
1

||output
3

||description
Una forma óptima es elegir $s = 5$ y $d = 5$, así que Leo entrena los días $5$, $10$ y $15$.
||end

## Límites

- $1 \leq N, Q \leq 1000$
- $1 \leq c_i \leq 10^4$
- Los concursos iniciales están en orden estrictamente creciente.
- En cada consulta de tipo $2 \ x$, el día $x$ no coincide con ningún concurso existente.
- Se garantiza que todos los concursos ocurren en días distintos.
- Habrá a lo mucho 100 consultas de tipo $1$.
- Se garantiza que existe al menos una consulta de tipo $1$.

## Subtareas

- Subtarea 1 (20 puntos): $1 \leq N, Q \leq 100$ y $1 ≤ c_i, x ≤ 200$.
- Subtarea 2 (15 puntos): Sólo hay una consulta de tipo $1$ en toda la secuencia.
- Subtarea 3 (15 puntos): Sólo hay una consulta de tipo $2$ en toda la secuencia.
- Subtarea 4 (50 puntos): Sin restricciones adicionales.
