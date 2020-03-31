#include<iostream>
#define MAX 10
using namespace std;
struct producto
{
  int numProducto;
  int profit;
  int peso;
  float ratio;
  float guarda;
};
int main()
{
  producto P[MAX],temp;
  int i,j,total_producto,capacidad;
  float value=0;
  cout<<"Num de objetos : ";
  cin>>total_producto;
  cout<<"Capacidad de la mochila: ";
  cin>>capacidad;
  cout<<"\n";
  for(i=0;i<total_producto;++i)
  {
    P[i].numProducto=i+1;
    cout<<"Teclea el beneficio y su peso (separado con un espacio)"<<i+1<<" : ";
    cin>>P[i].profit>>P[i].peso;
    P[i].ratio=(float)P[i].profit/P[i].peso;
    P[i].guarda=0;
  }
  //Sort the ratio
  for(i=0;i<total_producto;++i)
  {
    for(j=i+1;j<total_producto;++j)
    {
      if(P[i].ratio<P[j].ratio)
      {
        temp=P[i];
        P[i]=P[j];
        P[j]=temp;
      }
    }
  }
  for(i=0;i<total_producto;++i)
  {
    if(capacidad==0)
      break;
    else if(P[i].peso<capacidad)
    {
      P[i].guarda=1;
      capacidad-=P[i].peso;
    }
    else if(P[i].peso>capacidad)
    {
      P[i].guarda=(float)capacidad/P[i].peso;
      capacidad=0;
    }
  }
  cout<<"\n\nLista de productos en mochila";
  for(i=0;i<total_producto;++i)
  {
    cout<<"\nLleva el producto"<<P[i].numProducto<<" : "<<P[i].guarda*P[i].peso<<" UNITS";
    value+=P[i].profit*P[i].guarda;
  }
  cout<<"\nEl beneficio de la mochila es: "<<value<<endl;
  return 0;
}
