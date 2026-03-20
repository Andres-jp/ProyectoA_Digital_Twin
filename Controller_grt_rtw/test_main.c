#include <stdio.h>
#include <math.h>
#include "Controller.h"
// Stubs para funciones de logging
const char_T *rt_UpdateTXYLogVars(RTWLogInfo *li, time_T *tPtr) {
    return NULL;
}

const char_T *rt_StartDataLoggingWithStartTime(RTWLogInfo *li, const real_T startTime, const real_T finalTime, const real_T stepSize, const char_T **errStatusPtr) {
    return NULL;
}

int main() {
    //Inicialización de los estados del modelo
    Controller_initialize();
    
    printf("=== TEST DEL CONTROLADOR PI ===\n");

    while(1) {
        printf("\n------------------------------------------------\n");
        printf("INGRESO DE ENTRADAS\n");

        // Lectura de Goal
        printf("1. robotGoal [X Y]: ");
        if (scanf("%lf %lf", &Controller_U.robotGoal[0], &Controller_U.robotGoal[1]) != 2) break;

        // Lectura de Pose actual
        printf("2. fb_currentPose [X Y Theta_rad]: ");
        if (scanf("%lf %lf %lf", &Controller_U.fb_currentPose[0], &Controller_U.fb_currentPose[1], &Controller_U.fb_currentPose[2]) != 3) break;

        // Lectura de Velocidades (feedback)
        printf("3. fb_spd (lineal) y fb_dotw (angular): ");
        if (scanf("%lf %lf", &Controller_U.fb_spd_LPF, &Controller_U.fb_dotw) != 2) break;

        // Lectura de Waypoint inmediato (simplificación de planOutput)
        double wp_x, wp_y;
        printf("4. Siguiente Waypoint inmediato [X Y]: ");
        if (scanf("%lf %lf", &wp_x, &wp_y) != 2) break;

        // Mapeo del arreglo de 200 elementos: [X0..X99, Y0..Y99]
        for(int i = 0; i < 100; i++) {
            if (i == 0) {
                Controller_U.planOutput[i]       = wp_x; // Primera X
                Controller_U.planOutput[i + 100] = wp_y; // Primera Y
            } else {
                Controller_U.planOutput[i]       = NAN;  // Resto X vacías
                Controller_U.planOutput[i + 100] = NAN;  // Resto Y vacías
            }
        }

        // 2. Ejecución del paso algorítmico
        Controller_step();

        // 3. Impresión de las Salidas Calculadas
        printf("\nRESULTADOS DEL STEP:\n");
        printf(" u_spd  (Comando Vel Lineal):  %f\n", Controller_Y.u_spd);
        printf(" u_dotw (Comando Vel Angular): %f\n", Controller_Y.u_dotw);
        printf(" Not at atGoal:     %d\n", Controller_Y.atGoal);

        // Verificación de parada
        if (!Controller_Y.atGoal) {
            printf("\nMETA ALCANZADA.\n");
        }
    }

    // 4. Liberación
    Controller_terminate();
    printf("\nSimulacion terminada.\n");
    
    return 0;
}