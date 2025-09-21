#include <stdio.h>

int main(void){
    char Nombre[50];
    int esEstudiante, cursoAprobado, Gafete, Bata, Lentes, Guantes, Laser, experienciaPrevia, adeudosBiblioteca;
    int Edad, numeroPracticas;
    float promedio = 0.0f, horasSueno, cuotaBase;

    int banderaAlguna = 0, banderaRestriccion1 = 0, banderaRestriccion2 = 0, banderaRestriccion3 = 0, banderaRestriccion4 = 0, banderaAjuste = 0;
    int contadorRestricciones = 0, contadorAjustes = 0, contadorTotal = 0;
    int aptitud = -1;

    /* NUEVO: banderas de ajustes para listar cuáles aplicaron */
    int b1_promedio90 = 0, b2_experiencia = 0, b3_estudiante3pr = 0, b4_adeudo = 0;

    /* CLAVE: inicializa porcentajes */
    int descuento = 0, recargo = 0;
    float cuotaFinal;

    printf("----- CAPTURA DE DATOS DEL ASPIRANTE A LABORATORIO -----\n");

    printf("Ingrese su nombre: ");
    /* Nota: no uses & con arreglos y consume espacios previos */
    scanf(" %49[^\n]", Nombre);

    printf("Ingrese su edad: ");
    scanf("%i", &Edad);

    printf("Es usted estudiante actualmente? (0/1): ");
    scanf("%i", &esEstudiante);

    if (esEstudiante == 1){
        printf("Ingrese su promedio general: ");
        scanf("%f", &promedio);
    }

    printf("Usted acredito completamente el curso de seguridad? (0/1): ");
    scanf("%i", &cursoAprobado);

    printf("Tiene usted un gafete actualmente vigente? (0/1): ");
    scanf("%i", &Gafete);

    printf("Tiene usted una bata de seguridad? (0/1): ");
    scanf("%i", &Bata);

    printf("Tiene usted lentes de seguridad? (0/1): ");
    scanf("%i", &Lentes);

    printf("Tiene usted guantes de seguridad? (0/1): ");
    scanf("%i", &Guantes);

    printf("Cuantas horas durmio en las ultimas 24h?: ");
    scanf("%f", &horasSueno);

    printf("Utilizara equipo laser en su practica? (0/1): ");
    /* CLAVE: formato correcto */
    scanf("%i", &Laser);

    printf("Tiene usted experiencia previa en cuartos limpios? (0/1): ");
    scanf("%i", &experienciaPrevia);

    printf("Tiene usted adeudos pendientes con la biblioteca? (0/1): ");
    scanf("%i", &adeudosBiblioteca);

    printf("Cuantas practicas realizara durante esta sesion?: ");
    scanf("%i", &numeroPracticas);

    printf("Cual es el monto de su cuota base?: ");
    scanf("%f", &cuotaBase);

    /* Regla dura por edad (salida temprana) */
    if (Edad < 16){
        printf("\n!!! NO APTO !!!\nLo sentimos, el minimo de edad es 16 anios.\n");
        return 0;
    }

    /* --------- RESTRICCIONES --------- */
    if (Bata == 0 || Lentes == 0 || Guantes == 0){
        printf("\n!En riesgo!\nTodos los EPP son absolutamente requeridos en esta zona.\n");
        banderaAlguna = 1;
        banderaRestriccion1 = 1;
        contadorRestricciones += 1;
    }

    if (horasSueno < 6.0f && Laser == 1){
        printf("\n!En riesgo!\nManipular lasers sin descanso adecuado esta prohibido.\n");
        banderaAlguna = 1;
        banderaRestriccion2 = 1;
        contadorRestricciones += 1;
    }

    if (cursoAprobado == 0 || Gafete == 0){
        printf("\n!En riesgo!\nEs obligatorio aprobar el curso de seguridad y contar con gafete vigente.\n");
        banderaAlguna = 1;
        banderaRestriccion3 = 1;
        contadorRestricciones += 1;
    }

    /* Solo evaluar promedio si es estudiante */
    if (esEstudiante == 1 && promedio < 70.0f){
        printf("\n!En riesgo!\nSolicitamos un promedio minimo de 70 en aspirantes estudiantes.\n");
        banderaAlguna = 1;
        banderaRestriccion4 = 1;
        contadorRestricciones += 1;
    }

    /* --------- AJUSTES ECONOMICOS --------- */
    if (esEstudiante == 1 && promedio >= 90.0f){
        descuento += 20;
        b1_promedio90 = 1;
        banderaAlguna = 1;
        banderaAjuste = 1;
        contadorAjustes += 1;
    }

    if (experienciaPrevia == 1){
        descuento += 10;
        b2_experiencia = 1;
        banderaAlguna = 1;
        banderaAjuste = 1;
        contadorAjustes += 1;
    }

    if (esEstudiante == 1 && numeroPracticas >= 3){
        descuento += 5;
        b3_estudiante3pr = 1;
        banderaAlguna = 1;
        banderaAjuste = 1;
        contadorAjustes += 1;
    }

    if (adeudosBiblioteca == 1){
        recargo += 8;
        b4_adeudo = 1;
        banderaAlguna = 1;
        banderaAjuste = 1;
        contadorAjustes += 1;
    }

    /* --------- CALCULO DE CUOTAS --------- */
    /* CLAVE: usa float, no division entera */
    cuotaFinal = cuotaBase * (1.0f + recargo / 100.0f - descuento / 100.0f);
    contadorTotal = contadorRestricciones + contadorAjustes;

    /* --------- SALIDAS --------- */
    printf("\n------------- RESULTADOS ---------------\n");

    if (contadorRestricciones >= 3){
        printf("---------- RIESGO ALTO ----------\n");
        aptitud = 3;
    }
    else if (contadorRestricciones == 2){
        printf("-------- RIESGO MEDIO --------\n");
        aptitud = 2;
    }
    else if (contadorRestricciones == 1){
        printf("------ RIESGO BAJO ------\n");
        aptitud = 1;
    }
    else { /* contadorRestricciones == 0 */
        printf("---- RIESGO NULO ----\n");
        aptitud = 0;
    }

    if (aptitud == 3){
        printf("APTITUD: No APTO\n");
    }
    else if (aptitud == 2){
        printf("APTITUD: APTO, bajo supervision moderada\n");
    }
    else if (aptitud == 1){
        printf("APTITUD: APTO, bajo supervision leve\n");
    }
    else {
        printf("APTITUD: APTO\n");
    }

    if (contadorRestricciones >= 1){
        printf("\nRestricciones activadas:\n");
        if (banderaRestriccion1 == 1){
            printf("- R1: Falta algun EPP (bata/lentes/guantes)\n");
        }
        if (banderaRestriccion2 == 1){
            printf("- R2: Suenio < 6 h con laser\n");
        }
        if (banderaRestriccion3 == 1){
            printf("- R3: Curso no acreditado o gafete no vigente\n");
        }
        if (banderaRestriccion4 == 1){
            printf("- R4: Promedio < 70 (solo estudiantes)\n");
        }
    }

    /* Detalle de ajustes aplicados */
    if (contadorAjustes >= 1){
        printf("\nAjustes economicos aplicados:\n");
        if (b1_promedio90)   printf("- B1: Descuento 20%% por promedio >= 90\n");
        if (b2_experiencia)  printf("- B2: Descuento 10%% por experiencia en sala limpia\n");
        if (b3_estudiante3pr)printf("- B3: Descuento 5%% por estudiante con >= 3 practicas\n");
        if (b4_adeudo)       printf("- B4: Recargo 8%% por adeudos en biblioteca\n");
    }

    if (banderaAlguna == 1){
        printf("\n--- Resumen de Activaciones ---\n");
        printf("Restricciones: %i\n", contadorRestricciones);
        printf("Ajustes: %i\n", contadorAjustes);
        printf("Total: %i\n", contadorTotal);
    } else {
        printf("\nNo se activo ninguna condicion.\n");
    }

    printf("\n--- Resumen de cuota ---\n");
    printf("Cuota base: %.2f\n", cuotaBase);
    printf("Descuento total: %d%%\n", descuento);
    printf("Recargo total: %d%%\n", recargo);
    printf("Cuota final: %.2f\n", cuotaFinal);

    return 0;
}
