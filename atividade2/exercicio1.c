#include <stdio.h>

                                                           

int soma_array(int array[]){
    int i=0,soma=0;
    for(i=0;i<4;i++){

        soma=array[i]+soma;
    }

    return soma;

}

int main(){
    int array[4], i=0;

    for(i=0;i<4;i++){
        printf("Digite o numero %d\n",i+1);
        scanf("%d",&array[i]);
    }

    printf("A soma e %d",soma_array(array));
    



    return 0;
}