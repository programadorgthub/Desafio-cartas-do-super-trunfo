#include <stdio.h>

typedef struct{
       char estado[50];
       char codigo[10];
       char nome_cidade[50];
       int populacao;
       float area;
       float bip;
       int pontosTuristicos;
    } carta;

              int main (){
                      carta carta1 = {"Espirito santo", "ES001", "vitoria", 4102129, 46077.519, 10000000000.0, 7};
                      carta carta2 = {"Rio de janeiro", "RJ002","Rio de janeiro", 6747815, 1255.3, 1000000000000.0, 20};

                           float densidade1 = carta1.populacao / carta1.area;
                           float densidade2 = carta2.populacao / carta2.area;
                           float pib_per_capita1 = carta1.pib / carta1.populacao;
                           float pib_per_capita2 = carta2.pib / carta2.populacao;
                           
              }


    