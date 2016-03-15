# Algoritmos y Estructuras de Datos Avanzadas

## Práctica 3: Polimorfismo y excepciones

### Enunciado
* **Implementar una** jerarquía de tipos de números. Para ello se creará una **clase abstracta *Numero*** que define todas las operaciones comunes de los tipos de datos numéricos. A partir de esta clase abstracta se derivan las clases que implementan las operaciones para cada uno se los tipos de números. Los tipos de números desarrollados en la práctica 2: *Racional* y *Complejo*, se amplían con la implementación de los tipos de números: *Entero* y *Real*, que encapsulan un dato de tipo básico, *int* y *double*, respectivamente.

 La **clase *Numero* define** las operaciones, como mínimo:
   * **virtual const Entero toEntero() const = 0;** *Devuelve una copia del Numero actual en el tipo Entero*
   * **virtual const Racional toRacional() const = 0;** *Devuelve una copia del Numero actual en el tipo Racional*
   * **virtual const Real toReal() const = 0;** *Devuelve una copia del Numero actual en el tipo Real*
   * **virtual const Complejo toComplejo() const = 0;** *Devuelve una copia del Numero actual en el tipo Complejo*
   * **virtual ostream& toStream(ostream& sout) const = 0;** *Escribe un Numero al flujo sout*
   * **virtual istream& fromStream(istream& sin) = 0;** *Lee un Numero desde flujo sin*

* Manejar, mediante el mecanismo de las excepciones, las condiciones de error que se detectan en las implementaciones de las plantillas *(vector, Lista, Pila y cola)*, y en los tipos de números *(entero, racional, real y complejo)*.

* Para comprobar el funcionamiento del código escribir un programa que utilice las plantillas con datos de cualquier tipo de número a través de punteros a la clase base *Numero**.

### Objetivo
El objetivo de esta práctica es la utilización del polimorfismo para crear una jerarquía de clases e introducir el manejo de errores mediante el uso de excepciones.

Para realizar esta práctica se utilizará y modificará el código generado en las dos primeras prácticas:
* **[Practica1 ->][1]** Implementación de estructuras de datos: *Vector, List, Stack y Queue*.

* **[Práctica2 ->][2]** Implementación de una calculadora en notación postfija.

[1]: (sorry "Esto no está en un repositorio externo. Búscalo en este.")
[2]: (https://github.com/alu0100769609/aedaP2 "Ir al repositorio")


### Forma de uso

#### Compilación
```bash
$ g++ main/main.cpp -o main.out
```
```bash
$ ./main.out
```
#### Ejecución
* Para el ejemplo usando **int**: (3 + 2) * (5 - 7)
```
 3 2 + 5 7 - *
```
* Para el ejemplo usando **float**: (3.2 + 2.4) * (5 - 7.1)
```
 3.2 2.4 + 5 7.1 - *
```
* Para el ejemplo usando **complejo**: (3+2i + 2+4i) - (5+2i - 7+1i)
```
 (3,2) (2,4) + (5,2) (7,1) - -
```
* Para el ejemplo usando **racional**: (3/2 + 2/4) * (7/1 - 5/1)
```
 {3/2} {2/4} + {7/1} {5/1} - *
```
### Autor

* [Adexe Sabina Pérez](http://alu0100769609.github.io)
