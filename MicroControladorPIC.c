//Conexiones de LCD a pic
sbit LCD_RS at RD7_bit;
sbit LCD_EN at RD6_bit;
sbit LCD_D4 at RD5_bit;
sbit LCD_D5 at RD4_bit;
sbit LCD_D6 at RD3_bit;
sbit LCD_D7 at RD2_bit;
sbit LCD_RS_Direction at TRISD7_bit;
sbit LCD_EN_Direction at TRISD6_bit;
sbit LCD_D4_Direction at TRISD5_bit;
sbit LCD_D5_Direction at TRISD4_bit;
sbit LCD_D6_Direction at TRISD3_bit;
sbit LCD_D7_Direction at TRISD2_bit;
//fin de conexiones de LCD a pic
// Constantes
#define S_HOME 0
#define S_RESI 1
#define S_VOLT 2
#define S_AMPI 3
#define S_CAPA 4

//Variables
unsigned int estado_actual = S_HOME;
unsigned int b = 1;
int pantalla_menu = 0;
unsigned int ValorDigital, vd2, v2;
unsigned    Voltaje,x;
char     cad2[10];
unsigned long i=0;
char cad[7];
char aux[7];
unsigned int flag = 1;

//Prototipos
void loop();
void pantalla_principal();
void pantalla_capacitancia();
void pantalla_resistencia();
void pantalla_amperaje();
void pantalla_voltaje();
void imprimir_opciones(int numero_pantalla);

/*
 * Funcion main
 */
void main(){
    TRISC.RC6 = 1;      // ARRIBA
    TRISC.RC5 = 1;      // ABAJO
    TRISC.RC4 = 1;      // SELECCION
    PORTB.RB2 = 0;      //LCD escribir
    TRISB.RB2 = 0;      //PD.2 Salida
    Lcd_Init();         //Inicializa el LCD
    Lcd_Cmd(_LCD_CURSOR_OFF);
    lcd_cmd(_LCD_CLEAR);
    lcd_Out(1,1,"Carro Carroso");
    delay_ms(1000);
    // Inicia el programa
    while(1){
        loop();
    }
}

/*
 * Funcion que cambia los estados
 * del multimetro
 */
void loop(){
    switch (estado_actual){
        case S_HOME:
            pantalla_principal();
            break;
        case S_CAPA:
            pantalla_capacitancia();
            break;
        case S_RESI:
            pantalla_resistencia();
            break;
        case S_AMPI:
            pantalla_amperaje();
            break;
        case S_VOLT:
            pantalla_voltaje();
            break;
    }
}

/*
 * Funcion que imprime la pantalla del menu
 */
void pantalla_principal(){
    char aux[7];
    int estado;
    //Texto
    if (b){//Si es la primera vez
        b = 0;
        Lcd_Out(1,1,"Menu principal: ");
        Lcd_Out(2,1,"Oprima un boton");
    }

    if ((estado = PORTC.RC5) != 0){    // Cuando se presiona down
        if ((pantalla_menu = pantalla_menu + 1) > 4){
            pantalla_menu = 0;
        }
        lcd_cmd(_LCD_CLEAR);
        Lcd_Out(1,1,"BTN: down");

        imprimir_opciones(pantalla_menu);
    }

    if ((estado = PORTC.RC6) != 0){    // Cuando se presiona up
        if ((pantalla_menu = pantalla_menu - 1) < 0){
            pantalla_menu = 4;
        }
        lcd_cmd(_LCD_CLEAR);
        Lcd_Out(1,1,"BTN: up");
        imprimir_opciones(pantalla_menu);
    }

    // Si se preciona el boton de seleccion
    // Se cambia si  no se selecciono la pantalla 0
    if ((estado = PORTC.RC4) !=0 && pantalla_menu != 0){
        lcd_cmd(_LCD_CLEAR);
        Lcd_Out(1,1,"BTN: selec");
        estado_actual = pantalla_menu;
    }
}

/*
 * Funcion que imprime las opciones
 */
void imprimir_opciones(int numero_pantalla){
    lcd_cmd(_LCD_CLEAR);
    delay_ms(500);
    Lcd_Out(1,1,"Menu principal: ");
    switch (numero_pantalla){
        case S_HOME:
            Lcd_Out(2,1,"Oprima un boton");
            break;
        case S_RESI:
            Lcd_Out(2,1,"Resistencia");
            break;
        case S_VOLT:
            Lcd_Out(2,1,"Voltimetro");
            break;
        case S_AMPI:
            Lcd_Out(2,1,"Amperimetro");
            break;
        case S_CAPA:
            Lcd_Out(2,1,"Capacimetro");
            break;
    }
}

/*
 * Calculo de la capacitancia 
 */
void pantalla_capacitancia(){
    //Texto
    lcd_cmd(_LCD_CLEAR);
    Lcd_Out(1,1,"CAPA");
    delay_ms(1000);
    aux[0]='\0';
    aux[1]='\0';
    aux[2]='\0';
    aux[3]='\0';
    aux[4]='\0';
    aux[5]='\0';
    aux[6]='\0';
    Lcd_Cmd(_LCD_CURSOR_OFF);
    Lcd_Cmd(_LCD_CLEAR);
    Lcd_Out(1,1,aux);
    delay_ms(1000);
    Lcd_Cmd(_LCD_CLEAR);
    Lcd_out(1,1, "Cargando...");
    // inicio del programa
    while(1){
        TRISB.RB7=0;  // RB7 como salida
        delay_ms(1500);
        PORTB.RB7=1;  // Alimentacion del capacitor

        while (ValorDigital < 648){
            ValorDigital = ADC_Read(0);  // 0 --- 1024    == 44.20 useg
            delay_us(500);
            i++;
        }
        if (flag){  // Si es la primera vez, limpia
            Lcd_Cmd(_LCD_CLEAR);  //  Limpia
            ~flag;
        }

        PORTB.RB7=0;  // Apaga puerto
        IntToStr(i, aux);
        // Transforma i en char y se almacena en aux

        Voltaje =  i;      //2345
        x = Voltaje / 1000;            //2
        cad[0] = x + 0x30;
        x = Voltaje % 1000;            //345
        Voltaje = x / 100;             //3

        cad[1] = Voltaje + 0x30;
        Voltaje = x % 100;             // 45
        x = Voltaje / 10;              //4
        cad[2] = x + 0x30;
        x = Voltaje % 10;              //5

        cad[3] = ' ';
        cad[4] = 'u';
        cad[5] = 'F';           //2.345
        cad[6] = '\0';
        aux[0]='\0';
        aux[1]='\0';
        aux[2]='\0';
        aux[3]='\0';
        aux[4]='\0';
        aux[5]='\0';
        aux[6]='\0';
        if (flag){
            Lcd_Out(1,1,aux);
            delay_ms(1000);
            Lcd_Cmd(_LCD_CLEAR);
        }

        Lcd_Out(1,1,cad);    // Impresion en LCD
        Delay_ms(400);
    }
}

/*
 * Calculo de la resistencia 
 */
void pantalla_resistencia(){
    //Texto
    lcd_cmd(_LCD_CLEAR);
    Lcd_Out(1,1,"RESIS");
    delay_ms(1000);

    while(1){
        ValorDigital = ADC_Read(2); //Digitalizar el AN0
        Voltaje =  (5000L * ValorDigital) / 1024;      //2345
        Voltaje = 1000 * 5000L / Voltaje;
        Voltaje = (Voltaje - 1000);
        x = Voltaje / 1000;            //2
        cad2[0] = x + 0x30;
        x = Voltaje % 1000;            //345
        Voltaje = x / 100;             //3

        cad2[1] = Voltaje + 0x30;
        Voltaje = x % 100;             // 45
        x = Voltaje / 10;              //4
        cad2[2] = x + 0x30;
        x = Voltaje % 10;              //5
        cad2[3] = x + 0x30;
        cad2[4] = ' ';
        cad2[5] = 'o';
        cad2[6] = 'h';           //2.345
        cad2[7] = 'm';
        cad2[8] = 's';
        cad2[9] = '\0';
        Lcd_Out(1,1,cad2);
        Delay_ms(400);
    }
}
    
/*
 * Calculo de la corriente 
 */
void pantalla_amperaje(){
    //Texto
    lcd_cmd(_LCD_CLEAR);
    Lcd_Out(1,1,"AMP");
    delay_ms(1000);
    while(1){
        ValorDigital = ADC_Read(3); //Digitalizar el AN0
        Voltaje =  (5000L * ValorDigital) / 1024;      //2345
        vd2 = ADC_Read(4);
        v2 = (5000L * vd2) / 1024;
        Voltaje = Voltaje - v2;
        x = Voltaje / 1000;            //2
        cad2[0] = x + 0x30;
        x = Voltaje % 1000;            //345
        Voltaje = x / 100;             //3

        cad2[1] = Voltaje + 0x30;
        Voltaje = x % 100;             // 45
        x = Voltaje / 10;              //4
        cad2[2] = x + 0x30;
        x = Voltaje % 10;              //5
        cad2[3] = x + 0x30;
        cad2[4] = ' ';
        cad2[5] = 'u';
        cad2[6] = 'A';           //2.345
        cad2[7] = 'm';
        cad2[8] = 'p';
        cad2[9] = '\0';
        Lcd_Out(1,1,cad2);
        Delay_ms(400);
    }
}

/*
 * Calculo de voltaje 
 */
void pantalla_voltaje(){
    //Texto
    lcd_cmd(_LCD_CLEAR);
    Lcd_Out(1,1,"VOLT");
    delay_ms(1000);
    while(1){
        ValorDigital = ADC_Read(1); //Digitalizar el AN0
        Voltaje =  (5000L * ValorDigital) / 1024;      //2345
        x = Voltaje / 1000;            //2
        cad2[0] = x + 0x30;
        x = Voltaje % 1000;            //345
        Voltaje = x / 100;             //3
        cad2[1] = '.';
        cad2[2] = Voltaje + 0x30;
        Voltaje = x % 100;             // 45
        x = Voltaje / 10;              //4
        cad2[3] = x + 0x30;
        x = Voltaje % 10;              //5
        cad2[4] = x + 0x30;
        cad2[5] = ' ';
        cad2[6] = 'V';
        cad2[7] = '\0';           //2.345
        Lcd_Out(1,1,cad2);
        Delay_ms(400);
    }
}
