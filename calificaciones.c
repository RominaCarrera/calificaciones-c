#include <stdio.h>

#define EST 5
#define ASIG 3

void ingresarNotas(float notas[][ASIG]);
void mostrarNotas(float notas[][ASIG]);
float promedioEstudiante(float notas[][ASIG], int e);
float promedioAsignatura(float notas[][ASIG], int a);
float mayorEstudiante(float notas[][ASIG], int e);
float menorEstudiante(float notas[][ASIG], int e);
float mayorAsignatura(float notas[][ASIG], int a);
float menorAsignatura(float notas[][ASIG], int a);
int contarAprobados(float notas[][ASIG], int a);

int main() {
    float notas[EST][ASIG];
    int opcion, i, aprobados;

    printf("=== CALIFICACIONES DE LA ESCUELA ===\n");
    ingresarNotas(notas);

    do {
        printf("\n--- MENU ---\n");
        printf("1. Ver tabla de calificaciones\n");
        printf("2. Promedio por estudiante\n");
        printf("3. Promedio por asignatura\n");
        printf("4. Nota mas alta y mas baja por estudiante\n");
        printf("5. Nota mas alta y mas baja por asignatura\n");
        printf("6. Aprobados y reprobados por asignatura\n");
        printf("7. Salir\n");
        printf("Opcion: ");
        if (scanf("%d", &opcion) != 1) {
            opcion = 0;
            while (getchar() != '\n');
        }

        switch (opcion) {
            case 1:
                mostrarNotas(notas);
                break;
            case 2:
                printf("\nPromedio por estudiante\n");
                for (i = 0; i < EST; i++) {
                    printf("Estudiante %d: %.2f\n", i + 1, promedioEstudiante(notas, i));
                }
                break;
            case 3:
                printf("\nPromedio por asignatura\n");
                for (i = 0; i < ASIG; i++) {
                    printf("Asignatura %d: %.2f\n", i + 1, promedioAsignatura(notas, i));
                }
                break;
            case 4:
                printf("\nNota mas alta y mas baja por estudiante\n");
                for (i = 0; i < EST; i++) {
                    printf("Estudiante %d: alta %.2f, baja %.2f\n", i + 1,
                           mayorEstudiante(notas, i), menorEstudiante(notas, i));
                }
                break;
            case 5:
                printf("\nNota mas alta y mas baja por asignatura\n");
                for (i = 0; i < ASIG; i++) {
                    printf("Asignatura %d: alta %.2f, baja %.2f\n", i + 1,
                           mayorAsignatura(notas, i), menorAsignatura(notas, i));
                }
                break;
            case 6:
                printf("\nAprobados y reprobados por asignatura (nota minima 6)\n");
                for (i = 0; i < ASIG; i++) {
                    aprobados = contarAprobados(notas, i);
                    printf("Asignatura %d: aprobados %d, reprobados %d\n", i + 1,
                           aprobados, EST - aprobados);
                }
                break;
            case 7:
                printf("Hasta luego!\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }
    } while (opcion != 7);

    return 0;
}

void ingresarNotas(float notas[][ASIG]) {
    int i, j;
    for (i = 0; i < EST; i++) {
        for (j = 0; j < ASIG; j++) {
            printf("Estudiante %d, Asignatura %d (0 a 10): ", i + 1, j + 1);
            while (scanf("%f", &notas[i][j]) != 1 || notas[i][j] < 0 || notas[i][j] > 10) {
                printf("Nota invalida. Ingrese un numero de 0 a 10: ");
                while (getchar() != '\n');
            }
        }
    }
}

void mostrarNotas(float notas[][ASIG]) {
    int i, j;
    printf("\n              ");
    for (j = 0; j < ASIG; j++) {
        printf("Asig %d  ", j + 1);
    }
    printf("\n");
    for (i = 0; i < EST; i++) {
        printf("Estudiante %d  ", i + 1);
        for (j = 0; j < ASIG; j++) {
            printf("%5.2f   ", notas[i][j]);
        }
        printf("\n");
    }
}

float promedioEstudiante(float notas[][ASIG], int e) {
    float suma = 0;
    int j;
    for (j = 0; j < ASIG; j++) {
        suma = suma + notas[e][j];
    }
    return suma / ASIG;
}

float promedioAsignatura(float notas[][ASIG], int a) {
    float suma = 0;
    int i;
    for (i = 0; i < EST; i++) {
        suma = suma + notas[i][a];
    }
    return suma / EST;
}

float mayorEstudiante(float notas[][ASIG], int e) {
    float mayor = notas[e][0];
    int j;
    for (j = 1; j < ASIG; j++) {
        if (notas[e][j] > mayor) {
            mayor = notas[e][j];
        }
    }
    return mayor;
}

float menorEstudiante(float notas[][ASIG], int e) {
    float menor = notas[e][0];
    int j;
    for (j = 1; j < ASIG; j++) {
        if (notas[e][j] < menor) {
            menor = notas[e][j];
        }
    }
    return menor;
}

float mayorAsignatura(float notas[][ASIG], int a) {
    float mayor = notas[0][a];
    int i;
    for (i = 1; i < EST; i++) {
        if (notas[i][a] > mayor) {
            mayor = notas[i][a];
        }
    }
    return mayor;
}

float menorAsignatura(float notas[][ASIG], int a) {
    float menor = notas[0][a];
    int i;
    for (i = 1; i < EST; i++) {
        if (notas[i][a] < menor) {
            menor = notas[i][a];
        }
    }
    return menor;
}

int contarAprobados(float notas[][ASIG], int a) {
    int aprobados = 0;
    int i;
    for (i = 0; i < EST; i++) {
        if (notas[i][a] >= 6) {
            aprobados++;
        }
    }
    return aprobados;
}
