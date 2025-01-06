//
//  proj1.cpp
//  INVENTORY-SYSTEM
//
//  Created by Krish Makwana on 1/5/25.
//
#include "proj1.hpp"
void writeInFile(vector<Item> v){     //function to write into the file
    ofstream of("Item_Inventory.txt"); //ofstream object
    for(int i=0;i<v.size();i++){
        of<<v[i];                       //writing each object into file from vector
    }
    of.close();                         //closing the file
}
void removeItem(vector<Item> &v,int itemNumber){   //function for deleting item from vector                                                 //and file
    if(itemNumber-1>=0 && itemNumber-1<=v.size()){ //checking for index errors
        vector<Item>::iterator itr;                //declaring iterator
        itr=v.begin()+(itemNumber-1);              //finding the index to delete item
        v.erase(itr);                              //deleting the element
        writeInFile(v);                            //rewriting the file after deletion
    }
    else{
        cout<<"invalid item number!!!"<<endl;    //for index issues
    }
}
void addItem(vector<Item> &v,Item i){            //function for adding item into list
    v.push_back(i);                             //appending new item into vector
    writeInFile(v);                             //updating the file after object addition
}
void display(vector<Item> v1){                  //function to read and display
    ifstream iff("Item_Inventory.txt");         //ifstream object
    if(!iff){                                   //checking if file is open
        cout<<"File can't be opened to display items!!!"<<endl;
    }
    else{
        vector<Item> v2(v1.size());         //creating a vector to store items from file
        for(int i=0;i<v2.size();i++){
            iff>>v2[i];                     //storing items in vector
        }
        iff.close();                        //closing the file
        vector<Item>::iterator itr;         //creating an iterator
        for(itr=v2.begin();itr!=v2.end();itr++){
            cout<<*itr;                    //printing objects
        }
    }
}
int main(){
    numberOfItems n;
    cout<<"Enter the number of items:";
    cin>>n;                             //asking for number of items
    vector<Item> v1;                    //delclaring item vector
    for(int i=0;i<n;i++){
        string name;                    //asking for name, price and amount for each item
        double price;
        int amount;
        cout<<"Enter for "<<i+1<<"th item:"<<endl;
        cout<<"Item Name:";
        cin>>name;
        cout<<"Item Price:";
        cin>>price;
        cout<<"Item Amount:";
        cin>>amount;
        Item temp=Item(name,price,amount);  //creating an object and putting members
        v1.push_back(temp);                 //putting the item object into item vector
        writeInFile(v1);                    //calling function tp write v1's objects in file
    }
    cout<<"Items have been added to the list and can be viewed in file."<<endl;
    bool keepWorking=true;  //to keep track of whether to keep using the program
    do{
        cout<<"--------------------MENU--------------------"<<endl; //option menu
        cout<<"1. Add items into the list"<<endl;
        cout<<"2. Delete item from the list"<<endl;
        cout<<"3. Display item list from file in console"<<endl;
        cout<<"4. Exit program"<<endl;
        cout<<"____________________________________________"<<endl;
        int choice=0;
        cout<<"Enter your choice from menu:";
        cin>>choice;                            //asking for user choice to choose from menu
        switch(choice){
            case 1:{
                cout<<"Enter the item you want to add:"<<endl;
                string name;
                double price;
                int amount;
                cout<<"Enter the name:";
                cin>>name;
                cout<<"Enter the price:";
                cin>>price;
                cout<<"Enter the amount:";
                cin>>amount;
                Item itemToAdd=Item(name,price,amount); //creats item to be added to list
                addItem(v1,itemToAdd);                  //adds to list
                break;
            }
            case 2:{
                int itemToDelete;
                cout<<"Enter the item number you want to delete:";
                cin>>itemToDelete;      //asking which item to delete
                removeItem(v1,itemToDelete); //removes the item
                break;
            }
            case 3:{
                cout<<"Reading items from file and displaying them"<<endl;
                display(v1);  //calls display function
                break;
            }
            case 4:{
                cout<<"Program exit!!!"<<endl;
                keepWorking=false;      //loop condition becomes false
                break;
            }
            default:{
                cout<<"Invalid choice, showing the menu again!!!"<<endl; //loop continues
                break;
            }
        }
    }while(keepWorking); //if user wants to exit, condition will become false
    return 0;
}

