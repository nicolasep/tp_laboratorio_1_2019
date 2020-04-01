#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "nicolas.h"
#include "Controller.h"
#include "conio.h"

int menuPrincipal()
{
    int opcion;
    printf("ELIJA UNA OPCION\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10. Salir\n");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}

/** \brief carga los datos desde un archivo de texto data.csv (modo texto).
 *
 * \param path char* archivo de origen
 * \param pArrayListEmployee LinkedList* lista donde se cargar los datos
 * \return int devuelve 0 si no se pudo cargar, -1 si elchivo no existe o 1 si se cargo correctamente
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* f= NULL;
    int flag = -1;
    f = fopen(path,"r");
    if(path == NULL || pArrayListEmployee == NULL || f == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        flag = 0;
    }
    else
    {

        if(f !=NULL)
        {
            parser_EmployeeFromText(f,pArrayListEmployee);
            flag = 1;
            fclose(f);
        }

    }

    return flag;
}


/** \brief carga los datos desde un archivo binario
 *
 * \param path char* archivo de origen
 * \param pArrayListEmployee LinkedList* lista donde se cargar los datos
 * \return int devuelve 0 si no se pudo cargar, -1 si elchivo no existe o 1 si se cargo correctamente
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int flag = -1;
    FILE* f= NULL;
    f = fopen(path,"rb");
    if(path == NULL || pArrayListEmployee == NULL || f == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        flag = 0;
    }
    else
    {
        parser_EmployeeFromBinary(f,pArrayListEmployee);
        flag = 1;
        fclose(f);
    }
    return flag;
}


/** \brief agrega un empleado
 *
 * \param pArrayListEmployee LinkedList* lista donde se guarda
 * \return int devuelve -1 si la lista da error, 0 si no se pudo guardar y 1 si se guardo
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int flag = -1;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    Employee* auxEmployee;
    auxEmployee = employee_new();
    if(auxEmployee != NULL)
    {
        getcharS(nombre,"Ingrese nombre","Error, ingrese solo letras",128);
        fflush(stdin);
        horasTrabajadas = getNumero("Ingrese las horas trabajadas","Error, ingrese solo numeros");
        sueldo = getNumero("ingrese sueldo","Error, ingrese solo numeros");

        if(employee_setId(auxEmployee,-1)
                && employee_setNombre(auxEmployee,nombre)
                && employee_setSueldo(auxEmployee,sueldo)
                && employee_setHorasTrabajadas(auxEmployee,horasTrabajadas))
        {
            if(!ll_add(pArrayListEmployee,auxEmployee))
            {
                printf("Empleado cargado con exito\n");
                flag = 1;

            }
            else
            {
                printf("No se pudo cargar el empleado\n");
                flag = 0;
            }
        }

    }

    return flag;
}


/** \brief modifica un empleado
 *
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int devuelve 1 si pudo modificar y 0 si no se pudo
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int opcioModificar;
    char modificarNombre[128];
    int idSeleccionado;
    int modificarHoras;
    int modificarSueldo;
    int flag=0;

    system("cls");
    printf("-------MODIFICAR EMPLEADO-------\n\n");
    fflush(stdin);
    idSeleccionado = getNumero("Ingrese el id a modificar","Error, debe ingresar solo numeros");
    fflush(stdin);
    for(int i=0; i<ll_len(pArrayListEmployee); i++)
    {
        if( idSeleccionado ==((Employee*)ll_get(pArrayListEmployee, i))->id )
        {
            flag = 1;
            printf("\n");
            printf("ID             NOMBRE      HORAS    SUELDO\n");
            printEmployee((Employee*) ll_get(pArrayListEmployee, i));
            printf("\n");

            printf("1- MODIFICAR NOMBRE\n2- MODIFICAR HORAS TRABAJADAS\n3- MODIFCAR SUELDO\n4- SALIR\n");


            opcioModificar = getNumero("Seleccione una opcion","Error, ingrese un numero entre 1 y 4");

            switch(opcioModificar)
            {
            case 1:

                getcharS(modificarNombre,"Ingrese nuevo nombre","Error, el nombre debe tener un minimo de 1 y maximo 128 caracteres",128);
                if( employee_setNombre((Employee*) ll_get(pArrayListEmployee, i), modificarNombre) )
                {
                    printf("\nNombre modificado con exito\n");
                }
                break;
            case 2:
                modificarHoras = getNumero("Ingrese la cantidad de horas", "Error, debe ingresar solo numeros");
                if(employee_setHorasTrabajadas((Employee*)ll_get(pArrayListEmployee,i),modificarHoras))
                {
                    printf("\nHoras modificadas con exito\n");
                }
                break;
            case 3:
                modificarSueldo = getNumero("Ingrese el nuevo sueldo","Error, debe ingresar solo numeros");
                if(employee_setSueldo((Employee*)ll_get(pArrayListEmployee,i),modificarSueldo))
                {
                    printf("\nSueldo modificado con exito\n");
                }
                break;
            case 4:
                printf("\nOperacion cancelada\n");
                break;
            }
        }
    }
    if(flag==0)
    {
        printf("Id incorrecto\n");

    }
    return flag;
}


/** \brief elimina un empleado
 *
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int devuelve -1 si no se pudo eliminar, 1 si se elimino y 0 si se cancelo
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{

    int flag = -1;
    int idEliminar;
    char confirmacion;

    if(pArrayListEmployee != NULL)
    {
        printf("------BAJA EMPLEADO------\n\n");
        fflush(stdin);
        idEliminar = getNumero("Ingrese el id del empleado a eliminar","Error, debe ingresar solo numeros");

        for(int i=0; i<ll_len(pArrayListEmployee); i++)
        {
            if(idEliminar ==((Employee*)ll_get(pArrayListEmployee,i))->id )
            {
                printEmployee((Employee*)ll_get(pArrayListEmployee, i));

                printf("\nSeguro decea eliminar este empleado, elija s o n: ");
                fflush(stdin);
                confirmacion = getche();

                if( confirmacion == 's' || confirmacion == 'S')
                {
                    if(ll_remove(pArrayListEmployee,i)==0)
                    {
                        printf("\n\nEl empleado se elimino correctamente\n");
                        flag = 1;
                        break;
                    }
                    else
                    {
                        printf("\nNo se pudo eliminar empleado\n");
                    }
                }
                else
                {
                    printf("\nOperacion cancelada\n");
                    flag = 0;
                    break;
                }
            }

        }

        if(flag==-1)
        {
            printf("No se encontro el empleado");
        }


    }

    return flag;
}


/** \brief muestra los empleados
 *
 * \param pArrayListEmployee LinkedList* la lista de empleados
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    if(pArrayListEmployee != NULL)
    {
        printEmployees(pArrayListEmployee);
    }
    return 1;
}


/** \brief ordena los emplados
 *
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int devuelve -1 si hubo un error, 0 si no se pudo ordenar y 1 si se ordeno
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int flag = -1;
    int orden;
    int tipoOrden;
    fflush(stdin);
    tipoOrden = getNumero("ELIJA 1 PARA ORDENAR POR NOMBRE Y 2 PARA ORDENAR POR ID","ERRROR, ELIJA 1 PARA ORDENAR POR NOMBRE Y 2 PARA ORDENAR POR ID");
    if(tipoOrden == 1 || tipoOrden == 2)
    {
        system("cls");
        fflush(stdin);
        orden = getNumero("ELIJA EL CRITERIO DE ORDEN: 1 ASCENDENTE Y 0 DESCENDENTE","ERROR, ELIJA EL CRITERIO DE ORDEN: 1 ASCENDENTE Y 0 DESCENDENTE");
        if(orden == 1 || orden == 0)
        {
            printf("Espere mientras se ordena\n");
            if(pArrayListEmployee!= NULL)
            {
                if(tipoOrden==1)
                {
                    if(ll_sort(pArrayListEmployee,ordenarPorNombre,orden)== 0)
                    {
                        printf("La liste se ordeno correctamente\n");
                        flag = 1;
                    }
                    else
                    {
                        printf("La lista no pudo ser ordenada");
                        flag = 0;
                    }
                }
                else
                {
                    if(ll_sort(pArrayListEmployee,ordenarPorId,orden)== 0)
                    {
                        printf("La liste se ordeno correctamenteppp\n");
                        flag = 1;
                    }
                    else
                    {
                        printf("La lista no pudo ser ordenada");
                        flag = 0;
                    }
                }

            }
        }
        else
        {
            printf("Opcion incorrecta\n");
        }
    }
    else
    {
        printf("Opcion incorrecta\n");
    }


    return flag;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* el archivo donde se guarda
 * \param pArrayListEmployee LinkedList* la lista que se guarda
 * \return int devuelve 0 si no se puedo guardar y 1 si se guardo
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int flag = 0;
    int can;
    int id;
    char nombre[127];
    int horasTrabajadas;
    int sueldo;

    FILE* f= NULL;
    Employee* aux;


    if(path != NULL && pArrayListEmployee != NULL)
    {
        can = ll_len(pArrayListEmployee);
        f = fopen(path,"w");
        if(f != NULL)
        {
            for(int i=0; i<can; i++)
            {
                aux =(Employee*)ll_get(pArrayListEmployee,i);

                employee_getId(aux,&id);
                employee_getNombre(aux,nombre);
                employee_getHorasTrabajadas(aux,&horasTrabajadas);
                employee_getSueldo(aux,&sueldo);

                fprintf(f,"%d,%s,%d,%d\n",id,nombre,horasTrabajadas,sueldo);

            }
            fclose(f);
            flag = 1;
        }
    }
    return flag;
}

/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *
 * \param path char* el archivo donde se guarda
 * \param pArrayListEmployee LinkedList* la lista que se guarda
 * \return int devuelve 0 si no se puedo guardar y 1 si se guardo
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int can;
    int flag=0;
    int contador=0;
    FILE* f= NULL;
    Employee* aux;
    can = ll_len(pArrayListEmployee);
    if(path != NULL && can > 0)
    {
        f = fopen(path, "wb");
        if(f != NULL)
        {
            for(int i=0; i<can; i++)
            {
                aux = (Employee*)ll_get(pArrayListEmployee,i);
                if(aux != NULL)
                {
                    fwrite(aux,sizeof(Employee),1,f);
                    contador++;
                }
                if(can == contador)
                {
                    fclose(f);
                    flag = 1;
                }
            }
        }
    }

    return flag;
}


