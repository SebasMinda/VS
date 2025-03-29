#include <stdio.h>

int main()
{
    int id, stock = 0, cantidad, opcion, productoregistrado = 0,status;
    float precio, total_ganancias = 0, venta, descuento;
    char nombre[30];
    do
    {
        printf("\n\t1. Registrar Producto\n");
        printf("\t2. Vender producto\n");
        printf("\t3. Reabastecer producto\n");
        printf("\t4. Mostrar informacion del producto\n");
        printf("\t5. Mostrar total de ganancias\n");
        printf("\t6. Salir\n\n");
        printf("\tSeleccione una opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            do
            {
                printf("Ingrese el ID del producto: ");
                scanf("%d", &id);
                if (id <= 0)
                {
                    printf("Id de producto no valido.\n");
                }
            } while (id <= 0);
            printf("Ingrese el nombre del producto: ");
            fflush(stdin);
            fgets(nombre, 30, stdin);

            do
            {
                printf("Ingrese la cantidad inicial en stock: ");
                status=scanf("%d", &stock);
                if (status==0)
                {
                    printf("Ingrese un numero");
                    while (getchar() != '\n');
                }
                if (stock <= 0)
                {
                    printf("Stock Invalido.\n");
                }
            } while (stock <= 0||status==0);

            do
            {
                printf("Ingrese el precio unitario del producto: ");
                status=scanf("%f", &precio);
                if (status==0)
                {
                    printf("Ingrese un numero");
                    while (getchar() != '\n');
                }
                if (precio <= 0)
                {
                    printf("Precio Invalido.\n");
                }
            } while (precio <= 0||status==0);
            productoregistrado = 1;
            break;
        case 2:
            if (productoregistrado != 1)
            {
                printf("\nPor favor primero registrar el producto.\n");
                break;
            }
            if (stock <= 0)
            {
                printf("El stock actual del producto es de 0 unidades, por favor reabastecer el producto\n");
                break;
            }
            do
            {
                printf("Ingrese la cantidad a vender: ");
                status=scanf("%d", &cantidad);
                if (status==0)
                {
                    printf("Ingrese un numero");
                    while (getchar() != '\n');
                }
                if (cantidad < 1)
                {
                    printf("La cantidad debe ser mayor a 0. Vuelva a ingresar la cantidad. \n");
                }
                if (cantidad > stock)
                {
                    printf("No existe la cantidad necesaria para esta venta. Vuelva a ingresar la cantidad. \n");
                }

            } while (cantidad < 1 || cantidad > stock||status==0);
            do
            {
                printf("Ingrese la cantidad de descuento que desea: ");
                status=scanf("%f", &descuento);
                if (status==0)
                {
                    printf("Ingrese un numero");
                    while (getchar() != '\n');
                }
                if (descuento < 0 || descuento > 100)
                {
                    printf("Cantidad de descuento no valida.\n");
                }
            } while (descuento < 0 || descuento > 100||status==0);
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
            printf("El total de la venta es %.2f\n", venta);
            total_ganancias += venta;
            stock -= cantidad;
            break;

        case 3:
            if (productoregistrado != 1)
            {
                printf("\nPor favor primero registrar el producto.\n");
                break;
            }
            do
            {
                printf("Ingrese la cantidad a agregar al stock: ");
                status=scanf("%d", &cantidad);
                if (status==0)
                {
                    printf("Ingrese un numero");
                    while (getchar() != '\n');
                }
                if (cantidad <= 0)
                {
                    printf("La cantidad debe ser mayor a 0. Vuelva a ingresar la cantidad. \n");
                }

            } while (cantidad <= 0||status==0);

            stock += cantidad;
            printf("el stock actual ahora es de %d\n", stock);
            break;

        case 4:
            if (productoregistrado != 1)
            {
                printf("\nPor favor primero registrar el producto.\n");
                break;
            }
            printf("\nInformación del producto:\n");
            printf("ID: %d\n", id);
            printf("Nombre: %s", nombre);
            printf("Stock disponible: %d\n", stock);
            printf("Precio unitario: %.2f\n", precio);
            break;

        case 5:
            if (productoregistrado != 1)
            {
                printf("\nPor favor primero registrar el producto.\n");
                break;
            }
            printf("Total de ganancias: $%.2f\n", total_ganancias);
            break;

        case 6:
            printf("Saliendo del programa...\n");
            break;

        default:
            printf("\nOpción inválida. Intente nuevamente.\n");
        }
    } while (opcion != 6);

    return 0;
}