#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

struct Time {
    char nome[4];
    int jogos, pontos, vitorias, empates, derrotas;
    int golsPro, golsContra, saldo;
    double aproveitamento;

    Time() {
        strcpy(nome, "");
        jogos = pontos = vitorias = empates = derrotas = 0;
        golsPro = golsContra = saldo = 0;
        aproveitamento = 0;
    }

    Time(char _nome[4]) {
        strcpy(nome, _nome);
        jogos = pontos = vitorias = empates = derrotas = 0;
        golsPro = golsContra = saldo = 0;
        aproveitamento = 0;
    }

    void computarJogo(int _golsPro, int _golsContra) {
        jogos++;
        if (_golsPro > _golsContra) {
            vitorias++;
            pontos += 3;
        } else if (_golsPro == _golsContra) {
            empates++;
            pontos += 1;
        } else {
            derrotas++;
        }
        golsPro += _golsPro;
        golsContra += _golsContra;
        saldo = golsPro - golsContra;
        aproveitamento = (pontos / (jogos * 3.0)) * 100.0;
    }

    void imprimirTime() {
        printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%.2lf\n",
               nome, jogos, pontos, vitorias, empates,
               derrotas, saldo, golsPro, golsContra,
               aproveitamento);
    }
};

void bubble_sorte_pontos(Time times[]){
    Time time2;
    
    printf ("TABELA ORDENADA USANDO BUBBLE SORT ");
     for(int i = 0; i<12; i++){
        for(int j =0; j<12;j++){
                if(times[i].pontos>times[j].pontos){
                    time2 = times[i];
                    times[i] = times[j];
                    times[j]= time2;
                }else if(times[i].pontos==times[j].pontos &&times[i].vitorias>times[j].vitorias){
                    time2 = times[i];
                    times[i] = times[j];
                    times[j]= time2;
                }else if(times[i].pontos==times[j].pontos &&times[i].vitorias==times[j].vitorias&&times[i].saldo>
                times[j].saldo){
                    time2 = times[i];
                    times[i] = times[j];
                    times[j]= time2;
                }else if(times[i].pontos==times[j].pontos &&times[i].vitorias==times[j].vitorias&&times[i].saldo==
                times[j].saldo&&times[i].golsPro>times[j].golsPro){
                    time2 = times[i];
                    times[i] = times[j];
                    times[j]= time2;
                }
        }
     }
    
}

void select_sort(Time times[]){
    Time time2;

    printf("TABELA ORDENADA USANDO SELECTION SORT ");
    for(int i = 0; i<12;i++){
        for(int j = i+1; j<12;j++){
            if(times[i].pontos<times[j].pontos){
                    time2 = times[i];
                    times[i] = times[j];
                    times[j]= time2;
                }else if(times[i].pontos==times[j].pontos &&times[i].vitorias<times[j].vitorias){
                    time2 = times[i];
                    times[i] = times[j];
                    times[j]= time2;
                }else if(times[i].pontos==times[j].pontos &&times[i].vitorias==times[j].vitorias&&times[i].saldo<
                times[j].saldo){
                    time2 = times[i];
                    times[i] = times[j];
                    times[j]= time2;
                }else if(times[i].pontos==times[j].pontos &&times[i].vitorias==times[j].vitorias&&times[i].saldo==
                times[j].saldo&&times[i].golsPro<times[j].golsPro){
                    time2 = times[i];
                    times[i] = times[j];
                    times[j]= time2;
                }
        }
    }

}


bool verifica(Time times, Time time2){
        if(times.pontos<time2.pontos){
            return true;
        }else if(times.pontos==time2.pontos &&times.vitorias<time2.vitorias){
            return true;
        }else if(times.pontos==time2.pontos &&times.vitorias==time2.vitorias&&times.saldo<
                time2.saldo){
            return true;
        }else if(times.pontos==time2.pontos &&times.vitorias==time2.vitorias&&times.saldo==
                time2.saldo&&times.golsPro<time2.golsPro){

        }

        return false;
    }

void insertion_sort(Time times[]){
    Time time2;
    int i , j;

    printf ("TABELA ORDENADA USANDO INSERTION SORTE ");
    for(i = 1; i<12;i++){
        time2 = times[i];
        for(j = i-1; j>=0 && verifica(times[j], time2) == true; j--){
                 times[j+1] = times[j];

            }

            times[j+1] = time2;
        }
    }

    


int main() {

    Time times[12];
    char t1[4], t2[4];
    int opMenu, ult_id = -1, rl1, rl2;
    FILE *f = fopen("dados.txt", "r+");

    while(fscanf(f, "%s %dX%d %s", t1, &rl1, &rl2, t2) != EOF) {
        int i1 = -1, i2 = -1;
        for (int i = 0; i <= ult_id; i++) {
            if (strcmp(times[i].nome, t1) == 0) { // Checa se time 1 já existe
                i1 = i;
            }
            if (strcmp(times[i].nome, t2) == 0) { // Checa se time 2 já existe
                i2 = i;
            }
        }
        if (i1 == -1) { // Se time1 não existe, cria um novo no vetor
            ult_id++;
            strcpy(times[ult_id].nome, t1);
            i1 = ult_id;
        }
        if (i2 == -1) { // Se time2 não existe, cria um novo no vetor
            ult_id++;
            strcpy(times[ult_id].nome, t2);
            i2 = ult_id;
        }
        times[i1].computarJogo(rl1, rl2); // Computa para t1
        times[i2].computarJogo(rl2, rl1); // Computa para t2
    }


  

    printf ("\n\nTABELA SEM ORDENACAO");
    for(int i =0; i<12;i++){
        times[i].imprimirTime();
    }

    
   
    
    printf ("\nEscolha a forma de ordenacao:") ;
    printf ("\n(1) - Bubble Sort\n(2) - Selection Sort\n(3) - Insertion Sort \n");
   
    scanf(" %d",&opMenu);
   
    
    
    switch (opMenu){

    case 1:
        bubble_sorte_pontos(times);

        for(int i =0; i<12;i++){
        times[i].imprimirTime();
        }
    break;

    case 2:
        select_sort(times);

        for(int i =0; i<12;i++){
        times[i].imprimirTime();
        }
    break;

    case 3:
        insertion_sort(times);

        for(int i =0; i<12;i++){
        times[i].imprimirTime();
        }
    break;

    default:
        printf ("Digite uma opcao correta!") ;
    break;
    }
    


    return 0;
}


