#include<iostream>
#include<string.h>

//algoritmo union-find para detecção de ciclos em DAGs

int buscaSubset(int subset[], int v);
void uniao(int subset[], int i, int j);
int ciclo(int grafo[3][3]);

int main(){
    int grafo[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}};
    grafo[0][1] = 1;
	grafo[1][0] = 1;
	grafo[1][2] = 1;
	grafo[2][1] = 1;
//	grafo[0][2] = 1;
//	grafo[2][0] = 1;
    if(ciclo(grafo)){
        std::cout << "ha ciclos";
    }
    else{
        std::cout << "nao ha ciclos";
    }
    return 0;    
}

int buscaSubset(int subset[], int v){

    if(subset[v] == -1){
        return v;
    }
    return buscaSubset(subset, subset[v]);
}

void uniao(int subset[], int i, int j){

    int v1_set = buscaSubset(subset, i);
    int v2_set = buscaSubset(subset, j);
    subset[v1_set] = v2_set;

}

int ciclo(int grafo[3][3]){

    int *subset = new int(3);

    memset(subset, -1, 3*sizeof(int));

    for(size_t i{0} ; i < 3 ; i+=1){

        for(size_t j{i} ; j < 3 ; j+=1){

            if(grafo[i][j] == 1){

                int v1 = buscaSubset(subset, i);
                int v2 = buscaSubset(subset, j);

                if(v1 == v2){
                    return 1;
                }
                else{
                    uniao(subset, v1, v2);
                }

            }

        }

    }
    return 0;
}