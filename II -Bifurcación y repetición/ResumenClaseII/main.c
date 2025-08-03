#include <stdio.h>

#include <windows.h>


int main() {

    SetConsoleOutputCP(CP_UTF8);  // Configura salida en UTF-8
    int numero;

    // ===== IF simple =====
    printf("Ingresá un número: ");
    scanf("%d", &numero);

    if (numero > 0) {
        printf("Es un número positivo.\n");
    }

    // ===== IF - ELSE =====
    if (numero % 2 == 0) {
        printf("Es par.\n");
    } else {
        printf("Es impar.\n");
    }

    // ===== IF anidados =====
    if (numero >= 0) {
        if (numero < 10) {
            printf("Es un número de un solo dígito.\n");
        } else {
            printf("Es un número de dos o más dígitos.\n");
        }
    } else {
        printf("Es un número negativo.\n");
    }

    // ===== SWITCH CASE =====
    // Vamos a clasificar el número según su valor exacto
    switch (numero) {
        case 0:
            printf("Ingresaste un cero.\n");
            break;
        case 1:
            printf("Ingresaste un uno.\n");
            break;
        case 2:
            printf("Ingresaste un dos.\n");
            break;
        default:
            printf("Ingresaste un número distinto de 0, 1 o 2.\n");
    }

    // ===== FOR =====
    printf("\nContando del 1 al 5 con for:\n");
    for (int i = 1; i <= 5; i++) {
        printf("i vale %d\n", i);
    }

    // ===== WHILE =====
    printf("\nContando del 1 al 5 con while:\n");
    int j = 1;
    while (j <= 5) {
        printf("j vale %d\n", j);
        j++;
    }

    // ===== DO WHILE =====
    printf("\nContando del 1 al 5 con do-while:\n");
    int k = 1;
    do {
        printf("k vale %d\n", k);
        k++;
    } while (k <= 5);

    // ===== INTEGRADOR =====
    // Queremos mostrar si los números del 1 al 10 son pares, impares o múltiplos de 3
    printf("\nResumen integrador del 1 al 10:\n");
    for (int x = 1; x <= 10; x++) {
        printf("Número %d: ", x);

        if (x % 3 == 0) {
            printf("Múltiplo de 3");
        } else if (x % 2 == 0) {
            printf("Par");
        } else {
            printf("Impar");
        }

        // Agregamos un switch para hacer algo simpático
        switch (x) {
            case 7:
                printf(" (¡El número de la suerte!)");
                break;
            case 10:
                printf(" (¡Llegamos al final!)");
                break;
        }

        printf("\n");
    }

    return 0;
}


/*
==========================================================
        CUÁNDO USAR WHILE, DO WHILE Y FOR EN C
==========================================================

1. WHILE:
   - Se usa cuando NO sabemos cuántas veces se repetirá el ciclo.
   - La condición se evalúa **antes de entrar** al bucle.
   - Si la condición es falsa desde el principio, el bloque **no se ejecuta nunca**.

   ✔️ Ventajas:
     - Muy útil para repetir hasta que se cumpla una condición externa (ej: esperar una tecla, leer hasta fin de archivo).
   ❌ Desventajas:
     - Puede haber peligro de bucle infinito si la condición nunca cambia dentro del ciclo.

   Ejemplo típico: Leer hasta que el usuario escriba "salir".

2. DO WHILE:
   - Similar al `while`, pero la condición se evalúa **después** de ejecutar el bloque.
   - Por lo tanto, el cuerpo del ciclo se ejecuta **al menos una vez sí o sí**.

   ✔️ Ventajas:
     - Perfecto cuando necesitamos que el bloque se ejecute al menos una vez (ej: menú interactivo).
   ❌ Desventajas:
     - Menos control si no queremos que se ejecute con ciertos valores iniciales.

   Ejemplo típico: Mostrar menú hasta que se elija "Salir".

3. FOR:
   - Ideal cuando **sabemos de antemano** cuántas veces se repite algo.
   - Tiene inicialización, condición y actualización **todo en una sola línea**, muy compacto y legible.

   ✔️ Ventajas:
     - Muy claro para contar ciclos fijos (ej: del 1 al 100).
     - Menos errores de condición infinita porque está todo junto.
   ❌ Desventajas:
     - No es tan flexible como `while` para condiciones complejas o múltiples salidas.

   Ejemplo típico: Calcular los primeros 10 múltiplos de un número.

==========================================================
CONSEJO:
Si sabés cuántas veces vas a repetir → FOR
Si no sabés cuántas veces → WHILE
Si querés que se ejecute al menos una vez → DO WHILE
==========================================================
*/



/*
==========================================================
       PROBLEMAS CON TILDES Y CARACTERES ESPECIALES
==========================================================

En C, los acentos (tildes), eñes y símbolos como "¿" o "¡"
pueden verse mal o deformarse en la consola, especialmente
en Windows. Esto ocurre por tres razones principales:

1. El archivo fuente puede no estar guardado como UTF-8.
2. La consola de salida (como CMD o Code::Blocks) no usa
   codificación UTF-8 por defecto.
3. La fuente usada por la terminal puede no tener esos
   caracteres.

Esto afecta funciones como printf(), que muestran texto con
acentos, produciendo resultados como "acci¢n" en lugar de "acción".

-------------------------------
    SOLUCIONES UNIVERSALES
-------------------------------

✅ 1. **Evitar tildes y usar lenguaje neutro**
   Lo más seguro y portátil. En lugar de "acción", escribir "accion".
   Así evitás problemas en cualquier sistema operativo.

✅ 2. **Guardar el archivo como UTF-8 sin BOM**
   En el editor de código (VSCode, Notepad++, etc.), asegurate de que
   el archivo esté codificado en "UTF-8 sin BOM".

✅ 3. **Forzar salida en UTF-8 (solo Windows)**
   Incluir al principio del código:
       #include <windows.h>
   Y dentro del main():
       SetConsoleOutputCP(CP_UTF8);

   ❗ Esta opción depende del sistema y puede no funcionar en algunos
   entornos como Code::Blocks, donde la consola no interpreta bien UTF-8.

✅ 4. **Usar funciones wide-char (wprintf) con Unicode (wchar_t)**
   Más complejo, pero más robusto. Requiere configuraciones extra y no se
   recomienda para programas simples o educativos.

-------------------------------
    RECOMENDACIÓN GENERAL
-------------------------------

Para mantener compatibilidad entre Windows, Linux y otros entornos:
→ Escribir los textos SIN tildes y SIN caracteres especiales.

Por ejemplo:
  - "Selecciona una opcion" en lugar de "Seleccioná una opción"
  - "Ingrese un numero" en lugar de "Ingrese un número"

Así te asegurás que tu código se vea bien en todas partes sin líos.
==========================================================
*/
