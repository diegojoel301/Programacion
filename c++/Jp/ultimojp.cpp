//vectorchar_archivo IPrado
#include<iostream>
#include<string.h>
using namespace std;
typedef struct x
{
	 char nombres[25];
     char apellidos[25];   
	 int nota;
}alumno;

alumno lectura_datos();
void borrar_alumno(alumno v[], char no1[], char ape1[]);
int leer(string g);
void copiar_del_archivo_al_vector(alumno v[]);
void crear_archivo_vacio();
void guardar_datos_del_vector_en_el_archivo(alumno z[]);
void leer_datos_vector(alumno v[], int ta);
void listado(string p,alumno z[], int ta);
void listado_alumno(alumno s);
void listar_datos_del_archivo();
void menu();
void modificar_alumno(alumno v[], char no1[], char ape1[]);
void ordenar(alumno v[]);
void registrar_datos_en_archivo(alumno x);


// variables globales
 char nombre_del_archivo[] = "alumnosSIS";
 int t=0; //Total de elementos
 
int main()
{  
   alumno V[10];
   alumno  y1;
   char nom[25],ape[25];
   int  opcion;
   do{
   	menu();
   	opcion=leer("?");
   	switch(opcion){
   		case 1:
	   	    crear_archivo_vacio();
   			break;
   		case 2:
   			  y1=lectura_datos();
              registrar_datos_en_archivo(y1);
              break;
   		case 3:
   			listar_datos_del_archivo();  
   			break;
   		case 4:
   			copiar_del_archivo_al_vector(V); 
   			ordenar(V);
   			crear_archivo_vacio();
   			guardar_datos_del_vector_en_el_archivo(V); 
   			break;
   		case 5:
   			cout<<"Escriba  nombre de la perssona a borrar: ";
    		gets(nom);
    		cout<<"Escriba  apellido de la perssona a borrar: ";
    		gets(ape);
    		cin.sync();//LIMPIAR EL BUFFER
   			copiar_del_archivo_al_vector(V); 
   			borrar_alumno(V,nom, ape);
   			crear_archivo_vacio();
   			guardar_datos_del_vector_en_el_archivo(V);
   			break;
   		case 6:
   			listar_datos_del_archivo(); 
   		    cout<<"\nEscriba  nombre a modificar : ";
    		gets(nom);
    		cout<<"Escriba  apellido a modificar : ";
    		gets(ape);
    		cin.sync();//LIMPIAR EL BUFFER
   			copiar_del_archivo_al_vector(V); 
   			modificar_alumno(V,nom, ape);
   			crear_archivo_vacio();
   			guardar_datos_del_vector_en_el_archivo(V); 
   			break;
	   }
   }while(opcion!=10);  
}

//---------------------------------------------------
void borrar_alumno(alumno v[], char no1[], char ape1[])
{ bool borrado=false;
	for(int i=0;i<t;i++)
	{
		if(strcmp(v[i].nombres,no1)==0 && strcmp(v[i].apellidos,ape1)==0)
		{
			for(int j=i;j<t-1;j++)
			{
				v[j]=v[j+1];
			}
			borrado=true;
			t=t-1;
		}
	}
	if(!borrado)
		cout<<"No encontrado...."<<endl;
}
//----------------------------------------------------------
void ordenar(alumno v[])
{
	alumno aux;
	for(int i=0;i<t;i++)
	{
		for(int j=i;j<t;j++)
		{
			if( strcmp(v[i].apellidos,v[j].apellidos)>0 )
			{
				aux=v[i];
				v[i]=v[j];
				v[j]=aux;				
			}
		}
	}
}
void menu()
{   system("cls");
	cout<<"\n\t** Alumnos de sis 111 **\n"<<endl;
	cout<<"\t\t1.- Crear archivo vacio"<<endl;
	cout<<"\t\t2.- Agregar datos en el archivo"<<endl;	
	cout<<"\t\t3.- listado de los datos del archivo"<<endl;
	cout<<"\t\t4.- Ordenar por apellido"<<endl;	
	cout<<"\t\t5.- Borrar un alumno"<<endl;
	cout<<"\t\t6.- Modificar datos de un alumno"<<endl;		
	cout<<"\t\t10.- salir"<<endl;	
}
void listado_alumno(alumno s)
{
	cout<<"\t\t"<<s.nombres<<" "<<s.apellidos<<"  "<<s.nota<<endl;
}
alumno lectura_datos()
{
	alumno y;
	cout<<"Escriba  nombre: ";
    gets(y.nombres);
    cout<<"Escriba  apellido: ";
    gets(y.apellidos);
    y.nota=leer("escriba nota ");
	return(y);
}
int leer(string g)
{
	int p; 
	cout<<g<<" ";
	cin>>p;
	fflush( stdin ); //limpiar el buffer
	return(p);
}
void crear_archivo_vacio()
{
     FILE *f;
     f=fopen(nombre_del_archivo,"wb");
     fclose(f);
} 
void registrar_datos_en_archivo(alumno x)
{
 FILE *f;
 f=fopen(nombre_del_archivo,"ab");
 fwrite(&x,sizeof(x),1,f);  
 fclose(f);   
} 
void listar_datos_del_archivo()
{
FILE *f;
int i=0;
alumno salida;
cout<<"\n *** Listado de nombres ***\n\n\t";
f=fopen(nombre_del_archivo,"rb");
fseek(f,SEEK_SET,0);
fread(&salida,sizeof(salida),1,f);
while(!feof(f)){
    cout<<i<<". "<<salida.nombres<<" "<<salida.apellidos<<", "<<salida.nota<<"\n\t";
    i++;
    fread(&salida,sizeof(salida),1,f);
                }
fclose(f); 
system("pause");    
}
//---------------------------------------------
void copiar_del_archivo_al_vector(alumno v[])
{
FILE *f;
t=0;
alumno salida;
f=fopen(nombre_del_archivo,"rb");
fseek(f,SEEK_SET,0);
fread(&salida,sizeof(salida),1,f);
while(!feof(f)){
	v[t]=salida;
    t++;
    fread(&salida,sizeof(salida),1,f);
                }
fclose(f); 
system("pause");    
}
//------------------------------------------
void guardar_datos_del_vector_en_el_archivo(alumno z[])
{
	for(int i=0;i<t;i++)
	{
		registrar_datos_en_archivo(z[i]);
	}
}
//-----------------------------
void modificar_alumno(alumno v[], char no1[], char ape1[])
{
    bool encontrado=false;
	for(int i=0;i<t;i++)
	{
		if(strcmp(v[i].nombres,no1)==0 && strcmp(v[i].apellidos,ape1)==0)
		{
			cout<<"*** Datos encontrados, escriba los datos modificados: "<<endl;
			v[i]=lectura_datos();
			
		}
	}
	if(!encontrado)
		cout<<"No encontrado...."<<endl;
}
