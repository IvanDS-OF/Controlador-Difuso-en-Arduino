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



### Partes del código



### Funciones de membresía utilizadas. 


## Simulación en MATLAB del comportamiento del controlador





