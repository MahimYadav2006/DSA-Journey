#include<bits\stdc++.h>
using namespace std;
class Student{
    private:
        string name;
        int age;
        int height;
    public:
        int getAge(){
            return this->age;
        }
};
class Human{
    public:
    int height;
    int age;
    int weight;

    // Getters and Setters
    void setAge(int age){
        this->age=age;
    }
    int getHeight(){
        return this->height;
    }
    private:
    int gaiko;  
};
class Male: public Human{
    public:
    string colour;
    void sleep(){
        cout<<"Male is sleeping now"<<endl;
    }
};

// // // // Single Level Inheritance // // // //
class Animal{
    public:
    string name;
    int height;
    public:
    void speak(){
        cout<<"Speaking"<<endl;
    }
};
class Dog: public Animal{
    string breed;
};

 // // Multi Level Ineheritance // //
class GS:public Dog{

};

// // Multiple Inheritance // // 
class Human1{
    public:
    void speak(){
        cout<<"Speaking"<<endl;
    }
};
class Animal1{
    public:
    void bark(){
        cout<<"Barking"<<endl;
    }
};
class Alia_Bhatt:public Human1,public Animal1{
    public:
    void Hello(){
        cout<<"Hello"<<endl;
    }
};


// // Heirarchical Inheritance // //
// class A{
//     public:
//     void func1(){
//         cout<<"Hello I am function 1"<<endl;
//     }
// };
// class B:public A{
//     public:
//     void func2(){
//         cout<<"Hello I am function 2"<<endl;
//     }
// };
// class C:public A
// {
//     public:
//     void func3(){
//         cout<<"Hello I am function 3"<<endl;
//     }
// };

/// // // Inheritance Ambiguity // // // 
// class A{
//     public:
//     void func(){
//         cout<<"Hello I am function 1"<<endl;
//     }
// };
// class B{
//     public:
//     void func(){
//         cout<<"Hello I am function 2"<<endl;
//     }
// };
// class C:public A,public B
// {
//     public:
//     void func3(){
//         cout<<"Hello I am function 3"<<endl;
//     }
// };

// // // Polymorphism // // //
// class A{
//     public:
//     void sayHello(){
//         cout<<"Hello Mahim"<<endl;
//     }
//     void sayHello(int a){
//         cout<<"Hello Bhallu"<<endl;
//     }
// };

// // Operator Overloading // // 
// class B{
//     public:
//     int a;
//     int b;
//     public:
//     int add(){
//         return a+b;
//     }
//     void operator + (B&obj){
//         int value1=this->a;
//         int value2=obj.a;
//         cout<<"output is "<<value1-value2<<endl;
//     }
//     void operator () (){
//         cout<<"Mai Bracket hu"<<endl;
//         cout<<this->a<<endl;
//     }
// };

// // // Runtime Polymorphism // // //
class A{
    public:
    void speak(){
        cout<<"Speaking"<<endl;
    }
};
class B:public A{
    public:
    void speak(){
        cout<<"Barking"<<endl;
    }
};


int main(){

    // // // // Encapsulation // // // // 
    // Student first;
    // cout<<"Sab Shi chal rha hai"<<endl;

    // // // // Inheritance // // // //
    // Male object1;
    // object1.setAge(23);
    // cout<<object1.age<<endl;
    // object1.sleep();

    // // Single Level Inheritance // //
    // Dog d;
    // d.speak();

    // // Multi Level Inheritance // //
    // GS g;
    // g.speak();

    // // Multiple Inheritance // //
    // Alia_Bhatt a;
    // a.speak();
    // a.bark();
    // a.Hello();

    // // Heirarchical Inheritance // // 
    // A a;
    // B b;
    // C c;
    // a.func1();
    // b.func1();
    // c.func1();
    // b.func2();
    // c.func3();


    // // Inheritance Ambiguity // // 
    // C obj;
    // // // obj.func(); // // This will lead to an error..  Because the obj do not know which func to call 
    // // // To avoid that we use scope resolution operator

    // obj.A::func();
    // obj.B::func();

    // // // Polymorphism // // //

    // // // Function Overloading // // 
    // A a;
    // a.sayHello();
    // a.sayHello(3);

    // // // Operator Overloading // // 
    // B b1,b2;
    // b1.a=3;
    // b2.a=7;
    // b1+b2;
    // b1();
    // b2();


    // // // Dynamic Polymorphism // // //
    B d;
    d.speak();
    A a;
    a.speak();

}