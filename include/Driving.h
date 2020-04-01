#ifndef DRIVING_H
#define DRIVING_H


class Driving
{
    public:
        Driving() {}
        virtual ~Driving() {}
        void drivingC();
        void setup();
    protected:

    private:

       //  vector <Item> I_one;
};
void Driving::drivingC()
{

binaryTreeType <Item> store;
    int choice=0;
    int buyNum=0;
    bool repeat=true;
    string holder;
    double holder1;
    while (repeat)
    {
        Item f;
        cout << "Welcome to Menelik's Market"<<endl;
        cout << "1. Add Selling Item"<<endl;
        cout << "2. Buy Item"<<endl;
        while (!(cin >> choice))
        {
            cout << "Must be a Number"<<endl;
            cin.clear();
            cin.ignore(100,'\n');
        }
        if (choice==1)
        {
            system("CLS");
            cout << "What is the name of the selling Item you want to add : " ;
            cin >> holder;
            f.itemName=holder;
            cin.clear();
            cin.ignore(150,'\n');
            cout << "\nWhat is the Price of the Item you wish to sell : ";
            while (!(cin >> f.price))
            {
                cout << "Must be a Number"<<endl;
                cin.clear();
                cin.ignore(100,'\n');
            }
            cout << "\nAny description you want to add for the Item : ";
            cin >> holder;
            f.description=holder;
            cin.clear();
            cin.ignore(150,'\n');
            store.insert(f);

        }
        else if (choice==2)
        {
            store.inorderTraversal();
            cout << "So what Item do you wish to purchase : ";
            cin >> buyNum;
            store.returnBuy(buyNum);
        }
        else if (choice==-999)
            repeat=false;

system("CLS");
    }



}



#endif // DRIVING_H
