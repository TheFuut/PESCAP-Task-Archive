# Búho

## Historia

Desde tiempos antiguos, el reino de Matías ha estado conectado por una compleja red de caminos que atraviesan bosques, montañas y desiertos. Para mantener la comunicación entre las aldeas, los habitantes suelen enviar mensajes utilizando búhos mensajeros especialmente entrenados.

Cada camino del reino tiene asociado un nivel de peligro. Algunos atraviesan territorios infestados de bandidos, otros cruzan barrancos peligrosos, y unos cuantos son tan seguros que los búhos los recorren sin dificultad. Cuando un búho realiza un viaje, el riesgo del trayecto queda determinado por el camino más peligroso que tuvo que recorrer durante su recorrido.

Gracias a siglos de experiencia, los búhos siempre eligen rutas de forma muy particular: entre todas las rutas posibles entre dos aldeas, seleccionan aquella cuyo riesgo sea el menor posible. Boris, encargado de organizar las comunicaciones del reino, necesita responder muchas consultas sobre el nivel de riesgo que tendrían distintos envíos.

## Problema

El reino está formado por $N$ aldeas numeradas del $1$ al $N$, conectadas mediante $M$ caminos bidireccionales.

Cada camino conecta dos aldeas y tiene asociado un entero positivo que representa su nivel de peligro.

El riesgo de una ruta se define como el mayor nivel de peligro entre todos los caminos utilizados en dicha ruta.

Para cada consulta, dadas dos aldeas $a$ y $b$, determina el menor riesgo posible de una ruta que conecte ambas aldeas.

Se garantiza que siempre existe al menos una ruta entre cualquier par de aldeas.

## Entrada

La primera línea contiene tres enteros $N, M$ y $Q$: número de aldeas, número de caminos y número de consultas.

Las siguientes $M$ líneas contienen tres enteros $u, v$ y $w$, indicando un camino bidireccional entre $u$ y $v$ con nivel de peligro $w$.

Las siguientes $Q$ líneas contienen dos enteros $a$ y $b$, que representan una consulta sobre las aldeas $a$ y $b$.

## Salida

Para cada consulta imprime una línea con un entero: el menor riesgo posible de una ruta entre las aldeas consultadas.

## Ejemplos

||input
5 6 3
1 2 4
2 3 7
1 3 10
3 4 2
4 5 8
2 5 6
1 5
1 4
3 5

||output
6
7
7

||description
Entre 1 y 5, una ruta óptima es: $1 → 2 → 5$. Los peligros son $4$ y $6$, por lo que el riesgo es $6$.

Entre 1 y 4, existe la ruta: $1 → 2 → 3 → 4$, cuyo riesgo es $7$.
||end

## Límites

- $2 \leq N \leq 2 \times 10^5$
- $N - 1 \leq M \leq 2 \times 10^5$
- $1 \leq Q \leq 2 \times 10^5$
- $1 \leq a, b \leq N$
- $1 \leq w \leq 10^9$
- El grafo es conexo.

## Subtareas

- Subtarea 1 (1 punto): Boris le preguntó al búho cuál es la respuesta de cada consulta antes del concurso.
- Subtarea 2 (14 puntos): $N \leq 500$
- Subtarea 3 (15 puntos): Todos los caminos tienen el mismo valor de peligro.
- Subtarea 4 (20 puntos): El grafo es un árbol.
- Subtarea 5 (20 puntos): $Q \leq 1000$
- Subtarea 6 (30 puntos): Sin restricciones adicionales.
