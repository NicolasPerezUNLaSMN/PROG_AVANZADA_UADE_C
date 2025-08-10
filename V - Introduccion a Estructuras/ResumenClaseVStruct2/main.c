#include <stdio.h>
#include <string.h>

// Definición de la estructura Mascota
struct Mascota {
    char nombre[20];
    char raza[20];
};

// Definición de la estructura Persona
struct Persona {
    char nombre[20];
    int edad;
    float altura;
    struct Mascota mascota;  // Mascota incluida
};

// ======================
//      PROTOTIPOS
// ======================

// Mascota
struct Mascota cargarMascota();
void mostrarMascota(struct Mascota m);

// Persona
struct Persona cargarPersonaTeclado();
struct Persona cargarPersonaFija();
struct Persona cargarPersonaParametros(int e, float a, char n[20], struct Mascota m);
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

    // Crear mascota para p3
    struct Mascota m3 = {"Firulais", "Labrador"};
    struct Persona p3 = cargarPersonaParametros(33, 2.01, "Brenda", m3);
    mostrarPersona(p3);

    // Otra persona con mascota
    struct Mascota m4 = {"Misu", "Siames"};
    struct Persona p4 = cargarPersonaParametros(55, 1.55, "Flor", m4);
    mostrarPersona(p4);

    return 0;
}

// ======================
//      FUNCIONES
// ======================

// Carga una mascota desde teclado
struct Mascota cargarMascota() {
    struct Mascota m;
    printf("Ingrese nombre de la mascota: ");
    scanf("%19s", m.nombre);

    printf("Ingrese raza de la mascota: ");
    scanf("%19s", m.raza);

    return m;
}

// Muestra una mascota
void mostrarMascota(struct Mascota m) {
    printf("Mascota -> Nombre: %s | Raza: %s\n", m.nombre, m.raza);
}

// Carga una persona desde teclado, usando cargarMascota()
struct Persona cargarPersonaTeclado() {
    struct Persona p;

    printf("Ingrese nombre: ");
    scanf("%19s", p.nombre);

    printf("Ingrese edad: ");
    scanf("%d", &p.edad);

    printf("Ingrese altura: ");
    scanf("%f", &p.altura);

    // Cargar mascota usando función separada
    p.mascota = cargarMascota();

    return p;
}

// Devuelve persona fija con mascota fija
struct Persona cargarPersonaFija() {
    struct Persona p = {"Nico", 12, 1.8, {"Bobby", "Bulldog"}};
    return p;
}

// Carga persona con parámetros y mascota pasada como struct
struct Persona cargarPersonaParametros(int e, float a, char n[20], struct Mascota m){
    struct Persona p;

    p.edad = e;
    p.altura = a;
    strcpy(p.nombre, n);
    p.mascota = m;

    return p;
}

// Muestra persona y llama a mostrarMascota
void mostrarPersona(struct Persona p) {
    printf("\n\nNombre: %s | Edad: %d | Altura: %.2f\n\t", p.nombre, p.edad, p.altura);
    mostrarMascota(p.mascota);
}
