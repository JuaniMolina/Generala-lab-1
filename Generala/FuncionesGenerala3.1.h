#ifndef FUNCIONESGENERALA_H_INCLUDED
#define FUNCIONESGENERALA_H_INCLUDED
#include "windows.h"
#include "rlutil.h"
/**FUNCIONES**/

void TirarDados(int VecDados[5], bool AZAR){ ///TIRAR DADOS

    if(AZAR==true){
    srand(time(NULL));
    for(int i=0; i<5; i++){
        VecDados[i]=(rand()%6)+1;}}
    else{
        for(int i=0; i<5; i++){
            cin >> VecDados[i];
            cout << endl;}}

}


void MostrarDados(int VecDados[5]){ ///MOSTRAR DADOS

    cout << "DADOS: " << endl<< endl<< endl;
    cout << endl;

    for(int i=0; i<5; i++){
   cout << "|" << VecDados[i] << "|" << "\t";}

}


void TirarDados2(int VecDados2[], int T){ ///FUNCION UTILIZADA PARA VOLVER A TIRAR DADOS EN CASO DE QUE EL USUARIO LO DECIDA


    srand(time(NULL));
    for(int i=0; i<T; i++){
        VecDados2[i]=(rand()%6)+1;}

}


void CargarVectorCambio(int VecCambio[], int T){///FUNCION UTILIZADA PARA VOLVER A TIRAR DADOS EN CASO DE QUE EL USUARIO LO DECIDA

    int i;

    for(i=0; i<T; i++){
       cout << "DADO #"; cin >> VecCambio[i];
       cout << endl;}
}


void CambiarDados(int VecDados[], int VecDados2[], int VecIndices[] , int T){///FUNCION QUE REEMPLAZA DADOS SELECCIONADOS POR EL USUARIO

    int i, f;

    for(i=0; i<5; i++){

        for(f=0; f<T; f++){

            if(VecIndices[f]-1==i){
                VecDados[i]=VecDados2[f];}}}

}



///FUNCIONES PARA PUNTAJE/COMBINACIONES




///JUEGOS
int VerificacionGENERALA(int VecDados[5]){

    int ContIguales=1;

    for(int i=0; i<5; i++){
        if(i!=4){
            if(VecDados[i]==VecDados[i+1]){ContIguales++;}
                }
            }

    if(ContIguales==5){
            if(VecDados[1]==0){
                return 0;}
            else{
                return 50;}}
    else{return 0;}

}


int VerificacionPOKER(int d1, int d2, int d3, int d4, int d5){

   if( (d1==d2 && d1==d3 && d1==d4 && d1!=d5) ||
       (d1==d2 && d1==d3 && d1==d5 && d1!=d4) ||
       (d1==d2 && d1==d4 && d1==d5 && d1!=d3) ||
       (d1==d3 && d1==d4 && d1==d5 && d1!=d2) ||
       (d2==d3 && d2==d4 && d2==d5 && d2!=d1))
       {return 40;}

       else{return 0;}

}


int VerificacionFULL(int d1, int d2, int d3, int d4, int d5){
        if((d1==d2 && d2==d3 && d1!=d4 && d4==d5) ||
          (d1==d2 && d1==d4 && d1!=d3 && d3==d5) ||
          (d1==d3 && d1==d4 && d1!=d2 && d2==d5) ||
          (d2==d3 && d2==d4 && d2!=d1 && d1==d5) ||
          (d1==d2 && d1==d5 && d1!=d3 && d3==d4) ||
          (d1==d3 && d1==d5 && d1!=d2 && d2==d4) ||
          (d2==d3 && d3==d5 && d2!=d1 && d1==d4) ||
          (d1==d4 && d1==d5 && d1!=d2 && d2==d3) ||
          (d2==d5 && d2==d4 && d2!=d1 && d1==d3) ||
          (d3==d4 && d4==d5 && d3!=d1 && d1==d2))
        {return 30;}
        else{return 0;}
}


int VerificacionESCALERA(int VecDados[5]){

///ordena el vector de menor a mayor
int aux, c=1;

for(int i=0; i<5; i++){
        for(int j=i+1; j<5; j++){
                if(VecDados[i]>VecDados[j]){
                aux=VecDados[i];
                VecDados[i]=VecDados[j];
                VecDados[j]=aux;
                }
            }///FOR j
        }///FOR i

///verifica si es estrictamente creciente
for (int i=0; i<5; i++){
        if(VecDados[i]==VecDados[i+1]-1){
            c++;}}

if(c==5){return 25;}
else{return 0;}


}



///NUMEROS
int VerificacionDeSEIS(int VecDados[5]){

    int ContSeis=0;

    for(int i=0; i<5; i++){

        if(VecDados[i]==6){ContSeis++;}
        }

        return ContSeis*6;
}


int VerificacionDeCINCO(int VecDados[5]){

    int ContCinco=0;

    for(int i=0; i<5; i++){

        if(VecDados[i]==5){ContCinco++;}
        }

        return ContCinco*5;
}


int VerificacionDeCUATRO(int VecDados[5]){

    int ContCuatro=0;

    for(int i=0; i<5; i++){

        if(VecDados[i]==4){ContCuatro++;}
        }

        return ContCuatro*4;
}


int VerificacionDeTRES(int VecDados[5]){

    int ContTres=0;

    for(int i=0; i<5; i++){

        if(VecDados[i]==3){ContTres++;}
        }

        return ContTres*3;
}


int VerificacionDeDOS(int VecDados[5]){

    int ContDos=0;

    for(int i=0; i<5; i++){

        if(VecDados[i]==2){ContDos++;}
        }

        return ContDos*2;
}


int VerificacionDeUNOS(int VecDados[5]){

    int ContUno=0;

    for(int i=0; i<5; i++){

        if(VecDados[i]==1){ContUno++;}
        }

        return ContUno;
}



///FUNCIONES BUSCO MAYOR PUNTAJE Y ACUMULO

void CargarVectorPuntos(int Vec[10], int GENERALA, int POKER, int FULL, int ESCALERA, int SEIS, int CINCO, int CUATRO, int TRES, int DOS, int UNO){


  Vec[0]=GENERALA;
  Vec[1]=POKER;
  Vec[2]=FULL;
  Vec[3]=ESCALERA;
  Vec[4]=SEIS;
  Vec[5]=CINCO;
  Vec[6]=CUATRO;
  Vec[7]=TRES;
  Vec[8]=DOS;
  Vec[9]=UNO;




}


int BuscarPuntosMax(int Vec[]){

    int Mayor, i;

for(i=0; i<10; i++){


if(i==0 || Vec[i]>Mayor){
    Mayor=Vec[i];}

    }

    return Mayor;
}




///MENSAJES

void MuestraRondaTiroPuntos(int ContRonda, int ContTiros, int AcumPtosX){

                cout << "\t\t   ---------------------------------------" << endl;
                cout << "\t\t  | RONDA " << ContRonda << " - TIRO " << ContTiros  << " - PUNTOS TOTALES: " << AcumPtosX << "  |" << endl;
                cout << "\t\t   ---------------------------------------" << endl;
                cout << endl;


}


void entreturnos (char nombre[30], int puntos, int rondas){

    cout<<endl<<endl<<endl;
    cout<<endl<<endl<<endl;
    cout<<"\t\t\t\t   RONDA "<<rondas<<endl<<endl<<endl;
    cout<<"         -------------------------------------------------------------"<<endl<<endl;
    cout<<"\t\t\t  TURNO DE: "<<nombre<<" CON: " <<puntos<<" PUNTOS"<<endl<<endl;
    cout<<"         -------------------------------------------------------------"<<endl;
    cout<<endl<<endl<<endl<<endl;
    cout<<endl<<endl<<endl<<endl;
    Sleep(2000);
    system("cls");

}


void ganador2jugadores(char nombre[30],int puntos,int rondas){
    locate(30,9);
    cout<< "--------------------" ;
    locate(30,11);
    cout<< "   FELICITACIONES   " ;
    locate(37,13);
    cout<<nombre;
    locate(30,15);
    cout<< "--------------------" ;
    Sleep(2000);
    system("cls");

    locate(30,9);
    cout<< "---------------------" ;
    locate(30,11);
    cout<< "   G A N A S T E     " ;
    locate(30,13);
    cout<< "    LA  PARTIDA      " ;
    locate(30,15);
    cout<< "---------------------" ;
    Sleep(2000);
    system("cls");

    locate(30,9);
    cout<< "--------------------";
    locate(30,11);
    cout<< "   CON "<<puntos<<" PUNTOS";
    locate(30,13);
    cout<< "    EN "<<rondas<<" RONDAS";
    locate(30,15);
    cout<< "--------------------" ;
    locate(1,23);
    system("pause");
    system("cls");




}


void cartelgenerala(char nombre[30],int puntos, int rondas){
    locate(30,9);
    cout<< "--------------------";
    locate(30,12);
    cout<< " GENERALA  SERVIDA  ";
    locate(30,15);
    cout<< "--------------------";
    Sleep(2000);
    system("cls");

    locate(30,9);
    cout<< "--------------------";
    locate(30,11);
    cout<< "   FELICITACIONES   ";
    locate(37,13);
    cout<<nombre;
    locate(30,15);
    cout<< "--------------------";
    Sleep(2000);
    system("cls");


    locate(30,9);
    cout<< "---------------------" ;
    locate(30,11);
    cout<< "   G A N A S T E     " ;
    locate(30,13);
    cout<< "    LA  PARTIDA      " ;
    locate(30,15);
    cout<< "---------------------" ;
    Sleep(2000);
    system("cls");

    locate(30,9);
    cout<< "--------------------";
    locate(30,11);
    cout<< "   CON "<<puntos<<" PUNTOS";
    locate(30,13);
    cout<< "    EN "<<rondas<<" RONDAS";
    locate(30,15);
    cout<< "--------------------" ;
    locate(1,23);
    system("pause");
    system("cls");

}


void MenuPrincipal(){
    cout << "\t\t -------------------------------------------" << endl;
    cout << "\t\t| BIENVENIDX A GENERALA 2.0 - UTN - PACHECO |" << endl;
    cout << "\t\t -------------------------------------------" << endl;
    cout << endl << endl;


    cout << "\t\t    SELECCIONE UNA OPCION PARA COMENZAR: " << endl << endl<<endl;
    cout << endl << endl;
    cout << "\t\t        1. NUEVO JUEGO 1 JUGADOR. " << endl;
    cout << "\t\t        2. NUEVO JUEGO 2 JUGADORES." << endl;
    cout << "\t\t        3. MAXIMA PUNTUACION." << endl;
    cout << "\t\t        4. SALIR DEL JUEGO." << endl<<endl<<endl;

}


void Puntajefinal(char nombre[30],int puntos, int rondas){

    locate(30,9);
    cout << "--------------------" ;
    locate(38,11);
    cout <<nombre;
    locate(30,13);
    cout << "  PUNTAJE FINAL: " ;
    locate(47,13);
    cout<< puntos ;
    locate(30,15);
    cout << "  RONDAS       : " ;
    locate(47,15);
    cout<< rondas ;
    locate(30,17);
    cout << "--------------------" ;
    Sleep(2000);
    system("cls");

}


void NuevoRecord (char nombre[30]){
    locate(30,9);
    cout<< "---------------------" ;
    locate(30,11);
    cout<< "      N U E V O      " ;
    locate(30,13);
    cout<< "     R E C O R D     " ;
    locate(30,15);
    cout<< "---------------------" ;
    Sleep(2000);
    system("cls");
}


void GENERALA (){
    cout<<endl;
    cout<<"  ######   ######## ##    ## ######## ########     ###    ##          ###    "<<endl;
    cout<<" ##    ##  ##       ###   ## ##       ##     ##   ## ##   ##         ## ##   "<<endl;
    cout<<" ##        ##       ####  ## ##       ##     ##  ##   ##  ##        ##   ##  "<<endl;
    cout<<" ##   #### ######   ## ## ## ######   ########  ##     ## ##       ##     ## "<<endl;
    cout<<" ##    ##  ##       ##  #### ##       ##   ##   ######### ##       ######### "<<endl;
    cout<<" ##    ##  ##       ##   ### ##       ##    ##  ##     ## ##       ##     ## "<<endl;
    cout<<"  ######   ######## ##    ## ######## ##     ## ##     ## ######## ##     ## 2.0"<<endl;
    cout<<" ------------------------------------------------------------------------------"<<endl;
    cout<<" By FELI - FRAN - JUANCITO";
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<endl<<endl<<endl;
    system("pause");
    system("cls");


}


void Saludo(){
    locate(30,9);
    cout<< "---------------------";
    locate(30,11);
    cout<< "    G R A C I A S    ";
    locate(30,13);
    cout<< "      POR JUGAR      ";
    locate(30,15);
    cout<< "---------------------" ;
    Sleep(1800);
    system("cls");
}



#endif // FUNCIONESGENERALA_H_INCLUDED
