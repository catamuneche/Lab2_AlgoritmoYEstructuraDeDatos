# Lab2_AnalisisYDisenoDeAlgoritmos

Enunciado. 
 
Generar un programa que muestre el menú de la figura 1, para que el usuario pueda realizar las operaciones de Inserción, Eliminación, Búsqueda y Cálculo de Altura, sobre dos tipos de Árboles Binarios de Búsqueda: un ABO y un ABO Balanceado por altura (AVL).  
 
=================================================== 
MENU 
===================================================
1. Insertar un elemento. 
2. Eliminar un elemento. 
3. Consultar la presencia de un elemento. 
4. Altura. 
5. Salir. 
 
   Ingrese una opción: _ 
=================================================== 

Se debe realizar cada una de las siguientes funciones:  
 
Opción 1: Inserción. En esta opción se espera que usted implemente las funciones de inserción para ABO (“Apuntes Nº6 (TDA Árboles Binarios Ordenados).pptx”) y para AVL (“Apuntes Nº8 (TDA AVL).pptx”). No debe modificar los algoritmos (ni siquiera para hacerlos más eficientes). 
 
Opción 2: Eliminación. En esta opción se espera que usted implemente las funciones de eliminación para ABO (“Apuntes Nº6 (TDA Árboles Binarios Ordenados).pptx”), en particular el algoritmo del caso 3; y para AVL (“Apuntes Nº8 (TDA AVL).pptx”). No debe modificar los algoritmos (ni siquiera para hacerlos más eficientes). 
Algoritmos y Estructuras de Datos 

Opción 3: Buscar un elemento. Como sabe un AVL también es un ABO que cuida su condición de estar balanceado. Por este motivo, la función que se solicita implemente en esta opción, corresponde al mismo algoritmo: El de búsqueda sobre un ABO. (“Apuntes Nº6 (TDA Árboles Binarios Ordenados).pptx”). 
 
Opción 4: Altura. Para realizar este cálculo notará que se realiza de la misma forma, independiente del orden que tenga la información dentro del Árbol Binario. Es decir, esta función es la misma para un AB, para un ABO y para un AVL y corresponde a: 
 
Num Altura(ArbolBinario A) {     
	SI (Vacio?(A)) ENTONCES         
		RETORNAR 0;     
	SINO         
		RETORNAR máximo(Altura(Izq(A)), Altura(Der(A))); 
}