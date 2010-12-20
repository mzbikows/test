#include <iostream>
using namespace std;
struct Wezel {
int dana;
Wezel* next;
};

void showList(const Wezel* head) {          //funkcja wyswietlajaca elementy listy
if (! head) {//jezeli nie istnieje glowa
 cout<< "Lista jest pusta" << endl;
return;
}
while (head) {
cout << head->dana << " ";
head = head->next;
}
cout << endl;
}

Wezel* arrayToList(const int tab[], int size) {

if(size<1)
          return NULL;
else{
Wezel *wsk;
Wezel *tmp;
Wezel *head;
//wsk to kopia head'a
//lista jednoelementowa
head = new Wezel;
head->dana = tab[0];
if(size==1)
head->next = NULL;

wsk = head;
for(int i = 1; i<size; i++)
{
tmp = new Wezel;
//cout<<tmp<<endl;
tmp->dana = tab[i];
//cout<<tmp->dana<<"temp od dana"<<endl;
tmp->next = NULL;
wsk->next = tmp;
wsk = tmp;
}

return head;
}
}


/*
Wezel *head = new Wezel;
head->dana=tab[0];
Wezel *h1 = new Wezel;
h1->dana=tab[1];
head->next = h1;
Wezel *h2 = new Wezel;
h2->dana = tab[2];
h1->next = h2;
h2->next = NULL;*/


Wezel* removeOdd(Wezel* head) {
Wezel *oper;
oper = head;
Wezel *usu;
int status;

if(head == NULL) //ZAPOMNIELISMY O PRZYPADKU KIEDY LISTA JEST PUSTA
return NULL; //ZAPOMNIELISMY O PRZYPADKU KIEDY LISTA JEST PUSTA
else
{

while(oper)
{
           if(oper->dana%2==0)
           {
           //cout<<"glowa jest parzysta"<<endl;
           status = 1;
           break;
           }
           else if(oper->dana%2==1)  //dana nieparzysta i oper rozny od null
           {
           usu = oper;
           oper = oper->next;
           cout<<"usuwamy: "<<usu->dana<<endl;
           delete usu;
           status = 0;
           }
}

if(status == 0)
         { return NULL;  }//wszystkie el. byly nieparzyste
else if(status == 1)
     {
     Wezel *newHead;   //nowa glowa na pewno parzysta          
     newHead = oper;
     oper = newHead->next;
     Wezel *lastPar;
     lastPar = newHead;
           while(oper)
           {
           if(oper->dana%2==0)
           {
           lastPar = oper;         //ustawiamy polozenie ostatniego parzysztego          
           oper = oper->next;      
                }
           else if(oper->dana%2==1)
                {
                usu = oper;
                oper = oper->next;
                cout<<"usuwamy "<<usu->dana<<endl;
                delete usu;
                lastPar->next = oper;    
                }
}

return newHead; 
}
}

//PONIZSZE WYSWIETLANIE NIE MA SENSU BO JEZELI WCZESNIEJ MAMY RETURN TO TUTAJ NAWET NIE WEJDZIEMY

/*
while ( head) {
cout << " head->dana << " ";
head = head->next;
}*/

//return head; RETURN HEAD NIE POWINNO BYC NA KONCU BO JEZELI WCZESNIEJ MAMY RETURN TO TUTAJ NAWET NIE WEJDZIEMY

}





Wezel* removeAll(Wezel* head) {

do
{
Wezel *wsk;
wsk = head->next;
delete head;
head = wsk;
}
while(head!=NULL);

return head;
}

int main(void) {


/*
int tab[] = {};
cout<<tab[1199]<<"tab od 5"<<endl;
cout<<sizeof(tab)<<"sizeof tab"<<endl;                       //sizeof - rozmiar w sensie ile pamieci zajmuje w bajtach np. 4kb na jednego inta
cout<<sizeof(tab[0])<<"siezeof tab[0]"<<endl;                    //tab[0] - ile zajmuje pierwszy element
*/

//int tab[] = {1,2,3,4,4,5,5,6,7,8,99,10};
int tab[] = {3};
int size = sizeof(tab)/sizeof(tab[0]);
Wezel *head = arrayToList(tab, size);

showList(head);

//Wezel *head2 = removeAll(head);
//showList(head2);

Wezel *head2 = removeOdd(head);
showList(head2);


system("Pause");

return 0; 
}
