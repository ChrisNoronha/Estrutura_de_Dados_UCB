#include <stdio.h>

                                                           

int encontra_min_max(int array[], int maior_ou_menor){
    int i=0,menor_valor=0, maior_valor=0;
    if(maior_ou_menor==0){
        for(i=0;i<4;i++){

        if(i==0){
           menor_valor=array[i]; 
        }

        if(array[i]<menor_valor){
            menor_valor=array[i];
        }
    }

    return menor_valor;
    }
  
      if(maior_ou_menor==1){
        for(i=0;i<4;i++){

        if(i==0){
           maior_valor=array[i]; 
        }

        if(array[i]>maior_valor){
            maior_valor=array[i];
        }
    }

    return maior_valor;
    }

}

int main(){
    int array[4], i=0, maior_ou_menor; /*menor valor=0 , maior valor=1*/

    for(i=0;i<4;i++){
        printf("Digite o numero %d\n",i+1);
        scanf("%d",&array[i]);
    }
    maior_ou_menor=0;
    printf("O menor valor e %d\n",encontra_min_max(array,maior_ou_menor));
      maior_ou_menor=1;
    printf("O maior valor e %d\n",encontra_min_max(array,maior_ou_menor));  



    return 0;
}