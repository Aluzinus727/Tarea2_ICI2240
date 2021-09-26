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
    Funciones para buscar
*/

void buscarPorCriterio(HashMap* criterio, char* key);

void anadirProducto(HashMap* productos, HashMap* productosPorMarca, HashMap* productosPorTipo);

void mostrarProductos(HashMap* productos);