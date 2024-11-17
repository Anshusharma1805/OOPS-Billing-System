#include <iostream>
#include<fstream>
#include <sstream>
#include <windows.h>
using namespace std;

class Bill{
    private:
      string Item;
      int Rate, Quantity;
    public:
     Bill(): Item(""), Rate(0) , Quantity(0){ }
     void setItem(string item){
         Item = item;
     }
     void setRate(int rate){
         Rate = rate;
     }
     void setQuantity(int quant){
         Quantity = quant;
     }
     string getItem(){
         return Item;
     }
     int getRate(){
         return Rate;
     }
     int getQuantity(){
         return Quantity;
     }
};

void addItem (Bill b){
    bool close = false;
    while(!close){
        int choice;
        cout<< "\t1.Add."<<endl;
        cout<< "\t2.close."<<endl;
        cout<< "\t.Enter Choice:";
        cin>>choice;

        if(choice ==1){
            system ("cls");
            string item;
            int rate , quant;
            
            cout <<"\tEnter Item Name:";
            cin>>item;
            b.setItem(item);

            cout <<"\tEnter rate:";
            cin>>rate;
            b.setRate(rate);

            cout <<"\tEnter Quantity:";
            cin>>quant;
            b.setQuantity(quant);

            ofstream out("D;/Bill.txt", ios::app);
            if(!out){
                cout<<"\tError: File can't open!"<<endl;

            }
            else{
                cout<<"\t"<<b.getItem()<<" : "<< b.getRate()<<" : "<< b.getQuantity()<<endl<<endl;
            }
            out.close();
            cout<< "\tItem Added Successfully";
            Sleep(3000); //for 3000 msec this will be displayed 
        }
        else if (choice == 2){
            system("cls");
            close = true;
            cout<<"\tback to Main Menu"<<endl;
            Sleep(3000);
        }
    }
    }

    void printBill(Bill b){
        system ("cls");
        int count = 0;
        bool close = false;
        while(!close){
            system("cls");
            int choice;
        cout<< "\t1.Add Bill."<<endl;
        cout<< "\t2.close Session."<<endl;
        cout<< "\t.Enter Choice:";
        cin>>choice;

        if (choice == 1){
            string item;
            int quant;
            cout << "\tEnter Item: ";
            cin>>item;
            cout<<"Enter Quantity";
            cin>>quant;

            ifstream in("D;/bill.txt");
            ofstream out( "D:/Bill Temp.txt");

            string line;
            bool found = false;

            while(getline(in, line)){
                stringstream ss;
                ss<<line;
                string itemName;
                int itemRate;
                int itemQuant;
                char delimiter;
                ss>> itemName>>delimiter>>itemRate>>delimiter>>itemQuant>>delimiter;  //delimiter sets boundary 

                if (item == itemName){
                    found = true;
                    if (quant == itemQuant){
                       int amount = itemRate * quant;
                       cout<<"\t Item | Rate | Quant | Amount"<<endl;
                       cout <<"\t"<<itemName<<"/t"<<itemRate<< "\t"<<quant<<"\t"<<amount<<endl;
                       int newQuant = itemQuant - quant;
                       itemQuant = newQuant;
                       count += amount;

                       out<<"\t"<<itemName<<" : "<<itemRate<<" : "<<itemQuant<<endl<<endl;
                    }
                    else{
                        //not Available
                        cout<<"\tSorry, "<< item<<"Ended!"<<endl;
                    }
                } 
                 else{
                    //if not item found
                    out<<line;
                 }          
                           }
                           if(!found){
                            cout<<"\tItem Not Available"<<endl;
                           }
                           out.close();
                           in.close();
                           remove("D:/Bill.txt");
                           rename("D:/Bill.temp.txt","D:/Bill.txt");
        }
        else if (choice == 2){
            close = true;
            cout<<"\tCounting Total Bill"<<endl;
        }
        Sleep(3000);
        }
        system("cls");
        cout<<endl<<endl;
        cout<<"\t Total bill -------------------- :"<< count<<endl<<endl;
        cout<<"\t Thanks for Shopping"<<endl;
        Sleep(5000);

    }
int main() {
    Bill b;
    
    bool exit = false;
    while(!exit){
        system("cls");
        int val;

        cout << "\tWelcome To Super Market Billing System"<<endl;
        cout<< "\t***************************************"<<endl;
        cout<< "\t\t1.Add Item."<<endl;
        cout<< "\t\t2.Print Bill."<<endl;
        cout<< "\t\t3.Exit."<<endl;
        cout<< "\t\tEnter Choice:";
        cin>>val;

        if (val ==1){
            system("cls");
            addItem(b);
            Sleep(3000);

        }
        else if (val ==2){
            printBill(b);
        }
        else if (val ==3 ){
            system("cls");
            exit = true;
            cout<<"\tGood Luck!"<<endl;
            Sleep(3000);

        }
}
}