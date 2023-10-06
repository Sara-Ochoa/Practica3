#include <iostream>
#include <fstream>

using namespace std;

void MenuPrincipal();
void MenuUno();
void MenuDos();
void Metodo();
int BinToDeci(int binario[]);
int Potencia(int base,int exp);
void DeciToBin(char letra, int* Binario);
void MetodoUno();
void MetodoDos();

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
                    string InfoBin;
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
                                InfoBin +=Binario[i];
                            }
                        }
                    }
                    cout<<InfoBin<<endl;
                    archivoEscritura.close();
                    archivoLectura.close();

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
                            archivoLectura.open("binario.txt");
                            archivoEscritura.open(nomArchivo);
                            for(int i=0; i<semilla; i++){
                                char temp = archivoLectura.get();
                                if(archivoLectura.good()){
                                    binario[i]=temp;
                                }
                            }
                            for(int i=0; i<semilla; i++){
                                if(binario[i]=='1'){
                                    codificado[i]=0;
                                    archivoEscritura<<codificado[i];
                                }
                                else{
                                    codificado[i]=1;
                                    archivoEscritura<<codificado[i];
                                }
                            }
                            /*Invocar la funcion del metodo 1 para codificar
                            se le pasan los arreglos por referencia
                            Los escribe en el archivo
                            luego se aumenta los valores de i y semilla para obtener el otro arreglo (cuaderno)
                            O revisar el link que esta en wpp para trabajar con strings
                            */
                            archivoEscritura.close();
                            archivoLectura.close();
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

void MetodoUno(){
    //Esta funcion realiza la codificacion (decodificacion) correspondiente al metodo uno
}
