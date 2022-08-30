#include <stdio.h>
#include <string.h>
 
int main(){
	int o, n, a, l, g, e, r, b, d = 5, t = 0;
	long nom1, nom2, nom3, resultadoReal; 
	char letras[9];  /*DONALGERBT -> Cada posicion corresponde a una letra.*/ 
	letras[0] = '5'; /*5		  -> Primera posicion corresponde a la letra "D", en esa posicion se encuentra su valor asignado.*/
	letras[9] = '0'; /*			0 -> Si se hace el reemplazo de las "D" (5+5=10, c5 = 1, T = 0), se obtiene el valor de T, el cual es 0.*/
	
	char nombre1[6] = "DONALD"; /*Primer nombre*/
	char nombre2[6] = "GERALD"; /*Segundo nombre*/
	char nombre3[6] = "ROBERT"; /*Tercer nombre (nombre resultado)*/
	
	for(o = 1; o <= 9; o++){ /*Generar todas las combinaciones de números para las letras.*/
	    /*Asignar en cadena "letras" en la posicion que le corresponde a la letra "O" en cadena "letras" (posicion 1), el valor de la variable "o".*/
		letras[1] = o + '0'; 
		for(n = 1; n <= 9; n++){ 
			/*Asignar en la posicion que le corresponde a la letra "N" en cadena "letras" (posicion 2), el valor de la variable "n".
			  Lo mismo sucede con las demas letras siguientes, se asigna el valor de la variable del ciclo en su correspondiente posicion
			  en cadena "letras".*/
			letras[2] = n + '0'; 
			for(a = 1; a <= 9; a++){
				letras[3] = a + '0'; 
				for(l = 1; l <= 9; l++){
					letras[4] = l + '0'; 
					for(g = 1; g <= 9; g++){
						letras[5] = g + '0'; 
						for(e = 1; e <= 9; e++){
							letras[6] = e + '0'; 
							for(r = 1; r <= 9; r++){
								letras[7] = r + '0'; 
								for(b = 1; b <= 9; b++){
									letras[8] = b + '0'; 
									
									/*Verificar que en la combinacion generada (valor asignado a cada letra),
									  no exista mas de una letra con el mismo valor. Por que cada valor, debe ser unico de una letra.*/
									if(repetido(letras) != 1){ /*No hay valores en cadena "letras" asignados a más de una letra.*/
										nom1 = reemplazar(nombre1,letras); /*Remplazar cada letra del nombre1(DONALD) por el respectivo valor asignado a cada letra
																		 	 y guardar el numero generado en nom1.*/
										
										
										nom2 = reemplazar(nombre2,letras); /*Remplazar cada letra del nombre2(GERALD) por el respectivo valor asignado a cada letra
																			 y guardar el numero generado en nom2.*/	
										
										nom3 = reemplazar(nombre3,letras); /*Remplazar cada letra del nombre3(ROBERT) por el respectivo valor asignado a cada letra
																		     y guardar el numero generado en nom3.*/
									
										resultadoReal = nom1 + nom2; /*Si los numeros asignados a las letras son los correctos, el resultado de la suma de nom1 y nom2
																	   debera ser el mismo valor que tiene nom3 (ROBERT) despues del remplazo de las letras por los numeros.*/
										
										/*Si nom3 despues del reemplazo tiene el mismo valor que el resultado de la suma de num1 + nom2, es decir, 
										  nom3 tiene almacenado el resultado de la operacion aritmetica de los numeros resultantes de reemplazar las letras de "DONALD" y "GERALD". 
										  En el caso de que si sea asi, el valor de cada letra es el correcto.*/
										if(nom3 == resultadoReal){ 
											printf("%s\n%s\n-------\n%s\n\n\n", nombre1, nombre2, nombre3);
											printf("%d\n%d\n-------\n%d\n\n\n", nom1, nom2, nom3);
											printf("D = %d, O = %d, N = %d, A = %d, L = %d, G = %d, E = %d, R = %d, B = %d, T = %d\n", d, o, n, a, l, g, e, r, b, t);
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	
	return 0;
}

/*
FUNCION REEMPLAZAR
Reemplazar cada letra de la cadena, por su respectivo valor asignado.
Recibe por parametro la cadena del nombre a reemplazar y la cadena con el valor de cada letra.
*/
int reemplazar(char *nombreOriginal, char *letras){ 
	int i = 0;
	char nombre[6]; 
	
	strcpy(nombre,nombreOriginal);
	
	for(i = 0; i <= 5; i++){ /*Recorrer toda la cadena "nombre".*/
		if(nombre[i] == 'D'){ /*Si la letra en la posicion i de la cadena es "D".*/
			nombre[i] = letras[0]; /*El valor asignado a la letra "D" en la cadena "letras" se encuentra en la posicion 0.
								     Reemplazar caracter de la posicion i de "nombre" por el valor dasignado a la letra D (letras[0]).
									 Lo mismo sucede con las demas letras, a diferencia que cambia la posicion en la cadena "letras" y el
									 valor asignado a la letra*/	
		} else if(nombre[i] == 'O'){
			nombre[i] = letras[1];	
		} else if(nombre[i] == 'N'){
			nombre[i] = letras[2];	
		} else if(nombre[i] == 'A'){
			nombre[i] = letras[3];	
		} else if(nombre[i] == 'L'){
			nombre[i] = letras[4];	
		} else if(nombre[i] == 'G'){
			nombre[i] = letras[5];	
		} else if(nombre[i] == 'E'){
			nombre[i] = letras[6];	
		} else if(nombre[i] == 'R'){
			nombre[i] = letras[7];	
		} else if(nombre[i] == 'B'){
			nombre[i] = letras[8];	
		} else if(nombre[i] == 'T'){
			nombre[i] = letras[9];	
		}
	}
	
	/*En la cadena de caracteres "nombre", las letras ya fueron reemplazados por el número asignado a cada letra 
	  y se retorna la cadena convertida a entero.*/
	return atoi(nombre); 
}

/*
FUNCION REPETIDO
Verificar que en la cadena "letras" no haya un número más de una vez, lo cual significaria que más de una letra tiene el mismo valor asignado.
Recibe por parametro la cadena de caracteres donde estan los valores asignados de las letras, segun la combinacion generada.
*/
int repetido(char *letras){
	int i, j;
	
	for(i = 0; i <= 9; i++) {
    	for(j = i+1; j <= 9; j++) {
        	if(letras[j] == letras[i]) {
            	return 1; /*Retornar 1 si hay un mismo número asignado a mas de una letra (si un número se repite en la cadena "letras").*/
       		}
    	}
	}
	
	return -1; /*Retornar -1 si no hay un mismo número asignado a mas de una letra.*/
}
