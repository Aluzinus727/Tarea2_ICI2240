#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "headers/funciones.h"
#include "headers/list.h"


struct Producto {
    char* nombre;
    char* marca;
    char* tipo;
    int stock;
    int precio;
};

struct Carrito {
    char* nombre;
    void* productos;
};

void importarProductos(HashMap* productos, HashMap* productosPorMarca, HashMap* productosPorTipo, char* nombreArchivo) {
    FILE *fp = fopen (nombreArchivo, "r");
    
    if (nombreArchivo) {
        char linea[1024];
        char* nombre;
        char* marca;
        char* tipo;
        char* cantidad;
        char* precio;

        while (fgets (linea, 1023, fp) != NULL) { 
            nombre = get_csv_field(linea, 0); 
            marca = get_csv_field(linea, 1);
            tipo = get_csv_field(linea, 2);
            cantidad = get_csv_field(linea, 3);
            precio = get_csv_field(linea, 4);

            printf("%s %s %s %s %s\n", nombre, marca, tipo, cantidad, precio);

            agregarProducto(productos, productosPorMarca, productosPorTipo, nombre, marca, tipo, cantidad, precio);
        }

    } else 
        printf("No se pudo encontrar ningun archico con ese nombre");
}


//Funcion para leer el k-esimo elemento de un string (separado por comas)
char *get_csv_field (char * tmp, int k) {
    int open_mark = 0;
    char* ret=(char*) malloc (100*sizeof(char));
    int ini_i=0, i=0;
    int j=0;
    while(tmp[i+1]!='\0'){

        if(tmp[i]== '\"'){
            open_mark = 1-open_mark;
            if(open_mark) ini_i = i+1;
            i++;
            continue;
        }

        if(open_mark || tmp[i]!= ','){
            if(k==j) ret[i-ini_i] = tmp[i];
            i++;
            continue;
        }

        if(tmp[i]== ','){
            if(k==j) {
               ret[i-ini_i] = 0;
               return ret;
            }
            j++; ini_i = i+1;
        }

        i++;
    }

    if(k==j) {
       ret[i-ini_i] = 0;
       return ret;
    }


    return NULL;
}

void agregarProducto(HashMap* productos, HashMap* productosPorMarca, HashMap* productosPorTipo, char* nombre, char* marca, char* tipo, char* cantidad, char* precio) {
    Pair* productosPair = searchMap(productos, nombre);
    List* productosList;
    Producto* auxProducto;
    int encontrado = 0;

    if (productosPair == NULL) {
        productosList = create_list();
        insertMap(productos, nombre, productosList);
    }
    else {
        auxProducto = first(productosPair->value);

        while (auxProducto != NULL) {
            if (strcmp(auxProducto->marca, marca) == 0) {
                if (isdigit(*cantidad)) 
                    auxProducto->stock = auxProducto->stock + atoi(cantidad);

                encontrado = 1;
                break;
            }

            auxProducto = next(productosPair->value);
        };
    }

    if (!encontrado) {
        auxProducto = crearProducto(nombre, marca, tipo, cantidad, precio);
        Pair* marcasPair = searchMap(productosPorMarca, marca);
        
        List* marcasList;
        List* tiposList;


        if (marcasPair == NULL) {
            marcasList = create_list();
            push_back(marcasList, auxProducto);
            insertMap(productosPorMarca, marca, marcasList);
        } else 
            push_back(marcasPair->value, auxProducto);

        Pair* tiposPair = searchMap(productosPorTipo, tipo);

        if (tiposPair == NULL) {
            tiposList = create_list();
            insertMap(productosPorTipo, tipo, tiposList);
            push_back(tiposList, auxProducto);
        } else
            push_back(tiposPair->value, auxProducto);

        push_back(productosList, auxProducto);
    }
}

void* crearProducto(char* nombre, char* marca, char* tipo, char* stock, char* precio) {
    Producto* producto = malloc(sizeof(Producto));

    producto->nombre = malloc(sizeof(char) * strlen(nombre) + 1);
    producto->marca = malloc(sizeof(char) * strlen(marca) + 1);
    producto->tipo = malloc(sizeof(char) * strlen(tipo) + 1);

    strcpy(producto->nombre, nombre);
    strcpy(producto->marca, marca);
    strcpy(producto->tipo, tipo);

    producto->stock = atoi(stock);
    producto->precio = atoi(precio);

    return producto;    
}

void buscarPorCriterio(HashMap* criterio, char* key) {
    Pair* criterioPair = searchMap(criterio, key);

    if (criterioPair == NULL) {
        printf("No se pudo encontrar ningun producto con el filtro especificado.\n");
        return;
    }
    
    printf("%d\n", size(criterioPair->value));
    Producto* auxProducto = first(criterioPair->value);
    int cont = 1;

    while (auxProducto != NULL) {
        printf("%d. %s, %s, %s, %d, %d\n", cont, auxProducto->nombre, auxProducto->marca, auxProducto->tipo, auxProducto->stock, auxProducto->precio);

        cont++;
        auxProducto = next(criterioPair->value);
    }
}

void anadirProducto(HashMap* productos, HashMap* productosPorMarca, HashMap* productosPorTipo)
{
    char nombre[256];
    char marca[256];
    char tipo[256];
    char cantidad[10];
    char precio[10];

    printf("Ingrese el nombre del producto: \n");
    fgets(nombre, sizeof(nombre), stdin);
    strtok(nombre, "\n");

    printf("Ingrese la marca del producto: \n");
    fgets(marca, sizeof(marca), stdin);
    strtok(marca, "\n");

    printf("Ingrese el tipo del producto: \n");
    fgets(tipo, sizeof(tipo), stdin);
    strtok(tipo, "\n");

    printf("Ingrese el stock del producto: \n");
    fgets(cantidad, sizeof(cantidad), stdin);
    strtok(cantidad, "\n");

    printf("Ingrese el precio del producto: \n");
    fgets(precio, sizeof(precio), stdin);
    strtok(precio, "\n");

    agregarProducto(productos, productosPorMarca, productosPorTipo, nombre, marca, tipo, cantidad, precio);
}

void mostrarProductos(HashMap* productos)
{
    Pair* productoPair = firstMap(productos);
    int cont = 1;

    while (productoPair != NULL) {
        List* productosList = productoPair->value;
        Producto* auxProducto = first(productosList);

        while (auxProducto != NULL) {
            printf("%d. %s, %s, %s, %d, %d\n", cont, auxProducto->nombre, auxProducto->marca, auxProducto->tipo, auxProducto->stock, auxProducto->precio);

            cont++;
            auxProducto = next(productosList);
        }

        productoPair = nextMap(productos);
    }
}

void* crearCarrito(char* nombreCarrito) {
    Carrito* carrito = malloc(sizeof(Carrito));

    carrito->nombre = malloc(strlen(nombreCarrito));
    carrito->productos = create_list();

    return carrito;
}

void agregarAlCarrito(HashMap* carritos, HashMap* productos, char* nombre, char* marca, int cantidad, char* nombreCarrito) {
    Pair* carritoPair = searchMap(carritos, nombreCarrito);
    int encontrado = 0;

    if (carritoPair == NULL) {
        Carrito* carrito = crearCarrito(nombreCarrito);
        insertMap(carritos, nombreCarrito, carrito);
        carritoPair = searchMap(carritos, nombreCarrito);
    }

    Pair* productoPair = searchMap(productos, nombre);

    if (productoPair != NULL) {
        Producto* productoAux = first(productoPair->value);

        while(productoAux != NULL) {
            if (strcmp(productoAux->marca, marca) == 0) {
                Carrito* carritoAux = carritoPair->value; 
                encontrado = 1;

                for (int i = 0; i < cantidad; i++)
                    push_back(carritoAux->productos, productoAux);
                    
                break;
            }
        }
    }

    if (encontrado == 0) 
        printf("No existe ningun producto con el nombre especificado");
}