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
    printf("5. Buscar contactos por tel�fono\n");
    printf("6. Eliminar contacto por nombre\n");
    printf("7. Eliminar todos los contactos\n");
    printf("8. Salir\n");
    imprimirSeparador();    
}

//se encarga de leer nombre, tel�fono, mail y direcci�n del contacto que se desea agregar,
//llama a nuevoContactoLista(...) para agregarlo a la lista de ser posible y
//finalmente comunica al usuario el resultado de la operaci�n
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
		printf("El nombre es demasiado largo. Intenta nuevamente con uno m�s corto.\n");
		printf("Nombre: ");
		scanf("%s", new->name);
	}
	printf("Tel�fono: ");
	scanf("%s", new->number);
	while(strlen(new->number) > M){ 		//si la cadena es demasiado larga
		imprimirSeparador();
		printf("El n�mero de tel�fono es demasiado largo. Intenta nuevamente con uno m�s corto.\n");
		printf("Tel�fono: ");
		scanf("%s", new->number);
	}
	printf("Mail: ");
	scanf("%s", new->mail);
	while(strlen(new->mail) > M){ 			//si la cadena es demasiado larga
		imprimirSeparador();
		printf("El mail es demasiado largo. Intenta nuevamente con uno m�s corto.\n");
		printf("Mail: ");
		scanf("%s", new->mail);
	}
	printf("Direcci�n: ");
	scanf("%s%s", new->address.calle, new->address.numero);
	while(strlen(new->address.calle) > M || strlen(new->address.numero) > M){ //si la cadena es demasiado larga
		imprimirSeparador();
		printf("La direcci�n es demasiado larga. Intenta nuevamente con una m�s corta.\n");
		printf("Direcci�n: ");
		scanf("%s%s", new->address.calle, new->address.numero);
	}
	imprimirSeparador();
	nuevoContactoLista(new->name, new->number, new->mail, new->address.calle, new->address.numero);
	free(new);
}

//recibe como argumento nombre, tel�fono, mail y direcci�n del contacto que se desea agregar,
//si no existe ning�n otro contacto con el mismo nombre lo agrega a la lista
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
				printf("El n�mero de tel�fono ingresado ya existe.\n");
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
    printf("La informaci�n del contacto ha sido guardada exitosamente.\n"); 
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
	//Ordenamiento de burbuja: ordena alfab�ticamente los contactos
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
		printf("Nombre:    %s\nTel�fono:  %s\nMail:      %s\nDirecci�n: %s %s\n", auxiliar->name, auxiliar->number, auxiliar->mail, auxiliar->address.calle, auxiliar->address.numero);
		auxiliar = auxiliar->next;
	}
	if(TAM == 0){
		printf("=========\n");
		printf("La agenda est� vac�a.\n");
	}
 
}
//lee la letra con que se quiere que empiecen los nombres de los contactos que se desean imprimir,
//luego le pasa el caracter a la funci�n encargada de imprimirlos
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
			printf("Nombre:    %s\nTel�fono:  %s\nMail:      %s\nDirecci�n: %s %s\n", aux->name, aux->number, aux->mail, aux->address.calle, aux->address.numero);
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
//lee el nombre (o el inicio del mismo) que desea usarse para la b�squeda y se lo pasa a la funci�n encargada de buscar
void buscarContactosNombre(){
	char nam[N];
	imprimirSeparador();
	printf("Ingrese el nombre, o el inicio del mismo, que desea utilizar para la b�squeda de contactos: ");
	scanf("%s", nam);
	buscarContactosNombreLista(nam);
}
//recibe una cadena de caracteres y devuelve los contactos cuyo nombre comienza con dicha cadena
//aclaraci�n: NO debe diferenciar may�sculas de min�sculas
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
			printf("Nombre:    %s\nTel�fono:  %s\nMail:      %s\nDirecci�n: %s %s\n", aux->name, aux->number, aux->mail, aux->address.calle, aux->address.numero);
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
//lee el tel�fono (o el inicio del mismo) que desea usarse para la b�squeda y se lo pasa a la funci�n encargada de buscar
void buscarContactosTelefono(){
	char num[N];
	imprimirSeparador();
	printf("Ingrese el tel�fono, o el inicio del mismo, que desea utilizar para la b�squeda de contactos: ");
	scanf("%s", num);
	buscarContactosTelefonoLista(num);
}
//recibe un tel�fono (o parte de �l) y devuelve los contactos cuyo tel�fono empieza con ese n�mero
void buscarContactosTelefonoLista(char num[]){
	Contact *aux;
	int i;
	imprimirSeparador();
	printf("Contactos cuyo tel�fono est� relacionado con '%s'\n", num);
	aux = head;
	i = 0;
	while(aux != NULL){
		if(strncmp(aux->number, num, strlen(num)) == 0){
			printf("=========\n");
			printf("Nombre:    %s\nTel�fono:  %s\nMail:      %s\nDirecci�n: %s %s\n", aux->name, aux->number, aux->mail, aux->address.calle, aux->address.numero);
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
//lee el nombre del contacto que se desea eliminar, solicita la confirmaci�n del usuario,
//llama a eliminarContactoNombreLista(...) la cual borra el contacto si es que existe y
//finalmente comunica al usuario el resultado de la operaci�n 
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
			printf("�Est� seguro de querer eliminar a '%s' de la agenda?\n", nom);
			printf("1. S�\n");
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
		printf("No existe ning�n contacto con el nombre '%s'.\n", nom);
	}
}
//recibe un nombre, si existe alg�n contacto en la lista con ese nombre lo borra 
void eliminarContactoNombreLista(char nom[]){ 
	 Contact *aux_borrar;
	 Contact *anterior = NULL;
	 aux_borrar = head; 
	 while(strcmp(aux_borrar->name, nom) != 0){ 						//mientras el nombre no coincida con el nombre del contacto
		 anterior = aux_borrar;										 		//se pasar� al siguiente contacto
		 aux_borrar = aux_borrar->next;
	 }
	 //salir del while significa que se encontr� el contacto cuyo nombre coincide con el ingresado
 
	 if(aux_borrar->next != NULL){										//si el contacto ha ser eliminado NO es el �LTIMO
			if(aux_borrar != head){											// si el contacto no es el primero
				anterior->next = aux_borrar->next;							//su anterior seguir� a su sucesor
				free(aux_borrar);											//y el contacto ser� eliminado
			}
			else{														//si el contacto ES el PRIMERO
				head = aux_borrar->next;									//el segundo se convertir� en el primero
				free(aux_borrar);											//y el contacto ser� eliminado
			}
	}
	else{ //aux_borrar->next = NULL										//si el contacto ha ser eliminado ES el �LTIMO
		if(aux_borrar != head){												//y si no es el primero (hay m�s contactos)
			anterior->next = NULL;											//su anterior seguir� a NULL
			free(aux_borrar);												//el contacto ser� eliminado
			tail = anterior;												//y el anterior se convertir� en el �ltimo
		}
		else{															//si el contacto es el �nico (ES el PRIMERO y el �LTIMO)
			free(aux_borrar);												//ser� eliminado
			head = NULL;
			tail = NULL;
		}
	}
}
//solicita la confirmaci�n del usuario antes de borrar todos los contactos,
//en caso de obtenerla llama a eliminarTodosContactosLista(...) y
//finalmente muestra un mensaje apropiado
void eliminarTodosContactos(){
	imprimirSeparador();
	printf("�Est� seguro de querer eliminar todos los contactos de la agenda?\n");
	printf("1. S�\n");
	printf("2. No\n");
	imprimirSeparador();
	submenuTodosContactos();
}
//sub-men� de la funci�n eliminarTodosContactos() 
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
 
/**************************************************  FUNCI�N MAIN()  *******************************************************/
 
int main() {
 
    int opcion;
 
    while(1) { 
 
        imprimirOpciones();
 
        scanf("%d", &opcion);
        //while(getchar() != '\n'); ac� deber�a limpiar el buffer para que no caiga en bucle infinito si se iingresa una letra, pero por alg�n motivo no me funcion� 
correctamente cuando lo utilic�
 
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
