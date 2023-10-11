#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void MenuPrincipal();
void MenuUno();
void Metodo();
int BinToDeci(int* binario);
int Potencia(int base,int exp);
void DeciToBin(char letra, int* Binario);
void MetodoUno(char* codificado, char* binario, char* copia, int semilla);
void MetodoDos(char* codificado, char* binario, int semilla);
void MetodoDosDecod(char* codificado, char* binario, int semilla);

int main()
{
    int opcion=1;
    try
    {
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
                    cin>>nombreArchivo; //ESTE ES EL QUE SE PASA PARA QUE SE ABRA Y TIENE QUE ESTAR EN EL PC YA CREADO
                    cout<<"Ingrese el nombre del archivo que contendra el codificado: "<<endl;
                    cin>>nomArchivo;
                    archivoLectura.open(nombreArchivo);
                    archivoEscritura.open("binario.txt");
                    if(archivoLectura.is_open()){
                        if(archivoEscritura.is_open()){
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
                        }
                        else{
                            throw'2';
                        }
                    }
                    else{
                        throw '1';
                    }

                    string contenido;//Aquí está almacenado el binario
                    string linea;
                    archivoLectura.open("binario.txt");

                    if (archivoLectura.is_open()){
                        while (getline(archivoLectura, linea)) {
                            contenido += linea + "\n"; // Agrega cada línea al contenido
                        }
                        archivoLectura.close();
                    }
                    else{
                        throw '1';
                    }


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

                            char binario[semilla];
                            char copia[semilla];
                            char codificado[semilla];

                            archivoEscritura.open(nomArchivo);
                            if(archivoEscritura.is_open()){
                                for(size_t i=0; i<contenido.length()-1;){
                                    for(int j=0; j<semilla; j++){
                                        binario[j]=contenido[i+j];
                                        if(i==0){
                                            copia[j]=binario[j];
                                        }
                                    }

                                    if(i==0){//Esto es para que invierta todos los elementos del primer grupo no más
                                        for(int i=0; i<semilla; i++){
                                            if(binario[i]=='1'){
                                                codificado[i]='0';
                                                archivoEscritura<<codificado[i];
                                            }
                                            else{
                                                codificado[i]='1';
                                                archivoEscritura<<codificado[i];
                                            }
                                        }
                                    }
                                    else{
                                        //Invocar el método uno

                                        for(int i=0; i<semilla; i++){
                                            codificado[i]=binario[i];
                                        }
                                        MetodoUno(codificado, binario, copia, semilla);

                                        for(int i=0; i<semilla; i++){
                                            archivoEscritura<<codificado[i];
                                        }

                                        for(int j=0; j<semilla; j++){
                                            copia[j]=binario[j];
                                        }
                                    }
                                    i = i+semilla;
                                }
                                archivoEscritura.close();
                            }
                            else{
                                throw '2';
                            }

                            break;
                        }
                        case 2://Metodo 2
                        {

                            char binario[semilla];
                            char codificado[semilla];

                            archivoEscritura.open(nomArchivo);

                            if(archivoEscritura.is_open()){
                                for(size_t i=0; i<contenido.length()-1;){
                                    for(int j=0; j<semilla; j++){
                                        binario[j]=contenido[i+j];
                                    }
                                    //Invocar el metodo dos
                                    MetodoDos(codificado, binario, semilla);

                                    for(int i=0; i<semilla; i++){
                                        archivoEscritura<<(codificado[i]-48);
                                    }
                                    i = i+semilla;
                                }
                                archivoEscritura.close();
                            }
                            else{
                                throw '2';
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
                case 2://Quiere decodificar un archivo
                {

                    ifstream archivoLectura;
                    ofstream archivoEscritura;
                    string nombreArchivo;
                    string nomArchivo;
                    cout<<"Ingrese el nombre del archivo donde se guardo el codificado: "<<endl;
                    cin>>nombreArchivo; //ESTE ES EL QUE SE PASA PARA QUE SE ABRA EL CODIFICADO QUE ESTA GUARDADO EN EL PC
                    cout<<"Ingrese el nombre del archivo que contendra el decodificado: "<<endl;
                    cin>>nomArchivo;

                    string contenido;//Aquí está almacenado el codificado
                    string linea;
                    archivoLectura.open(nombreArchivo);

                    if (archivoLectura.is_open()){
                        while (getline(archivoLectura, linea)) {
                            contenido += linea + "\n"; // Agrega cada línea al contenido
                        }
                        archivoLectura.close();
                    }
                    else{
                        throw '1';
                    }

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
                        {
                            char binario[semilla];
                            char copia[semilla];
                            char codificado[semilla];

                            archivoEscritura.open("binarioM1.txt");

                            if(archivoEscritura.is_open()){
                                for(size_t i=0; i<contenido.length()-1;){
                                    for(int j=0; j<semilla; j++){
                                        codificado[j]=contenido[i+j];
                                    }

                                    if(i==0){//Esto es para que invierta todos los elementos del primer grupo no más
                                        for(int i=0; i<semilla; i++){
                                            if(codificado[i]=='1'){
                                                binario[i]='0';
                                                archivoEscritura<<binario[i];
                                            }
                                            else{
                                                binario[i]='1';
                                                archivoEscritura<<binario[i];
                                            }
                                        }
                                        for(int i=0; i<semilla; i++){
                                            copia[i]=binario[i];
                                        }
                                    }
                                    else{
                                        //Invocar el método uno

                                        for(int i=0; i<semilla; i++){
                                            binario[i]=codificado[i];
                                        }
                                        MetodoUno(binario, codificado, copia, semilla);

                                        for(int i=0; i<semilla; i++){
                                            archivoEscritura<<binario[i];
                                        }

                                        for(int j=0; j<semilla; j++){
                                            copia[j]=binario[j];
                                        }
                                    }
                                    i = i+semilla;
                                }
                                archivoEscritura.close();
                            }
                            else{
                                throw '2';
                            }

                            string contenido1;//Aquí está almacenado el binario
                            string linea;
                            archivoLectura.open("binarioM1.txt");

                            if (archivoLectura.is_open()){

                                while (getline(archivoLectura, linea)) {
                                    contenido1 += linea + "\n"; // Agrega cada línea al contenido
                                }
                                archivoLectura.close();
                            }
                            else{
                                throw '1';
                            }

                            int bin[8];
                            archivoEscritura.open(nomArchivo);
                            if(archivoEscritura.is_open()){
                                for(size_t i=0; i<contenido1.length()-1;){
                                    for(int j=0; j<8; j++){
                                        bin[j]=contenido1[i+j];
                                    }

                                    archivoEscritura<<static_cast<char>(BinToDeci(bin));

                                    i = i+8;
                                }
                                archivoEscritura.close();
                            }
                            else{
                                throw '2';
                            }
                            break;
                        }
                        case 2:
                        {
                            char binario[semilla];
                            char codificado[semilla];

                            archivoEscritura.open("binarioM2.txt");

                            if(archivoEscritura.is_open()){
                                for(size_t i=0; i<contenido.length()-1;){
                                    for(int j=0; j<semilla; j++){
                                        codificado[j]=contenido[i+j];
                                    }
                                    //Invocar el metodo dos
                                    MetodoDosDecod(codificado, binario, semilla);

                                    for(int i=0; i<semilla; i++){
                                        archivoEscritura<<(binario[i]-48);
                                    }
                                    i = i+semilla;
                                }
                                archivoEscritura.close();
                            }
                            else{
                                throw '2';
                            }

                            string contenido2;//Aquí está almacenado el binario
                            string linea;
                            archivoLectura.open("binarioM2.txt");

                            if (archivoLectura.is_open()){
                                while (getline(archivoLectura, linea)) {
                                    contenido2 += linea + "\n"; // Agrega cada línea al contenido
                                }
                                archivoLectura.close();
                            }
                            else{
                                throw '1';
                            }

                            int bin[8];
                            archivoEscritura.open(nomArchivo);

                            if(archivoEscritura.is_open()){
                                for(size_t i=0; i<contenido2.length()-1;){
                                    for(int j=0; j<8; j++){
                                        bin[j]=contenido2[i+j];
                                    }

                                    archivoEscritura<<static_cast<char>(BinToDeci(bin));

                                    i = i+8;
                                }
                                archivoEscritura.close();
                            }
                            else{
                                throw '2';
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
            cout<<"No lo realice"<<endl;
            break;
        }
        default:
            if(opcion!=0)
                cout<<"La opcion no valida"<<endl;
            break;
        }
    }
    }
    catch(char c){
        if(c=='1')
            cout<<"Error con el archivo de lectura"<<endl;
        else if(c=='2')
            cout<<"Error con el archivo de escritura"<<endl;
        else
            cout<<"Error inesperado"<<endl;
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

void Metodo(){
    cout<<endl;
    cout<<"*********** Metodo ***********"<<endl;
    cout<<endl;
    cout<<"1. Metodo uno"<<endl;
    cout<<"2. Metodo dos"<<endl;
    cout<<"0. Para salir"<<endl;
}

int BinToDeci(int* binario){
    //Esta funcion convierte un numero binario a decimal
    int decimal=0;
    for(int i=7, e=0; i>=0; i--, e++){
        decimal += (binario[i]-48)*Potencia(2, e);
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

void MetodoUno(char* codificado, char* binario, char* copia, int semilla){
    //Esta funcion realiza la codificacion (decodificacion) correspondiente al metodo uno
    int unos=0;
    int ceros=0;
    //Hacer un for que cuente cuantos 1 y 0 hay

    for(int i=0; i<semilla; i++){
        if(copia[i]=='0')
            ceros += 1;
        else
            unos += 1;
    }

    //Si hay igual cantidad, se invierten todos los bits

    if(ceros == unos){
        for(int i=0; i<semilla; i++){
            if(binario[i]=='1'){
                codificado[i]='0';
            }
            else{
                codificado[i]='1';
            }
        }
    }

    //Si hay mas 0, se invierten cada dos bits

    else if(ceros>unos){
        for(int i=1; i<semilla;){
            if(binario[i]=='1'){
                codificado[i]='0';
            }
            else{
                codificado[i]='1';
            }
            i=i+2;
        }
    }

    //Sino, se invierten cada 3 bits
    else{
        for(int i=2; i<semilla;){
            if(binario[i]=='1'){
                codificado[i]='0';
            }
            else{
                codificado[i]='1';
            }
            i=i+3;
        }
    }
}

void MetodoDos(char* codificado, char* binario, int semilla){
    //Esta función realiza la codificacion correspondiente al metodo dos
    for(int i=semilla-1; i>semilla-2; i--){
        for(int j=0; j<1; j++){
            codificado[j]=binario[i];
        }
    }
    for(int k=0; k<semilla-2;){
        for(int j=1; j<semilla; j++){
            codificado[j]=binario[k];
            k++;
        }
    }
}

void MetodoDosDecod(char* codificado, char* binario, int semilla){
    //Esta función realiza la decodificacion correspondiente al metodo dos
    for(int i = 1; i < semilla; i++) {
        binario[i -1] = codificado[i];
        binario[semilla -1] = codificado[0];
    }
}
