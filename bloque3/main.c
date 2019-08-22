#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i,j;
FILE *fp;

void copymatrix(int A[50][50],int B[50][50]){
  for(i=0;i<50;i++){
    for(j=0;j<50;j++){
      A[i][j]=B[i][j];
    }
  }
}

void llenarrandom(int A[50][50]){
  srand((unsigned)time(0));
  for(i=0;i<50;i++){
    for(j=0;j<50;j++){
      A[i][j]=rand()%2;
    }
  }
}

void mostrar(int A[50][50]){
  for(i=0;i<50;i++){
    for(j=0;j<50;j++){
      if(A[i][j]==1){
	printf("X ");
      }else{
	printf("  ");
      }
    }
    printf("\n");
  }
}

void vida(int A[50][50],int B[50][50]){
  int suma;
  for(i=0;i<50;i++){
    for(j=0;j<50;j++){
      suma=0;
      if(i!=0&&j!=0&&i!=49&&j!=49){
	suma=A[i-1][j-1]+A[i-1][j]+A[i-1][j+1]+A[i][j-1]+A[i][j+1]+A[i+1][j-1]+A[i+1][j]+A[i+1][j+1];
      }else{
	if(i!=j){
	  if(i==0||i==49){
	    if(i==0){
	      if(j!=49){
		suma=A[i][j-1]+A[i][j+1]+A[i+1][j]+A[i+1][j-1]+A[i+1][j+1];
	      }else{
		suma=A[i][j-1]+A[i+1][j]+A[i+1][j-1];
	      }
	    }else{
	      if(j!=0){
		suma=A[i][j-1]+A[i][j+1]+A[i-1][j]+A[i-1][j-1]+A[i-1][j+1];
	      }else{
		suma=A[i][j-1]+A[i-1][j]+A[i-1][j-1];
	      }
	    }
	  }else{
	    if(j==0){
	      suma=A[i-1][j]+A[i-1][j+1]+A[i][j+1]+A[i+1][j]+A[i+1][j+1];
	    }else{
	      suma=A[i-1][j]+A[i-1][j-1]+A[i][j-1]+A[i+1][j]+A[i+1][j-1];	      
	    }
	  }
	}else{
	  if(i==0){
	    suma=A[i][j+1]+A[i+1][j]+A[i+1][j+1];
	  }else{
	    suma=A[i][j-1]+A[i-1][j]+A[i-1][j-1];
	  }
	}
      }
      if(A[i][j]==0){
	if(suma==3){
	  B[i][j]=1;
	}
      }else{
	if(suma<2||suma>3){
	  B[i][j]=0;
	}
      }
    }
  }
}

void manual(int A[50][50]){
  for(i=0;i<50;i++){
    for(j=0;j<50;j++){
      scanf("%d",&A[i][j]);
    }
  }
}

void readfile(int A[50][50],char *dir){
  if((fp=fopen(dir,"r"))!=NULL){
    for(i=0;i<50;i++){
      for(j=0;j<50;j++){
	fscanf(fp,"%d",&A[i][j]);
      }
    }
    fclose(fp);
  }else{
    printf("Error Archivo no encontrado\n");
    exit(1);
  }
}

int compare(int A[50][50],int B[50][50]){
  int k=0;
  for(i=0;i<50;i++){
    for(j=0;j<50;j++){
      if(A[i][j]==B[i][j]){
	k++;
      }
    }
  }
  return (k);
}

void savefile(int A[50][50],char *dir){
  if((fp=fopen(dir,"a+"))!=NULL){
    for(i=0;i<50;i++){
      for(j=0;j<50;j++){
	/*if(A[i][j]==1){
	  fprintf(fp,"X ");
	}else{
	  fprintf(fp,"  ");
	  }*/
	fprintf(fp,"%d ",A[i][j]);
      }
      fprintf(fp,"\n");
    }
    for(i=0;i<50;i++){
      fprintf(fp,"**");
    }
    fprintf(fp,"\n");
    fclose(fp);
  }else{
    printf("Error al abrir el archivo\n");
    exit(1);
  }
}

void main(){
  int a[50][50],b[50][50],opt;
  char dir[70];
  float s;
  do{
    opt=0;
    printf("Menu Principal\n");
    printf("Por favor elija una opcion\n");
    printf("1>Crear la matriz aleatoriamente\n");
    printf("2>Leer la matriz desde archivo\n");
    printf("3>Insertar la matriz manualmente\n");
    printf("4>Salir\n");
    scanf("%d",&opt);
    switch(opt){
    case 1:
      llenarrandom(a);
      break;
    case 2:
      printf("Por favor ingrese la direcion del archivo\n");
      scanf("%*c%[^\n]%*c",dir);
    readfile(a,dir);
    break;
    case 3:
      printf("Ingrese \"1\" para una celula viva y \"0\" para una celula muerta\n");
      manual(a);
      break;
    case 4:
      break;
    default:
      printf("Opcion no valida\n");
      exit(0);
      break;
    }
    if(opt!=4){
      printf("Ingrese la direccion del archivo destino\n");
      scanf("%*c%[^\n]%*c",dir);
      copymatrix(b,a);
      mostrar(a);
      getchar();
      do{
	vida(a,b);
	mostrar(b);
	savefile(b,dir);
	s=compare(a,b);
	s=s/2500;
	if(s > 0.98){
	  printf("Parece que el algoritmo entro en un bucle puede salir presionando \"X\"\n");
	}
	copymatrix(a,b);
      }while(getchar()!='x');
    }
  }while(opt!=4);
}
