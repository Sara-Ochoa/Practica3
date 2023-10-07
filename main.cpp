#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void MenuPrincipal();
void MenuUno();
void MenuDos();
void Metodo();
int BinToDeci(int binario[]);
int Potencia(int base,int exp);
void DeciToBin(char letra, int* Binario);
void MetodoUno(int* codificado, int* binario, int semilla);
void MetodoDos(int* codificado, int* binario, int semilla);

int main()
{
    int opcion=1;
    while(opcion!=0){
        MenuPrincipal();//Menu principal
        cin>>opcion;
        switch (opcion) {
        case 1://Ejercicio 1
        {
            int opcion=1;
            while(opcion!=0){
                MenuUno();//Pregunta si quiere codificar o decodificar un archivo
                cin>>opcion;
                switch (opcion) {
                case 1://Quiere codificar un archivo
                {
                    ifstream archivoLectura;
                    ofstream archivoEscritura;
                    string nombreArchivo;
                    string nomArchivo;
                    cout<<"Ingrese el nombre del archivo: "<<endl;
                    cin>>nombreArchivo; //ESTE ES EL QUE SE PASA PARA QUE SE ABRA
                    cout<<"Ingrese el nombre del archivo que contendra el codificado: "<<endl;
                    cin>>nomArchivo;
                    archivoLectura.open(nombreArchivo);
                    archivoEscritura.open("binario.txt");
                    while(archivoLectura.good()){
                        char temp = archivoLectura.get();//LO QUE ESTÁ EN TEMP CONVERTIRLO A BINARIO Y LUEGO ESCRIBIRLO
                        if(archivoLectura.good()){
                            int Binario[8];
                            DeciToBin(temp, Binario);

                            for(int i=7; i>=0; i--){
                                archivoEscritura<<Binario[i];
                            }
                        }
                    }
                    archivoEscritura.close();
                    archivoLectura.close();

                    archivoLectura.open("binario.txt");

                    if (!archivoLectura.is_open()){
                        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
                    }

                    string contenido;//Aquí está almacenado el binario
                    string linea;

                    while (getline(archivoLectura, linea)) {
                        contenido += linea + "\n"; // Agrega cada línea al contenido
                    }
                    archivoLectura.close();

                    //cout<<"El binario es: "<<contenido<<endl;

                    int semilla=0;
                    cout<<"Ingrese la semilla de codificacion: "<<endl;
                    cin>>semilla;
                    cout<<"Con cual metodo quiere codificar el archivo?"<<endl;
                    int opcion=1;
                    while(opcion!=0){
                        Metodo();//Metodo de codificacion
                        cin>>opcion;
                        switch (opcion) {
                        case 1://Metodo 1
                        {

                            int binario[semilla];
                            int codificado[semilla];

                            archivoEscritura.open(nomArchivo);
                            /*//Esto ya no se hace porque la info la tengo en el string, por lo que no tengo que leerel archivo.
                            for(int i=0; i<semilla; i++){
                                char temp = archivoLectura.get();
                                if(archivoLectura.good()){
                                    binario[i]=temp;
                                }
                            }*/

                            for(int i=0; ; i+semilla){
                                for(int j=0; j<semilla; j++){
                                    binario[j]=contenido[j];
                                }
                            }






                            /*
                            for(int i=0; i<semilla; i++){
                                if(binario[i]=='1'){
                                    codificado[i]=0;
                                    archivoEscritura<<codificado[i];
                                }
                                else{
                                    codificado[i]=1;
                                    archivoEscritura<<codificado[i];
                                }
                            }*/


                            archivoEscritura.close();

                            break;
                        }
                        case 2://Metodo 2
                        {
                            break;
                        }
                        default:
                            if(opcion!=0)
                                cout<<"La opcion no valida"<<endl;
                            break;
                        }
                    }
                    break;
                }
                case 2://Quiere decodificar un archivo
                {
                    int semilla=0;
                    cout<<"Cual fue la semilla de codificacion que uso: "<<endl;
                    cin>>semilla;
                    cout<<"Con cual metodo codifico el archivo?"<<endl;
                    int opcion=1;
                    while(opcion!=0){
                        Metodo();
                        cin>>opcion;
                        switch (opcion) {
                        case 1:

                            break;
                        case 2:

                            break;
                        default:
                            if(opcion!=0)
                                cout<<"La opcion no valida"<<endl;
                            break;
                        }
                    }
                    break;
                }
                default:
                    if(opcion!=0)
                        cout<<"La opcion no valida"<<endl;
                    break;
                }
            }
            break;
        }
        case 2://Ejercicio 2
        {
            int opcion=1;
            while(opcion!=0){
                MenuDos();
                cin>>opcion;
                switch (opcion) {
                case 1:
                    break;
                case 2:
                    break;
                default:
                    if(opcion!=0)
                        cout<<"La opcion no valida"<<endl;
                    break;
                }
            }
            break;
        }
        default:
            if(opcion!=0)
                cout<<"La opcion no valida"<<endl;
            break;
        }
    }
    return 0;
}

void MenuPrincipal(){
    cout<<endl;
    cout<<"*********** Menu practica 3 ***********"<<endl;
    cout<<endl;
    cout<<"1. Ejercicio uno"<<endl;
    cout<<"2. Ejercicio dos"<<endl;
    cout<<"0.Para salir"<<endl;
}

void MenuUno(){
    cout<<endl;
    cout<<"*********** Ejercicio 1 ***********"<<endl;
    cout<<endl;
    cout<<"1. Codificar un archivo"<<endl;
    cout<<"2. Decodificar un archivo"<<endl;
    cout<<"0.Para salir"<<endl;
}

void MenuDos(){
    cout<<endl;
    cout<<"*********** Ejercicio 2 ***********"<<endl;
    cout<<endl;
    cout<<"1. Acceder como administrador"<<endl;
    cout<<"2. Acceder como usuario"<<endl;
    cout<<"0.Para salir"<<endl;
}

void Metodo(){
    cout<<endl;
    cout<<"*********** Metodo ***********"<<endl;
    cout<<endl;
    cout<<"1. Metodo uno"<<endl;
    cout<<"2. Metodo dos"<<endl;
    cout<<"0.Para salir"<<endl;
}

int BinToDeci(int binario[]){
    //Esta funcion convierte un numero binario a decimal
    int decimal=0;
    for(int i=7, e=0; i>=0; i--, e++){
        decimal += binario[i]*Potencia(2, e);
    }
    return decimal;
}

int Potencia(int base, int exp){
    //Esta funcion calcula la potencia de un numero (base) elevado a exp
    int x=1;
    for(int i=0; i<exp; i++){
        x *= base;
    }
    return x;
}

void DeciToBin(char letra, int* Binario){
    //Esta funcion convierte un caracter a su representacion binaria
    for(int i=0; i<8; i++){
        Binario[i] = letra % 2;
        letra /= 2;
    }
}

void MetodoUno(int* codificado, int* binario, int semilla){
    //Esta funcion realiza la codificacion (decodificacion) correspondiente al metodo uno
    int unos=0;
    int ceros=0;
    //Hacer un for que cuente cuantos 1 y 0 hay

    for(int i=0; i<semilla; i++){
        if(binario[i]=='0')
            ceros += 1;
        else
            unos += 1;
    }

    //Si hay igual cantidad, se invierten todos los bits

    if(ceros == unos){
        for(int i=0; i<semilla; i++){
            if(binario[i]=='1'){
                codificado[i]=0;
            }
            else{
                codificado[i]=1;
            }
        }
    }

    //Si hay mas 0, se invierten cada dos bits

    else if(ceros>unos){
        for(int i=0; i<semilla; i+2){
            if(binario[i]=='1'){
                codificado[i]=0;
            }
            else{
                codificado[i]=1;
            }
        }
    }

    //Sino, se invierten cada 3 bits
    else{
        if(ceros>unos){
            for(int i=0; i<semilla; i+2){
                if(binario[i]=='1'){
                    codificado[i]=0;
                }
                else{
                    codificado[i]=1;
                }
            }
        }
    }
}

void MetodoDos(int* codificado, int* binario, int semilla){
    //Esta función realiza la codificacion (decodificacion) correspondiente al metodo dos
    for(int i=semilla-1; i>semilla-2; i--){
        for(int j=0; j<1; j++){
            codificado[j]=binario[i];
        }
        for(int k=1; k<semilla; k++){
            for(int j=1; j<semilla; j++){
                codificado[j]=binario[k];
            }
        }
    }
}










