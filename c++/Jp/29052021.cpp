//Juan Pablo Revollo Esprella
#include<iostream>
#include<string.h>
using namespace std;
typedef struct x
{
	string amigo;
	string correo;
	string telefono;
	
}amigos;
void listado(string out, amigos v[], int n);
amigos lectura_datos();
int leer(string g);
string leer_l(string g);
void leer_datos_vector(amigos v[], int ta);
int buscarAmigo(amigos v[], int n, string x);
void eliminarAmigo(amigos v[], int n, int k);
void menu();

void mileer(amigos v[]);

int main()
{  
   amigos V[10];
   int t, opcion;
   string x;
   do{
   	menu();
   	opcion=leer("?");
   	switch(opcion){
   		case 1:
   		/*descomentar si deseas llenar
   			do{
   				t=leer("Total de amigos?");
			   }while(t<=0 || t>10);
			//leer_datos_vector(V,t);
		*/
		//eliominar estas dos linea si no quieres que se llene automaticamente
			t = 9;
			mileer(V); 
   			break;
   		case 2:
   			listado(" \nlos datos son \n",V,t);
   			break;
   		case 3:
   		    
   		    //getline(cin, x);
   		    cin >> x;
   		    
   		    if(buscarAmigo(V, t, x) > 0)
                cout << "SI\n";
            else
                cout << "NO\n";
   		    break;
   		case 4:
   		    cin >> x;
   		    //A quien quieres borrar
   		    if(buscarAmigo(V, t, x) > 0)
   		    {
   		        eliminarAmigo(V, t, buscarAmigo(V, t, x));
   		        t--;
   		        listado(" \nlos datos son \n",V,t);    
   		    }
   		    
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
void mileer(amigos v[])
{
    v[0].amigo = "Manuel"; v[0].correo = "manolo@gmail.com"; v[0].telefono = "2635153";
    v[1].amigo = "Roger"; v[1].correo = "rogelio@gmail.com"; v[1].telefono = "3674635";
    v[2].amigo = "Juan"; v[2].correo = "manolo@gmail.com"; v[2].telefono = "4873646";
    v[3].amigo = "Juan"; v[3].correo = "juanpi@gmail.com"; v[3].telefono = "2746343";
    v[4].amigo = "Jose"; v[4].correo = "joselo@gmail.com"; v[4].telefono = "8263532";
    v[5].amigo = "Jorge"; v[5].correo = "jorgelaso@gmail.com"; v[5].telefono = "8364521";
    v[6].amigo = "Wilder"; v[6].correo = "wilderaso@gmail.com"; v[6].telefono = "846252";
    v[7].amigo = "Gabriel"; v[7].correo = "gabrielaso@gmail.com"; v[7].telefono = "9473523";
    v[8].amigo = "Genaro"; v[8].correo = "generaso@gmail.com"; v[8].telefono = "94725354";
}
void menu()
{
	cout<<"*Amigos**"<<endl;
	cout<<"1.- Registrar"<<endl;
	cout<<"2.- listado"<<endl;
	cout<<"3.- A que amigo quiere buscar?"<<endl;
	cout<<"4.- A quien quieres borrar?"<<endl;	
	cout<<"10.- salir"<<endl;	
}
/*
void listado_amigos(amigos s)
{
	cout<<s.amigo<<" "<<s.correo<<"  "<<s.telefono<<endl;
}*/
//void listado(string out, amigos v[], int n);
void listado(string out, amigos v[], int n)
{
    for(int i = 0; i < n; i++)
        cout << v[i].amigo <<" "<< v[i].correo <<"  "<< v[i].telefono <<endl;    
}
int buscarAmigo(amigos v[], int n, string x)
{
    int pos = -1; //esta variable denota la posicion del amigo
    for(int i = 0; i < n; i++)
    {
        if(v[i].amigo == x) //verificamos si el nombre del amigo es igual al nombre x
            pos = i;
    }
    return pos;
}
void ordenar()
{
	
}
void eliminarAmigo(amigos v[], int n, int k)
{
    for(int i = k; i < n - 1; i++)
    {
        amigos tmp = v[i];
        v[i] = v[i + 1];
        v[i + 1] = tmp;
    }
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
