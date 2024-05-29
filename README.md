# Proyecto: Gestión de Restaurante.
Un restaurante familiar de nombre Charl´s quiere un programa que les permita tener más control con sus clientes y pedidos, este restaurante cuenta con un menú ya establecido de comida italiana y unas bebidas fuera de este mundo así como con una capacidad máxima para 50 clientes. En este proyecto recrearemos usando el lenguaje de c++ esta simulación.

## Correcciones realizadas
- Se le puso el mismo nombre a los metodos **calcula_costo** y **muestra_datos** para que de esta forma cumpla como sobreescritura correctamente.

## Novedades del avance 3
- Ahora la clase restaurante no se le agregan objetos de la clase Bebida y Comida, sino que se implemento polimorfismo en la clase de Pedido (clase padre de estas ultimas dos), donde ahora restaurante recibe una lista de Pedidos que son objetos de comida y bebida, pero que hace más limpio el codigo debido al polimorfismo.

- La funcion recibe clientes ahora regresa un vector de clientes para poder hacer uso de sus atributos en el main.

- Se cambio la estructura del main, ahora solo incluyendo la historia del restaurante y se añadio una funcion para calcular el cambio en funcion al dinero del cliente.

- Se añadieron destructores a las clases, así como un destructor virtual a la clase pedido debido a que como tiene polimorfismo para que pueda eliminar los objetos de sus clases hijas correctamente.

## UML (diagrama de clases).
En el UML se encuentran 5 clases (Restaurante, Pedido, Persona, Comida, Bebida), a continuación se explicarán las relaciones entre clases para dar a comprender el porque se colocaron de esta forma.
- **Relación de Composición:** La clase Persona compone a la clase de Restaurante, debido a que las personas actuarían como nuestros clientes y sin el restaurante no puede haber clientes.

- **Relación de Agregación:** Actualmente la clase Pedido se agrega a la clase de Restaurante, donde Pedido es una clase padre de Comida y Bebida pero que gracias al polimorfismo podemos simplemente agregar la clase Pedido y usar los metodos de sus clases hijas dependiendo el objeto a crear // (esto en anterior avance)Tanto la clase Comida como Bebida se agregan a la clase de Restaurante, por el motivo de que los restaurantes ya tienen un menú definido y creado, permitiendo a los clientes escoger de este.
  
- **Relación de Herencía:** La clase pedido es madre de dos clases llamadas Comida y Bebida, puesto que al final de cuentas ambos son considerados pedidos y estos tienen atributos en común entre sí, por este motivo resulta mejor que estos atributos en común se compartan para facilitar la lectura y comprensión del codigo.

- **Polimorfismo:** La clase Pedido tiene dos metodos con polimorfismo, **muestra_datos** y **calcula_costo** la cual se pueden crear instancias de objetos de comida y bebida en los cuales dependiendo el tipo de objeto se mandarán llamar los diferentes metodos con sobreescritura.

## Funcionamiento esperado en avances futuros:
Lo que se espera que se haga son los métodos de clases, para una mejor explicación lo separaré por sus clases:
- **Restaurante:** primeramente tendremos los setters y getters que permitirán modificar los valores de los atributos y conocerlos, así como crear pedidos, ingresar las personas y en base al numero de estas calcular la capacidad del restaurante, donde si llega al tope que retorne un valor de string indicando que se ha alcanzado la capacidad máxima y finalmente, calcular el costo de los pedidos.
  
- **Persona:** tenemos los setters y getters de sus atributos, así como un metodo para mostrar sus datos.
  
- **Pedido:** tenemos sus setters y getters de sus atributos, así como un metodo para calcular el precio individual y mostrar sus datos, en caso de que algún cliente desee ver la descripcion de su producto o el menú.
  
- **Comida:** estan sus setters y getters para sus atributos, del mismo modo que tiene los atributos y metodos de la clase padre y un metodo que permita pedir que se cambie a una orden vegana y el calculo del precio dependiendo de diversos factores como el tamaño o si es comida vegana.
  
- **Bebida:** tiene sus setters y getters para sus atributos, los atributos y metodos de la clase padre y un metodo que permita agregar hielo a su bebida y el calculo del precio que dependa de factores como el tamaño o si tiene hielo.

## Casos que harían que dejara de funcionar:
- Algun parametro ingresado de mala manera: por ejemplo en lugar de ingresar un entero ingresar un float y viceversa.
- Tamaño invalido en una cadena de caracteres: en una cadena de caracteres ingresar un tamaño superior al que esta permitido.
- El uso de la Ñ: ya que c++ no permite usar esta letra.
- El uso de numeros negativos: cosas como precio o cantidad que sean negativas, quizá se permita su uso pero en ese caso el resultado no tendría ningun sentido.
- Si se ingresan strings con espacios de separación, ejemplo: Yael Charles, se recomienda usar _ o - por si es indispensable separar palabras.
