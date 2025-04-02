#include <stdio.h>
#include <string.h>
int main()
{
    int cantidad, opcion, status;
    float descuento;
    char id[5][10];
    char nombres[5][30];
    int stock[5];
    float precio[5];
    float total_ganancias = 0, venta = 0;
    int cont=0;
    int preciofinal;

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
            printf(Celeste"1. Registrar Producto"Reset);
            printf(Verde "                |\n" Reset);
            printf(Verde "\t| " Reset);
            printf(Celeste"2. Vender producto"Reset);
            printf(Verde "                   |\n" Reset);
            printf(Verde "\t| " Reset);
            printf(Celeste"3. Reabastecer producto"Reset);
            printf(Verde "              |\n" Reset);
            printf(Verde "\t| " Reset);
            printf(Celeste"4. Mostrar informacion del producto"Reset);
            printf(Verde "  |\n" Reset);
            printf(Verde "\t| " Reset);
            printf(Celeste"5. Mostrar total de ganancias"Reset);
            printf(Verde "        |\n" Reset);
            printf(Verde "\t| " Reset);
            printf(Celeste"6. Salir"Reset);
            printf(Verde "                             |\n" Reset);
            printf(Verde "\t|======================================|\n" Reset);
            printf(Celeste"\tSeleccione una opcion: "Reset);
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
        if (cont<5)
        {
            printf("\nIngrese el ID del producto %d: ",cont);
            scanf("%s", &id[cont]);
            printf("Ingrese el nombre del producto %d: ",cont);
            fflush(stdin);
            fgets(nombres[cont], 30, stdin);

            do
            {
                printf("Ingrese la cantidad inicial en stock %d: ",cont);
                status = scanf("%d", &stock[cont]);
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
                printf("Ingrese el precio unitario del producto %d: ",cont);
                status = scanf("%f", &precio[cont]);
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
            cont++;
        }
            break;
        case 2:
            if (stock <= 0)
            {
                printf(Rojo "El stock actual del producto es de 0 unidades, por favor reabastecer el producto.\n" Reset);
                break;
            }
            char naux[10];
            printf("Seleccione el producto que desea vender escribiendo el Id correspondiente\n");
            printf("ID\t\tNombre\t\tStock\t\tPrecio\n");
            for (int i = 0; i < 5; i++)
            {
                printf("%s\t\t%s\t\t%d\t\t%f\n",id[i],nombres[i],stock[i],precio[i]);
            }
            fflush(stdin);
            scanf("%s",&naux);
            do
            {
                for (int i = 0; i < 5; i++)
                {
                if (strcmp(id[i], naux) == 0)
                {
                    ("\nIngrese la cantidad a vender: ");
                status = scanf("%d", &cantidad);
                if (status == 0)
                {
                    printf(Rojo "Error ingrese un numero. " Reset);
                    while (getchar() != '\n');
                }
                else if (cantidad <= 0)
                {
                    printf(Rojo "La cantidad a vender debe ser mayor a 0. \n" Reset);
                }
                if (cantidad > stock[i])
                {
                    printf(Rojo "No existe la cantidad necesaria para esta venta. Vuelva a ingresar la cantidad. \n" Reset);
                    status=0;
                }
                }
                preciofinal=precio[i];
                }
            } while (cantidad < 1 || status == 0);
            
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
                venta = cantidad * preciofinal;
            }
            if (descuento >= 1)
            {
                venta = cantidad * preciofinal;
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
        char stck[10];
            printf("Seleccione el producto que desea agregar stock escribiendo el Id correspondiente\n");
            printf("ID\t\tNombre\t\tStock\t\tPrecio\n");
            for (int i = 0; i < 5; i++)
            {
                printf("%s\t\t%s\t\t%d\t\t%f\n",id[i],nombres[i],stock[i],precio[i]);
            }
            fflush(stdin);
            scanf("%s",&stck);
        
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
            printf(Celeste "\n\t----------------\n" Reset);
            printf("\tInformacion del producto:\n");
            printf("\tID: %d\n", id);
            printf("\tNombre: %s", nombres);
            printf("\tStock disponible: %d\n", stock);
            printf("\tPrecio unitario: $%.2f\n", precio);
            printf(Celeste "\t----------------\n" Reset);
            break;

        case 5:
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