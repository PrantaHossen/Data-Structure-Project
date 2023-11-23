
//21-44472-1-Pranta Hossen

#include <iostream>

using namespace std;//abbreviation for standard.


class FoodShop //class Foodshop
{
    string shopName;
    string location;
    string Item;
    double foodprice;

public:
    FoodShop() // Empty constructor
    {

    }

    FoodShop( string &shopName, string &location, string &Item, double foodprice)// Parameterized constructor
    {

    }

    void setshopName(string &shopName)//set method for Shop name
    {
        this->shopName = shopName;//this pointer
    }

     string &getshopName()//Get method for shop name
    {
        return shopName;//Return value
    }

    void setlocation( string &location)//set method for location
    {
        this->location = location;//this pointer
    }

     string &getlocation()//Get method for location
     {
        return location;//Return value
    }

    void setItem( string &Item)//set method for Item
    {
        this->Item = Item;//this pointer
    }
     string &getItem()//Get method for Item
    {
        return Item;//Return value
    }

    void setfoodprice(double foodprice)//set method for Food price
    {
        this->foodprice = foodprice;//this pointer
    }

    double getfoodprice()//Get method for Food Price
    {
        return foodprice;//Return value
    }


};

class Node//class Node
{
    FoodShop info; // this is Info part of the FoodShop object
    Node *next = nullptr; // this is pointer to the next node
public:
    Node() {}// Empty constructor
    Node(FoodShop &info, Node *next){}// Parameterized constructor

    void setinfo(FoodShop &info)//set method for info
    {
        this->info = info;//this pointer
    }
     FoodShop &getInfo()//Get method for Info
    {
        return info;//return value
    }

    void setNext(Node *next)//set method for Next
    {
        this->next = next;//this pointer
    }

    Node *getNext()//Get method for
    {
        return next;//return value
    }

};
void showing(FoodShop element)//Function Of showing..which show All element info by using Get Method
 {  cout<<endl;
    cout << "*******************************************" << endl;
    cout << "Shop Name     : " << element.getshopName() << endl;
    cout << "Shop location : " << element.getlocation() << endl;
    cout << "Name of Item  : " << element.getItem() << endl;
    cout << "Price Of Item : " << element.getfoodprice() << endl;
    cout<<endl;
    cout << "******************************************" << endl;
}
class BST   //BST
{
    FoodShop data;
    BST *left, *right;

public:

    BST()//Empty constructor
    {
        left = NULL;
        right =NULL;
    }

    BST(FoodShop value)// Parameterized constructor
    {
        data = value;
        left = NULL;
        right= NULL;
    }

    BST* Insert(BST* base, FoodShop value)
    {
        if (!base)
        {
            return new BST(value); //Return value
        }

        else if (value.getfoodprice() > base->data.getfoodprice()) //condition
        {
            base->right = Insert(base->right, value);
        }
        else
        {
            base->left = Insert(base->left, value);
        }
        return base;
    }

    void Inorder(BST* base)//Function for Inorder
    {
        if (!base)
        {
            return;
        }
        Inorder(base->left);//order
        showing(base->data);
        Inorder(base->right);//
    }
};


void ShowDetails(FoodShop *AllComponent, int number) //Function for show Details
{
    cout << "************************************************************" << endl;
    for(int i=0; i<number; i++)// For condition
    {
        //Showing  Data
        cout << "******************"<<i+1<<" - "<<"Shop no. Details *************" << endl;
        cout << "Shop Name     : " << AllComponent[i].getshopName() << endl;
        cout << "Shop Location : " << AllComponent[i].getlocation() << endl;
        cout << "Name of  Item : " << AllComponent[i].getItem() << endl;
        cout << "Price of Item : " << AllComponent[i].getfoodprice() << endl;
    }
    cout << "************************************************************" << endl;
}
void Bubble_sort(FoodShop *AllComponent, int number, string point = "foodprice") //Function For Bubble Sort
{
    for(int i = 0;i < number;i++) //for condition
        {
        for(int j = i+1;j < number;j++)//Nested For
        {
            if(point == "foodprice" && AllComponent[i].getfoodprice() > AllComponent[j].getfoodprice())//checking condition

            {
                FoodShop temp;
                temp.setshopName(AllComponent[i].getshopName());
                temp.setItem(AllComponent[i].getItem());
                temp.setlocation(AllComponent[i].getlocation());
                temp.setfoodprice(AllComponent[i].getfoodprice());

                AllComponent[i] = AllComponent[j];
                AllComponent[j] = temp;
            }
        }
    }
}

void Selection_sort(FoodShop *AllComponent, int number, string point = "foodprice") //Function for Selection sort
{
    for(int i=0; i<number; i++)
    {
        int min_index = i;

        for(int j=i+1; j<number; j++)
        {

            if(point == "foodprice" && AllComponent[i].getfoodprice() > AllComponent[j].getfoodprice())
            {
                min_index = j;
            }
        }

        FoodShop temp = AllComponent[min_index];
        AllComponent[min_index] = AllComponent[i];
        AllComponent[i] = temp;
    }
}

int main()
{
    cout<<"...............................Loading............................"<<endl<<endl;
    cout<<"..............................FOOD Shop Management..................... \n"<<endl;
    int number;
    cout << "How many element insert : ";
    cin >> number;
    FoodShop AllComponent[number];
    for (int i = 0; i < number; i++)
        {
        string shopName, location, Item;
        double foodprice;
        {
            cout<<endl;
            cout<<"Creating object......."<<endl;
            cout<<endl;
            cout << "Enter Shop-"<<i+1<<" Name : ";
            cin >> shopName;
            cout << "Enter Shop-"<<i+1<<"Location : ";
            cin >> location;
            cout << "Enter a Item-"<<i+1<<" Name : ";
            cin >> Item;
            cout << "Enter Item-"<<i+1<<" Price: ";
            cin >> foodprice;
            cout<<endl;
        }
        {
            AllComponent[i].setshopName(shopName);
            AllComponent[i].setlocation(location);
            AllComponent[i].setItem(Item);
            AllComponent[i].setfoodprice(foodprice);
        }
        cout<<"Object Created................"<<endl;
    }
    while(true)
    {

        {
            cout <<endl<<"-----Your options are given bellow......." << endl;
            cout << " '1' ----- for Show Details the objects" << endl;
            cout << " '2' ----- for selection sorting the objects" << endl;
            cout << " '3' ----- for bubble sorting the objects" << endl;
            cout << " '4' ----- for binary search the objects" << endl;
            cout << " '5' ----- for BST of the objects" << endl;

        }
        int Option;
        cout<<"Please enter your option....... : ";
        cin >> Option;

        switch (Option)
        {
            case 1:

                ShowDetails(AllComponent, number);
                break;
            case 2:

                Selection_sort(AllComponent, number, "foodprice");
                cout<<"Selection Sort..........";
                break;
            case 3:

                Bubble_sort(AllComponent, number, "foodprice");
                cout<<"Bubble Sort..........";
                break;
            case 4:
            {
                Bubble_sort(AllComponent, number, "foodprice");
                cout << "Enter Food price : ";
                double item;
                cin >> item;
                int low = 0;
                int range = number;
                int mid = 0;
                while (range >= low)
                {
                    mid = (low + range) / 2;
                    if (AllComponent[mid].getfoodprice() == item)
                    {
                        cout << endl << "Item found at index: " << mid << endl;
                        break;
                    }
                    if (AllComponent[mid].getfoodprice() > item)
                    {
                        range = mid - 1;
                    }
                    else
                    {
                        low = mid + 1;
                    }
                }
            }
                break;
            case 5: {
                BST bst, *base = nullptr;
                base = bst.Insert(base, AllComponent[0]);
                for (int i = 1; i < number; i++) {
                    bst.Insert(base, AllComponent[i]);
                }

                bst.Inorder(base);
            }
        }
    }
}
