#include<stdio.h>

int x1[4]={0,0,1,1}, x2[4]={0,1,0,1}, output[4]={0,1,1,1};     //patrones de entrada y salida 
float w1=1, w2=0, theta=0.5, alpha=0.1;                               //definicion de pesos sesgo y tasa de aprendizaje

//función de activación heavyside
int activationFun(float x){
    
    float cbug=x*x*x*x*x*x*x;
    //printf("x:%f bug:%f\n",x,bug);
    if(x>=0.0 || (x<0&&cbug==0))
        return 1;
    if(x<0)
        return 0;
        
}

//calculo de error
int Error(int res,int real){
    return real - res;
}

//actualizacion de valores
void update(float x1, float x2,float e){
    w1=w1+alpha*e*x1;
    w2=w2+alpha*e*x2;
    theta=theta+alpha*e;

}


int main(){
    int e=0, obt=0, i=0;
    int errors=0,error_flag=0,epoch=0;
    printf("valores iniciales w1:%f w2:%f theta:%f",w1,w2,theta);
    do // itera sobre las entradas x hasta que se complete un ciclo sin errores
    {
        error_flag=0;
        while(i<4){ //iteracion sobre las salidas
         obt = activationFun( ((float)x1[i])*w1 + ((float)x2[i])*w2 + theta); //resultado perceptron y suma ponderada
         e = Error(obt,output[i]);
            if(e!=0) // si hay error  notifica y actaliza valores
            { 
            errors++;
            error_flag=1;
            update((float)x1[i],(float)x2[i],(float)e);
            }
        i++;
        }
        i=0;
        epoch++;
    } while (error_flag!=0);

    printf("valores finales w1:%f w2:%f theta:%f \nepocas:%d",w1,w2,theta,epoch);
    
   

}


