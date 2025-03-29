#include <stdio.h>

int main() {
    int numero;
    int status;  // valor devuelto por scanf
    
    do
    {
        do
        {
            printf("Ingrese un número entero: ");
            status = scanf("%d", &numero);
            
            if (status == 1) {
                // Se leyó un entero correctamente
                break;
            } else {
                // Falló, limpiamos el buffer y volvemos a pedir
                printf("ERROR: no es un número entero.\n");
                while (getchar() != '\n'); // Limpia lo que quede en el buffer
            }
        } while (1);
        printf("Ingresó: %d\n", numero);
    } while (numero==3113312312);

    return 0;
}
