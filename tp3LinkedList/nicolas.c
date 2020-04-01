#include "nicolas.h"



/** \brief valida una palabra
 *
 * \param palabra[] char palabra a evaluar
 * \return int devuelve 1 si esta bien y 0 si esta mal
 *
 */
int validaPalabra(char palabra[])
{
    int flag= -1;
    int contador = 0;
    for(int i=0; i<strlen(palabra); i++)
    {
        if((palabra[i] < 'a' && palabra[i]> 'z') || (palabra[i]< 'A' && palabra[i]> 'Z'))
        {

        }
        else
        {
            contador++;
        }

    }
    if(contador == strlen(palabra))
    {
        flag=1;
    }
    else
    {
        flag = 0;
    }
    return flag;
}

/** \brief pide una palabra y la valida
 *
 * \param mensaje[] char mensaje a mostrar para ingresar la palabra
 * \param mensajeError[] char mensaje de error
 * \param tamPalabra int largo maximo de palabra
 * \return char devuelve la palabra validada
 *
 */
int getcharS(char palabra[],char mensaje[], char mensajeError[],int tamPalabra)
{

    int validaTam;
    int valida;
    printf("%s: ",mensaje);
    fflush(stdin);
    gets(palabra);
    validaTam = validaTamPalabra(palabra,tamPalabra);
    valida=validaPalabra(palabra);

    while(valida !=1 || validaTam != 1)
    {

        printf("%s: ",mensajeError);
        fflush(stdin);
        gets(palabra);
        validaTam = validaTamPalabra(palabra,tamPalabra);
        valida=validaPalabra(palabra);

    }
    return 1;
}
/** \brief valida el tamaño de una palabra
 *
 * \param palabra[] char palabra a evaluar
 * \param tamPalabra int tamaño maximo de palabra
 * \return int devuelve 0 si la palabra supera el maximo y 1 si esta bien
 *
 */
int validaTamPalabra(char palabra[],int tamPalabra)
{
    int flag= -1;
    int valida;

    if((valida = strlen(palabra))<= tamPalabra)
    {
        flag = 1;
    }
    else
    {
        flag = 0;
    }

    return flag;
}
/** \brief valida el numero
 *
 * \param numero[] char el numero a ser validado
 * \return int el numero validado
 *
 */
int validaNumero(char numero[])
{
    int numeroOk;

    for(int i=0; i<strlen(numero); i++)
    {

        if(isalpha(numero[i]) != 0)
        {
            return 0;
        }
    }
    numeroOk= atoi(numero);

    return numeroOk;
}
/** \brief pide un numero y lo valida
 *
 * \param mensaje[] char mensaje para mostrar antes de tomar el dato
 * \param mensajeError[] char mensaje de error
 * \return int devuelve el numero validado y si esta mal 0
 *
 */
int getNumero(char mensaje[],char mensajeError[])
{
    int valida;
    char numeroAux[100];
    int numeroOk;
    do
    {
        printf("%s: ",mensaje);
        gets(numeroAux);
        valida= validaNumero(numeroAux);
        if(valida < 0)
        {
            printf("%s: ",mensajeError);

        }
        else
        {
            numeroOk = atoi(numeroAux);
            return numeroOk;
        }
    }
    while(valida==0);
return 0;
}
