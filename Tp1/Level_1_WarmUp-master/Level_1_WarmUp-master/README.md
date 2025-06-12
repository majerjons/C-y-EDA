# EDA #level1: Orbital simulation

## Integrantes del grupo y contribución al trabajo de cada integrante

* Quiroga, Ignacio: Configuración y creación de asteroides y mejora de la complejidad computacional.
* Riverós, Santiago Andrés: Estructuras de OrbitalSim.h, funciones de OrbitalSim.cpp, mejoras en la complejidad computacional, bonus
points de Júpiter y Alpha Centauri y redacción de README.md.
* Solar Grillo, Lucas: Funciones de View.h, verificación del timeStep, mejoras en la complejidad computacional, descubrimiento
del Easter Egg, y redacción del README.md.

## Verificación del timestep

Primero, se analizó qué era la variable timeStep, llegando a la conclusión de que es una variable que controla la velocidad de la 
simulación. Esto se logra de la siguiente manera: tras cada iteración del bucle principal main, la simulación avanza un timeStep, 
lo que permite regularlo. Cuanto más pequeño sea, más cercano será a la realidad.

Análisis del impacto de timeStep respecto a los recursos de la CPU y la GPU:
GPU:
Al reducir el timeStep, implica un incremento en la cantidad de fotogramas por segundo (FPS). Esto impacta negativamente en la GPU,
ya que debe renderizar más fotogramas por segundo. Además, puede provocar un cuello de botella entre la CPU y la GPU debido al estrés
provocado en la CPU. Por último, si se incrementa el timeStep, aliviará la carga de la GPU ya que renderizará menos FPS. 
Sin embargo, la simulación no será fluida.

CPU:
Al reducir el timeStep, se provoca una mayor cantidad de cálculos por iteración del bucle principal. Esto puede provocar estrés en la 
CPU. Por el contrario, un timeStep mayor alivia la carga de la CPU, pero hace menos precisa la simulación.

En conclusión, se decidió dejar el valor de timeStep como fue dado, ya que nos parece un valor más que óptimo para no estresar
tanto a la CPU como a la GPU, y al mismo tiempo ofrece un nivel de precisión más que aceptable.

## Verificación del tipo de datos float

Considerando que:
* El cuerpo más pesado del Sistema Solar es el Sol, que pesa 1,989 E+30 kg [https://www.nationalgeographic.com.es/ciencia/sol-estrella-que-sostiene-vida-tierra_18659],
* El planeta que viaja más rápido en el Sistema Solar es Mercurio, que lo hace a 48055,55 m/s [https://www.nationalgeographic.com.es/ciencia/sol-estrella-que-sostiene-vida-tierra_18659],
* El planeta más alejado del Sol es Neptuno, que llega a estar a 5,456 E+12 m de él [http://hyperphysics.phy-astr.gsu.edu/hbasees/Solar/soldata3.html],
* El planeta de mayor tamaño es Júpiter, cuyo radio es 71,49 E+6 m [http://hyperphysics.phy-astr.gsu.edu/hbasees/Solar/soldata2.html#c5],

El tipo de datos float es adecuado para representar todas estas magnitudes de los distintos cuerpos del Sistema Solar, ya que en la arquitectura de 64 bits 
tiene un rango de representación de 1,175494351 E-38 a 3,402823466 E+38. 
El tipo de datos double sería excesivo, ya que su rango de representación va de 2,2250738585072014 E-308 a 1,7976931348623158 E+308,
e insumiría muchos más recursos innecesariamente [https://learn.microsoft.com/es-es/cpp/c-language/type-float?view=msvc-170].

## Complejidad computacional con asteroides
En un primer lugar, al colocar 500 asteroides, la simulación se realentizó considerablemente, con los fps oscilando entre 15 y 20 aproximadamente. 
La complejidad algorítmica de esta situación consiste en que, tal como estaba planteado el programa, ahora se tendrían que renderizar 500 cuerpos adicionales,
cada un con un radio determinado, y se añadirían **500 términos** a la sumatoria de fuerza neta para el cálculo de la aceleración de cada uno de los
cuerpos del sistema.


## Mejora de la complejidad computacional
Para mejorar la complejidad computacional se tomaron las siguientes decisiones:
* Al advertir que para el cálculo de la aceleración de cada cuerpo la masa del mismo se cancelaría, se evitó multiplicar
y dividir por el mismo valor, ahorrando recursos.
* Como hay una diferencia de 12 órdenes de magnitud entre la masa de los planetas y la de los asteroides, se consideró despreciable el efecto
de los mismos en el cálculo de fuerza neta sobre cada cuerpo, evitando una cantidad de ciclos igual a la cantidad de asteroides en cada cálculo.
* En View.cpp, para la visualización de los asteroides, se reemplazó la función DrawSphere() por DrawPoint3D(). Como consecuencia de esto, los valores
de masa y radio de mismos fueron desestimados y esos campos no fueron cargados en la estructura.

## Bonus points
* Al multiplicar por 1000 la masa de Júpiter, el Sol deja de ser el centro del Sistema Solar, y llegado un momento la Tierra se sale 
de órbita abruptamente. **Para activar este bonus, definir JUPITER_MASIVO en ephemerides.h**.
* Al agregar un agujero negro 10 veces más masivo que el Sol y de 30000km de radio en una posición arbitraria con velocidad inicial cero, el Sistema Solar se altera 
y se traslada en conjunto hacia él. **Para visualizar este fenómeno, definir AGUJERO_NEGRO en ephemerides.h**. [https://www.nationalgeographic.es/espacio/agujeros-negros].
* El sistema Alpha Centauri contiene la segunda y la tercera estrella más cercana al Sistema Solar. **Para activar este bonus, definir ALPHA_CENTAURI en OrbitalSim.h.**.
* El easter egg es que al inicializar la variable phi con el número áureo, los asteroides se mueven en espiral, como representación de
este fenómeno. **Para visualizar este fenómeno, definir EASTER_EGG en OrbitalSim.h**.
