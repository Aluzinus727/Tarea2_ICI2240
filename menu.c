#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "headers/menu.h"
#include "headers/funciones.h"
#include "headers/hashmap.h"


void initMenu() {
    HashMap* productos = createMap(100);
    HashMap* productosPorMarca = createMap(100);
    HashMap* productosPorTipo = createMap(100);

    HashMap* carritos = createMap(20);
    
    int choice;
    char buscar[128];

    while(choice != 0) {
        printf(" ---------------------------------------------------------------------- \n");
        printf("|                                                                      |\n");
        printf("|         MENU OPCIONES                                                |\n");
        printf("|                                                                      |\n");
        printf("|         1: Importar productos desde un archivo CSV                   |\n");
        printf("|         2: Exportar productos a un archivo CSV                       |\n");
        printf("|         3: Agregar un producto                                       |\n");
        printf("|         4: Buscar un producto por tipo                               |\n");
        printf("|         5: Buscar un producto por marca                              |\n");
        printf("|         6: Buscar un producto por nombre                             |\n");
        printf("|         7: Mostrar todos los productos                               |\n");
        printf("|         8: Agregar al carrito de compras                             |\n");
        printf("|         9: Concretar compra                                          |\n");
        printf("|         0: Salir                                                     |\n");
        printf("|                                                                      |\n");
        printf(" ----------------------------------------------------------------------\n");

        choice = getChoice();

        switch (choice) {
            case 1:
                importarProductos(productos, productosPorMarca, productosPorTipo, "Archivo_100productos.csv");
                break;
            case 2:
                break;
            case 3:
                anadirProducto(productos, productosPorMarca, productosPorTipo);
                break;
            case 4:
                printf("Ingrese el tipo de producto que desea buscar\n");
                fgets(buscar, sizeof(buscar), stdin);
                strtok(buscar, "\n");

                buscarPorCriterio(productosPorTipo, buscar);
                break;
            case 5:
                printf("Ingrese la marca que desea buscar\n");
                fgets(buscar, sizeof(buscar), stdin);
                strtok(buscar, "\n");

                buscarPorCriterio(productosPorMarca, buscar);
                break;
            case 6:
                printf("Ingrese el nombre del producto que desea buscar (REVISAR LA BUSQUEDA POR NOMBRE DE PRODUCTO)\n");
                fgets(buscar, sizeof(buscar), stdin);
                strtok(buscar, "\n");

                buscarPorCriterio(productos, buscar);
                break;
            case 7:
                printf("Mostrando todos los productos\n");
                mostrarProductos(productos);
                break;
            case 8:
                agregarAlCarritoUI(carritos, productos);
                break;
            case 9: 
                break;
        }
    };  
}

/*
    Función que solicita la opción al usuario. Se verifica que la opción ingresada sea un número y no un char o una cadena.
*/

int getChoice() {
    int validInput = 0;
    char inputChoice[3];

    while(validInput == 0) {
        scanf("%2s", inputChoice);
        fflush(stdin);
    
        if(isdigit(*inputChoice)){
            return atoi(inputChoice);
        } else {
            printf("La opcion que ingresaste no es valida.");
        }
    }
}

void agregarAlCarritoUI(HashMap* carritos, HashMap* productos) {
    char nombreCarrito[128];
    char nombre[128];
    char marca[128];
    char cantidadInput[10];
    int cantidad;

    printf("Ingrese el nombre del carrito\n");
    fgets(nombreCarrito, sizeof(nombreCarrito), stdin);
    strtok(nombreCarrito, "\n");

    printf("Ingrese el nombre del producto\n");
    fgets(nombre, sizeof(nombre), stdin);
    strtok(nombre, "\n");

    printf("Ingrese la marca del producto\n");
    fgets(marca, sizeof(marca), stdin);
    strtok(marca, "\n");

    printf("Ingrese cantidad de productos a anadir al carrito.\n");
    fgets(cantidadInput, sizeof(cantidadInput), stdin);
    strtok(cantidadInput, "\n");

    if (isdigit(*cantidadInput))
        cantidad = atoi(cantidadInput);

    agregarAlCarrito(carritos, productos, nombre, marca, cantidad, nombreCarrito);
}
