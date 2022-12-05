#include <iostream>
using namespace std;


struct Noeud{ // Structure de mon noeud
    int val;
    Noeud *gauche;
    Noeud *droite;
};

void createArbrePrefixe(Noeud **racine, int prof){ // creation d'un arbre binaire de maniere prefixe
    if (prof >= 0){       
        Noeud *N = new Noeud;

        cout<<"Entrer une valeur: ";
        cin >> N->val;
        // N->val = 1;

        *racine = N;
        N->droite = nullptr;
        N->gauche = nullptr;
        createArbrePrefixe(&(N->gauche), prof -1 );  
        createArbrePrefixe(&(N->droite), prof -1 );          
    }
  
}


void createArbreInfixe(Noeud **racine, int prof){ // creation d'un arbre binaire de maniere Infixe
    if (prof >= 0){     
        Noeud *N = new Noeud;
        N->gauche = nullptr;   
        createArbreInfixe(&(N->gauche), prof -1 );

        cout<<"Entrer une valeur: ";
        cin >> N->val;
        *racine = N;

        N->droite = nullptr;
        createArbreInfixe(&(N->droite), prof -1 );             
    } 
}

void createArbrePostfixe(Noeud **racine, int prof){ // creation d'un arbre binaire de maniere postfixe
    if (prof >= 0){     
        Noeud *N = new Noeud;

        N->gauche = nullptr;   
        createArbrePostfixe(&(N->gauche), prof -1 );
        
        N->droite = nullptr;
        createArbrePostfixe(&(N->droite), prof -1 ); 

        cout<<"Entrer une valeur: ";
        cin >> N->val;
        *racine = N;                    
    } 
}


void affichePrefixe(Noeud *parent){ // Affichage des valeurs d'un arbre binaire de maniere prefixe

    Noeud *ptr = parent;
    if (ptr != nullptr){
        cout<< ptr->val<<" ";  
        affichePrefixe(ptr->gauche);
        affichePrefixe(ptr->droite);
    }
    
}

void afficheInfixe(Noeud *parent){ // Affichage des valeurs d'un arbre binaire de maniere Infixe
    Noeud *ptr = parent;
    if (ptr != nullptr){
        afficheInfixe(ptr->gauche);
        cout<< ptr->val<<" ";       
        afficheInfixe(ptr->droite);
    }
    
}

void affichePostfixe(Noeud *parent){ // Affichage des valeurs d'un arbre binaire de maniere Postfixe

    Noeud *ptr = parent;
    if (ptr != nullptr){
        affichePostfixe(ptr->gauche);
        affichePostfixe(ptr->droite);
        cout<< ptr->val<<" ";  
    }
    
}

 
void afficheValeurPrefixe(Noeud *parent, int Val_Max){ // Affiche les valeurs qui sont inferieurs a x de  maniere Prefixe
    Noeud *ptr = parent;
    if (ptr != nullptr){
        if (ptr->val < Val_Max) cout<< ptr->val<<" ";  

        afficheValeurPrefixe(ptr->gauche, Val_Max);
        afficheValeurPrefixe(ptr->droite, Val_Max);
    }
}

void afficheValeurInfixe(Noeud *parent, int Val_Max){ // Affiche les valeurs qui sont inferieurs a x de  maniere Infixe
    Noeud *ptr = parent;
    if (ptr != nullptr){
        afficheValeurInfixe(ptr->gauche,Val_Max);
        if (ptr->val < Val_Max) cout<< ptr->val<<" ";      
        afficheValeurInfixe(ptr->droite,Val_Max);
    }
}

void afficheValeurPostfixe(Noeud *parent, int Val_Max){ // Affiche les valeurs qui sont inferieurs a x de  maniere Postfixe

    Noeud *ptr = parent;
    if (ptr != nullptr){
        afficheValeurPostfixe(ptr->gauche, Val_Max);
        afficheValeurPostfixe(ptr->droite, Val_Max);
        if (ptr->val < Val_Max) cout<< ptr->val<<" ";  
    }
}

bool rechercheValeurPrefixe(Noeud *parent, int val){ // recherche si une valeur existe dans l'arbre
    if (parent != nullptr){
        return  ( (parent->val == val) ||  rechercheValeurPrefixe(parent->gauche, val) 
                || rechercheValeurPrefixe(parent->droite, val));
    }
    return false;
}

int compterFeuilles(Noeud *parent){ //Compte le nombre de feuilles qu'il y a dans l'arbre
    if (parent != nullptr){
        if (parent->gauche == nullptr && parent->droite == nullptr) return 1;
        return compterFeuilles(parent->gauche) + compterFeuilles(parent->droite);
    }
    return 0;
}

int compterNoeuds(Noeud *parent){ // Compte le nombre de noeuds qu'il y a dans mon arbre
    if (parent != nullptr) return 1 + compterNoeuds(parent->gauche)  + compterNoeuds(parent->droite);   
    return 0;
}

int compterNoeudsInternes(Noeud *parent, Noeud *racine){ // Compte le nombre de noeud interne
    if (parent != nullptr){
        if (racine == parent || (parent->gauche == nullptr && parent->droite == nullptr)) return compterNoeudsInternes(parent->gauche, racine)  + compterNoeudsInternes(parent->droite, racine);
   
        return 1+compterNoeudsInternes(parent->gauche, racine)  + compterNoeudsInternes(parent->droite, racine);
    }
    return 0;
}


void profondeur(Noeud *parent, int *max, int cpt){ // Calcule la profondeur de l'arbre
    if (parent != nullptr && (parent->droite != nullptr) && (parent->gauche != nullptr)){
            
        profondeur(parent->droite, max, cpt + 1); 
        profondeur(parent->gauche, max, cpt + 1); 
        }
        
    if (cpt >= *max) *max = cpt;  
}


int combienProf(Noeud *parent, int prof){ // Calcule le nombre de noeuds qu'il y a a une profondeur
    if (parent != nullptr){
        if (prof == 0) return 1;
        if (prof > 0) return combienProf( parent->gauche, prof-1) + combienProf( parent->droite, prof-1);    
    }
    return 0;
}

void noeudsProf(Noeud *parent, int prof){ //Affiche les noeuds qui sont a une profondeur
    if (parent != nullptr){
        if (prof == 0) cout<<parent->val<<" ";
        if (prof > 0){
            noeudsProf( parent->gauche, prof-1) ;
            noeudsProf( parent->droite, prof-1);         
        }     
    }
}

bool estPlein(Noeud *parent){ // Verifie si l'arbre est plein
    
  if (parent!=NULL) {
    if (parent->gauche !=NULL || parent->droite !=NULL)
      return estPlein(parent->gauche) && estPlein(parent->droite);
    else return true;
  }
  return false;
}



int main(){
    int prof = 2, x, pf;

    Noeud *arbrePrefixe;
    cout<<"Arbre binaire Prefixe"<<endl;
    createArbrePrefixe(&arbrePrefixe, prof);
    affichePrefixe(arbrePrefixe); cout<<endl;

    cout<<"Entrer une valeur X pour afficher toutes les valeurs de l'arbre inférieures à une valeur X: ";
    cin>>x;
    afficheValeurPrefixe(arbrePrefixe, x); cout<<endl;

    Noeud *arbreInfixe;
    cout<<"Arbre binaire Infixe"<<endl;
    createArbreInfixe(&arbreInfixe, prof);
    afficheInfixe(arbreInfixe); cout<<endl;

    cout<<"Entrer une valeur X pour afficher toutes les valeurs de l'arbre inférieures à une valeur X: ";
    cin>>x;
    afficheValeurInfixe(arbreInfixe, x); cout<<endl;

    Noeud *arbrePostfixe;
    cout<<"Arbre binaire Postfixe"<<endl;
    createArbrePostfixe(&arbrePostfixe, prof);
    affichePostfixe(arbrePostfixe); cout<<endl;

    cout<<"Entrer une valeur X pour afficher toutes les valeurs de l'arbre inférieures à une valeur X: ";
    cin>>x;
    afficheValeurPostfixe(arbrePostfixe, x); cout<<endl;
 
    cout<<"Entrer une valeur a trouvee: ";
    cin>>x;
    bool val = rechercheValeurPrefixe(arbrePrefixe, x);
    if(val) cout<<"Trouver"<<endl;
    else cout<<"Pas trouver "<<endl;

    cout<<"Le nombre de feuilles est: "<<compterFeuilles(arbrePrefixe)<<endl;
    cout<<"Le nombre de noeuds est: "<<compterNoeuds(arbrePrefixe)<<endl;
    cout<<"Le nombre de noeuds internes est: "<<compterNoeudsInternes(arbrePrefixe, arbrePrefixe)<<endl;
    int prfnd = 0;
    
    profondeur(arbrePrefixe,&prfnd, 0);
    cout<<"La profondeur est: "<<prfnd<<endl;
    

    cout<<"Entrer une profondeur: ";
    cin>>pf;
    int nb = combienProf(arbrePrefixe,pf);
    cout<<"Le nombre de noeuds d'un arbre binaire qui sont exactement à la profondeur "<<pf<<" est: "<<nb<<endl;
    if (nb>0) cout<<"Ces valeurs sont: ";
    noeudsProf(arbrePrefixe, pf);cout<<endl;

    if(estPlein(arbrePrefixe)) cout<<"Notre arbre est plein"<<endl;
    else cout<<"Notre arbre n'est pas plein"<<endl;
    

}

