#include <iostream>
#include<conio.h>
using namespace std;

struct nodo
{
    int nro;
    struct nodo *sgte;
};

main()
{ 
	struct nodo NodoCabecera;
	struct nodo *q;
	int i, n;
	NodoCabecera.sgte=NULL;
	cout<<"Numero de elementos:";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"Elemento:"<<(i+1)<<endl;
	   	q=new(struct nodo);
	   	cin>>q->nro;
	   	q->sgte=NodoCabecera.sgte;
	   	NodoCabecera.sgte=q;
  	}
  	cout<<endl<<"Listado:"<<endl;
  	q=NodoCabecera.sgte;
  	while(q!=NULL)
  	{
  		cout<<q->nro<<endl;
  		q=q->sgte;
  	}
  	getch();
}
