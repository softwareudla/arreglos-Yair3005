#include <stdio.h>

int main() {
    float calificaciones[5][3];
    int aprobados[3] = {0};
    float suma, promedio, max, min;

    // Ingresamos calificaciones validas, no mas de 10
    for (int i = 0; i < 5; i++) {
        printf("Estudiante %d:\n", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("  Asignatura %d (nota entre 0 y 10): ", j + 1);
            scanf("%f", &calificaciones[i][j]);
            //Se vuelve a pedir la calificacion si esta es mayor a 10
            for (; calificaciones [i][j] < 0 || calificaciones[i][j] > 10;) {
                printf(" Nota invalida. Debe estar entre 0 y 10.\n");
                printf(" Asignatura %d (nota entre 0 y 10): ", j + 1);
                scanf("%f", &calificaciones[i][j]);
            }
        }
    }

    // Calculamos las notas de cada estudiante
    for (int i = 0; i < 5; i++) {
        suma = 0;
        max = min = calificaciones[i][0];
        for (int j = 0; j < 3; j++) {
            float nota = calificaciones[i][j];
            suma += nota;
            if (nota > max) max = nota;
            if (nota < min) min = nota;
        }
        promedio = suma / 3;
        printf("\nEstudiante %d - Promedio: %.2f, Max: %.2f, Min: %.2f\n", i + 1, promedio, max, min);
    }

    // Calculamos las notas por cada asignatura
    for (int j = 0; j < 3; j++) {
        suma = 0;
        max = min = calificaciones[0][j];
        for (int i = 0; i < 5; i++) {
            float nota = calificaciones[i][j];
            suma += nota;
            if (nota > max) max = nota;
            if (nota < min) min = nota;
            if (nota >= 6.0) aprobados[j]++;
        }
        promedio = suma / 5;
        printf("\nAsignatura %d - Promedio: %.2f, Max: %.2f, Min: %.2f, Aprobados: %d\n", j + 1, promedio, max, min, aprobados[j]);
    }

    return 0;
}