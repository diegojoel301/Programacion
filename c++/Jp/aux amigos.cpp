//Juan Pablo Revollo Esprella
#include<iostream>
#include<string.h>
using namespace std;
typedef struct x
{
	string amigo; //esto es el nombre
	string correo;
	int telefono;
	
}amigos;

amigos lectura_datos();
int leer(string g);
string leer_l(string g);
void listarAmigos(amigos v[])
void leer_datos_vector(amigos v[], int ta);
void menu();
main()
{  
   amigos V[10];
   int t, opcion;
   do{
   	menu();
   	opcion=leer("?");
   	switch(opcion){
   		case 1:
   			do{
   				t=leer("Total de amigos?");
			   }while(t<=0 || t>10);
			leer_datos_vector(V,t);
   			break;
   		case 2:
   			cout << "Listado de amigos: " << "\n";
   			listarAmigos(v);
   			break;
	   }
   }while(opcion!=10);  
} 

void leer_datos_vector(amigos v[], int ta)
{
	for(int i=0;i<ta;i++)
	{
		cout<<"Datos del amigo  #"<<(i+1)<<endl;
		v[i]=lectura_datos();
	}
}
void menu()
{
	cout<<"**Amigos***"<<endl;
	cout<<"1.- Registrar"<<endl;
	cout<<"2.- listado"<<endl;
	cout<<"3.- A que amigo quiere buscar?"<<endl;
	cout<<"4.- A quien quieres borrar?"<<endl;	
	cout<<"10.- salir"<<endl;	
}
//nos va a servir
void listado_amigos(amigos s)
{
	cout<<s.amigo<<" "<<s.correo<<"  "<<s.telefono<<endl;
}

void listarAmigos(amigos v[])
{
	//el vector v tiene una funcion dentro la cual nos devuelve la longitud
	for(int i = 0; i < v.length; i++)
		cout<< v[i].amigo <<" "<< v[i].correo<<"  "<< v[i].telefono <<endl;
}


amigos lectura_datos()
{
	amigos aux;
	aux.amigo=leer_l("Escribe nombre del amigo");
	aux.correo=leer_l("Escribe correo del amigo");
	aux.telefono=leer_l("Telefono del amigo");
	return(aux);
}
string leer_l(string g)
{
	string p; 
	cout<<g<<endl;
	getline(cin, p);
    cin.sync();
	return(p);
}
int leer(string g)
{
	int p; 
	cout<<g<<" ";
	cin>>p;
	fflush( stdin ); //limpiar el buffer
	return(p);
}
