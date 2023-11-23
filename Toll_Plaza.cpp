//21-44472-1-Pranta hossen
#include<iostream>//libary
using namespace std;//abbreviation for standard.
#define Size 50//size define

class Conveyance//class
{


    public :

    string date;
    int ConveyanceNumber;
    int tickeToken;

    Conveyance()//empty constructor
    {

    }

    Conveyance(int VahNumber, string date, int Token)//constructor
    {
        this->ConveyanceNumber = VahNumber;//this pointer
        this->date = date;
        this->tickeToken = Token;
    }

    //get method
    string getDate()
    {
        return date;//return value
    }

    int getConveyanceNumber()
    {
        return ConveyanceNumber;
    }

    int getTickeToken()
    {
        return tickeToken;
    }
};

class TollCentre//class
{
public :

    Conveyance heavyDuty[Size];//array creation
    Conveyance mediumDuty[Size];
    Conveyance lightDuty[Size];
    int HFront = -1;
    int MFront = -1;
    int LFront = -1;
    int HRear = -1;
    int MRear = -1;
    int LRear = -1;
    int highDuty=0;
    int mediumDutyV=0;
    int lowDuty=0;

    void ConveyanceDat()//function
    {
        int VahNumber;
        string date;
        int VahType = 0;
        cout<<"\nPress 1 for Heavy-duty Vehicle. ";
        cout<<"\nPress 2 for Medium-duty Vehicle.";
        cout<<"\nPress 3 for Light-duty Vehicle.";
        cout<<"                     \n\nEnter choice:-";
        cin>>VahType;
        cout<<"Enter Conveyance Number: ";
        cin>>VahNumber;
        cout<<"Enter Date with Time   : ";
        cin>>date;


        switch(VahType)//conditional operator
        {
            case 1 :
                {
                if(HFront == -1)
                {
                    HFront++;
                }

                if(HRear+1 < Size)
                {
                    HRear++;
                    Conveyance c(VahNumber, date, 123+HRear);//object creating
                    heavyDuty[HRear] = c;
                    highDuty += 800;
                }
                else
                {
                    cout<<"Heavy-duty Line is full...";
                }
                cout<<endl;
                break;
            }
            case 2 :
            {
                if(MFront == -1)
                {
                    MFront++;
                }

                if(MRear+1 < Size)
                {
                    MRear++;
                    Conveyance c(VahNumber, date, 456+MRear);//object creating
                    mediumDuty[MRear] = c;
                    mediumDutyV += 500;
                }
                else
                {
                    cout<<"Medium-duty Line is full...";
                }
                cout<<endl;
                break;
            }
            case 3 :{
                if(LFront == -1)
                {
                    LFront++;
                }

                if(LRear+1 < Size)
                {
                    LRear++;
                    Conveyance c(VahNumber, date,789+LRear);//object creation
                    lightDuty[LRear] = c;
                    lowDuty += 300;
                }
                else
                {
                    cout<<"Light-duty Line is full";
                }
                cout<<endl;
                break;
            }
            default:
                cout<<"Not A Valid Conveyance Type!"<<endl;
        }
    }

    void heavyDutyDat()//function
    {
        if(HFront < 0)
        {
            cout<<"Counter is empty!"<<endl;
        }
        else
        {
            cout<<"    Heavy Duty   : "<<endl;
            for(int i =HFront; i <=HRear; i++)
            {
                cout<<"Conveyance Number: "<<heavyDuty[i].getConveyanceNumber()<<endl;
                cout<<"Date             : "<<heavyDuty[i].getDate()<<endl;
                cout<<"Ticket Number    : "<<heavyDuty[i].getTickeToken()<<endl;
                cout<<endl;
            }
        }
        cout<<endl;
    }

    void mediumDutyDat()//function
    {
        if(MFront < 0)
        {
            cout<<"Counter is empty!"<<endl;
        }
        else
        {
            cout<<"    Medium Duty: "<<endl;
            for(int i =MFront; i <=MRear; i++)
            {
                cout<<"Conveyance Number: "<<mediumDuty[i].getConveyanceNumber()<<endl;
                cout<<"Date         : "<<mediumDuty[i].getDate()<<endl;
                cout<<"Ticket Number: "<<mediumDuty[i].getTickeToken()<<endl;
                cout<<endl;
            }
        }

        cout<<endl;
    }

    void lightDutyDat()//function
    {
        if(LFront < 0)
        {
            cout<<"Counter is empty!"<<endl;
        }
        else
        {
            cout<<"    Light Duty: "<<endl;
            for(int i =LFront; i <=LRear; i++)
            {
                cout<<"Conveyance Number: "<<lightDuty[i].getConveyanceNumber()<<endl;
                cout<<"Date         : "<<lightDuty[i].getDate()<<endl;
                cout<<"Ticket Number: "<<lightDuty[i].getTickeToken()<<endl;
                cout<<endl;
            }
        }
        cout<<endl;
    }

    void hdEarning()//function
    {
        cout<<highDuty<<" Tk\n\n";
    }

    void mdEarning()//function
    {
        cout<<mediumDutyV<<" Tk\n\n";
    }

    void ldEarning()//function
    {
        cout<<lowDuty<<" Tk\n\n";
    }

    void totalEarning()//function
    {
        int total = 0;
        total =highDuty +mediumDutyV +lowDuty;//total amount counting
        cout<<total<<" Tk\n";
    }
    int searchConveyanceByNumber()//function
    {
        int VahicleNumber;
        cout<<"Enter Conveyance Number: ";
        cin>>VahicleNumber;
        for(int i = 0; i <=HRear; i++)
        {
            if(heavyDuty[i].getConveyanceNumber() == VahicleNumber)
            {
                cout<<"Date           : "<<heavyDuty[i].getDate()<<endl;
                cout<<"Ticket Number  : "<<heavyDuty[i].getTickeToken()<<endl;
                cout<<endl;
                return 0;
            }
        }
        for(int i = 0; i <=MRear; i++)
        {
            if(mediumDuty[i].getConveyanceNumber() == VahicleNumber)
            {
                cout<<"Date         : "<<mediumDuty[i].getDate()<<endl;
                cout<<"Ticket Number: "<<mediumDuty[i].getTickeToken()<<endl;
                cout<<endl;
                return 0;
            }
        }
        for(int i = 0; i <=LRear; i++)
        {
            if(lightDuty[i].getConveyanceNumber() == VahicleNumber)
            {
                cout<<"Date         : "<<lightDuty[i].getDate()<<endl;
                cout<<"Ticket Number: "<<lightDuty[i].getTickeToken()<<endl;
                cout<<endl;
                return 0;
            }
        }

        cout<<"No matching Conveyance plate found!"<<endl;
        return 0;
    }
};

int main()//main function or method
{
    TollCentre TollCentre;
    int choice = 10;//local variable

    while(choice != 0)//conditional operator
    {
        cout<<endl;
        cout<<"                    Press 1 for selecting Vehicle Type."<<endl;
        cout<<"                    Press 2 for Heavy-duty Conveyance Sheet."<<endl;
        cout<<"                    Press 3 for Medium-duty Conveyance Sheet."<<endl;
        cout<<"                    Press 4 for Light-duty Conveyance Sheet."<<endl;
        cout<<"                    Press 5 for show total earning of Heavy-duty Conveyance Box."<<endl;
        cout<<"                    Press 6 for show total earning of Medium-duty Conveyance Box."<<endl;
        cout<<"                    Press 7 for show total earning of Light-duty Conveyance Box."<<endl;
        cout<<"                    Press 8 for show total earning of toll Booth."<<endl;
        cout<<"                    Press 9 to search vehicle by number."<<endl;
        cout<<"\n                    Press 0 for exit";
        cout<<endl;

        cout<<"Enter Your Choice: ";
        cin>>choice;
        switch (choice)
         {
            case 1:
                TollCentre.ConveyanceDat();
                break;
            case 2:
                TollCentre.heavyDutyDat();
                break;
            case 3:
                TollCentre.mediumDutyDat();
                break;
            case 4:
                TollCentre.lightDutyDat();
                break;
            case 5:
                TollCentre.hdEarning();
                break;
            case 6:
                TollCentre.mdEarning();
                break;
            case 7:
                TollCentre.ldEarning();
                break;
            case 8:
                TollCentre.totalEarning();
                break;
            case 9:
                TollCentre.searchConveyanceByNumber();
                break;
            case 0:
                break;
            default:
                cout<<"Error !!"<<endl<<endl;
        }
    }
}

