/*      THE BEST POSSIBLE WAY     */

// #include<bits\stdc++.h>
// using namespace std;
// class Hero{
//     private:
//     int health;
//     char level;
//     string *name=new string;
//     int pincode;
//     string address;
//     public:
//     static int time_to_complete;

//     public:
//     void setName(string name){
//         *this->name=name;
//     }
//     void setLevel(char level){
//         this->level=level;
//     }
//     void setHealth(int health){
//         this->health=health;
//     }
//     static int random(){
//         cout<<"Hello I am a static function "<<endl;
//         return time_to_complete;
//     }
//     string getName(){
//         return (*name);
//     }
//     char getLevel(){
//         return this->level;
//     }
//     int getHealth(){
//         return this->health;
//     }
//     Hero(){
//         cout<<"Hello I am a constructor"<<endl;
//     }
//     Hero(int pincode,string address){
//         this->pincode=pincode;
//         this->address=address;
//     }
//     int getPincode(){
//         return this->pincode;
//     }
//     string getAddress(){
//         return this->address;
//     }
//     Hero(Hero& temp){
//         this->health=temp.health;
//         this->level=temp.level;
//         this->address=temp.address;
//         this->pincode=temp.pincode;
//         // this->name=temp.name;
//         this->name=new string(*temp.name);
//         // (*s)=temp.name;
//         // *this->name=(*s);
//     }
//     ~Hero(){
//         delete name;
//         cout<<"BYE BYE"<<endl;
//     }

// };
// int Hero:: time_to_complete=5;
// int main(){
//     cout<<Hero::time_to_complete<<endl;
//     Hero* h1=new Hero(301702,"Roneeja");
//     // cout<<sizeof(*h1);
//     h1->setHealth(45);
//     h1->setLevel('a');
//     h1->setName("Hailo");
//     cout<<h1->getName()<<" "<<h1->getHealth()<<" "<<h1->getLevel()<<endl;
//     cout<<h1->getAddress()<<" "<<h1->getPincode()<<endl;
//     Hero *h2=new Hero();
//     (*h2)=(*h1);
//     h2->setName("ElvishBhai");
//     cout<<h2->getName()<<" "<<h2->getHealth()<<" "<<h2->getLevel()<<endl;
//     cout<<h2->getAddress()<<" "<<h2->getPincode()<<endl;
//     cout<<"Printing the name of object h1 "<<h1->getName()<<endl;
//     cout<<Hero::random()<<endl;
//     delete h1;
//     delete h2;
// }


#include<iostream>
#include<string>
#include<bits\stdc++.h>
using namespace std;
// class Hero{
//     private:
//     char level;
//     int health;
//     string name;
//     // Setters
//     public:
//     void setName(string s){
//         name=s;
//     }
//     void setLevel(char n){
//         level=n;
//     }
//     void setHealth(int c){
//         health=c;
//     }
//     // Getters
//     string getName(){
//         return name;
//     }
//     char getLevel(){
//         return level;
//     }
//     int getHealth(){
//         return health;
//     }

//     // // // Constructors // // //
//     // Hero(){
//     //     cout<<"I am a constructor"<<endl;
//     // }
//     // Hero(int health,char level){
//     //     this->health=health;
//     //     this->level=level;
//     // }
//     Hero(int health,char level,string name){
//         this->health=health;
//         this->level=level;
//         this->name=name;
//     }

//     // // // Copy Constructor // // //
//     // Hero(Hero* temp){
//     //     this->health=temp->health;
//     //     this->level=temp->level;
//     //     this->name=temp->name;
//     // }

//     //

//     Hero(Hero& temp){
//         this->health=temp.health;
//         this->level=temp.level;
//         this->name=temp.name;
//     }
// };


// // // Shallow copy and Deep copy and some other related concepts  // // //
// class Hero{
//     private:
//     int health;
//     char *name=new char[100];

//     public:
//     void setHealth(int health){
//         this->health=health;
//     }
//     void setName(char name[]){
//         this->name=name;
//     }
//     void print(){
//         cout<<"Health is "<<health<<endl;
//         cout<<"Name is "<<name<<endl;
//     }
//     Hero(){
//         cout<<"Hi I am called"<<endl;
//     }
//     Hero(Hero& temp){
//         char *ch=new char[strlen(temp.name)+1];
//         strcpy(ch,temp.name);
//         this->name=ch;
//         this->health=temp.health;
//     }
// };

// // // Destructor and static keyword // // // 
class Hero{
    public:
    int health=25;
    static int timeToComplete;

    // Creation of destructor
    ~Hero(){
        cout<<"Aa le chak mai aa gya"<<endl;
    }

    // Creating static function
    static int random(){
        return timeToComplete;
    }
};
int Hero::timeToComplete=5;


int main(){
    // // Static Allocation // //

    // Hero Ramesh;
    // cout<<sizeof(Ramesh)<<endl;
    // Ramesh.setHealth(25);
    // Ramesh.setLevel('A');
    // Ramesh.setName("Deepika_Padukone");
    // cout<<Ramesh.getHealth()<<endl;
    // cout<<Ramesh.getLevel()<<endl;
    // cout<<Ramesh.getName()<<endl;

    // // Dynamic Allocation // //
    // Hero* Ramesh=new Hero;

    // cout<<sizeof(*Ramesh)<<endl;

    // // Method 1 // //


    // (*Ramesh).setHealth(25);
    // (*Ramesh).setLevel('A');
    // (*Ramesh).setName("Deepika_Padukone");
    // cout<<(*Ramesh).getHealth()<<endl;
    // cout<<(*Ramesh).getLevel()<<endl;
    // cout<<(*Ramesh).getName()<<endl;

    // // Method 2 // //

    // (Ramesh)->setHealth(25);
    // (Ramesh)->setLevel('A');
    // (Ramesh)->setName("Deepika_Padukone");
    // cout<<(Ramesh)->getHealth()<<endl;
    // cout<<(Ramesh)->getLevel()<<endl;
    // cout<<(Ramesh)->getName()<<endl;


    // // Constructors // //
    // Hero Ramesh;
    // Hero* ramesh=new Hero(19,'A');
    // cout<<ramesh->getHealth()<<endl;
    // cout<<ramesh->getLevel()<<endl;
    // Hero* r=new Hero(19,'a',"Alia_Bhatt");
    // cout<<r->getHealth()<<endl;
    // cout<<r->getLevel()<<endl;
    // cout<<r->getName()<<endl;

    // // // // Copy Constructors // // //
    // Hero R(19,'a',"Alia_Bhatt");
    // cout<<R.getHealth()<<endl;
    // cout<<R.getLevel()<<endl;
    // cout<<R.getName()<<endl;

    // // Copying using copy constructor
    // Hero* S=new Hero(R);
    // cout<<S->getHealth()<<endl;
    // cout<<S->getLevel()<<endl;
    // cout<<S->getName()<<endl;


    // // // // Shallow Copy and Deep copy // // //
    // Hero h1;
    // char ch[100]="Bhallu";
    // h1.setName(ch);
    // h1.setHealth(445);
    // h1.print();

    // Hero* h2=new Hero(h1);
    // h2->print();
    // ch[0]='L';
    // h1.print();
    // h2->print();  // For demonstartion of shallow copy constructor default copy constructor is used
    // cout<<endl<<endl;
    
    // // Copy Assignment Operator //
    // h1=(*h2);
    // h1.print();
    // h2->print();
    
    // // // Destructor and Static // // // // 
    Hero a;
    Hero *b=new Hero();
    
    cout<<Hero::timeToComplete<<endl;
    cout<<a.timeToComplete<<endl;
    b->timeToComplete=25;
    cout<<Hero::timeToComplete<<endl;

    // testing static function
    cout<<Hero::random()<<endl;
    delete b;

}