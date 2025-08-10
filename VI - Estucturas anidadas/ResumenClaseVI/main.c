#include <stdio.h>
#include <string.h>

#define MAX_MASCOTAS 3

// Definición de la estructura Mascota
struct Mascota {
    char nombre[20];
    char raza[20];
};

// Definición de la estructura Persona con array de mascotas
struct Persona {
    char nombre[20];
    int edad;
    float altura;
    struct Mascota mascotas[MAX_MASCOTAS];
};

// ======================
//      PROTOTIPOS
// ======================

// Mascota
struct Mascota cargarMascota();
void mostrarMascota(struct Mascota m);
void ordenarMascotasPorNombre(struct Mascota mascotas[], int n);
int buscarMascota(struct Mascota mascotas[], int n, char nombreBuscado[]);
int eliminarMascota(struct Mascota mascotas[], int n, char nombreEliminar[]);
int agregarMascota(struct Mascota mascotas[], int n);

// Persona
struct Persona cargarPersonaTeclado();
void mostrarPersona(struct Persona p);

// ======================
//      MAIN
// ======================
int main() {
    printf("=== Carga persona y sus 3 mascotas ===\n");
    struct Persona p = cargarPersonaTeclado();

    printf("\n=== Mascotas cargadas ===\n");
    mostrarPersona(p);

    printf("\n=== Ordenando mascotas por nombre ===\n");
    ordenarMascotasPorNombre(p.mascotas, MAX_MASCOTAS);
    mostrarPersona(p);

    // Buscar mascota
    char nombreBuscar[20];
    printf("\nIngrese el nombre de la mascota a buscar: ");
    scanf("%19s", nombreBuscar);
    int idx = buscarMascota(p.mascotas, MAX_MASCOTAS, nombreBuscar);
    if (idx != -1) {
        printf("Mascota encontrada en posicion %d:\n", idx);
        mostrarMascota(p.mascotas[idx]);
    } else {
        printf("Mascota '%s' no encontrada.\n", nombreBuscar);
    }

    // Eliminar mascota
    char nombreEliminar[20];
    printf("\nIngrese el nombre de la mascota a eliminar: ");
    scanf("%19s", nombreEliminar);
    int eliminado = eliminarMascota(p.mascotas, MAX_MASCOTAS, nombreEliminar);
    if (eliminado) {
        printf("Mascota '%s' eliminada.\n", nombreEliminar);
    } else {
        printf("No se encontro la mascota '%s' para eliminar.\n", nombreEliminar);
    }

    printf("\n=== Mascotas despues de eliminar ===\n");
    mostrarPersona(p);

    // Intentar agregar una mascota nueva
    printf("\n=== Intentando agregar una mascota nueva ===\n");
    if (agregarMascota(p.mascotas, MAX_MASCOTAS)) {
        printf("Mascota agregada con exito.\n");
    } else {
        printf("No hay espacio para agregar mas mascotas.\n");
    }

    printf("\n=== Mascotas finales ===\n");
    mostrarPersona(p);

    return 0;
}

// ======================
//      FUNCIONES
// ======================

struct Mascota cargarMascota() {
    struct Mascota m;
    printf("Ingrese nombre de la mascota (o ENTER para dejar vacio): ");
    fflush(stdin);
    fgets(m.nombre, 20, stdin);
    size_t len = strlen(m.nombre);
    if(len > 0 && m.nombre[len-1] == '\n') {
        m.nombre[len-1] = '\0';
    }
    if(strlen(m.nombre) == 0) {
        m.raza[0] = '\0';
        return m;
    }
    printf("Ingrese raza de la mascota: ");
    fgets(m.raza, 20, stdin);
    len = strlen(m.raza);
    if(len > 0 && m.raza[len-1] == '\n') {
        m.raza[len-1] = '\0';
    }
    return m;
}

void mostrarMascota(struct Mascota m) {
    if(strlen(m.nombre) == 0) {
        printf("[Posicion vacia]\n");
    } else {
        printf("Mascota -> Nombre: %s | Raza: %s\n", m.nombre, m.raza);
    }
}

void ordenarMascotasPorNombre(struct Mascota mascotas[], int n) {
    for(int i=0; i < n-1; i++) {
        for(int j=0; j < n-1-i; j++) {
            if(strlen(mascotas[j].nombre) > 0 && strlen(mascotas[j+1].nombre) > 0) {
                if(strcmp(mascotas[j].nombre, mascotas[j+1].nombre) > 0) {
                    struct Mascota temp = mascotas[j];
                    mascotas[j] = mascotas[j+1];
                    mascotas[j+1] = temp;
                }
            } else if(strlen(mascotas[j].nombre) > 0 && strlen(mascotas[j+1].nombre) == 0) {
                struct Mascota temp = mascotas[j];
                mascotas[j] = mascotas[j+1];
                mascotas[j+1] = temp;
            }
        }
    }
}

int buscarMascota(struct Mascota mascotas[], int n, char nombreBuscado[]) {
    for(int i=0; i < n; i++) {
        if(strcmp(mascotas[i].nombre, nombreBuscado) == 0) {
            return i;
        }
    }
    return -1;
}

int eliminarMascota(struct Mascota mascotas[], int n, char nombreEliminar[]) {
    int pos = buscarMascota(mascotas, n, nombreEliminar);
    if(pos == -1) return 0;
    mascotas[pos].nombre[0] = '\0';
    mascotas[pos].raza[0] = '\0';
    return 1;
}

// Agrega una mascota por teclado si hay espacio
// Retorna 1 si agregó, 0 si no hay lugar
int agregarMascota(struct Mascota mascotas[], int n) {
    for(int i=0; i < n; i++) {
        if(strlen(mascotas[i].nombre) == 0) {  // posición libre
            printf("Ingrese datos de la nueva mascota para la posicion %d:\n", i+1);
            mascotas[i] = cargarMascota();

            // Verificamos que no hayan ingresado vacío (nombre)
            if(strlen(mascotas[i].nombre) == 0) {
                printf("No se ingreso nombre valido. Mascota no agregada.\n");
                return 0;
            }
            return 1;
        }
    }
    return 0; // no hay lugar
}

struct Persona cargarPersonaTeclado() {
    struct Persona p;

    printf("Ingrese nombre: ");
    scanf("%19s", p.nombre);

    printf("Ingrese edad: ");
    scanf("%d", &p.edad);

    printf("Ingrese altura: ");
    scanf("%f", &p.altura);

    getchar(); // limpiar buffer para fgets

    for(int i = 0; i < MAX_MASCOTAS; i++) {
        printf("\nCarga mascota #%d\n", i+1);
        p.mascotas[i] = cargarMascota();
    }

    return p;
}

void mostrarPersona(struct Persona p) {
    printf("Nombre: %s | Edad: %d | Altura: %.2f\n", p.nombre, p.edad, p.altura);
    printf("Mascotas:\n");
    for(int i = 0; i < MAX_MASCOTAS; i++) {
        printf("  [%d] ", i);
        mostrarMascota(p.mascotas[i]);
    }
}
