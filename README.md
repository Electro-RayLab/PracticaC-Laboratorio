# Control de acceso a laboratorio (C)

Programa en C que **evalúa restricciones de seguridad** (EPP, curso, gafete, sueño + láser, promedio) y **calcula una cuota final** aplicando **descuentos/recargos**. Incluye **banderas** y **contadores** para auditar qué reglas se activan y una **clasificación de riesgo** (NULO/BAJO/MEDIO/ALTO).

## Características
- Captura **secuencial** de datos.
- Condicionales **simples** y **compuestas (&&, ||)**.
- **Banderas** por regla y **contadores** por familia (R y B).
- Cálculo de cuota: `base * (1 + recargo% - descuento%)`.
- Reporte detallado de reglas y ajustes activados.

## Compilar
```bash
# Linux / macOS
gcc -o laboratorio laboratorio.c
./laboratorio

