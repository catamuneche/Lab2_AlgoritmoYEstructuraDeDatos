#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long OperABO=0;
long OperAVL=0;

struct Nodo {
int info;
    struct Nodo *izq;
    struct Nodo *der;
};
typedef struct Nodo tNodo;
typedef tNodo *ABO;

struct NodoAVL {
int info;
int altura;
    struct NodoAVL *izq;
    struct NodoAVL *der;
};
typedef struct NodoAVL tNodoAVL;
typedef tNodoAVL *AVL;

//////////////////////////////////Firmas
ABO CreaNodoABO (int);
int Info (ABO);
ABO Der (ABO);
ABO Izq (ABO);
void LiberaNodoABO (ABO);
int VacioABO (ABO);
int Menor (ABO);
ABO InsertarABO (ABO, int);
ABO EliminarABO (ABO, int);
int EstaABO (ABO, int );
int AlturaABO (ABO);
ABO Insertar_Archivo_ABO (char *, ABO);
ABO Eliminar_Archivo_ABO (char *, ABO);
ABO Buscar_Archivo_ABO (char *, ABO);
AVL CreaNodoAVL (int);
int VacioAVL (AVL);
int AlturaNodo (AVL);
int DiferenciaAlturaHijos (AVL);
int Maximo (int, int);
void LiberaNodoAVL (AVL);
AVL ActualizarAltura (AVL);
AVL RotarSimpleDerecha (AVL);
AVL RotarSimpleIzquierda (AVL);
AVL RotarDobleIzquierdaDerecha (AVL);
AVL RotarDobleDerechaIzquierda (AVL);
AVL Balancear (AVL);
AVL InsertarAVL (AVL, int);
int EsHoja (AVL);
AVL EliminarAVL (AVL, int);
int EstaAVL (AVL, int);
int AlturaAVL (AVL);
AVL Insertar_Archivo_AVL (char *, AVL);
AVL Eliminar_Archivo_AVL (char *, AVL);
AVL Buscar_Archivo_AVL (char *, AVL);

//////////////////////////////////Funciones ABO

ABO CreaNodoABO(int val){

    ABO aux;

    aux = (ABO)malloc(sizeof(tNodo));
    aux->info = val;
    aux->izq = NULL;
    aux->der = NULL;
    //printf("info= %d\n",aux->info);//CAMBIAR DESPUES
    OperABO=OperABO+4;
    return aux;
}

int Info(ABO A){
    OperABO=OperABO+1;
    return A->info;
}

ABO Der(ABO A){
    OperABO=OperABO+1;
    return A->der;
}

ABO Izq(ABO A){
    OperABO=OperABO+1;
    return A->izq;
}

void LiberaNodoABO(ABO A){
	free(A);
    OperABO=OperABO+1;
}

int VacioABO(ABO A){
    OperABO=OperABO+1;
	if(A==NULL)
		return 1;
	else
		return 0;
}

int Menor(ABO A){
    OperABO=OperABO+1;
    if(VacioABO(Izq(A)))
        return (Info(A));
    else
		return Menor(Izq(A));
}

void InOrdenABO(ABO A){
    if(!(VacioABO(A))){
        InOrdenABO(Izq(A));
        printf("%d - ",Info(A));
        InOrdenABO(Der(A));
    }
}

ABO InsertarABO(ABO A, int x){
	OperABO=OperABO+1;
    if(VacioABO(A)){
    	OperABO=OperABO+1;
        A = CreaNodoABO(x);
    }
    else{
    	OperABO=OperABO+1;
        if(x < Info(A)){
        	//printf("info Izq = %d\n",A->info);//CAMBIAR DESPUES
        	OperABO=OperABO+1;
        	A->izq = InsertarABO(Izq(A), x);
        }
        else{
        	//printf("info Der = %d\n",A->info);//CAMBIAR DESPUES
        	OperABO=OperABO+1;
            A->der = InsertarABO(Der(A), x);
        }
    }
    return A;
}

ABO EliminarABO(ABO A, int x){
    ABO p;
    int menor;
    OperABO=OperABO+1;
    if(Info(A) == x){
    	OperABO=OperABO+2;
    	if(VacioABO(Izq(A))&&VacioABO(Der(A))){ //A es hoja
    		//printf("VacioABO 1 = %d\n",A->info);//CAMBIAR DESPUES
            LiberaNodoABO(A);
            return NULL;
        }
    	OperABO=OperABO+2;
        if(VacioABO(Izq(A))&&!(VacioABO(Der(A)))){ //A sólo tiene hijo derecho
        	//printf("VacioABO Izq = %d\n",A->info);//CAMBIAR DESPUES
        	OperABO=OperABO+1;
        	p = Der(A);
            LiberaNodoABO(A);
            return p;
        }
        OperABO=OperABO+2;
        if(VacioABO(Der(A))&&!(VacioABO(Izq(A)))){ //A sólo tiene hijo izquierdo
            //printf("VacioABO Der = %d\n",A->info);//CAMBIAR DESPUES
            OperABO=OperABO+1;
        	p = Izq(A);
            LiberaNodoABO(A);
            return p;
        }
        OperABO=OperABO+1;
        menor = Menor(Der(A)); //A tiene ambos hijos
        //printf("Ambos = %d\n",menor);//CAMBIAR DESPUES
        OperABO=OperABO+3;
        A->info = menor;
        A->der = EliminarABO(Der(A), menor);
    }
    else {
    	OperABO=OperABO+1;
        if(x < Info(A)){
        	//printf("Izq = %d\n",A->info);//CAMBIAR DESPUES
        	OperABO=OperABO+1;
            A->izq = EliminarABO(Izq(A), x);
        }
        else{
        	//printf("Der = %d\n",A->info);//CAMBIAR DESPUES
        	OperABO=OperABO+1;
            A->der = EliminarABO(Der(A), x);
        }
    }
    return A;
}

int EstaABO(ABO A, int x){
	OperABO=OperABO+1;
    if(VacioABO(A))
        return 0;
    OperABO=OperABO+1;
    if(x == Info(A))
        return 1;
    OperABO=OperABO+2;
    if(x < Info(A))
    	return EstaABO(Izq(A), x);
    else
        return EstaABO(Der(A), x);
}

int AlturaABO(ABO A){
	int AltIzq, AltDer;
 	OperABO=OperABO+1;
 	if(VacioABO(A))
 		return 0;
 	else{
 		OperABO=OperABO+2;
 		AltIzq = 1 + AlturaABO(Izq(A));
 	 	AltDer = 1 + AlturaABO(Der(A));
 	 	if (AltIzq > AltDer)
 	 		return AltIzq;
 	 	else
 	 		return AltDer;
 }
}

ABO Insertar_Archivo_ABO(char * Arch, ABO A){
	FILE * Archivo;
	int valaux=0;//Variable tendrá el valor de el numero sacado del archivo ins
	char saux[100];//Variable para sacar el dato del archivo ins
	Archivo=fopen(Arch,"r");
	if(Archivo!=NULL){
		while(feof(Archivo)==0){//Ciclo para recorrer el archivo hasta que termine
			fgets(saux,100,Archivo);//Toma de dato del archivo ins
			if(feof(Archivo)==0){//If para controlar que el fgets no tome el salto de la ultima linea del archivo ins
				saux[strlen(saux)-1]=0;//Se le quita el salto de linea a la cadena y se le asigna 0 que es final de cadena
				valaux=atoi(saux);//Transformación de la cadena a entero
				OperABO=OperABO+1;
				A=InsertarABO(A,valaux);
			}
		}
		fclose(Archivo);
	}
	else
		printf("No se encontró el archivo %s.\n",Arch);
	return A;
}

ABO Eliminar_Archivo_ABO(char * Arch, ABO A){
	FILE * Archivo;
	int valaux=0;//Variable tendrá el valor de el numero sacado del archivo ins
	char saux[100];//Variable para sacar el dato del archivo ins
	Archivo=fopen(Arch,"r");
	if(Archivo!=NULL){
		while(feof(Archivo)==0){//Ciclo para recorrer el archivo hasta que termine
			fgets(saux,100,Archivo);//Toma de dato del archivo ins
			if(feof(Archivo)==0){//If para controlar que el fgets no tome el salto de la ultima linea del archivo ins
				saux[strlen(saux)-1]=0;//Se le quita el salto de linea a la cadena y se le asigna 0 que es final de cadena
				valaux=atoi(saux);//Transformación de la cadena a entero
				OperABO=OperABO+1;
				if(EstaABO(A,valaux)){
					OperABO=OperABO+1;
					A=EliminarABO(A,valaux);
				}
				else
					printf("%d NO está en el ABO.\n",valaux);
			}
		}
		fclose(Archivo);
	}
	else
		printf("No se encontró el archivo %s.\n",Arch);
	return A;
}

ABO Buscar_Archivo_ABO(char * Arch, ABO A){
	FILE * Archivo;
	int valaux=0;//Variable tendrá el valor de el numero sacado del archivo ins
	char saux[100];//Variable para sacar el dato del archivo ins
	Archivo=fopen(Arch,"r");
	if(Archivo!=NULL){
		while(feof(Archivo)==0){//Ciclo para recorrer el archivo hasta que termine
			fgets(saux,100,Archivo);//Toma de dato del archivo ins
			if(feof(Archivo)==0){//If para controlar que el fgets no tome el salto de la ultima linea del archivo ins
				saux[strlen(saux)-1]=0;//Se le quita el salto de linea a la cadena y se le asigna 0 que es final de cadena
				valaux=atoi(saux);//Transformación de la cadena a entero
				OperABO=OperABO+1;
				if(EstaABO(A,valaux))
					printf("%d está en ABO.\n",valaux);
				else
					printf("%d NO está en ABO.\n",valaux);

			}
		}
		fclose(Archivo);
	}
	else
		printf("No se encontró el archivo %s.\n",Arch);
	return A;
}

/////////////////////////////////Funciones AVL

AVL CreaNodoAVL(int val){

    AVL aux;

    aux = (AVL)malloc(sizeof(tNodoAVL));
    aux->info = val;
    aux->izq = NULL;
    aux->der = NULL;
    aux->altura = 1;
    OperAVL=OperAVL+5;
    return aux;
}

int VacioAVL(AVL A){
    OperAVL=OperAVL+1;
	if(A==NULL)
		return 1;
	else
		return 0;
}

void InOrdenAVL(AVL A){
    if(!(VacioAVL(A))){
        InOrdenAVL(A->izq);
        printf("%d - ",A->info);
        InOrdenAVL(A->der);
    }
}

int AlturaNodo(AVL A){
    OperAVL=OperAVL+1;
    if (VacioAVL(A))
        return 0;
    else{
        OperAVL=OperAVL+1;
        return A->altura;
    }
}

int DiferenciaAlturaHijos(AVL A){
    OperAVL=OperAVL+2;
    return AlturaNodo(A->izq) - AlturaNodo(A->der);
}

int Maximo(int x, int y){
    OperAVL=OperAVL+2;
    if (x>y){
        printf("x=%d\n",x);
        return x;
    }
    else{
        printf("y=%d\n",y);
        return y;
    }
}

void LiberaNodoAVL(AVL A){
	free(A);
	OperAVL=OperAVL+1;
}

AVL ActualizarAltura(AVL A){
    OperAVL=OperAVL+1;
    if(!(VacioAVL(A))){
        OperAVL=OperAVL+3;
        A->altura = Maximo(AlturaNodo(A->izq), AlturaNodo(A->der))+1;
    }
    return A;
}

AVL RotarSimpleDerecha(AVL A){
    AVL aux;

    aux = A->izq;
    A->izq = aux->der;
    aux->der = A;
    A = ActualizarAltura(A);
    aux = ActualizarAltura(aux);
    OperAVL=OperAVL+3;
    return aux;
}

AVL RotarSimpleIzquierda(AVL A){
    AVL aux;

    aux = A->der;
    A->der = aux->izq;
    aux->izq = A;
    A = ActualizarAltura(A);
    aux = ActualizarAltura(aux);
    OperAVL=OperAVL+3;
    return aux;
}

AVL RotarDobleIzquierdaDerecha(AVL A){
    A->izq = RotarSimpleIzquierda(A->izq);
    A = RotarSimpleDerecha(A);
    OperAVL=OperAVL+2;
    return A;
}

AVL RotarDobleDerechaIzquierda(AVL A){
    A->der = RotarSimpleDerecha(A->der);
    A = RotarSimpleIzquierda(A);
    OperAVL=OperAVL+2;
    return A;
}

AVL Balancear(AVL A){
    int condicion, dif;
    OperAVL=OperAVL+1;
    if (!VacioAVL(A))
    {
        condicion = DiferenciaAlturaHijos(A);
        if (condicion == 2)
        {
            OperAVL=OperAVL+1;
            dif = DiferenciaAlturaHijos(A->izq);

            if (dif == 1 || dif == 0)
                return RotarSimpleDerecha(A);   //Caso 2
            else
                return RotarDobleIzquierdaDerecha(A);   //Caso 4
        }
        if (condicion == -2)
        {
            OperAVL=OperAVL+1;
            dif = DiferenciaAlturaHijos(A->der);

            if (dif == -1 || dif == 0)
                return RotarSimpleIzquierda(A);   //Caso 3
            else
                return RotarDobleDerechaIzquierda(A);   //Caso 5
        }
    }
    return A;
}

AVL InsertarAVL(AVL A, int x){
    OperAVL=OperAVL+1;
    if (VacioAVL(A)){
        OperAVL=OperAVL+1;
        A = CreaNodoAVL(x);
    }
    else
    {
        OperAVL=OperAVL+1;
        if (A->info > x){
            OperAVL=OperAVL+2;
            A->izq = InsertarAVL(A->izq, x);
        }
        else{
            OperAVL=OperAVL+2;
            A->der = InsertarAVL(A->der, x);
        }

        A = ActualizarAltura(A);
        A = Balancear(A);
        OperAVL=OperAVL+1;
    }
    return A;
}

int EsHoja(AVL A){
    OperAVL=OperAVL+1;
    if(VacioAVL(A))
	    return 0;
	OperAVL=OperAVL+2;
    if(VacioAVL(A->izq)&&VacioAVL(A->der))
        return 1;
    return 0;
}

AVL EliminarAVL(AVL A, int x){
    AVL aux;
    OperAVL=OperAVL+1;
    if (VacioAVL(A))
        return NULL;
    OperAVL=OperAVL+1;
    if (A->info == x)
    {
        if (EsHoja(A))
        {
            LiberaNodoAVL(A);
            return NULL;
        }
        OperAVL=OperAVL+2;
        if (VacioAVL(A->izq))
        {
            aux = A->der;
            A->der = NULL;
            LiberaNodoAVL(A);
            OperAVL=OperAVL+2;
            return aux;
        }
        OperAVL=OperAVL+2;
        if (VacioAVL(A->der))
        {
            aux = A->izq;
            A->izq = NULL;
            LiberaNodoAVL(A);
            OperAVL=OperAVL+2;
            return aux;
        }
        aux = A->der;
        OperAVL=OperAVL+3;
        while (!VacioAVL(aux->izq)){
            aux = aux->izq;
            OperAVL=OperAVL+1;
        }

        A->info = aux->info;
        A->der = EliminarAVL(A->der, aux->info);
        OperAVL=OperAVL+5;
    }
    else
    {
        OperAVL=OperAVL+1;
        if (x < A->info)
        {
            A->izq = EliminarAVL(A->izq, x);
            A->izq = ActualizarAltura(A->izq);
            A->izq = Balancear(A->izq);
            OperAVL=OperAVL+6;
        }
        else
        {
            A->der = EliminarAVL(A->der, x);
            A->der = ActualizarAltura(A->der);
            A->der = Balancear(A->der);
            OperAVL=OperAVL+6;
        }
    }
    return A;
}

int EstaAVL(AVL A, int x){
	OperAVL=OperAVL+1;
    if(VacioAVL(A))
        return 0;
    OperAVL=OperAVL+1;
    if(x == (A->info))
        return 1;
    OperAVL=OperAVL+2;
    if(x < (A->info))
    	return EstaAVL(A->izq, x);
    else
        return EstaAVL(A->der, x);
}

/*int AlturaAVL(AVL A){
    int j,k;
    if(VacioAVL(A))
        return 0;
    else{
        j=AlturaAVL(A->izq);
        k=AlturaAVL(A->der);
        printf("j=%d k=%d\n",j,k);
        return Maximo(j,k );   
    }
}*/

int AlturaAVL(AVL A){
	int AltIzq, AltDer;
 	OperAVL=OperAVL+1;
 	if(VacioAVL(A))
 		return 0;
 	else{
 		OperAVL=OperAVL+2;
 		AltIzq = 1 + AlturaAVL(A->izq);
 	 	AltDer = 1 + AlturaAVL(A->der);
 	 	if (AltIzq > AltDer)
 	 		return AltIzq;
 	 	else
 	 		return AltDer;
 }
}

AVL Insertar_Archivo_AVL(char * Arch, AVL A){
	FILE * Archivo;
	int valaux=0;//Variable tendrá el valor de el numero sacado del archivo ins
	char saux[100];//Variable para sacar el dato del archivo ins
	Archivo=fopen(Arch,"r");
	if(Archivo!=NULL){
		while(feof(Archivo)==0){//Ciclo para recorrer el archivo hasta que termine
			fgets(saux,100,Archivo);//Toma de dato del archivo ins
			if(feof(Archivo)==0){//If para controlar que el fgets no tome el salto de la ultima linea del archivo ins
				saux[strlen(saux)-1]=0;//Se le quita el salto de linea a la cadena y se le asigna 0 que es final de cadena
				valaux=atoi(saux);//Transformación de la cadena a entero
				OperAVL=OperAVL+1;
				A=InsertarAVL(A,valaux);
			}
		}
		fclose(Archivo);
	}
	else
		printf("No se encontró el archivo %s.\n",Arch);
	return A;
}

AVL Eliminar_Archivo_AVL(char * Arch, AVL A){
	FILE * Archivo;
	int valaux=0;//Variable tendrá el valor de el numero sacado del archivo ins
	char saux[100];//Variable para sacar el dato del archivo ins
	Archivo=fopen(Arch,"r");
	if(Archivo!=NULL){
		while(feof(Archivo)==0){//Ciclo para recorrer el archivo hasta que termine
			fgets(saux,100,Archivo);//Toma de dato del archivo ins
			if(feof(Archivo)==0){//If para controlar que el fgets no tome el salto de la ultima linea del archivo ins
				saux[strlen(saux)-1]=0;//Se le quita el salto de linea a la cadena y se le asigna 0 que es final de cadena
				valaux=atoi(saux);//Transformación de la cadena a entero
				OperAVL=OperAVL+1;
				if(EstaAVL(A,valaux)){
					OperAVL=OperAVL+1;
					A=EliminarAVL(A,valaux);
				}
				else
					printf("%d NO está en el AVL.\n",valaux);
			}
		}
		fclose(Archivo);
	}
	else
		printf("No se encontró el archivo %s.\n",Arch);
	return A;
}

AVL Buscar_Archivo_AVL(char * Arch, AVL A){
	FILE * Archivo;
	int valaux=0;//Variable tendrá el valor de el numero sacado del archivo ins
	char saux[100];//Variable para sacar el dato del archivo ins
	Archivo=fopen(Arch,"r");
	if(Archivo!=NULL){
		while(feof(Archivo)==0){//Ciclo para recorrer el archivo hasta que termine
			fgets(saux,100,Archivo);//Toma de dato del archivo ins
			if(feof(Archivo)==0){//If para controlar que el fgets no tome el salto de la ultima linea del archivo ins
				saux[strlen(saux)-1]=0;//Se le quita el salto de linea a la cadena y se le asigna 0 que es final de cadena
				valaux=atoi(saux);//Transformación de la cadena a entero
				OperAVL=OperAVL+1;
				if(EstaAVL(A,valaux))
					printf("%d está en AVL.\n",valaux);
				else
					printf("%d NO está en AVL.\n",valaux);

			}
		}
		fclose(Archivo);
	}
	else
		printf("No se encontró el archivo %s.\n",Arch);
	return A;
}

/////////////////////////////////MAIN

int main(){
	ABO A=NULL;
	AVL B=NULL;
	int Opcion;
	char arch[100];
	do{
		printf("\n\t\tMENU\n\n1. Insertar un elemento.\n2. Eliminar un elemento.\n3. Consultar la presencia de un elemento.\n4. Altura.\n5. Salir.");
			printf("\n\nIngrese una opción: ");
			scanf("%d",&Opcion);
			switch(Opcion)
				{
				case 1:
					printf("Ingrese el nombre del archivo: ");
					scanf("%s",arch);
					OperABO=1;
					OperAVL=1;
					A=Insertar_Archivo_ABO(arch, A);
					B=Insertar_Archivo_AVL(arch, B);
					printf("Números insertados.\n");
					printf("Número de operaciones de inserción ABO: %ld\n",OperABO);
					printf("Número de operaciones de inserción AVL: %ld\n",OperAVL);
					break;
				case 2:
					printf("Ingrese el nombre del archivo: ");
					scanf("%s",arch);
					OperABO=1;
					OperAVL=1;
					A=Eliminar_Archivo_ABO(arch, A);
					B=Eliminar_Archivo_AVL(arch, B);
					printf("Números eliminados.\n");
					printf("Número de operaciones de eliminación ABO: %ld\n",OperABO);
					printf("Número de operaciones de eliminación AVL: %ld\n",OperAVL);
					break;
				case 3:
					printf("Ingrese el nombre del archivo: ");
					scanf("%s",arch);
					OperABO=1;
					OperAVL=1;
					A=Buscar_Archivo_ABO(arch, A);
					printf("\n");
					B=Buscar_Archivo_AVL(arch, B);
					printf("Número de operaciones de busqueda ABO: %ld\n",OperABO);
					printf("Número de operaciones de busqueda AVL: %ld\n",OperAVL);
					break;
				case 4:
					printf("La altura del ABO es: %d\n",AlturaABO(A));
					printf("La altura del AVL es: %d\n",AlturaAVL(B));
					break;
				case 5:
					break;
				case 6://////ELIMINAR ESTE CASO
					InOrdenABO (A);
					printf("\n");
					InOrdenAVL (B);
					break;
				default:
					break;
			      }
	}while(Opcion!=5);

	return 0;
}