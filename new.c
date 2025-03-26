// Tarea Menú Interactivo - Sebastián Yaguana
#include <stdio.h>
#include <string.h>
#include "funciones.h"

// Función que despliega las opciones disponibles para el usuario
void mostrarMenu() {
    printf("\n=== Menú Principal ===\n");
    printf("1. Invertir una cadena\n");
    printf("2. Calcular el factorial de un número\n");
    printf("3. Generar la sucesión de Fibonacci\n");
    printf("4. Salir\n");
    printf("Ingrese su opción: ");
}

int main() {
    int seleccion; // Variable para almacenar la opción elegida por el usuario
    char buffer[100]; // Buffer para manejar entradas del usuario

    do {
        mostrarMenu(); // Llama a la función que muestra las opciones
        fgets(buffer, sizeof(buffer), stdin); // Captura la entrada del usuario como texto
        seleccion = atoi(buffer); // Convierte la entrada textual a un número entero

        switch (seleccion) {
            case 1: { // Caso para invertir una cadena
                char texto[100]; // Espacio para almacenar la cadena del usuario
                printf("Escriba una cadena: ");
                fflush(stdin); // Limpia el buffer de entrada
                fgets(texto, sizeof(texto), stdin); // Lee la cadena del usuario
                texto[strcspn(texto, "\n")] = 0; // Quita el salto de línea final
                printf("Cadena invertida: ");
                invertirCadena(texto, 0, strlen(texto) - 1); // Invierte la cadena usando la función
                printf("%s\n", texto);
                break;
            }
            case 2: { // Caso para calcular el factorial
                int numero; // Número proporcionado por el usuario
                printf("Ingrese un número entero positivo: ");
                fgets(buffer, sizeof(buffer), stdin); // Lee el número como texto
                numero = atoi(buffer); // Convierte el texto a entero
                if (numero < 0) {
                    printf("El número debe ser positivo.\n");
                } else {
                    printf("El factorial de %d es: %llu\n", numero, factorial(numero));
                }
                break;
            }
            case 3: { // Caso para generar la sucesión de Fibonacci
                int cantidad; // Número de términos que desea generar el usuario
                printf("Indique cuántos términos de Fibonacci desea: ");
                fgets(buffer, sizeof(buffer), stdin); // Captura la entrada como texto
                cantidad = atoi(buffer); // Convierte el texto a entero
                if (cantidad <= 0) {
                    printf("El número debe ser mayor que 0.\n");
                } else {
                    printf("Sucesión de Fibonacci: ");
                    generarFibonacci(cantidad, 0, 1); // Genera la secuencia con la función recursiva
                    printf("\n");
                }
                break;
            }
            case 4:
                printf("Finalizando el programa. ¡Hasta luego!\n");
                break;
            default:
                printf("Opción no válida. Por favor intente de nuevo.\n");
                break;
        }
    } while (seleccion != 4); // Repite el menú mientras el usuario no elija salir

    return 0;
}
