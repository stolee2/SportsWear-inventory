#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
using namespace std;
class obuvki{
protected:
    char *marka;
    float cena;
    float velicina;
public:
    obuvki();
    obuvki(char m[],float c,float v);
    virtual void set(char m[],float c,float v);
    char *getm(){return marka;}
    float getc(){return cena;}
    float getv(){return velicina;}
    virtual void pecati()=0;
    void setcena(float x){
        float pom=fabs(x)/100*cena;
        float c;
        if(x<0){c=cena-pom;
        cena=c;}
        else if(x>0){c=cena+pom;    
        cena=c;}
        cout<<"Novata cena e "<<cena;
    }
    ~obuvki();
    static int i;
    bool operator > (obuvki *o){return ((getc())>((*o).getc()));}
    };
obuvki::obuvki(){
        marka=NULL;
        cena=0.0;
        velicina=0.0;}
obuvki::obuvki(char m[],float c,float v){
    marka=new char[strlen(m)+1];
    strcpy(marka,m);
    cena=c;
    velicina=v;}
obuvki::~obuvki(){
            delete []marka;}
void obuvki::set(char m[],float c,float v){
    marka=new char[strlen(m)+1];
    strcpy(marka,m);
    cena=c;
    velicina=v;;}

class zeni:public obuvki{
public:
    zeni():obuvki(){};
    zeni(char m[],float c,float v):obuvki(m,c,v){};
    void pecati(){cout<<"Zenskata Obuvk e od marka "<<marka<<" i cini "<<cena<<" denari";}
    virtual void set(char m[],float c,float v){obuvki::set(m,c,v);}
    };


class mazi:public obuvki{
public:
     mazi():obuvki(){};
     mazi(char m[],float c,float v):obuvki(m,c,v){};  
     void pecati(){cout<<"Maskata obuvka e od marka "<<marka<<" i cini "<<cena<<" denari";}
     virtual void set(char m[],float c,float v){obuvki::set(m,c,v);}
    };    


class patiki:public zeni{
    char boja[10];
public:
     patiki():zeni(){};
     patiki(char m[],float c,float v,char *b):zeni(m,c,v){strcpy(boja,b);}     
     void pecati(){cout<<"Patikata e od marka "<<marka<<" i cini "<<cena<<" denari";}
     char *getb(){return boja;}
     virtual void set(char m[],float c,float v,char *b){obuvki::set(m,c,v);strcpy(boja,b);}
     };    


class patiki_za_trcanje:public zeni{
    char boja[10];
public:
     patiki_za_trcanje():zeni(){};
     patiki_za_trcanje(char m[],float c,float v,char *b):zeni(m,c,v){strcpy(boja,b);}     
     void pecati(){cout<<"PAtikite Za Trcanje se  od marka "<<marka<<" i cini "<<cena<<" denari";}
     char *getb(){return boja;}
     virtual void set(char m[],float c,float v,char *b){obuvki::set(m,c,v);strcpy(boja,b);}
     }; 


class papuci:public zeni{
    char boja[10];
public:
     papuci():zeni(){};
     papuci(char m[],float c,float v,char *b):zeni(m,c,v){strcpy(boja,b);}     
     void pecati(){cout<<"Papucise se od marka "<<marka<<" i cini "<<cena<<" denari";}
     char *getb(){return boja;}
     virtual void set(char m[],float c,float v,char *b){obuvki::set(m,c,v);strcpy(boja,b);}
     }; 


class patikim:public mazi{
    char boja[10];
    public:
    patikim():mazi(){};
    patikim(char m[],float c,float v,char *b):mazi(m,c,v){strcpy(boja,b);}     
    void pecati(){cout<<"Patikite se od marka "<<marka<<" i cinat "<<cena<<" denari";}
    char *getb(){return boja;}
    virtual void set(char m[],float c,float v,char *b){obuvki::set(m,c,v);strcpy(boja,b);}
    }; 
     
     
class patiki_za_trening:public mazi{
    char boja[10];
    public:
    patiki_za_trening():mazi(){};
    patiki_za_trening(char m[],float c,float v,char *b):mazi(m,c,v){strcpy(boja,b);}     
    void pecati(){cout<<"Patikite se od marka "<<marka<<" i cini "<<cena<<" denari";}
    char *getb(){return boja;}
    virtual void set(char m[],float c,float v,char *b){obuvki::set(m,c,v);strcpy(boja,b);}
    }; 


class papucim:public mazi{
    char boja[10];
    public:
    papucim():mazi(){};
    papucim(char m[],float c,float v,char *b):mazi(m,c,v){strcpy(boja,b);}     
    void pecati(){cout<<"Papucite se od marka "<<marka<<" i cini "<<cena<<" denari";}
    char *getb(){return boja;}
    virtual void set(char m[],float c,float v,char *b){obuvki::set(m,c,v);strcpy(boja,b);}
    }; 
    
int obuvki::i=0;
obuvki *pok[100];

void zenskaob(){
    ofstream out;
    int izbor,velicina;
    char marka[10],boja[10];
    float cena;
    cout<<"Odberete kakva  obuvka sakate:"<<endl<<"1.Patiki"<<endl<<"2. Patiki Za Trcanje"<<endl<<"3.Papuci"<<endl;
    cin>>izbor;
    cout<<"Marka na obuvkata:";
    cin>>marka;
    cout<<"Velicina na obuvkata:";
    cin>>velicina;
    cout<<"Cena na gobuvkata:";
    cin>>cena;
    switch (izbor){
        case 1:    
            cout<<"Boja na obuvkata:";
            cin>>boja;
            pok[obuvki::i]=new patiki(marka,cena,velicina,boja);
            obuvki::i++;
            out.open("patiki.txt",ios::app);
            out<<"Marka:"<<marka;
            out<<", cena:"<<cena;
            out<<", velicina:"<<velicina;
            out<<", boja:"<<boja<<endl;
            out.close();
            break;
        case 2:
            cout<<"Boja na obuvkata:";
            cin>>boja;
            pok[obuvki::i]=new patiki_za_trcanje(marka,cena,velicina,boja);
            obuvki::i++;
            out.open("patiki_za_trcanje.txt",ios::app);
            out<<"Marka:"<<marka;
            out<<", cena:"<<cena;
            out<<", velicina:"<<velicina;
            out<<", boja:"<<boja<<endl;
            out.close();
            break;
        case 3: 
            cout<<"Boja na obuvkata:";
            cin>>boja;
            pok[obuvki::i]=new papuci(marka,cena,velicina,boja);
            obuvki::i++;
            out.open("papuci.txt",ios::app);
            out<<"Marka:"<<marka;
            out<<", cena:"<<cena;
            out<<", velicina:"<<velicina;
            out<<", boja:"<<boja<<endl;
            out.close();
            break;}
}

void maskaob(){
    ofstream out;
    int izbor,velicina;
    char marka[10],boja[10];
    float cena;
    cout<<"Odberete kakva obuvka sakate:"<<endl<<"1.Patiki"<<endl<<"2.Patiki Za Trening"<<endl<<"3.Papuci"<<endl;
    cin>>izbor;
    cout<<"Marka na obuvkite:";
    cin>>marka;
    cout<<"Velicina na Obuvkite:";
    cin>>velicina;
    cout<<"Cena na Obuvkite                                                                                                                                      :";
    cin>>cena;
    switch (izbor){
        case 1:    
            cout<<"Boja na obuvkite:";
            cin>>boja;
            pok[obuvki::i]=new patikim(marka,cena,velicina,boja);
            obuvki::i++;
            out.open("patikim.txt",ios::app);
            out<<"Marka:"<<marka;
            out<<", cena:"<<cena;
            out<<", velicina:"<<velicina;
            out<<", boja:"<<boja<<endl;
            out.close();
            break;
        case 2:
            cout<<"Boja na obuvkite:";
            cin>>boja;
            pok[obuvki::i]=new patiki_za_trening(marka,cena,velicina,boja);
            patiki_za_trening::i++;
            out.open("patiki_za_trening.txt",ios::app);
            out<<"Marka:"<<marka;
            out<<", cena:"<<cena;
            out<<", velicina:"<<velicina;
            out<<", boja:"<<boja<<endl;
            out.close();
            break;
        case 3: 
            cout<<"Boja na obuvkata:";
            cin>>boja;
            pok[obuvki::i]=new papucim(marka,cena,velicina,boja);
            out.open("papucim.txt",ios::app);
            out<<"Marka:"<<marka;
            out<<", cena:"<<cena;
            out<<", velicina:"<<velicina;
            out<<", boja:"<<boja<<endl;
            out.close();
            break;}
}
void dodadi(){
    int izbor;
    cout<<"Odberete obuvki"<<endl<<"1.Zenska"<<endl<<"2.Maska"<<endl;
    cin>>izbor;
    switch(izbor){
        case 1:zenskaob();break;
        case 2:maskaob();break;}}

void promena(){
    float pro;
    char marka[10];
    cout<<"Vnesete go imeto na markata za koja sakate da napravite promena vo cenata:";
    cin>>marka;
    for(int j=0;j<obuvki::i;j++){
        if(!strcmp(marka,pok[j]->getm())){
            cout<<"Vnesete procent,negativen za popust,pozitiven za pokacuvanje na cenata:";
            cin>>pro;
            pok[j]->setcena(pro);
        }
    }        
    for(int j=0;j<obuvki::i;j++)
     {
              if(!strcmp(marka,pok[j]->getm())){
              cout<<endl;
              pok[j]->pecati();
              }    
     }
              
} 


    
template <class T> void sort(T a[],int n){
    T pom,max;
    int i,j,maxi;
    for(i=0;i<n-1;i++){
        max=a[i];
        maxi=i;
        for(j=i+1;j<i;j++){
            if(a[j]>max){
                max=a[j];
                maxi=j;
            }
                if(maxi!=i){
                    pom=a[i];
                    a[i]=a[maxi];
                    a[maxi]=pom;
                }
        }
    }    
}


void pecatenje(){
    cout<<"Ima vkupno "<<obuvki::i<<" vidovi  obuvki:"<<endl;
    for(int j=0;j<obuvki::i;j++){
    pok[j]->pecati();
    cout<<endl;
    }
}

void sortiranje(){
    int n=obuvki::i;
    sort(pok,n);
    pecatenje();
}   
                    
int main(){
    int iz;
    cout<<"                                 SPORT "<<endl<<endl;
    do{
        cout<<endl<<"        Odberete edna od navedente opcii ili pretisnete 5 za da izlezete"<<endl<<"*******************************************************************************"<<endl;
        cout<<"1.Primi obuvki"<<endl;
        cout<<"2.Promena na cena(popust ili pokacuvanje)"<<endl;
        cout<<"3.Sortiranje na obuvkite"<<endl;
        cout<<"4.Pecatenje na obuvkite"<<endl;
        cout<<"5.Izlez od programata"<<endl;
        cin>>iz;
        switch(iz){
            case 1:dodadi();break;
            case 2:promena();break;
            case 3:sortiranje();break;
            case 4:pecatenje();break;
        }
    }    
    while(iz<5);
system ("pause");
return 0;
}
