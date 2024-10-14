/*Suponha que você é o responsável por gerenciar o estoque de 
duas lojas de quadrinhos, "Heróis HQ" e "Ação Comics", que possuem 
coleções exclusivas de edições raras. Cada edição é identificada por 
um número único, o ID da edição.

Seu objetivo é criar um sistema para unir as coleções das duas lojas, 
garantindo que não haja edições repetidas e que a coleção final represente 
a união das duas.

Você precisa implementar uma função chamada unir_colecoes que recebe como 
entrada as coleções de edições das duas lojas, representadas por vetores 
de inteiros (colecao_herois_hq e colecao_acao_comics), juntamente com o número 
de edições em cada coleção (tamanho_herois_hq e tamanho_acao_comics). A função 
deve retornar um ponteiro para um terceiro vetor, colecao_unificada, alocado 
dinamicamente, que contém a união das duas coleções. Além disso, utilize um 
ponteiro tamanho_final para retornar o tamanho da coleção final.

Sugestão de assinatura da função que você deve implementar: */


#include <stdio.h>
#include <stdlib.h>

// Function to check if an element already exists in the array
int exists_in_collection(int *array, int size, int element) {
    for (int i = 0; i < size; i++) {
        if (array[i] == element) {
            return 1; // Element already exists in the collection
        }
    }
    return 0; // Element does not exist in the collection
}

// Function to merge collections without duplicates
int* merge_collections(int *heroes_hq_collection, int heroes_hq_size, 
                       int *action_comics_collection, int action_comics_size, 
                       int *final_size) {
    
    // Allocate a temporary array to store the union of both collections
    int temp_size = heroes_hq_size + action_comics_size;
    int *temp_collection = (int*)malloc(temp_size * sizeof(int));
    
    if (temp_collection == NULL) {
        printf("Memory allocation error!\n");
        *final_size = 0;
        return NULL;
    }

    // Copy elements from Heroes HQ collection to the temporary array
    int index = 0;
    for (int i = 0; i < heroes_hq_size; i++) {
        temp_collection[index++] = heroes_hq_collection[i];
    }

    // Copy elements from Action Comics collection to the temporary array
    for (int i = 0; i < action_comics_size; i++) {
        temp_collection[index++] = action_comics_collection[i];
    }

    // Remove duplicates and create the unified collection
    int *unified_collection = (int*)malloc(temp_size * sizeof(int));
    int unified_size = 0;

    if (unified_collection == NULL) {
        printf("Memory allocation error!\n");
        free(temp_collection);
        *final_size = 0;
        return NULL;
    }

    // Add unique elements to the unified collection
    for (int i = 0; i < temp_size; i++) {
        if (!exists_in_collection(unified_collection, unified_size, temp_collection[i])) {
            unified_collection[unified_size++] = temp_collection[i];
        }
    }

    // Update the final size
    *final_size = unified_size;

    // Free memory of the temporary array
    free(temp_collection);

    // Return the pointer to the unified collection
    return unified_collection;
}

// Main function to test the code
int main() {
    int heroes_hq_collection[] = {101, 102, 103, 104, 105};
    int heroes_hq_size = sizeof(heroes_hq_collection) / sizeof(heroes_hq_collection[0]);
    
    int action_comics_collection[] = {104, 105, 106, 107};
    int action_comics_size = sizeof(action_comics_collection) / sizeof(action_comics_collection[0]);
    
    int final_size = 0;
    int *unified_collection = merge_collections(heroes_hq_collection, heroes_hq_size, 
                                                action_comics_collection, action_comics_size, 
                                                &final_size);
    
    // Print the unified collection
    if (unified_collection != NULL) {
        printf("Unified collection (%d editions):\n", final_size);
        for (int i = 0; i < final_size; i++) {
            printf("%d ", unified_collection[i]);
        }
        printf("\n");
        
        // Free allocated memory
        free(unified_collection);
    }

    return 0;
}