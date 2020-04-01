#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
// BIENVENIDO A LA CALCULARA DE NICOLAS EDUARDO PEREZ DIVISION 1G.
// TENER EN CUENTA LOS VALORES INGRESADOS A LA HORA DE VER EL RESULTADO DEL FACTORIAL, POR QUE SI SE PASA DE CIERTO RANGO DA UN RESULTADO ERRONEO.
int main()
{

    int salir=0; //bandera para salir del while
    int opciones;
    int operando1;
    int operando2;
    int validaNumero=0;
    int validaNumero2=0;
    int sumar;
    int restar;
    float dividir;
    int multiplicar;
    long factor1;
    long factor2;
    int banderaOperaciones=0;
    int banderaOpciones=0;

    do
    {

        fflush(stdin);
        printf ("Seleccione una opcion\n");//Aca empieza el menu
        if(validaNumero==1)//Valida si se ingreso el primer numero.
        {
            printf("1. Ingrese primer operando: A= %d\n",operando1);//Si verifica que se halla ingresado el numero, se coloca en el menu.

        }
        else
        {
            printf("1. Ingrese primer operando\n");//Es para cuendo se inica por primera ves.
        }
        if(validaNumero2==1)//Valida si se ingreso el primer numero.
        {
            printf("2. Ingrese segundo operando: B= %d\n",operando2);//Si verifica que se halla ingresado el numero, se coloca en el menu.
        }
        else
        {
            printf("2. Ingrese segundo operando\n");//Es para cuendo se inica por primera ves.
        }
        printf("3. Calcular operaciones\n");
        printf("4. Informar resultados\n");
        printf("5. salir\n");
        printf("La opcion es: ");

        banderaOpciones=scanf("%d",&opciones);//Guarda la opcion ingresadad por consola en la variable.


        switch(opciones)
        {
        case 1:
            printf("Ingrese primer operando: ");//Pide el primer operando.
            validaNumero=scanf("%d",&operando1);//bandera para validar si ya se le cargo un numero, es para cuando se sigue despues de hacer los calculos. y aparte guarda el numero ingresado.
            banderaOperaciones=0;
            fflush(stdin);
            while(validaNumero!=1)//Valida si es un numero.
            {
                printf("incorrecto, ingrese primer operando: ");
                fflush(stdin);
                validaNumero=scanf("%d",&operando1);
            }

            break;

        case 2:
            if(validaNumero==1)//Pide el segundo operando.
            {
                printf("Ingrese segundo operando: ");
                validaNumero2=scanf("%d",&operando2);//bandera para validar si ya se le cargo un numero, es para cuando se se vuelven a cargar los numeros. y aparte guarda el numero ingresado.
                banderaOperaciones=0;
                fflush(stdin);
                while(validaNumero2!=1)//Valida si es un numero.
                {
                    printf("incorrecto, ingrese segundo operando: ");
                    fflush(stdin);
                    validaNumero2=scanf("%d",&operando2);
                }
            }
            else// Si no se ingreso el primer operando no va a dejar ingresar el segundo para no generar errores en los calculos.
            {
                printf("Primero ingrese operando 1\n");
            }

            break;

        case 3:
            if(validaNumero2==1 && validaNumero==1)//Valida que se hallan ingresado ambos numero A y B.
            {
                //Si se verifica que se hallan ingresado los numero se calculan las operaciones.
                sumar=suma(operando1,operando2);
                restar=resta(operando1,operando2);
                dividir=division(operando1,operando2);
                multiplicar=multiplicacion(operando1,operando2);
                factor1=factorial(operando1);
                factor2=factorial(operando2);
                printf("Operaciones realizadas\n");
                banderaOperaciones=1;
            }
            else
            {
                printf("Error, no se ingreso operandos\n");
            }

            break;

        case 4:
            if(validaNumero2==1 && validaNumero==1)//Valida que se hallan calculado las operaciones.
            {
                if(banderaOperaciones==1)//Valida si se modifico algun numero despues de calcular las operaciones, para que no el mismo resultado para distintos numeros.
                {
                    fflush(stdin);
                    printf("El resultado de A+B es: %d\n",sumar);
                    printf("El resultado de A-B es: %d\n",restar);
                    if(operando1==0 || operando2==0)// Verifica si un operando es cero antes de calcular la division
                    {
                        printf("No es posible dividir por cero\n");
                    }
                    else
                    {
                        printf("El reultado de A/b es: %.2f\n",dividir);
                    }
                    printf("El resultado de A*B es: %d\n",multiplicar);
                    if(operando1<0 || operando2<0)//Verifica si algunoi de los operandos es negativo.
                    {
                        if(operando1<0 && operando2>=0)//Verifica si operando 1 es negativo.
                        {
                            printf("No es posible calcular el factorial de A por que es negativo. El factorial de B es: %ld\n",factor2);
                        }
                        else if(operando2<0 && operando1>=0)//verifica si operando 2 es negativo.
                        {
                            printf("No es posible calcular el factorial de B por que es negativo. El factorial de A es: %ld\n",factor1);
                        }
                        else// En el caso que ambos numeros sean negativos.
                        {
                            printf("No es posible calcular el factorial de A y B por que ambos son negativos.\n");
                        }
                    }
                    else// En el caso que se hallan ingresado bien los numeros (ambos positivos).
                    {
                        printf("El factorial de A es: %ld y El factorial de B es: %ld\n",factor1,factor2);
                    }

                }
                else if(banderaOperaciones==0)//En el caso de que se hallan ingresado los numeros, pero no se hallan calculado las operaciones.
                {
                    printf("Primero aceda a la opcion 3 para realizar las operaciones\n");
                }
            }
            else//En el caso de que no se hallan ingresado operandos.
            {
                printf("Primero aceda a la opcion 3 para realizar las operaciones\n");
            }
            break;

        case 5:
            salir=1;//bandera para salir de while
            break;

        default:
            if(banderaOpciones!=1)
            {
                printf("Opcion incorrecta.\n");// Valida que se ingrese un numero.
            }
            else
            {
                printf("Opcion incorrecta.\n");// En el caso de ingresar otro numero que no sea del 1 al 5.
            }
            break;
        }
        system("pause");
        system("cls");//Es para limpiar la pantalla y que despues se vuelva a cargar el menu.

    }
    while(salir!=1);

    return 0;
}
