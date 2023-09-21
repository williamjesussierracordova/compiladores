#include <iostream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <math.h>


using namespace std;
string vocabulario[]={"a","b","|","(",")","*"};
int tamanio= sizeof(vocabulario)/sizeof(vocabulario[0]);

vector<string> expresionR;
vector<string> expresionR2;

void identificador(string expresion);
vector<string> identificador2(string expresion);
string interpretador(string expresion);
bool validador (string expresion,string vocabyulario[],int tamanio );


int main(){
    srand(time(NULL));
    string expresion;
    cout<<"Ingrese una expresion regular: ";cout<<endl;
    cin>>expresion;
    cout<<endl;

    if(validador(expresion,vocabulario,tamanio)==false){
        cout<<"Expresion invalida"<<endl;
        return 0;
    }
    else{
        identificador(expresion);
        for(int i=0;i<expresionR.size();i++){
            cout<<"Expresion "<<i<<": ";  
            cout<<expresionR[i]<<endl;
        }

        cout<<"------------------------------"<<endl<<endl;

        cout<<"ingrese cuantas expresiones regulares desea imprimir: ";
        int expresiones;
        cin>>expresiones;
        cout<<endl;

        for(int i=0;i<expresiones;i++){
            int posicion = 0 + rand() % expresionR.size() ;
            cout<<"Expresion: "<<expresionR[posicion]<<endl;
            /*cout<<interpretador(expresionR[posicion])<<endl;*/
            interpretador(expresionR[posicion]);
        }
    }
    

}

bool validador (string expresion,string vocabulario[], int tamanio){
    bool validador=false;
    for(int i=0;i<expresion.length();i++){
        validador=false;
        for(int p=0;p<tamanio;p++){
            if(expresion[i]==vocabulario[p][0]){
                validador= true;
                break;
            }
            else{
                validador= false;
            }

            if(p==tamanio-1 && validador==false){
                return false;
            }
        }
    }
    return validador;
}

void identificador(string expresion){
    string expresionaux;
    string expresionaux2;
    for ( int i=0;i<expresion.length();i++){
        if(expresion[i]=='('){
            for(int p=i;p<expresion.length();p++){
                if(expresion[p]==')'){
                    for(int j=i;j<p+1;j++){
                        expresionaux2+=expresion[j];
                        expresionaux+=expresion[j];
                        
                    }
            i=i+expresionaux2.length()-1;
            expresionaux2="";
                    break;
                }
            }
            
        }
        else if(expresion[i]=='|' && expresion[i+1]=='|'){
            expresionR.push_back(expresionaux);
            expresionaux="";
            i++;
            
        }
        else{
            expresionaux+=expresion[i];
        }
        
    }

    if (!expresionaux.empty()) {
        expresionR.push_back(expresionaux);
    }
  
}

vector<string> identificador2(string expresion){
    string expresionaux;
    for ( int i=0;i<expresion.length();i++){
        if(expresion[i]=='('){
            for(int p=i;p<expresion.length();p++){
                if(expresion[p]==')'){
                    for(int j=i;j<p+1;j++){
                        expresionaux+=expresion[j];
                    }
                }
            }
            i=i+expresionaux.length()-1;
        }
        else if(expresion[i]=='|' && expresion[i+1]=='|'){
            expresionR2.push_back(expresionaux);
            expresionaux="";
            i++;
        }
        else{
            expresionaux+=expresion[i];
        }
        
    }

    if (!expresionaux.empty()) {
        expresionR2.push_back(expresionaux);
    }

    return expresionR2;
}


string interpretador(string expresion){
    string expresion_aux;
    string expresion_aux2;
    string expresion_aux3;
    string expresion_aux4;
    string expresion_resultante;
    string expresionaux5;
    string expresionaux6;
    string expresion_aux7;
    vector<string> vector_expresiones;
    vector<string> nuevo_vector;
    vector<string> vector_aux;

    for(int i=0;i<expresion.length();i++){
        if(expresion[i]=='('){
            for(int b=i;b<expresion.length();b++){
                if(expresion[b]==')'){
                    for(int c=i+1;c<b;c++){
                        expresion_aux+=expresion[c];
                        expresion_aux2+=expresion_aux;
                        expresion_aux="";
                    }
                    
                    vector_expresiones=identificador2(expresion_aux2);
                    expresionR2.clear();
                    // (aba||a*)
                    if(vector_expresiones.size()==1){
                        expresionaux5=interpretador(vector_expresiones[0]);
                        expresion_resultante+=expresionaux5;
                        i=i+expresion_aux2.length()+1;
                    }

                    /*
                    ab
                    a
                    utlizamos la primera iteracion
                    abab   ab vector_expresiones[0] nuevo_vector[0]
                    aba    ab vector_expresiones[1] nuevo_vector[1]
                    aab     a vector_expresiones[0] nuevo_vector[2]
                    aa      a vector_expresiones[1] nuevo_vector[3]
                    utilizamos la segunda iteracion
                    ababab ab nuevo_vector[0] 
                    ababa  ab nuevo_vector[1]
                    abaab  ab nuevo_vector[2]
                    abaa   ab nuevo_vector[3]
                    aabab  a nuevo_vector[0]
                    aaba   a nuevo_vector[1]
                    aaab   a nuevo_vector[2]
                    aaa    a nuevo_vector[3]
                    */
                    else{
                        if(expresion[b+1]=='*'){
                            int repeticiones = 5;
                            for(int z=0;z<repeticiones;z++){
                            int iteraciones=pow(vector_expresiones.size(),z+1);
                                /*for(int j=0;j<iteraciones/2;j++ ){*/
                                        vector_aux=nuevo_vector;
                                                nuevo_vector.clear();
                                    for(int k=0;k<vector_expresiones.size();k++){
                                        
                                            if(z+1==1){
                                                cout<<vector_expresiones[k]<<endl;
                                            }
                                            else if(z+1==2){
                                                for(int e=0;e<vector_expresiones.size();e++){
                                                    expresion_aux7=vector_expresiones[k]+vector_expresiones[e];
                                                    nuevo_vector.push_back(expresion_aux7);
                                                    cout<<vector_expresiones[k]<<vector_expresiones[e]<<endl;
                                                }
                                                expresion_aux7="";
                                                
                                            }
                                            else{
                                                
                                                for(int e=0;e<vector_aux.size();e++){
                                                    expresion_aux7=vector_expresiones[k]+vector_aux[e];
                                                    nuevo_vector.push_back(expresion_aux7);
                                                    cout<<vector_expresiones[k]<<vector_aux[e]<<endl;
                                                }
                                                expresion_aux7="";
                                                
                                            }
                                        
                                    }
                                    cout<<"-------------------------"<<endl;
                                 /*cout<<iteraciones<<endl;

                                } */  
                            }

                            expresion_resultante+=expresion_aux3;
                            expresion_aux3="";
                            expresion_aux4="";
                            i=i+expresion_aux2.length()+2;
                        }
                        else{
                            cout<<vector_expresiones.size()<<endl;
                            int random = 0 + rand() % vector_expresiones.size();
                            expresion_resultante+=interpretador(vector_expresiones[random]);
                            i=i+expresion_aux2.length()+1;
                        }
                    } 
                    break;              
                }
                
            }
            expresion_aux2="";
        }
        else if(expresion[i]!=')' && expresion[i+1]=='*'){
                int repeticiones = rand() % 5 ; 
                for(int r=0;r<repeticiones;r++){
                    expresion_aux3=expresion[i];
                    expresion_resultante+=expresion_aux3;
                }
                i++;
        }
        else{
                expresion_resultante+=expresion[i];
            }

    

    }
    return expresion_resultante;
}

