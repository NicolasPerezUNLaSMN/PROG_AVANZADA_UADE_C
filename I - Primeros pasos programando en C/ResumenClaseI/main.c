///VIDEO DE REFERENCIA: https://youtu.be/2ycjx-trVrs?si=oZtqIw9_cet9ZG8_
#include <stdio.h>    // Para printf, scanf, fgets
#include <stdlib.h>   // Para funciones generales como system(), malloc(), exit(), etc.
// NOTA: En algunos sistemas, fflush(stdin) no está definido. En Windows sí funciona.
#include <string.h> // Para funciones de cadenas de caracteres

int main(void) {
    ///Comentanrios en negrita, una linea
    //Comentarios claros, una linea
    /**Comentarios de más de una linea, negrita**/
    /*Comentarios de más de una linea, claros*/

    /// Declaración de variables (solo declaramos por ahora)
    int entero;
    float flotante;
    double doble;
    char caracter;
    char cadena[100];      // Espacio para una palabra o frase
    char frase[100];       // Para capturar texto con espacios

    /// Asignación de valores de forma estática
    entero = 10;
    flotante = 3.14f;
    doble = 2.71828;
    caracter = 'Z';
    //frase = "Nico Perez"; //No se puede asignar palabras o frases, solo se puede una letra

    /// Mostrar valores iniciales
    printf("Valores asignados manualmente:\n");
    printf("Entero: %d\n", entero);
    printf("Float: %.2f\n", flotante);
    printf("Double: %.5lf\n", doble);
    printf("Char: %c\n", caracter);

    /// Entrada por teclado
    printf("\nIngresá un entero: ");
    scanf("%d", &entero);

    printf("Ingresá un número flotante: ");
    scanf("%f", &flotante);

    printf("Ingresá un número double: ");
    scanf("%lf", &doble);

    // SCANF con %c puede fallar por el ENTER previo.
    // Solución: limpiar el buffer


    printf("Ingresá un caracter: ");
    fflush(stdin);  //  En Linux no está definido por el estándar, usar con cuidado.
    scanf("%c", &caracter);  // Captura un solo carácter (sin espacios)




    //  Captura de texto sin espacios
    printf("Ingresá una palabra (sin espacios): ");
    //  Limpieza de buffer antes de fgets (recomendado antes de scanf)
    fflush(stdin);  // Esto es crucial si usaste scanf antes y vas a usar fgets
    scanf("%s", cadena);  // Captura hasta el primer espacio

    //  Captura de texto con espacios
    printf("Ingresá una frase (puede tener espacios): ");
    fflush(stdin);  // Esto es crucial si usaste scanf antes y vas a usar fgets
    fgets(frase, sizeof(frase), stdin);  // Lee toda la línea (incluyendo espacios)
    // fgets deja el salto de línea '\n' al final, si querés quitarlo:
    //frase[strcspn(frase, "\n")] = '\0'; //Opcional para cosas muy puntuales

    // Mostrar todo lo ingresado
    printf("\a\n--- Resumen de lo que ingresaste ---\n");
    //\n salto de linea, dejar renglon ... \a pitido, \t tabulacion.
    printf("\tEntero: %d\n", entero);
    printf("\tFloat: %.2f\n", flotante);
    printf("\tDouble: %.5lf\n", doble);
    printf("\tChar: %c\n", caracter);
    printf("\tCadena (sin espacios): %s\n", cadena);
    printf("\tFrase (con espacios): %s\n", frase);

    printf("\nPresioná ENTER para finalizar...");
    getchar(); // Captura el ENTER pendiente de fgets o scanf

    return 0;
}
