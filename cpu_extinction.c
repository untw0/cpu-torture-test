#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define LOG_FILE "cpu_result.log"

void write_log(const char *message) {
    FILE *log = fopen(LOG_FILE, "a");
    if (log == NULL) {
        printf("Erro ao abrir o arquivo de log!\n");
        return;
    }

    time_t now = time(NULL);
    char *timestamp = ctime(&now);
    timestamp[strcspn(timestamp, "\n")] = 0;

    fprintf(log, "[%s] %s\n", timestamp, message);
    fclose(log);
}

double calculate_pi_bbp(long iterations) {
    double pi = 0.0;
    for (long k = 0; k < iterations; k++) {
        double term = (1.0 / pow(16, k)) * 
                      (4.0 / (8 * k + 1) - 
                       2.0 / (8 * k + 4) - 
                       1.0 / (8 * k + 5) - 
                       1.0 / (8 * k + 6));
        pi += term;
    }
    return pi;
}

double factorial_iterative(int n) {
    double result = 1.0;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

double heavy_exponential(long iterations) {
    double result = 0.0;
    for (long i = 1; i <= iterations; i++) {
        result += exp(log(i + 1));
    }
    return result;
}

void heavy_matrix_multiplication(int size) {
    double **A = malloc(size * sizeof(double *));
    double **B = malloc(size * sizeof(double *));
    double **C = malloc(size * sizeof(double *));
    
    for (int i = 0; i < size; i++) {
        A[i] = malloc(size * sizeof(double));
        B[i] = malloc(size * sizeof(double));
        C[i] = malloc(size * sizeof(double));
        for (int j = 0; j < size; j++) {
            A[i][j] = rand() % 1000;
            B[i][j] = rand() % 1000;
            C[i][j] = 0.0;
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    for (int i = 0; i < size; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);
}

long count_primes(long limit) {
    long count = 0;
    for (long num = 2; num <= limit; num++) {
        int is_prime = 1;
        for (long div = 2; div * div <= num; div++) {
            if (num % div == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime) count++;
    }
    return count;
}

int main() {
    clock_t start, end;
    double cpu_time_used;

    write_log("==== INICIANDO TESTE PESADO DE CPU ====");

    write_log("Calculando PI (BBP)...");
    start = clock();
    double pi = calculate_pi_bbp(10000000);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("PI calculado (BBP): %.15f em %.2f segundos.\n", pi, cpu_time_used);
    write_log(cpu_time_used < 10.0 ? "Desempenho PI BBP: BOM" : "Desempenho PI BBP: RUIM");

    write_log("Calculando Fatorial Iterativo...");
    start = clock();
    double fact = factorial_iterative(170);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Fatorial calculado (170!): %.0f em %.2f segundos.\n", fact, cpu_time_used);
    write_log(cpu_time_used < 5.0 ? "Desempenho Fatorial: BOM" : "Desempenho Fatorial: RUIM");

    write_log("Calculando Exponenciais...");
    start = clock();
    double expo = heavy_exponential(10000000);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Exponenciais calculado: %.2f em %.2f segundos.\n", expo, cpu_time_used);
    write_log(cpu_time_used < 10.0 ? "Desempenho Exponenciais: BOM" : "Desempenho Exponenciais: RUIM");

    write_log("Multiplicando Matrizes 500x500...");
    start = clock();
    heavy_matrix_multiplication(500);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Multiplicação de Matrizes concluída em %.2f segundos.\n", cpu_time_used);
    write_log(cpu_time_used < 20.0 ? "Desempenho Matrizes: BOM" : "Desempenho Matrizes: RUIM");

    write_log("Contando Primos até 10 milhões...");
    start = clock();
    long primes = count_primes(10000000);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Primos encontrados: %ld em %.2f segundos.\n", primes, cpu_time_used);
    write_log(cpu_time_used < 30.0 ? "Desempenho Primos: BOM" : "Desempenho Primos: RUIM");

    write_log("==== FIM DO TESTE PESADO ====");

    printf("\nTeste finalizado! Logs salvos em '%s'\n", LOG_FILE);

    return 0;
}
