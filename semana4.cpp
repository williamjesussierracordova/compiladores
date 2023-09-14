#include<iostream>
#include <sstream>
#include <vector>
#include<cstdlib>
#include<ctime>

using namespace std;
vector<string> expresionR;
vector<string> expresionR2;
void identificador(string expresion);
void identificador2(int expresiones);
string expresiones1(int posicion);

int main(){
    srand(time(NULL));
    string expresion;
    int numeroExpresiones;
    cin>>expresion;
    identificador(expresion);

    cout<<"Cuantas expresiones regulares desea imprimir:";
    cin>>numeroExpresiones;

    identificador2(numeroExpresiones);
}


void identificador(string expresion) {
    
    string expresion_aux;

    for (int i = 0; i < expresion.length(); i++) {
        if (expresion[i] == '|') {
            expresionR.push_back(expresion_aux);
            expresion_aux = "";  // Reiniciar expresion_aux
            i++; // es para saltar el segundo "|"
        } else {
            expresion_aux += expresion[i];
        }
    }

    // para guardar la ultima parte de la expresion en el vector
    if (!expresion_aux.empty()) {
        expresionR.push_back(expresion_aux);
    }

    for (const string& partes : expresionR) {
        cout << "Parte: " << partes << endl;
    }
}

void identificador2(int expresiones){
    for(int i=0;i<expresiones;i++){
        int posicion = rand() % expresionR.size(); 
        string expresion=expresiones1(posicion);
        cout<<"la expresion "+ to_string(i+1) +" es: "+expresion<<endl; 
        cout<<endl<<endl;
    }
}

string expresiones1(int posicion){
    string expresion_aux;
    string expresion_aux2;
    string expresion_aux3;    
    cout<<expresionR[posicion]<<endl;
    for(int p=0;p<expresionR[posicion].length();p++){
            if(expresionR[posicion][p]!='*' && expresionR[posicion][p+1]=='*'){
                int repeticiones = rand() % 10 ; 
                for(int r=0;r<repeticiones;r++){
                    expresion_aux3=expresionR[posicion][p];
                    expresion_aux2+=expresion_aux3;
                }
                p++;
            }
            else{
                expresion_aux2+=expresionR[posicion][p];
            }
        }
        return expresion_aux2;
}

