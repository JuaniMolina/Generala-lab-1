#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <string.h> ///<--- PARA DEVOLVER EL NOMBRE DEL JUGADOR EN LA PUNTUACION FINAL.
#include "rlutil.h"

using namespace std;
using namespace rlutil;

#include "FuncionesGenerala3.1.h"
#include "windows.h"

int main (){
    hidecursor();
    system("color 1B");
    bool MODO=true; /// MODO ALEATORIO(TRUE) O MANUAL (FALSE)
    const int T=10; /// VARIABLE PARA EL NUMERO DE RONDAS
    int max_puntos=0, min_rondas=0;/// VARIABLES UTILIZADAS PARA LA PUNTUACION MAXIMA.
    char max_name[20]="------";
    GENERALA();

    while(true){ ///HACE QUE SIEMPRE VUELVA AL MENU PRINCIPAL.
        hidecursor();
        bool GeneralaServida=false;
        int opcion;
        MenuPrincipal();
        locate(1,20);
            cout << "OPCION: ";
            cin >> opcion;
        system("cls");

        switch(opcion){

            /// MODO 1 JUGADOR (OPCION 1)
            case 1: {
                char nombre[20];
                cout << "\t\t  ----------------------------------------" << endl;
                cout << "\t\t | Bienvenidx al modo de juego: 1 JUGADOR |" << endl;
                cout << "\t\t  ----------------------------------------" << endl<<endl<<endl;
                cout << endl;

                cout << "\t\tPor favor, ingrese su nombre antes de comenzar: "<<endl<<endl;
                cout << "\t\t\t\t    "; cin >> nombre;


                system("cls");

                /// VARIABLE QUE GUARDA LOS PUNTOS CUANDO SE HACE UN JUEGO DE NUMEROS
                int ptos1, ptos2, ptos3, ptos4, ptos5, ptos6, ptosGenerala, ptosPoker, ptosFull, ptosEscalera, VecPuntos[9], MayorPtos;
                /// CONTADOR DE RONDAS
                int ContRonda=0;
                /// VECTOR QUE SERÁ EVALUADO
                int v[5];
                /// ACUMULADOR DE PUNTOS
                int AcumPtos=0;
                /// VARIABLE QUE DETERMINA EL TAMAÑO DEL NUEVO VECTOR ALEATORIO QUE SE GENERARÁ
                int t;
                /// VARIABLES CHAR SI(S) O NO(N) QUE INGRESA EL USUARIO PARA CONTINUAR TIRANDO O DEJAR DE TIRAR
                char Respuesta, Respuesta2;




            ///ABRO CICLO WHILE PARA EJECUTAR "T" RONDAS
            while(ContRonda<T && GeneralaServida==false){
                ContRonda++;
                int ContTiros=1; ///CONTADOR DE TIROS
                entreturnos(nombre,AcumPtos,ContRonda);

                ///ABRO CICLO PARA EJECUTAR 3 TIROS
                while(ContTiros<3){

                    cout << "\t\t\t\t Partida de " << nombre << "\t\t" << endl;
                    cout << endl << endl;

                    MuestraRondaTiroPuntos(ContRonda, ContTiros, AcumPtos);

                    TirarDados(v, MODO);

                    MostrarDados(v);

                    cout << endl << endl<< endl<< endl;

                    ///VERIFICA SI SALIO GENERALA SERVIDA, DE SER ASI, LA VARIABLE BOOLEANA "GeneralaServida" SE CONVIERTE EN TRUE,
                    ///Y "ContTiros" SERÁ 3.

                    ptosGenerala=VerificacionGENERALA(v);
                    if( ptosGenerala==50 && ContTiros==1){
                        system("pause");
                        system("cls");
                        GeneralaServida=true;
                        ContTiros=3;
                    }

                    ///SI NO SE CUMPLE...
                    else{


                    ///OPCION DE TIRAR POR 2°VEZ

                    cout << "CONTINUAR TIRANDO? S/N: "; cin >> Respuesta;
                    cout << endl;

                    switch(Respuesta){

                        case 'S':
                        case 's':
                            {

                            ///SI LA RESPUESTA ES "S", INCREMENTA ++ "ContTiros"
                            ContTiros++;

                            cout << "CUANTOS VOLVES A TIRAR?: "; cin >> t;
                            cout << endl;
                            ///SI "t" ES MENOR A 5, PREGUNTA CUÁLES DADOS QUIERE VOLVER A TIRAR
                            if(t<5){

                            int v2[t];
                            TirarDados2(v2, t);

                            int v3[t];
                            cout << "CUAL/ES?: " << endl;
                            cout << endl;

                            ///SE CARGA UN VECTOR CON DADOS ALEATORIOS DE TAMAÑO "t"
                            CargarVectorCambio(v3, t);
                            ///EN EL VECTOR DADOS ORIGINAL SE REEMPLAZAN LAS POSICIONES INDICADAS POR EL USUARIO, CON EL NUEVO VECTOR ALEATORIO TAMAÑO "t".
                            CambiarDados(v, v2, v3, t);

                            system("pause");
                            system("cls");

                            cout << "\t\t\t\t Partida de " << nombre << "\t\t" << endl;
                            cout << endl << endl;

                            MuestraRondaTiroPuntos(ContRonda, ContTiros, AcumPtos);

                            MostrarDados(v);

                            cout << endl << endl;

                            }

                            ///SI "t" ES 5, NO PREGUNTA CUÁLES DADOS QUIERE VOLVER A TIRAR, SINO QUE TIRA LOS 5 AUTOMATICAMENTE
                            else{
                                TirarDados(v, MODO);
                                system("cls");

                                cout << "\t\t\t\t Partida de " << nombre << "\t\t" << endl;
                                cout << endl << endl;

                                MuestraRondaTiroPuntos(ContRonda, ContTiros, AcumPtos);

                                MostrarDados(v);

                                cout << endl << endl;

                                }

                            ///OPCION DE TIRAR POR 3°VEZ

                            cout << "CONTINUAR TIRANDO? S/N: "; cin >> Respuesta2;
                            cout << endl;

                            switch(Respuesta2){
                                case 'S':
                                case 's':
                                    {///ABRE LLAVE "AUXILIAR?"

                                    ///SI "Respuesta2" ES "S", ENTRA AL SWITCH E INCREMENTA "ContTiros"
                                    ContTiros++;

                                    cout << "CUANTOS VOLVES A TIRAR?: "; cin >> t;
                                    cout << endl;

                                    ///SI "t" ES MENOR A 5, PREGUNTA CUÁLES DADOS QUIERE VOLVER A TIRAR
                                    if(t<5){

                                    int v2[t];
                                    TirarDados2(v2, t);
                                    int v3[t];

                                    cout << "CUAL/ES?:" << endl;
                                    cout << endl;

                                    ///SE REPITE LO ANTERIOR
                                    CargarVectorCambio(v3, t);
                                    CambiarDados(v, v2, v3, t);

                                    system("pause");
                                    system("cls");

                                    cout << "\t\t\t\t Partida de " << nombre << "\t\t" << endl;
                                    cout << endl << endl;

                                    MuestraRondaTiroPuntos(ContRonda, ContTiros, AcumPtos);

                                    MostrarDados(v);

                                    cout << endl << endl;
                                    }

                                    ///SI "t" ES 5, NO PREGUNTA CUÁLES DADOS QUIERE VOLVER A TIRAR, SINO QUE TIRA LOS 5 AUTOMATICAMENTE
                                    else{
                                        TirarDados(v, MODO);
                                        system("cls");

                                        cout << "\t\t\t\t Partida de " << nombre << "\t\t" << endl;
                                        cout << endl << endl;

                                        MuestraRondaTiroPuntos(ContRonda, ContTiros, AcumPtos);

                                        MostrarDados(v);

                                        cout << endl << endl;
                                     }

                                    }///CIERRA LLAVE "AUXILIAR?"

                                    break;

                                case 'N':
                                case 'n':
                                    ContTiros=3;
                                    break;

                                default:{
                                    cout<< "Ingreso de opcion incorrecta. Se volveran a tirar los dados." << endl << endl;
                                    for(int i=0;i<5;i++){
                                    v[i]=0;
                                    }
                                    }
                                    break;
                                    }///Switch RESP2

                                    }
                            break;

                        case 'N':
                        case 'n':
                            {
                            ContTiros=3;
                                }
                            break;

                        default:
                            {
                                cout << "Ingreso de opcion incorrecta. Se volveran a tirar los dados." << endl << endl;
                                for(int i=0;i<5;i++){
                                    v[i]=0;
                                    }
                                }
                             break;


                    }///Switch RESP1




                    ///UTILIZO FUNCIONES PARA ANALIZAR EL VECTOR DADOS FINAL
                    ///CADA FUNCION RETORNA UN PUNTAJE DEPENDIENDO SI SE CUMPLEN LAS CONDICIONES DE CADA UNA

                    ptosGenerala=VerificacionGENERALA(v);

                    ptosPoker=VerificacionPOKER(v[0], v[1], v[2], v[3], v[4]);

                    ptosFull=VerificacionFULL(v[0], v[1], v[2], v[3], v[4]);

                    ptosEscalera=VerificacionESCALERA(v);

                    ptos6=VerificacionDeSEIS(v);

                    ptos5=VerificacionDeCINCO(v);

                    ptos4=VerificacionDeCUATRO(v);

                    ptos3=VerificacionDeTRES(v);

                    ptos2=VerificacionDeDOS(v);

                    ptos1=VerificacionDeUNOS(v);


                    ///SE CARGA UN VECTOR CON TODOS LOS VALORES QUE RETORNAN LAS FUNCIONES ANTERIORES
                    CargarVectorPuntos(VecPuntos, ptosGenerala, ptosPoker, ptosFull, ptosEscalera, ptos6, ptos5, ptos4, ptos3, ptos2, ptos1);
                    ///DENTRO DE ESE VECTOR SE BUSCA EL MAXIMO
                    MayorPtos=BuscarPuntosMax(VecPuntos);
                    cout << "PUNTOS: " << MayorPtos << endl << endl;
                    ///SE ACUMULA EL MAXIMO
                    AcumPtos+=MayorPtos;
                    cout << endl<<endl<<endl;

                    system("pause");
                    system("cls");

                } ///CIERRA "else" SI NO SE CUMPLE GENERALA SERVIDA

                }///WHILE TIROS



            }///WHILE RONDAS


                ///SI SE CUMPLE GENERALA SERVIDA, MUESTRA UN CARTEL
                if(GeneralaServida==true){
                    cartelgenerala(nombre,AcumPtos,ContRonda);
                }
                ///SI NO SE CUMPLE, MUESTRA EL PUNTAJE FINAL, NOMBRE Y RONDAS JUGADAS
                else{
                    Puntajefinal(nombre,AcumPtos,ContRonda);
                }

                ///ANALIZA SI EL PUNTAJE OBTENIDO ES EL PUNTAJE MAXIMO
                if(ContRonda<=min_rondas||min_rondas==0){
                    if(AcumPtos>max_puntos){
                       min_rondas=ContRonda;
                       max_puntos=AcumPtos;
                       strcpy(max_name, nombre);
                       NuevoRecord(nombre);
                    }
                }
            }///CIERRA MODO DE 1 JUGADOR


                break;

            /// MODO 2 JUGADORES
            case 2: {
                char nombre1[20],nombre2[20],ganadorgrlaservida[20];

                cout << "\t\t  ------------------------------------------" << endl;
                cout << "\t\t | Bienvenidx al modo de juego: 2 JUGADORES |" << endl;
                cout << "\t\t  ------------------------------------------" << endl<<endl<<endl;
                cout << endl;

                cout << "\t\tPor favor, ingrese el nombre del Jugador 1: "<<endl<<endl;
                cout << "\t\t\t\t    "; cin >> nombre1;
                cout<<endl<<endl<<endl;
                cout << "\t\tPor favor, ingrese el nombre del Jugador 2: "<<endl<<endl;
                cout << "\t\t\t\t    "; cin >> nombre2;
                system("cls");

                /// VARIABLE QUE GUARDA LOS PUNTOS CUANDO SE HACE UN JUEGO DE NUMEROS
                int ptos1, ptos2, ptos3, ptos4, ptos5, ptos6, ptosGenerala, ptosPoker, ptosFull, ptosEscalera, VecPuntos[9], MayorPtos;
                /// CONTADOR DE RONDAS
                int ContRonda=0;
                /// VECTOR QUE SERÁ EVALUADO
                int v[5];

                /// ACUMULADOR DE PUNTOS
                int AcumPtos1=0,AcumPtos2=0;
                /// VARIABLE QUE DETERMINA EL TAMAÑO DEL NUEVO VECTOR ALEATORIO QUE SE GENERARÁ
                int t;
                /// VARIABLES CHAR SI(S) O NO(N) QUE INGRESA EL USUARIO PARA CONTINUAR TIRANDO O DEJAR DE TIRAR
                char Respuesta, Respuesta2;
                /// CONTADOR DE TURNOS PARA 2 JUGADORES
                int turno=0;
                /// CONTADOR PARA MANTENER LAS RONDA DOS JUGADAS
                int sumaronda=0;
                ///GUARDA PUNTOS DE GENERALA SERVIDA
                int puntosgeneralaservida;

            ///ABRO CICLO WHILE PARA RONDAS
            while(sumaronda<(T*2) && GeneralaServida==false){
                int ContTiros=1;    ///CONTADOR DE TIROS
                if(sumaronda%2==0){ /// CONTADOR DE RONDAS, LE SUMA 1 CUANDO PASAN DOS VUELTAS.
                    ContRonda++;
                    }
                turno++;

                ///SI TURNOS ES IMPAR, JUEGA EL JUGADOR 1 Y SI PAR JUEGA JUGADOR 2
                if(turno%2!=0){
                        entreturnos(nombre1,AcumPtos1,ContRonda);
                    while(ContTiros<3){///ABRO CICLO PARA EJECUTAR 3 TIROS JUGADOR 1

                        cout << "\t\t\t\t Turno de " << nombre1 << "\t\t" << endl;
                        cout << endl << endl;

                        MuestraRondaTiroPuntos(ContRonda, ContTiros, AcumPtos1);
                        TirarDados(v, MODO);
                        MostrarDados(v);
                        cout << endl << endl<< endl<< endl;

                        ptosGenerala=VerificacionGENERALA(v);   ///<---GENERALA SERVIDA.
                        if( ptosGenerala==50 && ContTiros==1){
                            system("pause");
                            system("cls");
                            GeneralaServida=true;
                            ContTiros=3;
                            strcpy(ganadorgrlaservida, nombre1);
                            puntosgeneralaservida=AcumPtos1;
                        }
                        else{


                        ///OPCION DE TIRAR POR 2°VEZ

                        cout << "CONTINUAR TIRANDO? S/N: "; cin >> Respuesta;
                        cout << endl;



                        switch(Respuesta){

                            case 'S':
                            case 's':
                                {

                                ContTiros++;

                                cout << "CUANTOS VOLVES A TIRAR?: "; cin >> t;
                                cout << endl;
                                if(t<5){ ///<--- TIRA LOS 5 DADOS SIN PREGUNTAR CUALES.
                                int v2[t];
                                TirarDados2(v2, t);

                                int v3[t];
                                cout << "CUAL/ES?: " << endl;
                                cout << endl;

                                CargarVectorCambio(v3, t);
                                CambiarDados(v, v2, v3, t);

                                system("pause");
                                system("cls");

                                cout << "\t\t\t\t Turno de " << nombre1 << "\t\t" << endl;
                                cout << endl << endl;

                                MuestraRondaTiroPuntos(ContRonda, ContTiros, AcumPtos1);

                                MostrarDados(v);
                                cout << endl << endl;

                                }
                                else{
                                    TirarDados(v, MODO);
                                    system("cls");

                                    cout << "\t\t\t\t Turno de " << nombre1 << "\t\t" << endl;
                                    cout << endl << endl;

                                    MuestraRondaTiroPuntos(ContRonda, ContTiros, AcumPtos1);

                                    MostrarDados(v);
                                    cout << endl << endl;

                                    }
                                ///OPCION DE TIRAR POR 3°VEZ

                                cout << "CONTINUAR TIRANDO? S/N: "; cin >> Respuesta2;
                                cout << endl;

                                switch(Respuesta2){
                                    case 'S':
                                    case 's':
                                        {
                                        ContTiros++;

                                        cout << "CUANTOS VOLVES A TIRAR?: "; cin >> t;
                                        cout << endl;
                                        if(t<5){  ///<--- TIRA LOS 5 DADOS SIN PREGUNTAR CUALES.
                                        int v2[t];
                                        TirarDados2(v2, t);
                                        int v3[t];

                                        cout << "CUAL/ES?:" << endl;
                                        cout << endl;

                                        CargarVectorCambio(v3, t);
                                        CambiarDados(v, v2, v3, t);

                                        system("pause");
                                        system("cls");

                                        cout << "\t\t\t\t Turno de " << nombre1 << "\t\t" << endl;
                                        cout << endl << endl;

                                        MuestraRondaTiroPuntos(ContRonda, ContTiros, AcumPtos1);
                                        MostrarDados(v);
                                        cout << endl << endl;

                                        }
                                        else{
                                            TirarDados(v, MODO);
                                            system("cls");

                                            cout << "\t\t\t\t Turno de " << nombre1 << "\t\t" << endl;
                                            cout << endl << endl;

                                            MuestraRondaTiroPuntos(ContRonda, ContTiros, AcumPtos1);

                                            MostrarDados(v);
                                            cout << endl << endl;
                                        }
                                        }

                                        break;

                                    case 'N':
                                    case 'n':
                                        ContTiros=3;
                                        break;

                                    default:{
                                        cout<< "Ingreso de opcion incorrecta. Se volveran a tirar los dados." << endl << endl;
                                         for(int i=0;i<5;i++){
                                            v[i]=0;
                                            }
                                        }
                                        break;
                                        }///Switch RESP2

                                        }
                                break;

                            case 'N':
                            case 'n':
                                {
                                ContTiros=3;
                                    }
                                break;

                            default:
                                {
                                    cout << "Ingreso de opcion incorrecta. Se volveran a tirar los dados." << endl << endl;
                                     for(int i=0;i<5;i++){
                                    v[i]=0;
                                    }
                                     }
                                 break;


                        }///Switch RESP1


                    }


                    ///UTILIZO FUNCIONES PARA ANALIZAR EL VECTOR DADOS FINAL
                    ///CADA FUNCION RETORNA UN PUNTAJE DEPENDIENDO SI SE CUMPLEN LAS CONDICIONES DE CADA UNA

                    ptosGenerala=VerificacionGENERALA(v);

                    ptosPoker=VerificacionPOKER(v[0], v[1], v[2], v[3], v[4]);

                    ptosFull=VerificacionFULL(v[0], v[1], v[2], v[3], v[4]);

                    ptosEscalera=VerificacionESCALERA(v);

                    ptos6=VerificacionDeSEIS(v);

                    ptos5=VerificacionDeCINCO(v);

                    ptos4=VerificacionDeCUATRO(v);

                    ptos3=VerificacionDeTRES(v);

                    ptos2=VerificacionDeDOS(v);

                    ptos1=VerificacionDeUNOS(v);


                    ///SE CARGA UN VECTOR CON TODOS LOS VALORES QUE RETORNAN LAS FUNCIONES ANTERIORES
                    CargarVectorPuntos(VecPuntos, ptosGenerala, ptosPoker, ptosFull, ptosEscalera, ptos6, ptos5, ptos4, ptos3, ptos2, ptos1);
                    ///DENTRO DE ESE VECTOR SE BUSCA EL MAXIMO
                    MayorPtos=BuscarPuntosMax(VecPuntos);
                    cout << "PUNTOS: " << MayorPtos << endl << endl;
                    ///SE ACUMULA EL MAXIMO
                    AcumPtos1+=MayorPtos;
                    cout << endl<<endl<<endl;

                        system("pause");
                        system("cls");




                    }///WHILE TIROS
                }
                else{
                    entreturnos(nombre2,AcumPtos2,ContRonda);
                    while(ContTiros<3){ ///ABRO CICLO PARA EJECUTAR 3 TIROS PARA JUGADOR 2

                        cout << "\t\t\t\t Turno de " << nombre2 << "\t\t" << endl;
                        cout << endl << endl;

                        MuestraRondaTiroPuntos(ContRonda, ContTiros, AcumPtos2);
                        TirarDados(v, MODO);
                        MostrarDados(v);
                        cout << endl << endl<< endl<< endl;

                        ptosGenerala=VerificacionGENERALA(v);   ///<---GENERALA SERVIDA.
                        if( ptosGenerala==50 && ContTiros==1){
                            system("pause");
                            system("cls");
                            GeneralaServida=true;
                            ContTiros=3;
                            strcpy(ganadorgrlaservida, nombre2);
                            puntosgeneralaservida=AcumPtos2;
                        }
                        else{


                        ///OPCION DE TIRAR POR 2°VEZ

                        cout << "CONTINUAR TIRANDO? S/N: "; cin >> Respuesta;
                        cout << endl;



                        switch(Respuesta){

                            case 'S':
                            case 's':
                                {

                                ContTiros++;

                                cout << "CUANTOS VOLVES A TIRAR?: "; cin >> t;
                                cout << endl;
                                if(t<5){ ///<--- TIRA LOS 5 DADOS SIN PREGUNTAR CUALES.
                                int v2[t];
                                TirarDados2(v2, t);

                                int v3[t];
                                cout << "CUAL/ES?: " << endl;
                                cout << endl;

                                CargarVectorCambio(v3, t);
                                CambiarDados(v, v2, v3, t);

                                system("pause");
                                system("cls");

                                cout << "\t\t\t\t Turno de " << nombre2 << "\t\t" << endl;
                                cout << endl << endl;

                                MuestraRondaTiroPuntos(ContRonda, ContTiros, AcumPtos2);
                                MostrarDados(v);
                                cout << endl << endl;

                                }
                                else{
                                    TirarDados(v, MODO);
                                    system("cls");

                                    cout << "\t\t\t\t Turno de " << nombre2 << "\t\t" << endl;
                                    cout << endl << endl;

                                    MuestraRondaTiroPuntos(ContRonda, ContTiros, AcumPtos2);

                                    MostrarDados(v);
                                    cout << endl << endl;

                                    }
                                ///OPCION DE TIRAR POR 3°VEZ

                                cout << "CONTINUAR TIRANDO? S/N: "; cin >> Respuesta2;
                                cout << endl;

                                switch(Respuesta2){
                                    case 'S':
                                    case 's':
                                        {
                                        ContTiros++;

                                        cout << "CUANTOS VOLVES A TIRAR?: "; cin >> t;
                                        cout << endl;
                                        if(t<5){  ///<--- TIRA LOS 5 DADOS SIN PREGUNTAR CUALES.
                                        int v2[t];
                                        TirarDados2(v2, t);
                                        int v3[t];

                                        cout << "CUAL/ES?:" << endl;
                                        cout << endl;

                                        CargarVectorCambio(v3, t);
                                        CambiarDados(v, v2, v3, t);

                                        system("pause");
                                        system("cls");

                                        cout << "\t\t\t\t Turno de " << nombre2 << "\t\t" << endl;
                                        cout << endl << endl;

                                        MuestraRondaTiroPuntos(ContRonda, ContTiros, AcumPtos2);

                                        MostrarDados(v);
                                        cout << endl << endl;
                                        }
                                        else{
                                            TirarDados(v, MODO);
                                            system("cls");

                                            cout << "\t\t\t\t Turno de " << nombre2 << "\t\t" << endl;
                                            cout << endl << endl;

                                            MuestraRondaTiroPuntos(ContRonda, ContTiros, AcumPtos2);

                                            MostrarDados(v);
                                            cout << endl << endl;
                                        }
                                        }

                                        break;

                                    case 'N':
                                    case 'n':
                                        ContTiros=3;
                                        break;

                                    default:{
                                        cout<< "Ingreso de opcion incorrecta. Se volveran a tirar los dados." << endl << endl;
                                         for(int i=0;i<5;i++){
                                            v[i]=0;
                                            }
                                        }
                                        break;
                                        }///Switch RESP2

                                        }
                                break;

                            case 'N':
                            case 'n':
                                {
                                ContTiros=3;
                                    }
                                break;

                            default:
                                {
                                    cout << "Ingreso de opcion incorrecta. Se volveran a tirar los dados." << endl << endl;
                                     for(int i=0;i<5;i++){
                                            v[i]=0;
                                            }
                                    }
                                 break;


                        }///Switch RESP1


                         ///UTILIZO FUNCIONES PARA ANALIZAR EL VECTOR DADOS FINAL
                    ///CADA FUNCION RETORNA UN PUNTAJE DEPENDIENDO SI SE CUMPLEN LAS CONDICIONES DE CADA UNA

                    ptosGenerala=VerificacionGENERALA(v);

                    ptosPoker=VerificacionPOKER(v[0], v[1], v[2], v[3], v[4]);

                    ptosFull=VerificacionFULL(v[0], v[1], v[2], v[3], v[4]);

                    ptosEscalera=VerificacionESCALERA(v);

                    ptos6=VerificacionDeSEIS(v);

                    ptos5=VerificacionDeCINCO(v);

                    ptos4=VerificacionDeCUATRO(v);

                    ptos3=VerificacionDeTRES(v);

                    ptos2=VerificacionDeDOS(v);

                    ptos1=VerificacionDeUNOS(v);


                    ///SE CARGA UN VECTOR CON TODOS LOS VALORES QUE RETORNAN LAS FUNCIONES ANTERIORES
                    CargarVectorPuntos(VecPuntos, ptosGenerala, ptosPoker, ptosFull, ptosEscalera, ptos6, ptos5, ptos4, ptos3, ptos2, ptos1);
                    ///DENTRO DE ESE VECTOR SE BUSCA EL MAXIMO
                    MayorPtos=BuscarPuntosMax(VecPuntos);
                    cout << "PUNTOS: " << MayorPtos << endl << endl;
                    ///SE ACUMULA EL MAXIMO
                    AcumPtos2+=MayorPtos;
                    cout << endl<<endl<<endl;

                    system("pause");
                    system("cls");

                        }
                    }///WHILE TIROS

                }
                sumaronda++;
                }///Fin del while de las rondas.

                if(GeneralaServida==true){ ///<---GENERALA SERVIDA DE DOS JUGADORES.
                    cartelgenerala(ganadorgrlaservida,puntosgeneralaservida,ContRonda);
                    }
                    else{    ///<<<---MUESTRA PUNTAJE DE LOS DOS JUGADORES Y QUIEN FUE EL GANADOR.
                        Puntajefinal(nombre1,AcumPtos1,ContRonda);
                        Puntajefinal(nombre2,AcumPtos2,ContRonda);

                        if(AcumPtos1>AcumPtos2){/// IF PARA EL GANADOR.
                            ganador2jugadores(nombre1,AcumPtos1,ContRonda);
                            if(ContRonda<=min_rondas || min_rondas==0){ ///<---- PUNTAJE MAXIMO
                            if(AcumPtos1>max_puntos){
                                min_rondas=ContRonda;
                                max_puntos=AcumPtos1;
                                strcpy(max_name, nombre1);
                                NuevoRecord(nombre1);
                                }
                            }
                            }
                        else{
                            ganador2jugadores(nombre2,AcumPtos2,ContRonda);
                            if(ContRonda<=min_rondas || min_rondas==0){ ///<---- PUNTAJE MAXIMO
                            if(AcumPtos2>max_puntos){
                                min_rondas=ContRonda;
                                max_puntos=AcumPtos2;
                                strcpy(max_name, nombre2);
                                NuevoRecord(nombre2);
                                }
                            }
                            }
                        }
        }/// FIN DOS JUGADORES
                break;
            case 3: { /// PUNTAJES MAXIMOS ///ARREGLARLOS.

                cout<<endl<<endl<<endl<<endl;
                cout<<endl<<endl<<endl;
                cout<<endl<<endl<<endl;
                cout<<"         -------------------------------------------------------------"                 <<endl<<endl;
                cout<<"\t   MAXIMA PUNTUACION: "<<max_name<<" CON: "<<min_rondas<<" RONDAS Y " <<max_puntos<<" PUNTOS"<<endl<<endl;
                cout<<"         -------------------------------------------------------------"                  <<endl;
                cout<<endl<<endl<<endl<<endl;
                cout<<endl<<endl<<endl<<endl;
                system("pause");
                system("cls");

            }
                break;
            case 4: { /// SALIR DEL JUEGO
                Saludo();
                return 0;
                }
                break;
            default:{/// OPCION INCORRECTA
                locate(7,12);
                cout<<"\t\t\t INGRESASTE UNA OPCION INCORRECTA."<<endl;
                locate(1,23);
                system("pause");
                system("cls");
                }
                break;

                }///switch

            }

    return 0;

}
