/*
    Christopher Miranda
    Algoritmo avido de fontanero
*/

#include <iostream>
#include <vector>
using namespace std;

struct pendientes{
    int t;
    string sati="hola";
};
void Ordenar(pendientes *c, int num){ //ordena dependiendo de los itempos
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            if(c[j].t>c[j+1].t){ // si el de adelante es mayor lo cambia
                pendientes temp=c[j];
                c[j]=c[j+1];
                c[j+1]=temp;
            }
            
        }
    }
}// end ordenar
void Trabajar(pendientes *c, int nTrabajos)
{
    float tEspera=0.0;
    for(int i=0;i<nTrabajos;i++){
        if(tEspera<(c[i].t*2)){
            c[i].sati="Contento";
            cout<<"Tiempo del trabajo"<< c[i].t<<endl;
            cout<< "Tiempo que le tomó"<< tEspera<<endl;
            cout<< "Calificación"<<c[i].sati<<endl;
            
        }
        else if(tEspera>(c[i].t*2)&&tEspera<(c[i].t*2.5)){
            c[i].sati="Medio Contento";
            cout<<"Tiempo del trabajo"<< c[i].t<<endl;
            cout<< "Tiempo que le tomó"<< tEspera<<endl;
            cout<< "Calificación"<<c[i].sati<<endl;   
        }
        else{
            c[i].sati="Nada Contento";
            cout<<"Tiempo del trabajo"<< c[i].t<<endl;
            cout<< "Tiempo que le tomó"<< tEspera<<endl;
            cout<< "Calificación"<<c[i].sati<<endl;
        }
    }


}// end Trabajar

int main(){
    pendientes cliente[5];
    cliente[0].t=45;
    cliente[1].t=5;
    cliente[2].t=20;
    cliente[3].t=15;
    cliente[3].t=1;
    Ordenar(cliente,5);
    Trabajar(cliente,5);

    
}
