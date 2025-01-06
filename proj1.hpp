//
//  proj1.hpp
//  INVENTORY-SYSTEM
//
//  Created by Krish Makwana on 1/5/25.
//

#ifndef proj1_hpp
#define proj1_hpp
#include <stdio.h>
#include<iostream>
using namespace std;
#include<vector>  //including STL's vector library
#include<fstream> //for using file operations
typedef int numberOfItems;  //user defined data type for number of items
class Item{
private:        //class members
    string name;
    double price;
    int amount;
public:
    //constructor
    Item(string name=" ",double price=0,int amount=0);
    //mutators
    void setName(string name);
    void setPrice(double price);
    void setAmount(int amount);
    //accessors
    string getName(){return name;}
    double getPrice(){return price;}
    int getAmount(){return amount;}
    //friend functions for operator overloading
    friend ostream & operator<<(ostream &o, Item &i);
    friend ofstream & operator<<(ofstream &off, Item &i);
    friend ifstream & operator>>(ifstream &iff, Item &i);
    //empty destructor
    ~Item(){}
};
Item::Item(string name,double price,int amount){
    setName(name);
    setPrice(price);
    setAmount(amount);
}
void Item::setName(string name){
    if(name==""){            //handling no names
        this->name="unknown";
    }
    else{
        this->name=name;
    }
}
void Item::setPrice(double price){
    if(price<=0){       //handling negative prices
        this->price=0;
    }
    else{
        this->price=price;
    }
}
void Item::setAmount(int amount){
    if(amount<=0){      //handling negative amount
        this->amount=0;
    }
    else{
        this->amount=amount;
    }
}
ostream &operator<<(ostream &o, Item &i){   //printing object member values using object name
    o<<i.getName()<<" | "<<i.getPrice()<<" | "<<i.getAmount()<<endl;
    return o;
}
ofstream & operator<<(ofstream &off, Item &i){  //writing entire object into file
    off<<i.name<<" "<<i.price<<" "<<i.amount<<endl;
    return off;
}
ifstream & operator>>(ifstream &iff, Item &i){  //reading entire object from file
    iff>>i.name>>i.price>>i.amount;
    return iff;
}
#endif /* proj1_hpp */
