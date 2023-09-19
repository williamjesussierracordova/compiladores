#include<iostream>
#include <sstream>
#include <vector>
#include<cstdlib>
#include<ctime>

using namespace std;
vector<string> expresionR;
vector<string> expresionR2;
void identificador(string expresion);
void imprimir_expresiones(int expresiones);
string expresiones1(int posicion);
string identificador_parentesis(string expresion1);
string expresionRecursiva(string expresion);

int main(){
    srand(time(NULL));
    string expresion;
    int numeroExpresiones;
    cin>>expresion;
    identificador(expresion);

    cout<<"Cuantas expresiones regulares desea imprimir:";
    cin>>numeroExpresiones;

    imprimir_expresiones(numeroExpresiones);
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


void imprimir_expresiones(int expresiones){
    string expresionP;
    string expresionP2;
    string expresionAux;
    for(int i=0;i<expresiones;i++){
        int posicion = rand() % expresionR.size(); 
        /*if(expresionR[posicion][0]=='('){
            expresionP=identificador_parentesis(expresionR[posicion]);
            expresionP2=expresionRecursiva(expresionP);
            if(expresionR[posicion][expresionR[posicion].length()-1]=='*'){
                int repeticiones = 0 + rand() % 10 ;
                expresionAux=expresionP2;
                for(int r=0;r<repeticiones;r++){
                    expresionP2+=expresionAux;
                } 
            }
            cout<<"la expresionP "+ to_string(i+1) +" es: "+expresionP2<<endl; 
        }
        else{*/
            string expresion=expresiones1(posicion);
            cout<<"la expresion "+ to_string(i+1) +" es: "+expresion<<endl; 
        /*}*/

        /*string expresion=expresiones1(posicion);
        cout<<"la expresion "+ to_string(i+1) +" es: "+expresion<<endl; 
        cout<<expresionP2<<endl;*/
        cout<<endl<<endl;
    }
}

string expresiones1(int posicion){
    string expresion_aux;
    string expresion_aux2;
    string expresion_aux3;  
    string expresion_aux4;  
    string expresion_aux5;
    string expresion_aux6;
    cout<<expresionR[posicion]<<endl;
    for(int p=0;p<expresionR[posicion].length();p++){
            if(expresionR[posicion][p]=='('){
                for(int r=p;r<expresionR[posicion].length();r++){
                    if(expresionR[posicion][r]==')'){
                        for(int m=p+1;m<r;m++){
                            expresion_aux4+=expresionR[posicion][m];
                            expresion_aux5+=expresion_aux4;
                            expresion_aux4="";
                        }

                    	cout<<"expresion_aux5: "<<expresion_aux5<<endl;

                        expresion_aux6=expresionRecursiva(expresion_aux5);

                        cout<<"expresion_aux6: "<<expresion_aux6<<endl;
                        if(expresionR[posicion][r+1]=='*'){
                            int repeticiones = 0 + rand() % 10 ;
                            for(int z=0;z<repeticiones;z++){
                                expresion_aux2+=expresion_aux6;
                            }
                            p=p+expresion_aux5.length()+2;
                        }
                        else{
                            expresion_aux2+=expresion_aux6;
                            p=p+expresion_aux5.length()+1;
                        }
                        break;
                    }
                    else{

                    }
                }
                expresion_aux5="";
                
            }
            else if(expresionR[posicion][p]!=')' && expresionR[posicion][p+1]=='*'){
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

string identificador_parentesis(string expresion1){
    string expresion;
    for(int i=0;i<=expresion1.length();i++){
        if(expresion1[i]=='('){
            int j=i+1;
            while(expresion1[j]!=')'){
                expresion+=expresion1[j];
                j++;
            }
            i=j;
            break;
        }
        else{
            expresion+=expresion1[i];
        }
    }
    
    return expresion;
}

string expresionRecursiva(string expresion){
string expresion_aux;
    string expresion_aux2;
    string expresion_aux3;    
    for(int p=0;p<expresion.length();p++){
            if(expresion[p]!='*' && expresion[p+1]=='*'){
                int repeticiones = rand() % 10 ; 
                for(int r=0;r<repeticiones;r++){
                    expresion_aux3=expresion[p];
                    expresion_aux2+=expresion_aux3;
                }
                p++;
            }
            else{
                expresion_aux2+=expresion[p];
            }
        }
        return expresion_aux2;
        
}