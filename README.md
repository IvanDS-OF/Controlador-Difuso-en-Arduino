# Controlador difuso SISO

Este código sirve para controlar una salida dada una entrada mediante un controlador basado en lógica difusa en Arduino. 

## Arduino
Arduino es una plataforma de creación de proyectos de código abierto. Se escogió esta plataforma porque es sencilla de entender y utilizar para proyectos de universidad como el presente. 

## Lógica difusa
La lógica difusa se basa en una forma de ver una señal como analógica, en donde una característica medible puede variar en valores de entre 0 y 1 _(Un límite inferior y un límite superior)_ dependiendo de la señal, el sensor y las funciones de membresia etablecidas por un experto en el área. Tanto las señales de entrada como las de salida pueden estar fusificadas. pero puede existir la posibilidad que solo la entrada sea fusificada y la salida sea discreta _(dos valores solamente **True** ó **False**)_.

Como ejemplo podemos poner a la temperatura de un CPU de un ordenador **como entrada** y la señal (PWM) de un ventilador regulable **como salida**. 
Para la señal de entrada podemos decir que se dividirá de la siguiente manera: 

```
Frío -> de 0 a 25 Grados C
Tibio -> de 20 a 35 Grados C
Caliente -> de 30 a 50 Grados C
```

Como podemos apreciar, la señal de entrada no se basa en dos datos específicos para garantizar el **Verdadero** y el **Falso**, si no que existe la presencia de un sensor que necesita medir en tiempo real para saber cómo está de caliente el CPU. 

Dependiendo de la señal de entrada, se generan reglas para controlar algo, en este caso, las salidas será una señal PWM en porcentaje de Pulso para el ventilador regulable, como se muestra a continuación.  

```
Baja Velocidad -> de 10 a 50 %
Velocidad Media -> de 25 a 75 %
Alta Velocidad -> de 50 a 100 $
```

Al igual que con las entradas, podemos ver que la señal de salida se divide en 3 etapas, que estas, a su vez, se dividen en sus respectivos límites. 

**Reglas**

A forma de enunciado podemos decir que 

> Cuando el CPU se encuentre **FRIO**, el ventilador tendrá **BAJA VELOCIDAD**

> Cuando el CPU se encuentre **TIBIO**, el ventilador tendrá **VELOCIDAD MEDIA**

> Cuando el CPU se encuentre **CALIENTE**, el ventilador tendrá **ALTA VELOCIDAD**



## Controlador
El controlador del código de este repo se divide en 2 partes

Entrada: Temperatura (Grados Centigrados) -> Baja _(0 a 50)_, Media _(25 a 75)_, Alta _(50 a 100)_
Salida: Energía (Ventilador) -> Baja _(0 a 50)_, Media _(25 a 75)_, Alta _(50 a 100)_

Al final, la relación que existe entre la entrada y la salida está dada **en función del error** [^1]

### Partes del código

Comenzamos por declarar los sensores de entrada. Como es un programa que interactua con el ambiente físico, es necesario declarar las entradas dados los puertos del Arduino en físico. 

Declaramos los valores de entrada 
+ Límites
+ Fórmula

Declaramos los valores de salida igual que en la entrada. 
+ Límites
+ Fórmula

Declaramos propiedades del controlador

Inicializamos el **void setup()** propio de Arduino, colocamos los valores de entrada y hacemos un **for** para declarar y asignar las variables de salida y las reglas del controlador. 

Creamos una función llamada **SALIDA** que solo se leerá una vez, sirve para fusificar la salida. 

Iniciamos el **void loop()**, es aquí en donde leemos la señal de entrada y se irá evaluando en las funciones de membresía de entrada. Igualmente se manda a imprimir los valores que corresponde _(dada la evaluación en tiempo real)_ de cada una de las funciones de membrsia. También se manda a llamar a dos funciones llamadas **REGLAS** y **DEFUZZ**

La función **REGLAS** evalua x100 el resultado de la evaluación de las funciones de membresía en ese momento y al final obtiene un solo dato _que será el responsable de nuestra salida_

Al final la función llamada **DEFUZZ** acondiciona mediante una división el valor que necesita la salida real física, con aquella que podemos medir e interactuar. Del mismo modo, imprime los valores obtenidos en la función **REGLAS**.

### Funciones de membresía utilizadas. 

Lsa funciones de membresía que fueron utilizadas en el código tienen una forma en campana de Gauss. 

## Simulación en MATLAB del comportamiento del controlador

Para ver un video de solo el comportamiento de un controlador difuso puede [acceder al siguiente link](https://youtu.be/roEcpSXAyCQ)





[^1]: Error = Valor deseado - Valor actual   :v:


