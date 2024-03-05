#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct pilas{
	int d;
	pilas *a;
} *c,*e;
 

void ingresar (void){
 	
	if(!c){
		c=new(pilas);
		cout<<"\nIngrese elemento: ";
		cin>>c->d;
		c->a=NULL;
		return;
	}
 
 	e=new(pilas);
 	cout<<"\nIngrese elemento: ";
 	cin>>e->d;
 	e->a=c;
 	c=e;
}

void ultimo(void){
    if(c == NULL){
        cout << "\nLa pila esta vacia, no hay elementos para ser mostrar.";
    } else {
        e = c;
        while(e != NULL){
            if(e->a == NULL){
                cout << "\nEl primer dato ingresado fue: " << e->d;
            }
            e = e->a; //contador
        }
    }
}

void sacar(void){
	if(!c){
 		cout<<"\n\nNo hay elementos!!";
 		return;
 	}
 
 	e=new(pilas);
 	e=c;
 	cout<<"\n\nElemento eliminado: " <<e->d;
 	c=e->a;
 	delete(e);
}


void actualizar_pila(void){
 	int y=2,i,ca=0;
 	e=c;

 	while(e){
 		ca++;
 		e=e->a;
 	}
 
	for(i=0;i<=ca;i++){
 		cout<<" ";
 	}
 	
	 //muestro lo que tiene la pila!!
 	i=0;
 	e=c;
 	
	while(e){
 		cout<<"\n";
 		cout<<++i<<" - "<<e->d;
 		e=e->a;
 	}
}

bool estaVacia(void){
    if(c == NULL){
        return true;
    } else {
        return false;
    }
}

int contarElementos(void){
    int contador = 0;
    pilas* temp = c;
    while(temp != NULL){
        contador++;
        temp = temp->a;
    }
    return contador;
}

void vaciarPila(void){
    while(c != NULL){
        pilas* temp = c;
        c = c->a;
        delete temp;
    }
    cout << "\nLa pila ha sido vaciada.";
}


void menu(void){
    int y,opc;
    
    for(;;){
        cout<<"\n1. Ingresar datos";
        cout<<"\n2. Extraer datos";
        cout<<"\n3. Ver el ultimo elemento";
        cout<<"\n4. Verificar si la pila esta vacia";
        cout<<"\n5. Contar los elementos en la pila";
        cout<<"\n6. Vaciar la pila";
        cout<<"\n0. Terminar";
        cout<<"\n\nIngrese opcion: ";
        cin>>opc;
        
        switch(opc){
        
        case 1:
            ingresar();
        break;
        
        case 2: 
            sacar();
        break;
        
        case 3: 
            ultimo();
        break;

        case 4:
            if(estaVacia()){
                cout << "\nLa pila esta vacia.";
            } else {
                cout << "\nLa pila no esta vacia.";
            }
        break;

        case 5:
            cout << "\nHay " << contarElementos() << " elementos en la pila.";
        break;
        
        case 6:
            vaciarPila();
        break;
        
        case 0: 
            exit(1);
        	default: cout<<"\n\nOpcion no valida!!"; 
        break;
        }

        actualizar_pila();
        cout<<"\n\nOprima una tecla para continuar\n";
        getch();
        system ("cls");
    }
}
 
main(){
	menu();
}
