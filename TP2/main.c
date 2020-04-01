#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "ArrayEmployees.h"

#define TAM 1000 // ES PARA ESTABLECER EL LARGO DEL VECTOR EMPLEADOS.

// TP2 LABORATORIO 1 DIVISION 1G ALUMNO: NICOLAS EDUARDO PEREZ.
// LAS LOS NOMBRES DE LAS FUNCIONES LOS ESCRIBI EN INGLES, PERO DENTRO DE ELLAS EL CODIGO ESTA EN CASTELLANO. AL NO DOMINAR EL IDIOMA NO SE HUBIESE ENTENDIDO.

int main()
{
    eEmployee listEmployees[TAM];//VECTOR DE EMPLEADOS.
    initEmployees(listEmployees,TAM);// INICIALIZO ACA PARA NO GENERAR CONFLICTO CON EL HARCODEO
    int lastId=1; //DESDE ESTE NUMERO SE ASIGNAN LOS ID A LOS EMPLEADOS.
    //lastId=lastId+harcodearEmpleados(listEmployees,TAM,lastId); // FUNCION PROPIA PARA TEST, CARGA 10 EMPLEADOS AUMENTANDO EL NUMERO DE ID
    int respuesta; //SE ENCARGA DE VALIDAR LA RESPUESTA DE LA FUNCION DE ALTA EMPLEADO, EN EL CASO QUE SE LOGRE DAR DE ALTA LE SUMA 1 AL NUMERO DE ID PARA SU PROXIMA ASIGNACION.
    char seguir; // ES PARA LA OPCION DE SALIDA DEL PROGRAMA, OSEA DEL DO WHILE.
    eEmployee auxEmploye; //EMPLEADO AUXIAL QUE SE USA PARA DAR DE ALTA UN EMPLEADO.

    do
    {

        switch(menu())
        {
        case 1:

            respuesta = getEmployee(auxEmploye,listEmployees,TAM,lastId);
            if(respuesta == 0)
            {
                lastId++; //ACA SUMA 1 AL NUMERO DE ID QUE SE VA UTILIZAR EN LA PROXIMA CARGA DE EMPLEADOS.
            }
            break;

        case 2:
            modifyEmployee(listEmployees,TAM); // LLAMA A LAFUNCION DE MODIFICAR EMPLEADO.

            break;

        case 3:
            funtionRemoveEmployee(listEmployees,TAM); //LLAMA A LA FUNCION DE ELIMINAR EMPLEADO.

            break;

        case 4:

            switch(menuInform())//MUESTRA EL MENU DE INFORMACION, NO ESTOY SEGURO QUE SEA LO PRETENDIDO, PERO ME PARECIO LO MAS CONVENIENTE.
            {
            case 1:
                funtionSortEmployees(listEmployees,TAM);//LLAMA A LA FUNCION DE ORDENAR EMPLEADOS.
                break;
            case 2:
                searchAverage(listEmployees,TAM); //LLAMA A LA FUNCION DE MOSTRAR PROMEDIO, TOTAL Y CANTIDAD DE EMPLEADOS QUE SUPERAN EL PROMEDIO.
                break;
            }

        }
        printf("Para salir ingrese 'n'\n");
        fflush(stdin);
        seguir=getche(); //USAR ESTA FUNCION ME PARECE MAS COMODA POR QUE SOLO HAY QUE INGRESAR LA N EN MINUSCULA PARA SALIR Y DE LO CONTRARIO SEGUI FUNCIONANDO.
        system("cls");
    }
    while(seguir!='n');

    return 0;
}
