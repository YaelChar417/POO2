# Proyecto: Gestión de Restaurante.
Un restaurante familiar de nombre Charl´s quiere un programa que les permita tener más control con sus clientes y pedidos, este restaurante cuenta con un menú ya establecido de comida italiana y unas bebidas fuera de este mundo así como con una capacidad máxima para 50 clientes. En este proyecto recrearemos usando el lenguaje de c++ esta simulación.

## Correcciones realizadas
- Se le puso el mismo nombre a los metodos **calcula_costo** y **muestra_datos** para que de esta forma cumpla como sobreescritura correctamente.
- Se modificó el UML para mostrar el polimorfismo correctamente y con los atributos adecuados en la clase Restaurante.

## Funcionamiento actual
El programa sigue los siguientes pasos:

1.- El programa pide que ingreses cuantos clientes van a llegar, como sugerencia no ingresar numeros muy altos en primera para no estar ingresando muchas entradas y en segunda porque el limite de clientes a la vez es 50.

2.- Llenar los datos de los n clientes que decida el usuario, estos son: Nombre de tipo string, Edad de tipo int, Dinero de tipo float.

3.- El programa pregunta si el cliente n desea pedir una comida.

  - 3.1.- En caso de decir que si (1) el programa pregunta por el numero de comida que te gustaria ordenar del menu, **van del 1 al 3** y muestra sus datos de la comida así como su subtotal.

  - 3.2.- En caso de decir que no (0) el programa continua.

4.- El programa pregunta si el n cliente desea pedir una bebida.

  - 4.1.- En caso de decir que si (1) el programa pregunta por el numero de bebida que te gustaría ordenar del menu, **van del 4 al 6** y muestra sus datos de la bebida así como el total de la compra y llama la funcion de pagar que calcula el cambio que se le regresa al cliente.

  - 4.2.- En caso de decir que no (0) el programa finalizará, no sin antes darle su cambio al cliente.

5.- El programa sigue repitiendo los pasos del 3 al 4 si **n > 1.**

6.- Fin del programa

## Funcionamiento esperado en avances futuros:
Lo que espero realizar en avances futuros es mejorar el main para que sea más ordenado y cuente con una mejor estructura la cual me permita usar las siguientes funciones sin que sea un desorden:
- **Clase Restaurante:** float calcula_costo(Comida comida, Bebida bebida);
- **Clase Bebida:** void agregar_hielo(bool hie), float calcula_total(float onz, float c, int ca);
- **Clase Comida:** void cambiar_vegano(bool v), float calcula_total(string t, float c, int ca);
Como menciono las razones por las cuales estas funciones no estan implementadas es para que el main se mantenga simple y sin tantos bucles que ayuden a mantener un orden en mi codigo.

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

## Descripcion de las clases:
- **Restaurante:** La clase Restaurante se compone de la clase Persona y se agregan objetos de Pedido los cuales al implementar el polimorfismo pueden ser objetos de Comida o Bebida, es por esto que en sus atributos además del nombre del restaurante, cuenta con un arreglo para los clientes y otro para los diferentes pedidos. En cuanto a sus metodos están sus:
  - **constructores**
  - **destructor**
  - **vector<Persona> recibe_cliente(int num)** que retorna un arreglo de clientes y recibe un numero que representa la cantidad de clientes que se quiere ingresar
  - **void mostrar_cliente(int num)** que muestra los datos de los clientes y que igual recibe un numero para saber hasta que cliente mostrar.
  - void agrega_pedidos(Pedido *pedido) que recibe un puntero de pedidos para respetar el polimorfismo y estos los agrega en una lista de pedidos.
  - **void muestra_menu(int n)** que muestra los datos de los pedidos que son registrados.
  - **float calcula_costo(Comida comida, Bebida bebida)** la cual recibe objetos de Comida y Bebida para calcular el costo total de estos dos.

- **Persona:** La clase Persona es una clase que compone a la clase Restaurante, esta cuenta con los atributos de nombre, edad y dinero, sus metodos son:
  - **constructores**
  - **destructor**
  - **getters**
  - **setters**
  - **void mostrar_datos()** que imprime los atributos de la persona/cliente.
  - **float pagar(float t);** que usa el dinero del cliente y le resta el total de su compra para así devolverle el cambio.

- **Pedido:** La clase Pedido es abstracta por el motivo de que emplea polimorfismo, entonces para evitar que se genere un objeto como tal de pedido, mejor hacerla de esta forma para evitar problemas. A su vez es padre de Comida y Bebida, sus atributos son orden, cantidad y costo, sus metodos son:
  - **constructores**
  - **destructor virtual**
  - **getters**
  -  **Setters**
  -   **virtual float calcula_total(float c, int ca) = 0;** metodo con polimorfismo y que hace la clase abstracta que calcula el total del precio de la comida o bebida con pequeños aumentos en base a si es vegano o si tiene hielo, respectivamente.
  - **virtual void mostrar_datos() = 0;** metodo con polimorfismo y que hace la clase abstracta la cual imprime los datos de la comida o bebida, según sea el caso.

- **Comida:** La clase Comida es hija de la clase Pedido, sus atributos son además de los heredados por la clase Pedido tiene un tamaño y vegano que representa si la comida es vegana o no, sus metodos son:
  - **constructores**
  -  **Destructor**
  -   **getters**
  -    **setters**
  - **void mostrar_datos()** el cual tiene sobreescritura por lo tanto tambien imprime sus datos pero con sus nuevos atributos.
  - **void cambiar_vegano(bool v)** que verifica que el pedido no sea vegano y lo cambia a este.
  - **float calcula_total(float c, int ca)** que tiene sobreescritura y calcula el precio de la comida y la aumenta si es vegana.
  - **float calcula_total(string t, float c, int ca)** metodo con sobrecarga que calcula el total en base al tamaño de la orden.

- **Bebida:** La clase Bebida es hija de la clase Pedido, sus atributos son además de los heredados por la clase Pedido tiene onzas y hielo que representa si la bebida tiene hielo o no, sus metodos son:
  - **constructores**
  -  **Destructor**
  -   **getters**
  -    **setters**
  - **void mostrar_datos()** el cual tiene sobreescritura por lo tanto tambien imprime sus datos pero con sus nuevos atributos.
  - **void agregar_hielo(bool hie)** que verifica que el pedido no sea vegano y lo cambia a este.
  - **float calcula_total(float c, int ca)** que tiene sobreescritura y calcula el precio de la comida y la aumenta si es vegana.
  - **float calcula_total(float onz, float c, int ca)** metodo con sobrecarga que calcula el total en base las onzas de la bebida.

 ## Casos que harían que dejara de funcionar:
- Al momento de pedir cuantos clientes son los que ingresan al restaurante: Ingresar un numero negativo, string o caracter.
- Cuando se pide el nombre del cliente: Escribir un string con espacios, ejemplo: Yael Charles, como sugerencia optar por: Yael_Charles.
- Cuando se pide la edad del cliente: Ingresar un numero que sea float (que tenga decimales).
- Al momento de preguntar si desea ordenar comida o bebida: Ingresar un string o caracter.
- Al momento de preguntar que numero de comida o bebida desea ordenar: Ingresar un caracter o string.
