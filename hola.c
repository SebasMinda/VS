#include <stdio.h>

int main()
{
    int id, stock = 0, cantidad, opcion, productoregistrado = 0, status;
    float precio, total_ganancias = 0, venta, descuento;
    char nombre[30];

#define Rojo "\x1B[31m"
#define Verde "\x1B[32m"
#define Celeste "\x1B[36m"
#define Reset "\x1B[0m"

    do
    {
        do
        {
            printf(Verde "\n\t|================ Menu ================|\n" Reset);
            printf(Verde "\t| " Reset);
            printf("1. Registrar Producto");
            printf(Verde "                |\n" Reset);
            printf(Verde "\t| " Reset);
            printf("2. Vender producto");
            printf(Verde "                   |\n" Reset);
            printf(Verde "\t| " Reset);
            printf("3. Reabastecer producto");
            printf(Verde "              |\n" Reset);
            printf(Verde "\t| " Reset);
            printf("4. Mostrar informacion del producto");
            printf(Verde "  |\n" Reset);
            printf(Verde "\t| " Reset);
            printf("5. Mostrar total de ganancias");
            printf(Verde "        |\n" Reset);
            printf(Verde "\t| " Reset);
            printf("6. Salir");
            printf(Verde "                             |\n" Reset);
            printf(Verde "\t|======================================|\n" Reset);
            printf("\tSeleccione una opcion: ");
            fflush(stdin);
            status = scanf("%d", &opcion);
            if (status == 0)
            {
                printf(Rojo "Error ingrese un numero del 1 al 6. " Reset);
                while (getchar() != '\n')
                    ;
            }
            else if (opcion < 1 || opcion > 6)
            {
                printf(Rojo "Error ingrese un numero del 1 al 6. " Reset);
            }
        } while (opcion < 1 || opcion > 6 || status == 0);

        switch (opcion)
        {
        case 1:
            do
            {
                printf("\nIngrese el ID del producto: ");
                status = scanf("%d", &id);
                if (id <= 0 || status == 0)
                {
                    printf(Rojo "Id de producto no valido. Solo escriba numeros del 1 en adelante. \n" Reset);
                    while (getchar() != '\n')
                        ;
                }
            } while (id <= 0 || status == 0);
            printf("Ingrese el nombre del producto: ");
            fflush(stdin);
            fgets(nombre, 30, stdin);

            do
            {
                printf("Ingrese la cantidad inicial en stock: ");
                status = scanf("%d", &stock);
                if (status == 0)
                {
                    printf(Rojo "Error ingrese un numero. \n" Reset);
                    while (getchar() != '\n')
                        ;
                }
                else if (stock <= 0)
                {
                    printf(Rojo "Stock Invalido.\n" Reset);
                }
            } while (stock <= 0 || status == 0);

            do
            {
                printf("Ingrese el precio unitario del producto: ");
                status = scanf("%f", &precio);
                if (status == 0)
                {
                    printf(Rojo "Error ingrese un numero. \n" Reset);
                    while (getchar() != '\n')
                        ;
                }
                else if (precio <= 0)
                {
                    printf(Rojo "Precio Invalido.\n" Reset);
                }
            } while (precio <= 0 || status == 0);
            productoregistrado = 1;
            break;
        case 2:
            if (productoregistrado != 1)
            {
                printf(Rojo "\nPor favor primero registrar el producto.\n" Reset);
                break;
            }
            if (stock <= 0)
            {
                printf(Rojo "El stock actual del producto es de 0 unidades, por favor reabastecer el producto.\n" Reset);
                break;
            }
            do
            {
                printf("\nIngrese la cantidad a vender: ");
                status = scanf("%d", &cantidad);
                if (status == 0)
                {
                    printf(Rojo "Error ingrese un numero. " Reset);
                    while (getchar() != '\n')
                        ;
                }
                else if (cantidad <= 0)
                {
                    printf(Rojo "La cantidad a vender debe ser mayor a 0. \n" Reset);
                }
                if (cantidad > stock)
                {
                    printf(Rojo "No existe la cantidad necesaria para esta venta. Vuelva a ingresar la cantidad. \n" Reset);
                }

            } while (cantidad < 1 || cantidad > stock || status == 0);
            do
            {
                printf("Ingrese la cantidad de descuento que desea: ");
                status = scanf("%f", &descuento);
                if (status == 0)
                {
                    printf(Rojo "Error ingrese un numero. \n" Reset);
                    while (getchar() != '\n')
                        ;
                }
                if (descuento < 0 || descuento > 100)
                {
                    printf(Rojo "Cantidad de descuento no valida.\n" Reset);
                }
            } while (descuento < 0 || descuento > 100 || status == 0);
            if (descuento == 0)
            {
                venta = cantidad * precio;
            }
            if (descuento >= 1)
            {
                venta = cantidad * precio;
                descuento = venta * (descuento / 100);
                venta = venta - descuento;
            }
            if (cantidad == 1)
            {
                printf(Verde "La cantidad vendida fue de %d unidad\n", cantidad, Reset);
            }
            else
            {
                printf(Verde "La cantidad vendida fue de %d unidades\n", cantidad, Reset);
            }
            printf(Verde "El total de la venta es de $%.2f\n", venta, Reset);
            total_ganancias += venta;
            stock -= cantidad;
            if (stock == 1)
            {
                printf(Verde "El total stock actual es de %d unidad\n", stock, Reset);
            }
            else
            {
                printf(Verde "El total stock actual es de %d unidades\n", stock, Reset);
            }
            break;

        case 3:
            if (productoregistrado != 1)
            {
                printf(Rojo "\nPor favor primero registrar el producto.\n" Reset);
                break;
            }
            do
            {
                printf("\nIngrese la cantidad a agregar al stock: ");
                status = scanf("%d", &cantidad);
                if (status == 0)
                {
                    printf(Rojo "Error ingrese un numero. " Reset);
                    while (getchar() != '\n')
                        ;
                }
                else if (cantidad <= 0)
                {
                    printf(Rojo "La cantidad debe ser mayor a 0. Vuelva a ingresar la cantidad. \n" Reset);
                }

            } while (cantidad <= 0 || status == 0);

            stock += cantidad;
            printf(Verde "El stock actual ahora es de %d.\n", stock, Reset);
            break;

        case 4:
            if (productoregistrado != 1)
            {
                printf(Rojo "\nPor favor primero registrar el producto.\n" Reset);
                break;
            }
            printf(Celeste "\n\t----------------\n" Reset);
            printf("\tInformacion del producto:\n");
            printf("\tID: %d\n", id);
            printf("\tNombre: %s", nombre);
            printf("\tStock disponible: %d\n", stock);
            printf("\tPrecio unitario: $%.2f\n", precio);
            printf(Celeste "\t----------------\n" Reset);
            break;

        case 5:
            if (productoregistrado != 1)
            {
                printf(Rojo "\nPor favor primero registrar el producto.\n" Reset);
                break;
            }
            printf(Verde "\nTotal de ganancias: $%.2f\n", total_ganancias, Reset);
            break;

        case 6:
            printf(Rojo "Saliendo del programa...\n" Reset);
            break;

        default:
            printf(Rojo "\nOpción inválida. Intente nuevamente.\n" Reset);
        }
    } while (opcion != 6);

    return 0;
}