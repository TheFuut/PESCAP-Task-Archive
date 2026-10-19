# Influencer

## Historia

Libni es una reconocida creadora de contenido con más de 10 millones de seguidores en una red social. Gracias a su experiencia, ha perfeccionado sus estrategias de publicidad para maximizar el alcance de sus campañas.

Por otro lado, Alberto es un nuevo creador que ha comenzado recientemente en la plataforma. A pesar de su poca experiencia, ha logrado un crecimiento acelerado gracias a estrategias agresivas e innovadoras.

Ambos compiten por dominar la red social, la cual puede representarse como una cuadrícula de tamaño $N \times N$. Cada celda contiene una cantidad de usuarios potenciales que pueden ser alcanzados mediante publicidad.

## Problema

La red social está modelada como una matriz de tamaño $N \times N$, donde cada celda $(i, j)$ contiene un valor $a_{i,j}$, que representa la cantidad de usuarios potenciales.

En cada turno, un creador de contenido puede lanzar una campaña desde una celda $(i, j)$. Esta campaña afecta a la celda central y a sus cuatro vecinos ortogonales (arriba, abajo, izquierda y derecha), es decir:

- $(i,\ j)$
- $(i - 1,\ j)$
- $(i + 1,\ j)$
- $(i,\ j - 1)$
- $(i,\ j + 1)$

Las celdas fuera de la matriz se ignoran.

Cuando una campaña se realiza:

- Cada celda aún disponible dentro de la región afectada aporta su valor al jugador que realizó la campaña.
- Todas las celdas utilizadas en la campaña quedan **bloqueadas permanentemente** y no pueden volver a utilizarse ni aportar valor en turnos futuros.

Los creadores actúan de forma alternada:

- Libni realiza el primer movimiento.
- Luego alternan turnos hasta que todas las celdas de la matriz se encuentren bloqueadas.

En cada turno, el jugador elige una celda cuya campaña produce la mayor ganancia inmediata posible en ese instante.

Determina la suma total de valores obtenida por cada creador al finalizar el juego si ambas personas juegan de manera óptima.

## Entrada

La primera línea contiene un entero $N$, el tamaño de la matriz.

Las siguientes $N$ líneas contienen $N$ enteros cada una, donde el valor en la posición $a_{i,j}$ representa los usuarios potenciales alcanzables.

## Salida

Imprime dos enteros separados por un espacio: la cantidad total obtenida por Libni y la cantidad total obtenida por Alberto.

||input
3
1 2 3
4 5 6
7 8 9

||output
34 11

||description
La mejor campaña inicial se realiza en la celda con valor 8, obteniendo:

$5 + 7 + 8 + 9 = 29$

Posteriormente, Alberto obtiene una campaña de valor $11$ y Libni obtiene los valores restantes por un total de $5$.

Por lo tanto:

- $Libni = 34$
- $Alberto = 11$
||end

## Límites

- $1 \leq N \leq 10^3$
- $0 \leq a_{i,j} \leq 10^9$

## Subtareas

- Subtarea 1 (15 puntos): $N \leq 50$ y $a_{i,j} \leq 100$
- Subtarea 2 (15 puntos): $N \leq 200$
- Subtarea 3 (20 puntos): Todos los valores de $a_{i,j}$ son iguales.
- Subtarea 4 (50 puntos): Sin restricciones adicionales.
