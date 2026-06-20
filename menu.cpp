//CAFE MANAGEMENT SYSTEM
#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

//Structure to store order details
struct Order
    {
        string itemName;
        int quantity;
        int cost;
    };
//Displays Menu items
void displayMenu()
{
    cout<<"-----MENU-----\n";
    cout<<"1. Coffee    Rs.120\n";
    cout<<"2. Tea       Rs.70\n";
    cout<<"3. Sandwich  Rs.100\n";
    cout<<"4. Burger    Rs.90\n";
    cout<<"5. Pizza     Rs.300\n";
}
void printReceipt(vector<Order>& orders,string name,int grandtotal)
{
   cout << "\n-------RECEIPT-------" << endl;
   cout << "Customer: " << name << endl;
   cout << "\nItems Ordered:" << endl;
   for(int i = 0; i < orders.size(); i++)
   {
      cout << orders[i].itemName << " x " << orders[i].quantity<< " = Rs." << orders[i].cost<< endl;
   }

   cout << "\nTOTAL BILL = Rs." << grandtotal << endl;
   cout << "Thank You for Visiting!" << endl;
}
void saveReceiptToFile(vector<Order>& orders,string name,int grandtotal)
{
    ofstream file("receipt.txt",ios::app);
    file<<"-------RECEIPT-------"<<endl;
    file<< "Customer: "<<name<<endl;
    file<<endl;
    file<<" Items Ordered:"<<endl;
    for(int i=0;i<orders.size();i++)
    {
        file<<orders[i].itemName<< " x "<< orders[i].quantity<< " = Rs."<< orders[i].cost<<endl;
    }
    file << " TOTAL BILL = Rs." << grandtotal << endl;
    file<<"Thank You for Visiting!";
    file.close();
}
void viewReceipts()
{
    ifstream file("receipt.txt");

    string line;

    while(getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}
void totalSales()
{
    ifstream file("receipt.txt");

    string line;
    int totalSales = 0;

    while(getline(file, line))
    {
        if(line.find("TOTAL BILL = Rs.") != string::npos)
        {
            int amount = stoi(line.substr(17));
            totalSales += amount;
        }
    }

    file.close();

    cout << "\n===== SALES REPORT =====" << endl;
    cout << "Total Sales = Rs." << totalSales << endl;
}
int main()
{
    int userType;
    cout << "===== CAFE MANAGEMENT SYSTEM =====\n";
    cout << "1. Customer\n";
    cout << "2. Admin\n";
    cout << "3. Exit\n";
    cout << "Enter choice: ";

    // Admin Part
    cin >> userType;
    if(userType==2)
    {
        int adminchoice;
        string pass;
        cin>>pass;
        if(pass=="ABCD123")
          int adminChoice;

    cout << "\n===== ADMIN PANEL =====\n";
    cout << "1. View Receipts\n";
    cout << "2. View Total Sales\n";
    cout << "3. Exit\n";
    cout << "Enter choice: ";
    cin >> adminchoice;
    switch(adminchoice)
    {
        case 1:
            viewReceipts();
            break;

        case 2:
            totalSales();
            break;

        case 3:
            cout << "Exiting Admin Panel..." << endl;
            break;

        default:
            cout << "Invalid Choice!" << endl;
    }
    }
    else if(userType==3)
    {
        cout<<"Thankyou!"<<endl;
        return 0;
    }

    //Customer Part
    else if(userType==1){
    displayMenu();
    int choice, quantity;
    int total = 0;
    int grandtotal=0;
    char more;
    string name;
    cout<<"Enter Customer Name: ";
    cin.ignore();
    getline(cin,name);
    vector<Order> orders;
    do
    {
     cout << "Enter your choice: ";
     cin >> choice;
     Order o;
     switch(choice)
     {
        case 1:
            cout << "Enter quantity of coffee: ";
            cin >> quantity;
            total = 120 * quantity;
            grandtotal+=total;
            o.itemName="Coffee";
            o.quantity=quantity;;
            o.cost=total;
            orders.push_back(o);
            break;
        case 2:
            cout << "Enter quantity of tea: ";
            cin >> quantity;
            total = 70 * quantity;
            grandtotal+=total;
            o.itemName="Tea";
            o.quantity=quantity;;
            o.cost=total;
            orders.push_back(o);
            break;
        case 3:
            cout << "Enter quantity of sandwich: ";
            cin >> quantity;
            total = 100 * quantity;
            grandtotal+=total;
           o.itemName="Sandwich";
            o.quantity=quantity;;
            o.cost=total;
            orders.push_back(o);
            break;

        case 4:
            cout << "Enter quantity of Burger: ";
            cin >> quantity;
            total = 90 * quantity;
            grandtotal+=total;
           o.itemName="Burger";
            o.quantity=quantity;
            o.cost=total;
            orders.push_back(o);
            break;

        case 5:
            cout << "Enter quantity of pizza: ";
            cin >> quantity;
            total = 300 * quantity;
            grandtotal+=total;
            o.itemName="Pizza";
            o.quantity=quantity;
            o.cost=total;
            orders.push_back(o);
            break;
        default:
            cout << "Invalid option\n";
            continue;
     }
    cout<<"Add another item?(y or n)";
    cin>>more;
   }while(more=='y'|| more=='Y');
    saveReceiptToFile(orders,name,grandtotal);
    printReceipt(orders,name,grandtotal);
    return 0;
 }
}
