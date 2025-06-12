# EDA #level5: Lequel5

## Integrantes del grupo y contribucion al trabajo de cada integrante

* Lucas Solar Grillo, programador
* Matias Asmus, programador
* Andrea Belen Enricci Louzan, programador

## Respuestas del enunciado
Enrutador PCB

Durante la investigacion sobre algoritmos de enrutado encontramos que el El algoritmo Floodfill es preferido en el
enrutamiento PCB por varias razones clave. Su popularidad se fundamenta en su capacidad para optimizar la ruta de
las pistas eléctricas de manera eficiente y efectiva. Además, Floodfill es conocido por su capacidad para manejar
grandes cantidades de datos y complejidades geométricas,
lo que lo hace adecuado para aplicaciones en PCB modernos donde la densidad y la complejidad son altas.
Nosotros tomamos este acercamiento para el enrutado, primero se calculan las distancias de un punto
al resto de la matriz y luego se unen los puntos donde haya componentes buscando la distancia minima entre ellos.


sources:
https://www.electronicdesign.com/resources/whats-the-difference-between/article/21800231/whats-the-difference-pcb-routing-then-and-now

https://core.ac.uk/download/pdf/144446551.pdf

https://en.wikipedia.org/wiki/Routing_(electronic_design_automation)