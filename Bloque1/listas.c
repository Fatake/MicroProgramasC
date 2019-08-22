#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define N 300  //cantidad de caracteres para el espacio en memoria para las cadenas
#define M 30   //cantidad de caracteres para las cadenas

typedef struct direccion{
 
	char calle[N];
	char numero[N];
 
} _direccion;

typedef struct contact {
 
	char name[N];
	char number[N];
	char mail[N];
	_direccion address;
	struct contact *next;
 
} Contact;

Contact *head = NULL;
Contact *tail = NULL;

void imprimirSeparador(){
	printf("=================================\n");
}

void imprimirOpciones() {
    imprimirSeparador();
    printf("Agenda\n");
    printf("======\n");
    printf("1. Agregar contacto\n");
    printf("2. Mostrar contactos\n");
    printf("3. Mostrar contactos por letra\n");
    printf("4. Buscar contactos por nombre\n");
    printf("5. Buscar contactos por teléfono\n");
    printf("6. Eliminar contacto por nombre\n");
    printf("7. Eliminar todos los contactos\n");
    printf("8. Salir\n");
    imprimirSeparador();    
}

//se encarga de leer nombre, teléfono, mail y dirección del contacto que se desea agregar,
//llama a nuevoContactoLista(...) para agregarlo a la lista de ser posible y
//finalmente comunica al usuario el resultado de la operación
void nuevoContacto(){
	Contact *new; 
	new = (Contact *)malloc(sizeof(Contact));
	imprimirSeparador();
	printf("Contacto nuevo\n");
	printf("==============\n");
	printf("Nombre: ");
	scanf("%s", new->name);
	while(strlen(new->name) > M){ 			//si la cadena es demasiado larga
		imprimirSeparador();
		printf("El nombre es demasiado largo. Intenta nuevamente con uno más corto.\n");
		printf("Nombre: ");
		scanf("%s", new->name);
	}
	printf("Teléfono: ");
	scanf("%s", new->number);
	while(strlen(new->number) > M){ 		//si la cadena es demasiado larga
		imprimirSeparador();
		printf("El número de teléfono es demasiado largo. Intenta nuevamente con uno más corto.\n");
		printf("Teléfono: ");
		scanf("%s", new->number);
	}
	printf("Mail: ");
	scanf("%s", new->mail);
	while(strlen(new->mail) > M){ 			//si la cadena es demasiado larga
		imprimirSeparador();
		printf("El mail es demasiado largo. Intenta nuevamente con uno más corto.\n");
		printf("Mail: ");
		scanf("%s", new->mail);
	}
	printf("Dirección: ");
	scanf("%s%s", new->address.calle, new->address.numero);
	while(strlen(new->address.calle) > M || strlen(new->address.numero) > M){ //si la cadena es demasiado larga
		imprimirSeparador();
		printf("La dirección es demasiado larga. Intenta nuevamente con una más corta.\n");
		printf("Dirección: ");
		scanf("%s%s", new->address.calle, new->address.numero);
	}
	imprimirSeparador();
	nuevoContactoLista(new->name, new->number, new->mail, new->address.calle, new->address.numero);
	free(new);
}

//recibe como argumento nombre, teléfono, mail y dirección del contacto que se desea agregar,
//si no existe ningún otro contacto con el mismo nombre lo agrega a la lista
void nuevoContactoLista(char name[], char number[], char mail[], _direccion addressCalle[], _direccion addressNumero[]){
	Contact *contactoNuevo, *aux;
	contactoNuevo = (Contact *)malloc(sizeof(Contact));
	aux = head;
	while(aux != NULL) {
			if((strcmp(aux->name, name)) == 0){
				printf("El nombre de contacto ingresado ya existe.\n");
				return;
			}
			else{
				aux = aux->next;
			}
	}
	if(aux == NULL){
		strcpy(contactoNuevo->name, name);
	}
	aux = head;
	while(aux != NULL) {
			if((strcmp(aux->number, number)) == 0){
				printf("El número de teléfono ingresado ya existe.\n");
				return;
			}
			else{
				aux = aux->next;
			}
	}
	if(aux == NULL){
		strcpy(contactoNuevo->number, number);
	}
	strcpy(contactoNuevo->mail, mail);
	strcpy(contactoNuevo->address.calle, addressCalle);
	strcpy(contactoNuevo->address.numero, addressNumero);
	contactoNuevo->next = NULL;
	if(head == NULL){ 
		head = contactoNuevo;
	}
	else{
        tail->next = contactoNuevo;
	}
    tail = contactoNuevo;
    printf("La información del contacto ha sido guardada exitosamente.\n"); 
}
//imprime contactos
void imprimirContactos(){ 
	Contact *auxiliar;
	int TAM;
	imprimirSeparador();
	//TAM = cantidad de contactos
	auxiliar = head;
	TAM = 0;
	while(auxiliar != NULL) {
		auxiliar = auxiliar->next;
		TAM++;
	}
	//Ordenamiento de burbuja: ordena alfabéticamente los contactos
	if(head != NULL){
		Contact *first = NULL, *second = NULL, *auxi = NULL;
		first = head;
		while(first != tail){
			second = first->next;
			while(second != NULL){
				if(strcmp(first->name, second->name) > 0){	
					strcpy(auxi->name, first->name);						
					strcpy(auxi->number, first->number);
					strcpy(auxi->mail, first->mail);
					strcpy(auxi->address.calle, first->address.calle);
					strcpy(auxi->address.numero, first->address.numero);
 
					strcpy(first->name, second->name);
					strcpy(first->number, second->number);
					strcpy(first->mail, second->mail);
					strcpy(first->address.calle, second->address.calle);
					strcpy(first->address.numero, second->address.numero);
 
					strcpy(second->name, auxi->name);
					strcpy(second->number, auxi->number);
					strcpy(second->mail, auxi->mail);
					strcpy(second->address.calle, auxi->address.calle);
					strcpy(second->address.numero, auxi->address.numero);
				}
				second = second->next;
			}
			first = first->next;
		}
	}
	auxiliar = head;
	printf("Contactos\n");
	while(auxiliar != NULL) {
		printf("=========\n");
		printf("Nombre:    %s\nTeléfono:  %s\nMail:      %s\nDirección: %s %s\n", auxiliar->name, auxiliar->number, auxiliar->mail, auxiliar->address.calle, auxiliar->address.numero);
		auxiliar = auxiliar->next;
	}
	if(TAM == 0){
		printf("=========\n");
		printf("La agenda está vacía.\n");
	}
 
}
//lee la letra con que se quiere que empiecen los nombres de los contactos que se desean imprimir,
//luego le pasa el caracter a la función encargada de imprimirlos
void imprimirContactosLetra(){
	char c[1];
	imprimirSeparador();
	printf("Ingrese la primera letra de los contactos que desea ver: ");
	scanf("%s", c);
	imprimirContactosLetraLista(c);
 
}
//recibe un caracter e imprime todos los contactos cuyo nombre empieza con ese caracter
void imprimirContactosLetraLista(char c[]){
	Contact *aux;
	int i;
	imprimirSeparador();
	printf("Contactos que empiezan con la letra '%s'\n", c);
	aux = head;
	i = 0;
	while(aux != NULL){
		if(strncmp(aux->name, c, 1) == 0){
			printf("=========\n");
			printf("Nombre:    %s\nTeléfono:  %s\nMail:      %s\nDirección: %s %s\n", aux->name, aux->number, aux->mail, aux->address.calle, aux->address.numero);
			aux = aux->next;
			i++;
		}
		else{
			aux = aux->next;
		}
	}
	if(i == 0){
		printf("=========\n");
		printf("No hay resultados.\n");
	}
 
}
//lee el nombre (o el inicio del mismo) que desea usarse para la búsqueda y se lo pasa a la función encargada de buscar
void buscarContactosNombre(){
	char nam[N];
	imprimirSeparador();
	printf("Ingrese el nombre, o el inicio del mismo, que desea utilizar para la búsqueda de contactos: ");
	scanf("%s", nam);
	buscarContactosNombreLista(nam);
}
//recibe una cadena de caracteres y devuelve los contactos cuyo nombre comienza con dicha cadena
//aclaración: NO debe diferenciar mayúsculas de minúsculas
void buscarContactosNombreLista(char nam[]){
	Contact *aux;
	int i;
	imprimirSeparador();
	printf("Contactos relacionados con '%s'\n", nam);
	aux = head;
	i = 0;
	while(aux != NULL){
		if(strncasecmp(aux->name, nam, strlen(nam)) == 0){
			printf("=========\n");
			printf("Nombre:    %s\nTeléfono:  %s\nMail:      %s\nDirección: %s %s\n", aux->name, aux->number, aux->mail, aux->address.calle, aux->address.numero);
			aux = aux->next;
			i++;
		}
		else{
			aux = aux->next;
		}
	}
 
	if(i == 0){
		printf("=========\n");
		printf("No hay resultados.\n");
	}
}
//lee el teléfono (o el inicio del mismo) que desea usarse para la búsqueda y se lo pasa a la función encargada de buscar
void buscarContactosTelefono(){
	char num[N];
	imprimirSeparador();
	printf("Ingrese el teléfono, o el inicio del mismo, que desea utilizar para la búsqueda de contactos: ");
	scanf("%s", num);
	buscarContactosTelefonoLista(num);
}
//recibe un teléfono (o parte de él) y devuelve los contactos cuyo teléfono empieza con ese número
void buscarContactosTelefonoLista(char num[]){
	Contact *aux;
	int i;
	imprimirSeparador();
	printf("Contactos cuyo teléfono está relacionado con '%s'\n", num);
	aux = head;
	i = 0;
	while(aux != NULL){
		if(strncmp(aux->number, num, strlen(num)) == 0){
			printf("=========\n");
			printf("Nombre:    %s\nTeléfono:  %s\nMail:      %s\nDirección: %s %s\n", aux->name, aux->number, aux->mail, aux->address.calle, aux->address.numero);
			aux = aux->next;
			i++;
		}
		else{
			aux = aux->next;
		}
	}
	if(i == 0){
		printf("=========\n");
		printf("No hay resultados.\n");
	}
}
//lee el nombre del contacto que se desea eliminar, solicita la confirmación del usuario,
//llama a eliminarContactoNombreLista(...) la cual borra el contacto si es que existe y
//finalmente comunica al usuario el resultado de la operación 
void eliminarContactoNombre(){
	Contact *aux = head;
	int i = 0;
	char nom[N];
	int opc;
	imprimirSeparador();
	printf("Ingrese el nombre del contacto que desea eliminar: ");
	scanf("%s", nom);
	imprimirSeparador();
	while(aux != NULL){
		if(strcmp(aux->name, nom) == 0){
			i++;
			printf("¿Está seguro de querer eliminar a '%s' de la agenda?\n", nom);
			printf("1. Sí\n");
			printf("2. No\n");
			imprimirSeparador();
			scanf("%d", &opc);
			switch(opc) {
					case 1:
						eliminarContactoNombreLista(nom);
						break;
					case 2:
						return;
						break;
					default:
						break;
			}
			if(opc == 1){
				imprimirSeparador();
				printf("El contacto '%s' ha sido borrado de la agenda.\n", nom);
			}
			break;
		}	
		else{
			aux = aux->next;
		}
	}
	if(i == 0){
		printf("No existe ningún contacto con el nombre '%s'.\n", nom);
	}
}
//recibe un nombre, si existe algún contacto en la lista con ese nombre lo borra 
void eliminarContactoNombreLista(char nom[]){ 
	 Contact *aux_borrar;
	 Contact *anterior = NULL;
	 aux_borrar = head; 
	 while(strcmp(aux_borrar->name, nom) != 0){ 						//mientras el nombre no coincida con el nombre del contacto
		 anterior = aux_borrar;										 		//se pasará al siguiente contacto
		 aux_borrar = aux_borrar->next;
	 }
	 //salir del while significa que se encontró el contacto cuyo nombre coincide con el ingresado
 
	 if(aux_borrar->next != NULL){										//si el contacto ha ser eliminado NO es el ÚLTIMO
			if(aux_borrar != head){											// si el contacto no es el primero
				anterior->next = aux_borrar->next;							//su anterior seguirá a su sucesor
				free(aux_borrar);											//y el contacto será eliminado
			}
			else{														//si el contacto ES el PRIMERO
				head = aux_borrar->next;									//el segundo se convertirá en el primero
				free(aux_borrar);											//y el contacto será eliminado
			}
	}
	else{ //aux_borrar->next = NULL										//si el contacto ha ser eliminado ES el ÚLTIMO
		if(aux_borrar != head){												//y si no es el primero (hay más contactos)
			anterior->next = NULL;											//su anterior seguirá a NULL
			free(aux_borrar);												//el contacto será eliminado
			tail = anterior;												//y el anterior se convertirá en el último
		}
		else{															//si el contacto es el único (ES el PRIMERO y el ÚLTIMO)
			free(aux_borrar);												//será eliminado
			head = NULL;
			tail = NULL;
		}
	}
}
//solicita la confirmación del usuario antes de borrar todos los contactos,
//en caso de obtenerla llama a eliminarTodosContactosLista(...) y
//finalmente muestra un mensaje apropiado
void eliminarTodosContactos(){
	imprimirSeparador();
	printf("¿Está seguro de querer eliminar todos los contactos de la agenda?\n");
	printf("1. Sí\n");
	printf("2. No\n");
	imprimirSeparador();
	submenuTodosContactos();
}
//sub-menú de la función eliminarTodosContactos() 
void submenuTodosContactos(){
	Contact *auxil;
	int op;
	int i;
	auxil = head;
	i = 0;
	while(auxil != NULL) {
		auxil = auxil->next;
		i++;
	}
	scanf("%d", &op);
	switch(op) {
            case 1:
                eliminarTodosContactosLista();
                break;
            case 2:
                return;
            default:
                break;
        }
        imprimirSeparador();
 
        if(i != 0){
			printf("Todos los contactos de la agenda han sido borrados.\n");
		}
        else {
			printf("No existen contactos en la agenda.\n");
		}
}
//se encarga de borrar todos los nodos de la lista
void eliminarTodosContactosLista(){
 
    Contact *con;
 
    if(head != NULL) {
		while(1) {
        con = head;
        head = head->next;
        free(con);
    }
 
		tail = NULL;
	}
 
}
 
/***************************************************************************************************************************/
 
//liberar memoria al salir
void liberarMemoria(){
 
	imprimirSeparador();
 
	printf("Programa cerrado.\n");
 
	imprimirSeparador();
 
	eliminarTodosContactosLista();
 
}
 
/**************************************************  FUNCIÓN MAIN()  *******************************************************/
 
int main() {
 
    int opcion;
 
    while(1) { 
 
        imprimirOpciones();
 
        scanf("%d", &opcion);
        //while(getchar() != '\n'); acá debería limpiar el buffer para que no caiga en bucle infinito si se iingresa una letra, pero por algún motivo no me funcionó 
correctamente cuando lo utilicé
 
        switch(opcion) {
 
            case 1:
                nuevoContacto();
                break;
            case 2:
                imprimirContactos();
                break;
            case 3:
                imprimirContactosLetra();
                break;
            case 4:
                buscarContactosNombre();
                break;
            case 5:
                buscarContactosTelefono();
                break;
            case 6:
                eliminarContactoNombre();
                break;
            case 7:
                eliminarTodosContactos();
                break;
            case 8:
                liberarMemoria();
                return 0;
            default:
                break;
        }
 
 
    }
 
}
