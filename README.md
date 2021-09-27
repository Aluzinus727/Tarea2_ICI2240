(1) cómo compilar y ejecutar la tarea:

    Para compilar y ejecutar el programa, en caso de que se use VSCode, debe descargar el ZIP desde el repositorio, luego ir a
    Visual Studio Code y en la opción Open Folder... abrir la carpeta "Tarea2_ICI2240" y luego en el terminal escribir:
    gcc -g main.c menu.c list.c hashmap.c funciones.c -o "Ejecutable" (la parte escrita entre comillas puede ser
    modificada con el nombre que usted desee para el archivo .exe). El ejecutable se va a crear en la carpeta "Tarea2_ICI2240"
    o bien puede utilizar el comando ./Ejecutable en la consola de VSCode para ejecutarlo.

    Para compilar y ejecutar con CodeBlocks, descomprime el archivo y en CodeBlocks crea una aplicacion de consola nueva.
    Una vez creada, va a la sección Add Files y agrega todos los archivos contenidos en la carpeta "Tarea2_ICI2240", menos
    los asociados a vscode, .exe o bin. Terminada la incorporación de los archivos, utilice los botones de compilar y ejecutar
    incluidos en CodeBlocks y el programa funcionará correctamente.

(2) las opciones que funcionan correctamente y las que no lo hacen indicando posibles causas:

    Todas las funciones operan correctamente, excepto por:

    a. Las opciones de "Buscar un producto por..." usando productos agregados manualmente mediante la función "3. Agregar un producto" no funcionan como se espera, sin embargo, funcionan correctamente con los productos importados desde el archivo CSV. Desconocemos la causa de por qué no funciona, ya que los productos agregados mediante la función "3. Agregar un producto" sí se exportan correctamente con la función "2. Exportar productos a un archivo CSV". 

    b. La opción "8. Agregar al carrito de compras" agrega algunos productos al carrito y otros no, aparece un mensaje de que el producto no existe cuando sí existe, y algunas veces se "crashea" el output del programa, ocurre de manera aleatoria. Desconocemos la causa.

    c. La opción "9. Concretar compra" al revisar con prints nos dimos cuenta que la key se cambiaba dentro de la función por una no relacionada con la key del carro guardado. No sabemos por qué sucede esto si el nombre del carro y la key ingresada son iguales a nivel char.

    Observación general: Se debe tener cuidado con los espacios al momento de agregar al carro o buscar un producto, ya que en las comparaciones se considera si hay un espacio extra o no.

(3) aspectos positivos y a mejorar por cada uno de los integrantes (coevaluación):
     
    ANGELO: 
    Positivo: 
    - Buen reconocimiento de las causas de los errores.
    - Responsable.
    - Buen iniciador.
    A mejorar: 
    - El trabajo en equipo.

    JAVIER:
    Positivo:
    - Responsable.
    - Buena disposición.
    - Buen diálogo.
    A mejorar:
    - Manejo del tiempo.

    CAMILA:
    Positivo:
    - Orden y estética.
    - Responsable.
    - Iniciativa a nuevas ideas/cambios.
    A mejorar: 
    - Manejo del tiempo y de la motivación.

(4) puntos de premio/castigo a cada integrante dependiendo del trabajo realizado:

JAVIER: 0
CAMILA: 0
ANGELO: 0 


