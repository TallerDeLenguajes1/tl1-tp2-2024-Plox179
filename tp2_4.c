#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct compu {
    float velocidad;
    int anio;
    char *tipo_cpu;
    int cant;
};

void cargarPc(struct compu pcs[], int num_pcs, char tipos[][10]) {
    for (int i = 0; i < num_pcs; i++) {
        pcs[i].velocidad = 1 + (rand() / (RAND_MAX / (3 - 1 + 1.0)));
        pcs[i].anio = 2015 + (rand() % 9); // Rango de 2015 a 2023
        pcs[i].tipo_cpu = tipos[rand() % 6]; // Seleccionar aleatoriamente un tipo de CPU del arreglo tipos
        pcs[i].cant = 1 + (rand() % 8);
    }
}

struct compu pcMasVieja(struct compu pcs[], int num_pcs) {
    struct compu masVieja = pcs[0];

    for (int i = 1; i < num_pcs; i++) {
        if (pcs[i].anio < masVieja.anio) {
            masVieja = pcs[i];
        }
    }

    return masVieja;
}

struct compu pcMayorVelocidad(struct compu pcs[], int num_pcs) {
    struct compu mayorVelocidad = pcs[0];

    for (int i = 1; i < num_pcs; i++) {
        if (pcs[i].velocidad > mayorVelocidad.velocidad) {
            mayorVelocidad = pcs[i];
        }
    }

    return mayorVelocidad;
}

int main() {
    srand(time(NULL));

    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    struct compu pcs[5];

    cargarPc(pcs, 5, tipos);

    // Mostrar las características de las PCs cargadas
    printf("Caracteristicas de las PCs:\n");
    for (int i = 0; i < 5; i++) {
        printf("PC #%d\n", i + 1);
        printf("Velocidad: %.2f GHz\n", pcs[i].velocidad);
        printf("Anio: %d\n", pcs[i].anio);
        printf("Tipo de CPU: %s\n", pcs[i].tipo_cpu);
        printf("\n");
    }

    struct compu masVieja = pcMasVieja(pcs, 5);
    struct compu mayorVelocidad = pcMayorVelocidad(pcs, 5);

    // Mostrar la PC más vieja
    printf("La PC mas vieja es:\n");
    printf("Velocidad: %.2f GHz\n", masVieja.velocidad);
    printf("Anio: %d\n", masVieja.anio);
    printf("Tipo de CPU: %s\n", masVieja.tipo_cpu);

    // Mostrar la PC con mayor velocidad
    printf("\nLa PC con mayor velocidad es:\n");
    printf("Velocidad: %.2f GHz\n", mayorVelocidad.velocidad);
    printf("Anio: %d\n", mayorVelocidad.anio);
    printf("Tipo de CPU: %s\n", mayorVelocidad.tipo_cpu);

    return 0;
}