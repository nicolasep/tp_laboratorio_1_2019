#include "funciones.h"



/** \brief Realiza la suma de dos numeros enteros.
 *
 * \param Pide el primer numero entero.
 * \param Pide el segundo numero entero.
 * \return Retorna un numero entero.
 *
 */
int suma(int a, int b)
{
    int resultado;

    resultado = a + b;

    return resultado;
}

/** \brief Realiza la resta de dos numeros en enteros.
 *
 * \param Pide el primer numero entero.
 * \param Pide el segundo numero entero.
 * \return Retorna un numero entero.
 *
 */
int resta(int a, int b)
{

    int resultado;
    resultado= a - (b);

    return resultado;
}

/** \brief Realiza una multiplicacion entre dos enteros.
 *
 * \param Pide el primer numero entero.
 * \param Pide el segundo numero entero.
 * \return Retorna un numero entero.
 *
 */
int multiplicacion( int a, int b)
{

    int resultado;
    resultado= a * b;

    return resultado;
}

/** \brief Realiza la division de dos numeros enteros.
 *
 * \param Pide el primer numero entero.
 * \param Pide el segundo numero entero.
 * \return Retorna un numero flotante.
 *
 */
float division(int a, int b)
{

    float resultado;

    resultado=(float) a / b;


    return resultado;
}

/** \brief Realiza el factorial de un numero.
 *
 * \param Pide un numero entero.
 * \return Retorna un numero long.
 *
 */
long int factorial(int a)
{

    long factorial=1;
    int i;

    for(i=a; i>=1; i--)
    {

        factorial = factorial * i;
    }
    return factorial;
}
