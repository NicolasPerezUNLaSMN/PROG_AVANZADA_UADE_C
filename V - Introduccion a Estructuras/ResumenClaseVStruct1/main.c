#include <stdio.h>
#include <string.h>



// Definición de la estructura
struct Persona {
    char nombre[20];
    int edad;
    float altura;
};

// ======================
//      PROTOTIPOS
// ======================
// PRE: No se usa puntero; se cargará una persona desde teclado.
// POS: Devuelve una estructura Persona con los valores ingresados.
struct Persona cargarPersonaTeclado();

// PRE: No requiere entrada del usuario.
// POS: Devuelve una Persona con valores fijos: {"Nico", 12, 1.8}.
struct Persona cargarPersonaFija();

// PRE: No requiere entrada del usuario.
// POS: Devuelve una Persona con valores fijos enviados por parametros
struct Persona cargarPersonaParametros(int e, float a, char n[20]);

// PRE: Recibe una Persona ya cargada.
// POS: Muestra por pantalla los datos de la Persona.
void mostrarPersona(struct Persona p);

// ======================
//      MAIN
// ======================
int main() {
    struct Persona p1, p2;

    printf("=== Carga por teclado ===\n");
    p1 = cargarPersonaTeclado();

    printf("\n=== Carga por valores fijos ===\n");
    p2 = cargarPersonaFija();

    printf("\n=== Mostrando personas ===\n");
    mostrarPersona(p1);
    mostrarPersona(p2);

    //Carga fija parametro por parametro
    struct Persona p3;
    p3.edad = 33;
    p3.altura = 2.01;
    strcpy(p3.nombre, "Brenda");
    mostrarPersona(p3);

    //Carga fija por parametros
     struct Persona p4 = cargarPersonaParametros(55, 1.55, "Flor");
    mostrarPersona(p4);


    return 0;
}

// ======================
//      FUNCIONES
// ======================


struct Persona cargarPersonaTeclado() {
    struct Persona p;

    printf("Ingrese nombre: ");
    scanf("%s", p.nombre);

    printf("Ingrese edad: ");
    scanf("%d", &p.edad);

    printf("Ingrese altura: ");
    scanf("%f", &p.altura);

    return p;
}

struct Persona cargarPersonaParametros(int e, float a, char n[20]){


    struct Persona p;

    p.edad = e;
    p.altura = a;

    strcpy(p.nombre, n);

    return p;

};;


struct Persona cargarPersonaFija() {
    struct Persona p = {"Nico", 12, 1.8};
    return p;
}


void mostrarPersona(struct Persona p) {
    printf("Nombre: %s | Edad: %d | Altura: %.2f\n", p.nombre, p.edad, p.altura);
}
