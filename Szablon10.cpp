#include <iostream>
using namespace std;

struct Wezel 
{
       int dana;
       Wezel* next;
};

void showList(const Wezel* head) 
{
     if (! head) 
     {
        cout << "Lista jest pusta" << endl;
        return;
     }
     
     while (head) 
     {
           cout << head->dana << " ";
           head = head->next;
     }
     
     cout << endl;
}

Wezel* arrayToList(const int tab[], int size) 
{
     Wezel* head;
     Wezel* wsk;  
     Wezel* tmp; 
     
     for(int i=0; i<size; i++)
     {
         cout << tab[i] << " ";
     }
     cout << endl;
    
    if (size==0) 
    {
         return NULL;
    }
    else
    { 
       head = new Wezel;
       //head->next = NULL;
       head->dana = tab[0];
    
       wsk = head;
       for(int i=1;i<size;i++)
       {
          tmp = new Wezel;
          tmp->dana = tab[i];
          tmp->next = NULL;
          
          wsk->next = tmp;
          wsk=tmp;
       }
    }
    
    cout << endl;
      
    return head; 
}

Wezel* removeOdd(Wezel* head) 
{ 
  Wezel *tmp, *usw;
  Wezel *new_head, *oper, *lastpar;
  int findstatus;
  
  if(head == NULL)
  return NULL;
  else
  {
      // Najpierw znalezc dobry leb.
      // Znalezc pierwszy parzysty.
      oper = head;
      findstatus = 0;
      while(oper != NULL)
      {
          // Czy dana jest parzysta?
          if((oper->dana)%2 == 0)
          {
              // Znalezlismy parzysta dana.
              findstatus = 1;
              break;
          }
          else
          {
              usw = oper;
              oper = oper->next;
              cout << "usuwamy " << usw->dana << endl;
              delete(usw);
          }
      }
   // Jesli findstatus == 1 to mamy dobry leb.
   // Jesli findstatus == 0 to znaczy ze lista jest juz pusta.
   if(findstatus == 0)
   {
       return NULL;
   }
   else if(findstatus == 1)
   {
        new_head = oper;
        // Tutaj leb jest na pewno parzysty.
        oper = new_head->next;
        lastpar = new_head;

        // Kasowanie od lba do konca.
        while(oper != NULL)
        {
           if((oper->dana) % 2 == 0)
           {
              lastpar = oper;
              oper = oper->next;
           }
           else if((oper->dana) % 2 == 1)
           {
               usw = oper;
               oper = oper->next;
               lastpar->next = oper;
               cout << "usuwamy " << usw->dana << endl;
               delete(usw);
           }
        }    
   }

   return new_head;
  }
  
  while (head) 
  {
           cout << head->dana << " ";
           head = head->next;
  }
   return head;  
}

Wezel* usun_liste(Wezel *head)
{
    Wezel *tmp;
    if (head == NULL)
    return NULL;
    
    while(head != NULL)
    { 
      tmp = head->next;
      delete head;
      head = tmp;
    }
    
    return head;              
}

int main(void) 
{
    //int tab[] = {7,5,2,3,4,8,1,7,2};
    int tab[] = {7,5,3,3,5,2,17,7,9};
    //int tab[] = {2,4,10,8,8,2,12,14,18};
    int size = sizeof(tab)/sizeof(tab[0]);
    
    //int tab[]={};
    //int size = sizeof(tab)/sizeof(tab[0]);
    
    //int tab[]={1,2,3};
    //int size = sizeof(tab)/sizeof(tab[0]);
    
    Wezel *head = arrayToList(tab, size);
    showList(head);
    
    
    Wezel *head2 = arrayToList(tab, size);
    showList(head2);
    head2 = removeOdd(head2);
    //head2=usun_liste(head2);
    showList(head2);
    
    system("Pause");
    
    return 0;
}
