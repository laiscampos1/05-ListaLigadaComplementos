#include <iostream>       
  #include <cmath>           
  #include <cstdio>             
  using namespace std;             
  
  // definicao de tipo             
  struct NO {             
     int valor;             
     NO* prox;             
  };             
  
  NO* primeiro = NULL;             
  NO* MeioDaLista = NULL;          
  int quantidade = 0;          
  int Soma = 0;          
  float Media;        
  int MediaInt;        
  
  // headers             
  void menu();             
  void inicializar();             
  void exibirQuantidadeElementos();             
  void exibirElementos();             
  void inserirElemento();             
  void excluirElemento();             
  void buscarElemento();     
  void Apagador(NO* ValorInicial,int NumExc, bool Tanomeio);     
  void MostrarDados();  
  void Procurar(int Num,NO* Inicio,NO* Fim);  
  NO* posicaoElemento(int numero);             
             //--------------------------             
  
  
  int main(){             
    menu();             
  }             
  
  void menu(){             
     int op = 0;             
     while (op != 7) {             
        system("clear"); // somente no windows             
        cout << "Menu Lista Ligada";             
        cout << endl << endl;             
        cout << "1 - Inicializar Lista \n";             
        cout << "2 - Exibir quantidade de elementos \n";             
        cout << "3 - Exibir elementos \n";             
        cout << "4 - Buscar elemento \n";             
        cout << "5 - Inserir elemento \n";             
        cout << "6 - Excluir elemento \n";             
        cout << "7 - Sair \n\n";             
  
        cout << "Opcao: ";             
        cin >> op;             
  
        switch (op){             
           case 1: inicializar();             
                   break;             
           case 2: exibirQuantidadeElementos();             
                   break;             
           case 3: exibirElementos();             
                   break;             
           case 4: buscarElemento();             
                   break;             
           case 5: inserirElemento();             
                   break;             
           case 6: excluirElemento();             
                   break;             
           case 7: return;       
           case 8: MostrarDados();       
                   break;       
           default: break;             
        }             
        getchar();             
     }             
  }             
  
  
  void inicializar(){             
     // se a lista já possuir elementos             
     // libera a memoria ocupada             
     NO* aux = primeiro;             
     while (aux != NULL) {             
        NO* paraExcluir = aux;             
        aux = aux->prox;             
        free(paraExcluir);             
     }             
  
     primeiro = NULL;     
     quantidade = 0;    
     cout << "Lista inicializada \n";             
     cout << "\nPressione ENTER para continuar\n";             
     getchar();             
  
  }             
  
  void exibirQuantidadeElementos() {             
  
     int nElementos = 0;             
     NO* aux = primeiro;             
     while (aux != NULL) {             
        nElementos++;             
        aux = aux->prox;             
     }             
     cout << "Quantidade de elementos: " << nElementos << endl;     
     cout << "\nPressione ENTER para continuar\n";             
     getchar();     
  
  }             
  
  void exibirElementos(){             
     if(primeiro == NULL) {             
        cout << "Lista vazia \n";             
        cout << "\nPressione ENTER para continuar\n";             
        getchar();             
        return;             
     }             
     else {             
        cout << "Elementos: \n";             
        NO* aux = primeiro;             
        while (aux != NULL){             
           cout << aux->valor << endl;             
           aux = aux->prox;             
        }             
        cout << "\nPressione ENTER para continuar\n";             
        getchar();             
     }             
  }             
  
 void inserirElemento(){ 
    int ValNum;             
    cout << "Digite o elemento: ";             
    cin >> ValNum;             
    bool Inseriu=false;             
    // aloca memoria dinamicamente para o novo elemento             
    if(posicaoElemento(ValNum)==NULL){             
  
       NO* novo = (NO*)malloc(sizeof(NO));             
       bool PrimeiraVez=true;             
       if (novo == NULL){             
           return;             
       }             
       novo->valor=ValNum;             
       novo->prox = NULL;             
       NO* ValorAtual;             
       NO* Anterior;
       NO* Final;
       if(quantidade>=5){
           if(novo->valor<MeioDaLista->valor){
               ValorAtual=MeioDaLista;
               Final=NULL;
           }
           else{
               ValorAtual=primeiro;
               Final=MeioDaLista->prox;
           }
       }
       else{
           ValorAtual=primeiro;
           Final=NULL;
       }
       
       if(primeiro==NULL){          
           primeiro=novo;
       }          
        else{          
           while(ValorAtual!=Final){
               if(novo->valor>ValorAtual->valor){
                   novo->prox=ValorAtual;
                   primeiro=novo;
                   break;
               }
               else{
                   if(ValorAtual->prox==Final||novo->valor>ValorAtual->prox->valor){
                       novo->prox=ValorAtual->prox;
                       ValorAtual->prox=novo;
                       break;
                   }
                   ValorAtual=ValorAtual->prox;
               }
           }          
        }          
        cout <<"Valor inserido \n";           
        quantidade++; 
        MediaInt = (quantidade - (quantidade % 2))/2; 
        ValorAtual=primeiro; 
        for(int i=0;i<quantidade+1;i++){    
           if(i==MediaInt){    
              MeioDaLista=ValorAtual; 
              break; 
           }    
           else{    
              ValorAtual=ValorAtual->prox;    
           }    
        } 
        cout << "\nPressione ENTER para continuar\n";             
        getchar();             
     }             
     else{             
        cout << "Esse valor ja esta na lista";             
        cout << "\nPressione ENTER para continuar\n";             
        getchar();             
     }             
  
 }         
  
             void excluirElemento(){         
                 int NumExc;       
                 NO* ValorAtual=primeiro;       
                 NO* Anterior=primeiro;       
                 if(quantidade<=0){         
                     cout<<"Lista Vazia.";         
                     getchar();         
                 }         
                 else{         
                     cout<<"Digite o numero a ser excluido:\n";         
                     cin >> NumExc;         
                     if(quantidade>=3&&MeioDaLista!=NULL){        
                         if(NumExc<MeioDaLista->valor){       
                             cout<<"contando do meio da lista"<<endl;       
                             Apagador(MeioDaLista,NumExc,true);       
                         }        
                         else{       
                             cout<<"contando do comeco da lista";       
                             Apagador(primeiro,NumExc,false);        
                         }        
                     }         
                     else{         
                         Apagador(primeiro,NumExc,false);         
                     }       
                     MediaInt = (quantidade - (quantidade % 2))/2; 
                     ValorAtual=primeiro;  
                     for(int i=0;i<quantidade+1;i++){    
                         if(i==MediaInt){    
                             MeioDaLista=ValorAtual; 
                             break; 
                         }    
                         else{    
                             ValorAtual=ValorAtual->prox;    
                         }    
                     }     
                 }         
             }         
  
  
  
             void buscarElemento(){  
                 int NumBusca;  
                 if(quantidade<=0){  
                     cout<<"Lista Vazia. \n";  
                     getchar();  
                 }  
                 else{  
                     cout<<"Digite o valor: \n";  
                     cin>>NumBusca;  
                     if(quantidade>=5){  
                         if(NumBusca<MeioDaLista->valor){  
                              Procurar(NumBusca,MeioDaLista,NULL);  
                         }  
                         else{  
                              Procurar(NumBusca,primeiro,MeioDaLista);  
                         }  
                     }  
                     else{  
                         Procurar(NumBusca,primeiro,NULL);  
                     }  
                 }  
             }       
  
             void MostrarDados(){       
                 cout<<"MediaInt: "<<MediaInt<<endl;       
                 cout<<"quant: "<<quantidade<<endl;       
                 if(MeioDaLista==NULL){       
                     cout<<"a variavel esta nula";       
                 }       
                 else{       
                     cout<<"MeioDaLista: "<<MeioDaLista->valor;   
  
                 }       
                 getchar();       
             }       
  
             NO* posicaoElemento(int numero/*,NO* ValorInicial*/)  {               
                       NO* aux = primeiro; //mudar valor de aux para o argumento               
                       while (aux != NULL) {               
                               if (aux->valor == numero)               
                               {               
                                       break;               
                               }               
                               aux = aux->prox;               
                       }               
                       return aux;               
             }  
  
             void Procurar(int Num,NO* Inicio,NO* Fim){  
                 while(Inicio!=Fim){  
                     if(Inicio->valor==Num){  
                         cout<<"\nValor encontrado\n";  
                         break;  
                     }  
                     else{  
                         if(Inicio->prox==Fim){  
                             cout<<"\nValor nao encontrado\n";  
                             break;  
                         }  
                     }  
                     Inicio=Inicio->prox;  
                 }  
                 getchar();  
             }  
  
             void Apagador(NO* ValorInicial,int NumExc, bool Tanomeio){         
                 NO* ValorAtual;         
                 NO* Anterior;     
                 if(Tanomeio){     
                     ValorAtual=ValorInicial->prox;     
                     Anterior=ValorInicial;     
                 }     
                 else{     
                     ValorAtual=ValorInicial;     
                 }     
                 bool PrimeiraVez= true;         
                 bool apagou = false;         
                 while(ValorAtual!=NULL){         
                     if(PrimeiraVez){         
                         if(ValorAtual->valor==NumExc){     
                             if(Tanomeio==false){     
                                 primeiro=ValorAtual->prox;     
                             }     
                             else{     
                                 Anterior->prox=ValorAtual->prox;     
                             }     
                             cout<<"\nValor excluido\n";         
                             quantidade--;         
                             Soma = Soma - ValorAtual->valor;         
                             free(ValorAtual);         
                             apagou= true;         
                         }         
                         else{         
                             if(ValorAtual->prox==NULL){         
                                 cout<<"\nValor nao encontrado\n";         
                             }         
                             Anterior=ValorAtual;         
                         }         
                         PrimeiraVez=false;         
                     }         
                     else{         
                         if(ValorAtual->valor==NumExc){         
                             Anterior->prox=ValorAtual->prox;         
                             cout<<"\nValor excluido\n";         
                             quantidade--;         
                             Soma = Soma - ValorAtual->valor;         
                             free(ValorAtual);         
                             apagou=true;         
                         }         
                         else{         
                             Anterior=ValorAtual;         
                             if(ValorAtual->prox==NULL){         
                                 cout<<"\nValor nao encontrado\n";         
                             }         
                         }         
                     }         
                     if(apagou){         
                         break;         
                     }         
                     ValorAtual=ValorAtual->prox;         
                 }         
                 getchar();         
             }
