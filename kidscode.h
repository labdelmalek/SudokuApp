#ifndef KIDSCODE_H
#define KIDSCODE_H

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <time.h>
typedef struct element{
    int contenu;
    element *suivant;
    element *precedent;
    int abs;
    int ord;
}element;
using namespace std;
class kids{
private:
    int **kids_grill_solution;
    int **kids_grill_reset;
    int **kids_grill_empty;
public:
    int** get_grill(){
        return kids_grill_empty;
    }
    kids(){

        srand(time(NULL));

        this->kids_grill_solution=new int*[4];
        this->kids_grill_empty=new int*[4];
        this->kids_grill_reset=new int*[4];

        for(int i=0;i<4;i++){
            this->kids_grill_solution[i]=new int[4];
            this->kids_grill_empty[i]=new int[4];
            this->kids_grill_reset[i]=new int[4];

        }
        for(int i=0;i<4;i++){
            for (int j=0; j<4; j++) {
                this->kids_grill_solution[i][j]=0;
                this->kids_grill_empty[i][j]=0;
                this->kids_grill_reset[i][j]=0;


            }}
        int tab[2][4];
        int x,y;
        x=rand()%4;
        y=rand()%4;
        tab[0][0]=x;
        tab[1][0]=y;
        for (int i=1; i<4;i++) {
            int ind=1;
            while( ind==1){
                ind=0;
                x=rand()%4;
                y=rand()%4;
                for (int j=0; j<i;j++) {
                    if( x==tab[0][j] || y==tab[1][j]){
                        j=i;
                        ind =1;
                    }
                }
            }
            tab[0][i]=x;
            tab[1][i]=y;
        }
        for(int i=1;i<5;i++){
            this->kids_grill_empty[tab[0][i-1]][tab[1][i-1]]=i;
            this->kids_grill_solution[tab[0][i-1]][tab[1][i-1]]=i;
            this->kids_grill_reset[tab[0][i-1]][tab[1][i-1]]=i;

        }
        resultat(this->kids_grill_empty,recherche(this->kids_grill_empty));
        resultat(this->kids_grill_reset,recherche(this->kids_grill_reset));
        resultat(this->kids_grill_solution,recherche(this->kids_grill_solution));
        this->clear_grille();
    }
    //reset the empty grill
    void reset_grille(){
        for(int i=0;i<4;i++){
            for(int j=0; j<4; j++){
                kids_grill_empty[i][j]=kids_grill_reset[i][j];}}}
    // write an element in the gameplay matrix
        void element_write(int abs, int ord, int number){

            this->kids_grill_empty[abs][ord]=number;
        }
        // recover an element from the matrix knowing its position
        int element_read(int abs, int ord){
            return this->kids_grill_empty[abs][ord];
        }
        // recover element from the solution grill
        int element_read_solution(int abs, int ord){
            return this->kids_grill_solution[abs][ord];
        }

    //clearing the grill

    void clear_grille(){
        int a ;
        int b;

        int i=0;

        while(i<7){
            a=rand() % 4;
            b=rand() % 4;
            if(this->kids_grill_empty[a][b]!=0){
                i=i+1;
                this->kids_grill_empty[a][b]=0;
            this->kids_grill_reset[a][b]=0;}

        }
    }

    bool goodcolumn (int nombre,int **sudoku,int abs, int ord){ // pour tester si la valeur existe sur la colonne
        int indicateur=1; //indicateur d'existance du chiffre sur la colonne
        for(int i=0;i<4;i++){

            if(sudoku[i][ord]==nombre && i!=abs){
                indicateur=0;
                i=4;
            }
        }
        return indicateur;
    }
    bool goodrow (int nombre,int **sudoku,int abs, int ord){ // pour tester si la valeur existe sur la ligne
        int indicateur=1;//indicateur d'existance du chiffre sur la colonne
        for(int i=0;i<4;i++){
            if(sudoku[abs][i]==nombre && ord!=i){
                indicateur=0;
                i=4;
            }
        }
        return indicateur;
    }
    bool goodblock(int nombre,int **sudoku,int abs, int ord){// pour tester si la valeur existe sur le block
        int indicateur=1;//indicateur d'existance du chiffre sur le block
        if((abs%2)==0){
            if((ord%2)==0){
                for(int i=ord;i<ord+2;i++){
                    for(int j=abs;j<abs+2;j++){
                        if(sudoku[j][i]==nombre && i!=ord && j!=abs){
                            indicateur=0;
                            i=ord+4;
                            j=abs+2;
                        }}}}
            else{
                for(int i=ord;i>ord-2;i--){
                    for(int j=abs;j<abs+2;j++){
                        if(sudoku[j][i]==nombre && i!=ord && j!=abs){
                            indicateur=0;
                            i=ord-2;
                            j=abs+2;
                        }}}
            }
        }
        else{
            if((ord%2)==0){
                for(int i=ord;i<ord+2;i++){
                    for(int j=abs;j>abs-2;j--){
                        if(sudoku[j][i]==nombre && i!=ord && j!=abs){
                            indicateur=0;
                            i=ord+2;
                            j=abs-2;
                        }}}}
            else{
                for(int i=ord;i>ord-2;i--){
                    for(int j=abs;j>abs-2;j--){
                        if(sudoku[j][i]==nombre && i!=ord && j!=abs){
                            indicateur=0;
                            i=ord-2;
                            j=j>abs-2;
                        }}}
            }
        }
        return indicateur;
    }
    element *recherche(int **sudoku){
        element *pt;
        pt=NULL;
        element *tmp;
        tmp=NULL;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(sudoku[i][j]==0){
                    if(pt==NULL){
                        pt=new element;

                        pt->contenu=0;
                        pt->suivant=NULL;
                        pt->precedent=NULL;
                        pt->abs=i;
                        pt->ord=j;
                        tmp=pt;
                    }
                    else{
                        element *ptmp=NULL;
                        ptmp= new element;
                        ptmp->contenu=0;
                        ptmp->suivant=NULL;
                        ptmp->precedent=tmp;
                        ptmp->abs=i;
                        ptmp->ord=j;
                        tmp->suivant=ptmp;

                        tmp=tmp->suivant;}} }}
        return pt;	}

    void resultat(int **sudoku,element *listee){
        element *p;
        p=new element;
        p=listee;
        while(p!=NULL){
            int indicateur=1;
            for(int i=((p->contenu)+1);i<5;i++)
            {
                if(goodrow(i,sudoku,p->abs,p->ord)==1){

                    if(goodcolumn(i,sudoku,p->abs,p->ord)==1){
                        if(goodblock(i,sudoku,p->abs,p->ord)==1){
                            p->contenu=i;
                            indicateur=0;
                            sudoku[p->abs][p->ord]=i;
                            p=p->suivant;
                            i=5;}}}
            }
            if(indicateur==1){
                p->contenu=0;
                sudoku[p->abs][p->ord]=0;
                p=p->precedent;}
        }
    }
    };

#endif // KIDSCODE_H
