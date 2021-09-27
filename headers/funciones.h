#include "hashmap.h"

typedef struct Producto Producto;

typedef struct Carrito Carrito;

/*
    Funciones para importación desde CSV
*/

char* get_csv_field (char * tmp, int k);

void importarProductos(HashMap* productos, HashMap* productosPorMarca, HashMap* productosPorTipo, char* nombreArchivo);

/*
    Funciones para crear y agregar los productos
 */

void agregarProducto(HashMap* productos, HashMap* productosPorMarca, HashMap* productosPorTipo, char* nombre, char* marca, char* tipo, char* cantidad, char* precio);

void* crearProducto(char* nombre, char* marca, char* tipo, char* cantidad, char* precio);

/*
    Funcion para buscar
*/

void buscarPorCriterio(HashMap* criterio, char* key);

void anadirProducto(HashMap* productos, HashMap* productosPorMarca, HashMap* productosPorTipo);

void mostrarProductos(HashMap* productos);

/*  
    Funciones del carrito de compra
*/

void* crearCarrito(char* nombreCarrito);

void agregarAlCarrito(HashMap* carritos, HashMap* productos, char* nombre, char* marca, int cantidad, char* nombreCarrito);

void exportarProductos(HashMap* productos, char* archivo);

void mostrarNombresCarritos(HashMap* carritos);

void mostrarInfoCarrito(char* nombreCarrito, HashMap* carritos);

void aMinuscula(char *cadena);