#include<iostream>
#include <sstream>
#include <vector>
#include<cstdlib>
#include<ctime>

using namespace std;
string vocabulario[]={"a","b","|","(",")","*"};
int tamanio= sizeof(vocabulario)/sizeof(vocabulario[0]);
vector<string> expresionR;
vector<string> expresionR2;
void identificador(string expresion);
vector<string> identificador2(string expresion);
string interpretador(string expresion);
bool validador (string expresion,string vocabyulario[],int tamanio );
string expresionRecursiva(string expresion);

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
            cout<<interpretador(expresionR[posicion])<<endl;
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
    vector<string> vector_expresiones;

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
                    if(vector_expresiones.size()==1){
                        expresionaux5=expresionRecursiva(vector_expresiones[0]);
                        expresion_resultante+=expresionaux5;
                        i=i+expresion_aux2.length()+1;
                    }
                    else{
                        if(expresion[b+1]=='*'){
                            int repeticiones = 0 + rand() % 4 ;
                            for(int z=0;z<repeticiones;z++){
                                int posicion = 0 + rand() % vector_expresiones.size() ;
                                expresion_aux4=expresionRecursiva(vector_expresiones[posicion]);
                                expresion_aux3+=expresion_aux4;

                            }
                            expresion_resultante+=expresion_aux3;
                            expresion_aux3="";
                            expresion_aux4="";
                            i=i+expresion_aux2.length()+2;
                        }
                        else{
                            cout<<vector_expresiones.size()<<endl;
                            int random = 0 + rand() % vector_expresiones.size();
                            expresion_resultante+=expresionRecursiva(vector_expresiones[random]);
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

string expresionRecursiva(string expresion){
string expresion_aux="";
    string expresion_aux2="";
    string expresion_aux3="";    
    for(int p=0;p<expresion.length();p++){
            if(expresion[p]!='*' && expresion[p+1]=='*'){
                int repeticiones = rand() % 5 ; 
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
    cout<<"Recursiva :"<<expresion_aux2<<endl;
    return expresion_aux2;
        
}