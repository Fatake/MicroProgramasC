#include<stdio.h>
#include<stdlib.h>
#include<string.h>

FILE *archivo;

char *gets(char *s);

/*se escojio 2 estructuras para recolectar datos de manera dinamica(usando memoria dinamica y listas doblemente enlazadas) las estructuras
se tomaran como entidades para la base de datos*/

typedef struct dato_cliente{//entidad dato cliente
	char nombre[50];// nombre del cliente
	char nevento[5];//llave foranea de dato de funcion
	float costo;//precio final
	char tipo[10];
	char cel[10];//celular del cliente
	char tarjeta[16];// tarjeta del cliente
	char pin[3];// pin de la tarjeta
	char email[50];//correo electronico del cliente
	char password[16];//llave primaria
	char ine[13];// ine del cliente
	char vencimiento[5];//frcha de vencimiento del cliente
	char nivel[12];//zona elegida
	struct dato_cliente *sig1;//apuntador a la siguiente poscicion
	char *acientos;
}persona;// variable de control

typedef struct dato_funcion{// detalles de la funcion
	char clave[5];//llave primaria
        char presentador[50];// nombre del presentador
	char fecha[8];// fecha para precentar
	float horai;//hora de entrada
	float horaf;//hora de salida
	float duracion;//duracion de la funcion
	char passwd[16];//llave foranea de dato cliente
	char luneta[100];//zona disponible para la funcion
	char primer[50];//zona disponible para la funcion
	char palcos[200];//zona disponible para la funcion
	char galeria[500];//zona disponible para la funcion
	char estado[11];//estado de la funcion(disponibles o cupo lleno
	int cl;
	int cpr;
	int cpa;
	int cg;
	struct dato_funcion *sig2;//apuntador a la siguiente poscicion
}ponente;//variable de control

persona *pprimero = NULL;//punteros para listas
persona *pultimo = NULL;
persona *d_usuario;
persona *d2_usuario;
ponente *poprimero = NULL;//punteros para listas
ponente *poultimo = NULL;
ponente *d_ponente = NULL;

void agregar_persona(persona *nodo){//funcion para agregar nodos de persona
	nodo->sig1 = NULL;
	if(pprimero == NULL){
		pprimero = nodo;
		pultimo = nodo;
	}
	else{
		pultimo->sig1 = nodo;
		pultimo = nodo;
	}
}

void agregar_presentador(ponente *nodo2){//funcion para agregar nodos de presentador
	nodo2->sig2 = NULL;
	if(poprimero == NULL){
		poprimero = nodo2;
		poultimo = nodo2;
	}
	else{
		poultimo->sig2 = nodo2;
		poultimo = nodo2;
	}
}

int inicio(persona *var1){// funcion de inicio con argumento de tipo persona
	int modo,des,conteo = 1, error, control;
	char correo[50], contra[24];

	do{
	system("clear");
	printf("\n\n\n\t\t\t\t\t ****Sistema de venta de boletos****\n");
	printf("\t1)Tengo cuenta\n\t2)NO tengo cuenta\n\t3)Apagar sistema\n---->");
	scanf("%i",&des);
	setbuf(stdin,NULL);
	setbuf(stdin,NULL);
	switch(des){
		case 1: 
			do{
				setbuf(stdin,NULL);
                        	printf("correo electronco:\n---->");
                        	gets(correo);
				setbuf(stdin,NULL);
                        	setbuf(stdin,NULL);
                        	printf("contraseña:\n---->");
                        	gets(contra);
                        	setbuf(stdin,NULL);
				setbuf(stdin,NULL);
                        	if(strcmp(correo, "root") == 0 && strcmp(contra, "toor") == 0){
                                	modo = 1;//modo administrador
					error = 0;
					conteo = 4;
                        	}
                        	else{
					persona *bus = pprimero;
					while((bus != NULL) && (control != 1)){
						if((strcmp(correo,bus->email) == 0) && (strcmp(contra,bus->password))== 0){
							d_usuario = bus;
							control = 1;
							modo = 2;
							error = 0;
							conteo = 4;
						}
						bus = bus->sig1;
					}
						if( control == 1){
							break;
						}
                				else{
                                         		printf("usuario y/o contraseña erroneos, te quedan %i intento(s)\n",3-conteo);
                                         		conteo++;//conteo de intentos
                                         		error = 1;//manda error
						}
        				}
                	}while(conteo <= 3);
			break;
		case 2: modo = 3;//modo cliente
			error =0;
			break;
		case 3: modo = 4;
			error = 0;
			break;
		default: printf("opcion no valida...");
			error = 1;
			break;

	}
	}while(error == 1);
	return modo;
}

int registroeve(ponente *var2){ //funcion para llenar los campos con argumento de tipo ponente
	int salir;
		system("clear");
		setbuf(stdin,NULL);
		printf("ingrese el nombre del presentador: ");
		gets(var2->presentador);
		setbuf(stdin,NULL); //vacia el buffer
		printf("ingrese la fecha a presentar(ingresela en formato dd/mm/aa incluyendo las diagonales): ");
		gets(var2->fecha);
		setbuf(stdin,NULL);
		printf("ingrese la hora en que se presentara: ");
		scanf("%f",&var2->horai);
		setbuf(stdin,NULL);
		setbuf(stdin,NULL);
		printf("ingrese la duracion del evento: ");
		scanf("%f",&var2->duracion);
		setbuf(stdin,NULL);
		setbuf(stdin,NULL);
		var2->horaf = var2->horai + var2->duracion;
		setbuf(stdin,NULL);
		setbuf(stdin,NULL);
		printf("ingrese una clave alfanumerica (solo 4 caracteres): ");
		gets(var2->clave);
		setbuf(stdin,NULL);
		setbuf(stdin,NULL);
		if((archivo = fopen("dato_presentador.bin", "a+b")) != NULL){
			fwrite(var2,sizeof(ponente),1,archivo);
			fclose(archivo);
		}
		else{
			printf("error al crear o abrir");
		}
		printf("¿desea ingresar un nuevo evento? si = 1, no = 0 \n");
		scanf("%i",&salir);
		setbuf(stdin,NULL);
	return salir;
}

void borrado(ponente *lugar){ 
	for(int i = 0; i < 100; i++){
		lugar->luneta[i] = '0';
	}
	for(int i = 0; i < 50; i++){
		lugar->primer[i] = '0';
	}
	for(int i = 0; i < 200; i++){
                lugar->palcos[i] = '0';
        }
	for(int i = 0; i < 500; i++){
                lugar->galeria[i] = '0';
        }
}

int metodo;

float datos_personales(persona *var4){
	int error1, des1, a, porciento, error2;
	char c1[24], c2[24];

	system("clear");
	printf("Ingrese los datos que le pedimos para crearle un perfil de compra, porfavor ingrese bien su contraseña, de lo\n");
	printf("contrario se volveran a pedir el campo de la contraseña\n");
	printf("ingrese un correo electronico:\n---->");
	gets(var4->email);
	setbuf(stdin,NULL);
	do{
		printf("proporcione una contraseña: ");
		gets(c1);
		setbuf(stdin,NULL);
		printf("ingrese nuevamente su contraseña: ");
		gets(c2);
		setbuf(stdin,NULL);
	}while(strcmp(c1,c2) != 0);
	setbuf(stdin,NULL);
	strcpy(var4->password,c1);
	printf("ingrese nombre del cliente: ");
	gets(var4->nombre);
	setbuf(stdin,NULL);
	printf("ingrese el folio de INE: ");
	gets(var4->ine);
	setbuf(stdin,NULL);
	printf("ingrese el numero telefonico del cliente: ");
	gets(var4->cel);
	setbuf(stdin,NULL);
	do{
	printf("tipo:\n\t1)Entero\n\t2)insen\n\t3)trabador o estudiante\n---->");
	scanf("%i",&a);
	switch(a){
		case 1: porciento = 1;
			error2 = 0;
			break;
		case 2: porciento = 0.4;
			error2 = 0;
			break;
		case 3: porciento = 0.5;
			error2 = 0;
			break;
		default: printf("tipo de cliente no especificado\n");
			error2 = 1;
	}
	}while(error2 == 1);
	do{
		printf("Metodos de pago:\n\t1)Efectivo\n\t2)Targeta de credito o Debito\n");
		scanf("%i",&metodo);
		setbuf(stdin,NULL);
		switch(metodo){
			case 1: error1 = 0;
				break;
			case 2: do{
					printf("ingrese el numero de tarjeta: ");
					gets(var4->tarjeta);
					setbuf(stdin,NULL);
					printf("ingrese el pin de seguridad de la tarjeta: ");
					gets(var4->pin);
					setbuf(stdin,NULL);
					printf("ingrese la fecha de vigencia: ");
					gets(var4->vencimiento);
					setbuf(stdin,NULL);
					printf("¿son correctos los datos? s=1 o n=0\n");
					scanf("%i",&des1);
					setbuf(stdin,NULL);
				}while(des1 == 0);
				error1 = 0;
				break;
			default: printf("opcion no valida...\n");
				error1 = 1;
				break;
		}
	}while(error1 == 1);
	return porciento;
}

void zluneta(ponente *zona1){ //pasar a nueva version
	int b = 0;

	printf("usted escogio la zona luneta.\nAcotaciones: [x]ocupado [0]vacio [R]elegido(s)\n\n\n");
	for(int a = 0; a < 6; a++){
		printf("\t \t \t \t \t ");
		while(b < (a * 20)){
			printf("[%c]",zona1->luneta[b]);
			b++;
		}
		printf("\n");
	}
}

void zprimer(ponente *zona2){ //pasar a nueva version
	int a = 0;

	printf("usted escogio la zona de primer nivel.\n\n\n");
	for(int j = 0; j < 5; j++){
		printf("\t \t \t \t ");
                for(int i = 0; i < 20; i++){
                        if(i >= 2 && i <= 17)
                                printf(" / ");
                        else{
                             	printf("[%c]",zona2->primer[a]);
                                a++;
                        }
                        if(i == 19)
                        printf("\n");
                }
        }
	printf("\t \t \t \t ");
	for(int b = 20; b < 50; b++){
                printf("[%c]",zona2->primer[b]);
		if(b == 39)
		printf("\n\t \t \t \t ");
        }
	printf("\n");

}

void zpalcos(ponente *zona3){//pasar a nueva version
	int a = 0;

        printf("usted escogio la zona de palcos.\n\n\n");
        for(int j = 0; j <= 10; j++){
                printf(" \t \t ");
                for(int i = 0; i < 40; i++){
                        if(i >= 5 && i <= 34)
                                printf(" / ");
                        else{
                             	printf("[%c]",zona3->palcos[a]);
                                a++;
                        }
                        if(i == 39)
                        printf("\n");
                }
        }
	printf(" \t \t ");
        for(int b = 100; b < 200; b++){
                printf("[%c]",zona3->palcos[b]);
                if(b == 139)
                printf("\n \t \t ");
		else{
			if(b == 179)
				printf("\n \t \t ");}
        }
	printf("\n");
}

void zgaleria(ponente *zona4){//ppasar a nueva version
	int a = 0; int tab = 239;

        printf("usted escogio la zona de palcos.\n\n\n");
        for(int j = 0; j <= 20; j++){
                printf("\t ");
                for(int i = 0; i < 40; i++){
                        if(i >= 5 && i <= 34)
                                printf(" / ");
                        else{
                                printf("[%c]",zona4->galeria[a]);
                                a++;
                        }
                        if(i == 39)
                        printf("\n");
                }
        }
        printf("\t ");
        for(int b = 200; b < 500; b++){
		printf("[%c]",zona4->galeria[b]);
                if(b == tab){
                printf("\n\t ");
		tab = tab + 40;}
	}
	printf("\n");
}

void funciones(ponente *indice){// en verse
	printf("Las funciones disponibles en este teatro son:\n");
	printf("C.funcion| presentador                                     |hora de inicio|hora de salida|Fecha    |Estatus de funcion\n");
	for(indice = poprimero; indice != NULL; indice = indice->sig2 ){
		printf("%-10s",indice->clave);
		printf("%-50s",indice->presentador);
		printf("%-15.2f",indice->horai);
		printf("%-15.2f",indice->horaf);
		printf("%-10s",indice->fecha);
		if((indice->cl+indice->cpr+indice->cpa+indice->cg) == 850){
			printf("cupo lleno");
		}
		else{
			printf("lugares disponibles");
		}
		printf("\n");
	}
}

void cargar_persona(void){
	FILE *archivo2;
	if((archivo2 = fopen("dato_cliente.bin", "rb")) != NULL){
		persona *usuario = (persona*)malloc(sizeof(persona));
		while((fread(usuario,sizeof(persona),1,archivo2)) != 0){
			agregar_persona(usuario);
			usuario = (persona*)malloc(sizeof(persona));
		}
		fclose(archivo2);
	}
}

void cargar_ponente(void){
	FILE *archivo1;
	ponente *presentador;

	if((archivo1 = fopen("dato_presentador.bin","rb")) != NULL){
		presentador = (ponente *)malloc(sizeof(ponente));
		while((fread(presentador,sizeof(ponente),1,archivo1)) != 0){
			agregar_presentador(presentador);
			presentador = (ponente *)malloc(sizeof(ponente));//se agrego(ponente *)
		}
		fclose(archivo1);
	}
}

int main(void){
	float descu;
	int mode, opc, e, asci, seg, confirmar, *num, mod, error_admin = 0, des, control = 0;
	persona *nuevo, *person;
	ponente *nuevo1, *evento = poprimero, *evento2;
	//codigo para la apertura de archivo de personas
	cargar_persona();
	//codigo para la apertura de archivo de funciones
	cargar_ponente();
	do{
		nuevo = (persona *)malloc(sizeof(persona));
		mode = inicio(nuevo);//llamado a la funcion de inicio
	if(mode != 4){
		if(mode == 1){//si mode es igua a 1 entonces se iniciara secion como modo administrador
			free(nuevo);
			do{
				nuevo1 = (ponente *)malloc(sizeof(ponente));//presentador
				borrado(nuevo1);
			do{
				system("clear");
				printf("Modo administrador, porfavor escoja una opcion:\n\t1)ingrersar funcion\n\t2)Cancelar funcion\n\t3)salir\n");
				scanf("%i",&mod);
				setbuf(stdin,NULL);
				switch(mod){
					case 1:	opc = registroeve(nuevo1);
						agregar_presentador(nuevo1);
						error_admin = 0;
						break;
					case 2: /*printf("Cancelar Funcion:\n");
						char cadx[5];
						ponente *antes;

						free(nuevo1);
						ponente *registro = poprimero;
						funciones(registro);
						printf("ingrese el codigo de la funcion para eliminar funcion: ");
						gets(cadx);
						setbuf(stdin,NULL);
						ponente *busqueda = poprimero;
						while((busqueda != NULL) && (control != 1)){
							if(strcmp(cadx,busqueda->clave) == 0){
								d_ponente = busqueda;
								control = 1;
							}
							antes = busqueda;
							busqueda = busqueda->sig2;
						}
						eliminar_ponente(d_ponente,antes);
						system("clear");
						funciones(registro);
						printf("presione ENTER para continuar...");
						error_admin = 0;*/
						break;
					case 3: //salida
						break;
					default: printf("opcion no valida, presione ENTER para continuar...");
						getchar();
						setbuf(stdin,NULL);
						error_admin = 1;
				}
			}while(error_admin == 1);
			}while(opc != 0);
		}
		else{
			if(mode == 2){//si el mode es igual a 2 se iniciara sesion
				free(nuevo);//se libera memoria que no se ocupara con funcion free
				person = d_usuario;
				printf("Menu\n\t1)Comprar boletos\n\t2)cambiar perfil");//se muestran opciones
				scanf("%i",&des);//se lee la opcion
				switch(des){
					case 1: break;//sale del switch
					case 2: datos_personales(person);
						break;
				}
			}
			else{//si mode es 3 entonces se registraran los datos para crea una cuenta
				nuevo = (persona *)malloc(sizeof(persona));
				descu = datos_personales(nuevo);//llenado de los datos
				agregar_persona(nuevo);//se agrega o se anexa segun el caso
				if((archivo = fopen("dato_cliente.bin", "a+b")) != NULL){//se abre el archivo para agregar pero en modo binario
					fwrite(nuevo,sizeof(persona),1,archivo);//se actualiza el archivo
					fclose(archivo);//se cierra el archivo para evitar la perdida de informacion
				}
				else{
					printf("error al intentar abrir el archivo\n");//se manda mensaje si fopen debuelve NULL
				}
			}
		}
		if(mode != 1){//no se permite acceder a esta parte como modo administrador
		system("clear");
		setbuf(stdin,NULL);
		printf("\n\t\t\t\t\t**** Bienvenido al sistema de boletos ****\n\n");
		funciones(evento);
		printf("\n\n\n\n");
		printf("presione enter para poder continuar...");
		getchar();
		setbuf(stdin,NULL);
		printf("\n");
		printf("ingrese la funcion a la que desea entrar: ");
		gets(nuevo->nevento);
		setbuf(stdin,NULL);
		evento = poprimero;
		while((evento != NULL) && (control != 1)){
			if(strcmp(nuevo->nevento,evento->clave)== 0){
				evento2 = evento;
				control = 1;
			}
			evento = evento->sig2;
		}
		printf("Eleccion de Zona:\n\t 1)Luneta\n\t 2)Primer nivel\n\t 3)Palcos\n\t 4)Galeria\n");
		printf("ingrese numero de zona: ");
		scanf("%i",&e);
		switch(e){
			case 1://zona luneta
				strcpy(nuevo->nivel,"Luneta");//
				do{
					float costo = 4708;

					printf("numero de asientos:  ");
        		        	scanf("%i",&asci);
					num = malloc(asci*sizeof(int));
					nuevo->costo = (costo * asci) * descu;
					zluneta(evento2);
					for(int c = 0; c < asci; c++){
						printf("ingrese su o sus asientos: ");
						scanf("%i",&num[c]);
							if(evento2->luneta[num[c]] == '0'){
								evento2->luneta[num[c]] = 'R';
							}
							else{
								if(evento2->luneta[num[c]] == 'x'){
									printf("asiento ocupado\n");
									c--;
								}
							}
					}
						zluneta(evento2);
						printf("¿los lugares son correctos? si = 1 o no = 0\n");
						scanf("%i",&seg);
						if(seg == 0){
							for(int c = 0; c < asci; c++){
								if(evento2->luneta[num[c]] == 'R'){
									evento2->luneta[num[c]] = '0';
								}
								num[c] = '0';
							}
						}
						else{
						if(seg == 1){
							for(int c = 0; c < asci; c++){
								if(evento2->luneta[num[c]] == 'R')
									evento2->luneta[num[c]] = 'x';
							}
						}
						}
				}while(seg != 1);
				for(int ax = 0; ax < 100; ax++){
					if(evento2->luneta[ax] == 'x')
						evento2->cl++;
				}
				break;
			case 2:
				strcpy(nuevo->nivel,"Primer nivel");//
				do{
					float costo = 3500;

					printf("numero de asientos:  ");
        		        	scanf("%i",&asci);
					num = malloc(asci*sizeof(int));
					nuevo->costo = costo * asci * descu;
					zprimer(evento2);
					for(int c = 0; c < asci; c++){
						printf("ingrese su o sus asientos: ");
						scanf("%i",&num[c]);
							if(evento2->primer[num[c]] == '0'){
								evento2->primer[num[c]] = 'R';
							}
							else{
								if(evento2->primer[num[c]] == 'x'){
									printf("asiento ocupado\n");
									c--;
								}
							}
					}
						zprimer(evento2);
						printf("¿los lugares son correctos? si = 1 o no = 0\n");
						scanf("%i",&seg);
						if(seg == 0){
							for(int c = 0; c < asci; c++){
								if(evento2->primer[num[c]] == 'R'){
									evento2->primer[num[c]] = '0';
								}
								num[c] = '0';
							}
						}
						else{
						if(seg == 1){
							for(int c = 0; c < asci; c++){
								if(evento2->primer[num[c]] == 'R')
									evento2->primer[num[c]] = 'x';
							}
						}
						}
				}while(seg != 1);
				for(int bx = 0; bx < 50; bx++){
					if(evento2->primer[bx] == 'x')
						evento2->cpr++;
				}
				break;
			case 3: 
				strcpy(nuevo->nivel,"Palcos");//
				do{
					float costo = 2825;

					printf("numero de asientos:  ");
        		        	scanf("%i",&asci);
					num = malloc(asci*sizeof(int));
					nuevo->costo = costo * asci * descu;
					zpalcos(evento2);
					for(int c = 0; c < asci; c++){
						printf("ingrese su o sus asientos: ");
						scanf("%i",&num[c]);
							if(evento2->palcos[num[c]] == '0'){
								evento2->palcos[num[c]] = 'R';
							}
							else{
								if(evento2->palcos[num[c]] == 'x'){
									printf("asiento ocupado\n");
									c--;
								}
							}
					}
						zpalcos(evento2);
						printf("¿los lugares son correctos? si = 1 o no = 0\n");
						scanf("%i",&seg);
						if(seg == 0){
							for(int c = 0; c < asci; c++){
								if(evento2->palcos[num[c]] == 'R'){
									evento2->palcos[num[c]] = '0';
								}
								num[c] = '0';
							}
						}
						else{
						if(seg == 1){
							for(int c = 0; c < asci; c++){
								if(evento2->palcos[num[c]] == 'R')
									evento2->palcos[num[c]] = 'x';
							}
						}
						}
				}while(seg != 1);
				for(int cx = 0; cx < 200; cx++){
					if(evento2->palcos[cx] == 'x')
						evento2->cpa++;
				}
				break;
			case 4: 
				strcpy(nuevo->nivel,"Galeria");//
				do{
					float costo = 1500;

					printf("numero de asientos:  ");
        		        	scanf("%i",&asci);
					num = malloc(asci*sizeof(int));
					nuevo->costo = costo * asci * descu;
					zgaleria(evento2);
					for(int c = 0; c < asci; c++){
						printf("ingrese su o sus asientos: ");
						scanf("%i",&num[c]);
							if(evento2->galeria[num[c]] == '0'){
								evento2->galeria[num[c]] = 'R';
							}
							else{
								if(evento2->galeria[num[c]] == 'x'){
									printf("asiento ocupado\n");
									c--;
								}
							}
					}
						zgaleria(evento2);
						printf("¿los lugares son correctos? si = 1 o no = 0\n");
						scanf("%i",&seg);
						if(seg == 0){
							for(int c = 0; c < asci; c++){
								if(evento2->galeria[num[c]] == 'R'){
									evento2->galeria[num[c]] = '0';
								}
								num[c] = '0';
							}
						}
						else{
						if(seg == 1){
							for(int c = 0; c < asci; c++){
								if(evento2->galeria[num[c]] == 'R')
									evento2->galeria[num[c]] = 'x';
							}
						}
						}
				}while(seg != 1);
				for(int dx = 0; dx < 500; dx++){
					if(evento2->galeria[dx] == 'x')
						evento2->cg++;
				}
				break;
			default: printf("zona no existente\n");
				break;
		}
		system("clear");
		printf("\nconfirmacion de datos: \n");
		for(int in = 0; in < 50; in++){
			printf("-");
		}
		printf("\nnombre: %s",nuevo->nombre);
		printf("\nEvento: %s",evento2->presentador);
		printf("\nnivel: %s",nuevo->nivel);
		printf("\ntotal a pagar: %.2f",nuevo->costo);
		printf("\ntelefono del cliente: %10s\n",nuevo->cel);
		printf("Correo electronico del cliente: %s",nuevo->email);
		printf("\nnumero de INE del cliente: %s",nuevo->ine);
		printf("\nasientos:");
		for(int bol = 0; bol < asci; bol++){
			printf("%d ",num[bol]);
		}
		printf("\n");
		printf("¿desea confirmar los datos? si = 1 o no = 0\n");
		scanf("%i",&confirmar);
		if((archivo = fopen("dato_cliente.bin", "a+b")) != NULL){
			fwrite(nuevo,sizeof(persona),1,archivo);
      			fclose(archivo);
		}
		else{
			printf("error al acrualizar en el archivo\n");
		}
		ponente *final;
		final = poprimero;
		if((archivo = fopen("dato_presentador.bin", "wb")) != NULL){
			while(final != NULL){
                		fwrite(evento2,sizeof(ponente),1,archivo);
				final = final->sig2;
			}
			fclose(archivo);
		}
		else{
			printf("error al actualizar el archivo\n");
		}
		if(metodo == 1){
				float total = nuevo->costo, paga;
			do{
				printf("total : %.2f",total);
				scanf("%f",&paga);
				total = total - paga;
				//au = valor_abs(total);
//				total = au;
			}while(total > 0);
		}
		else{
			setbuf(stdin,NULL);
			printf("realizando transaccion....");
			getchar();
			printf("transaccion realizada\n");
		}
	}//fin de la condicional(mode != 4)
	}//fin del la condicional(mode != 1)
	}while(mode != 4);
	system("clear");
	return 0;
}
