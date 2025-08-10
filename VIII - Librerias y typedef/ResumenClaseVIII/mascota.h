#ifndef MASCOTA_H_INCLUDED
#define MASCOTA_H_INCLUDED


// Definición de la estructura Mascota
struct Mascota {
    char nombre[20];
    char raza[20];
};


typedef struct Mascota * MascotaPtr;

// Mascota
MascotaPtr cargarMascota();
void mostrarMascota(MascotaPtr m);
void ordenarMascotasPorNombre(MascotaPtr mascotas[], int n);
int buscarMascota(MascotaPtr mascotas[], int n, char nombreBuscado[]);
int eliminarMascota(MascotaPtr mascotas[], int n, char nombreEliminar[]);
int agregarMascota(MascotaPtr mascotas[], int n);


#endif // MASCOTA_H_INCLUDED
