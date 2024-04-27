#include<iostream>
//This Library is used as Sleep() function and system(cls) functions are used
#include<Windows.h>
#include<string>
//This library is used as setw() function is used
#include <iomanip>
#include<fstream>

using namespace std;

void Decor();
void Message();
//This is a seperate class to store all the details about addresss
class Address
{
    int houseno;
    int street;
    int postalcode;
    string sector;
    string place;
    string city;
    string nearby;


public:

    Address() :houseno(0), street(0), postalcode(0)
    {}

    Address(int houseno, int street, int postalcode, string sector, string place, string city, string nearby)
    {
        this->houseno = houseno;
        this->street = street;
        this->postalcode = postalcode;
        this->sector = sector;
        this->place = place;
        this->city = city;
        this->nearby = nearby;
    }

    //Setters
    void sethouseno(int houseno)
    {
        this->houseno = houseno;
    }
    void setstreet(int street)
    {
        this->street = street;
    }
    void setpostalcode(int postalcode)
    {
        this->postalcode = postalcode;
    }
    void setsector(string sector)
    {
        this->sector = sector;
    }
    void setplace(string place)
    {
        this->place = place;
    }
    void setcity(string city)
    {
        this->city = city;
    }
    void setnearby(string nearby)
    {
        this->nearby = nearby;
    }

    //GETTERS 
    int gethouseno()
    {
        return houseno;
    }
    int getstreet()
    {
        return street;
    }
    int getpostalcode()
    {
        return postalcode;
    }
    string getsector()
    {
        return sector;
    }
    string getplace()
    {
        return place;
    }
    string getcity()
    {
        return city;
    }
    string getnearby()
    {
        return nearby;
    }
    void modifyaddress()
    {
        int a, b, c;
        string d, e, f, g;
        cout << "Enter House Number :" << endl;
        cin >> a;
        sethouseno(a);
        cout << "Enter Street Number :" << endl;
        cin >> b;
        setstreet(b);
        cout << "Enter Postal Code :" << endl;
        cin >> c;
        setpostalcode(c);
        cout << "Enter Sector :" << endl;
        cin >> d;
        setsector(d);
        cout << "Enter Place :" << endl;
        cin >> e;
        setplace(e);
        cout << "Enter City :" << endl;
        cin >> f;
        setcity(f);
        cout << "Enter Nearby :" << endl;
        cin >> g;
        setnearby(g);
    }
};

class Admin
{
private:

    string Designation;
    string username;
    string password;

public:

    Admin() {}

    Admin(string d, string u, string p)
    {
        Designation = d;
        username = u;
        password = p;
    }

    Admin(string u, string p)
    {
        username = u;
        password = p;
    }

    void AdminPage(Admin object);
};

class Customer
{
private:

    string name;
    string email;
    string password;
    string phone;

    //Composition :
    // When a Customer object is constructed, an Address object is also created and associated with that customer object but when that object is 
    //destroyed ,the address one is also 
    Address address;

public:
    //These two functoins are friend as now they can access private members of the Customer class like name etc
    //Now can directly modify and access these members
    friend void SignUp();
    friend void SignIn();

    friend void Feedback(Customer& object);
    string arrname[100];
    float arrprice[100];
    static int forarr;
    static float totalbill;

    Customer() {}

    Customer(string n, string e, string p, Address add)
    {
        name = n;
        email = e;
        phone = p;
        address = add;
    }
    Customer(string e, string pass)
    {
        email = e;
        password = pass;
    }
    void CustomerPage(Customer& object);

    //Setters
    void setname(string name)
    {
        this->name = name;
    }
    void setemail(string email)
    {
        this->email = email;
    }
    void setphone(string phone)
    {
        this->phone = phone;
    }

    //Getters
    string getname()
    {
        return name;
    }
    string getemail()
    {
        return email;
    }
    string getphone()
    {
        return phone;
    }

    //To get data of Address class 
    int getaddhouseno()
    {
        return address.gethouseno();
    }
    int getaddstreet()
    {
        return address.getstreet();
    }
    int getaddpostalcode()
    {
        return address.getpostalcode();
    }
    string getaddsector()
    {
        return address.getsector();;
    }
    string getaddplace()
    {
        return address.getplace();
    }
    string getaddcity()
    {
        return address.getcity();
    }
    string getaddnearby()
    {
        return address.getnearby();
    }
    float gettotalbill()
    {
        return totalbill;
    }
};
int Customer::forarr = 0;
float Customer::totalbill = 0.0;


//FILING :
void Feedback(Customer& object)
{
    string feedback_text;
    int rating;

    cout << "Please provide your feedback and rating for our restaurant:" << endl;
    cout << "Enter your feedback: ";
    cin.ignore();
    getline(cin, feedback_text);

    cout << "Enter your rating (out of 5): ";
    cin >> rating;

    while (rating < 1 || rating > 5) {
        cout << "Invalid rating entered. Please enter a rating between 1 and 5: ";
        cin >> rating;
    }

    // Writing the feedback to a file as ofstream is used
    //Here, the open function is called to open the file "feedback.txt" in 
    //append mode. The ios::app flag is used to ensure that the content is 
    //appended to the existing content of the file, rather than overwriting it. 
    //If the file doesn't exist, it will be created.
    ofstream feedback_file;
    feedback_file.open("feedback.txt", ios::app);
    feedback_file << "Customer Name: " << object.name << endl;
    feedback_file << "Feedback: " << feedback_text << endl;
    feedback_file << "Rating: " << rating << "/5" << endl << endl;
    feedback_file.close();

    cout << endl << "Thank you for your feedback!" << endl;
    object.CustomerPage(object);
}
void DisplayFeedback(Admin &object)
{
    int x;
    //Using ifstream to read data frm the file 
    ifstream feedback_file;
    feedback_file.open("feedback.txt");

    if (!feedback_file) {
        cout << "Error opening file!" << endl;
        return;
    }
    //Getting information from the File.
    //while (getline(feedback_file, line)) - This loop reads the file 
    //line by line using getline. As long as there are more lines to read 
    //from the file, the loop continues.
    string line;
    while (getline(feedback_file, line)) {
        cout << line << endl;
    }
    feedback_file.close();

    cout << "Press 1 To Go Back Back To Menu " << endl;
    cin >> x;
    if (x == 1)
    {
        object.AdminPage(object);
    }
    else
        exit(0);
}

class Product
{
    string name;
    float price;
    int id;

public:

    Product() {}

    Product(string n, float p)
    {
        name = n;
        price = p;
    }
    //Setters 
    void setname(string n)
    {
        name = n;
    }
    void setprice(float p)
    {
        price = p;
    }
    //Getters 
    string getname()
    {
        return name;
    }
    float getprice()
    {
        return price;
    }

    //All The Menu Items Details :
    string chinesecategories[10] = { "Kung Pao Chicken", "Sweet and Sour Soup", "Egg Fried Rice", "Chow Mein","Veg Wontons" };
    double chineseprices[10] = { 10.99, 7.99, 5.99, 3.99, 6.99 };
    int chineseids[10] = { 1, 2, 3, 4, 5 };

    string italiancategories[10] = { "Spaghetti Bolognese", "Margherita pizza", "Lasagna", "Tiramisu","Bruschetta" };
    double italianprices[10] = { 9.99, 8.99, 6.99, 5.99, 10.99 };
    int italianids[10] = { 1, 2, 3, 4, 5 };

    string indianacategories[10] = { "Butter Chicken", "Naan", "Palak Paneer", "Tandoori Chicken","Chana Masala" };
    double indianprices[10] = { 9.99, 2.99, 6.99, 7.99, 4.99 };
    int indianids[10] = { 1, 2, 3, 4, 5 };

    string pakcat[10] = { "Biryani", "Karahi", "Haleem", "Seekh Kabab","Nihari" };
    double pakprices[10] = { 9.99, 9.99, 7.99, 6.99, 10.99 };
    int pakids[10] = { 1, 2, 3, 4, 5 };


    string fftcat[10] = { "Hamburger", "Cheeseburger", "Chicken sandwich", "Onion rings","Chicken nuggets" };
    double ffprices[10] = { 9.99, 9.99, 7.99, 6.99, 10.99 };
    int ffids[10] = { 1, 2, 3, 4, 5 };

    string turkcat[10] = { "Lahmacun", "Borek", "Manti", "Iskender Kebab","Baklava" };
    double turkprices[10] = { 9.99, 9.99, 7.99, 6.99, 10.99 };
    int turkids[10] = { 1, 2, 3, 4, 5 };

    string drinkcat[10] = { "Water", "Soda", "Iced Tea", "Juice","Lemonade" };
    double drinkprices[10] = { 2.99, 4.99, 7.99, 8.99, 9.99 };
    int drinkids[10] = { 1, 2, 3, 4, 5 };

    //All the number of items 
    int chineseno = 5;
    int italianno = 5;
    int indianno = 5;
    int pakno = 5;
    int ffno = 5;
    int turkno = 5;
    int dno = 5;
    int ab;

    //Objects are being sent in both admin and customers functions parameters which makes it easier to access 
    //the functions of the admin and customer class 
    //and also the object being sent is set to its values aswell so can access those in any function of both class
    //and so can modify it 

    //Admin Functions :
    void updateItem(Admin& object)
    {
        int category, item_id, newprice, a;
        system("cls");
        Decor();
        cout << "Choose From The Category Below :" << endl;
        cout << "1. Chinese " << endl;
        cout << "2. Italian " << endl;
        cout << "3. Indian  " << endl;
        cout << "4. Pakistani " << endl;
        cout << "5. Fast Food " << endl;
        cout << "6. Turkish " << endl;
        cout << "7. Drinks " << endl;
        cin >> category;

        switch (category)
        {
        case 1:
            system("cls");
            Decor();

            cout << "Chinese Menu:" << endl;
            for (int i = 0; i < 5; i++) {
                cout << chineseids[i] << ". " << chinesecategories[i] << " - Rs" << chineseprices[i] << endl;
            }
            cout << endl << endl;
            cout << "Enter the ID of the item you want to Update Price Of : " << endl;
            cin >> item_id;

            cout << "Name : " << chinesecategories[item_id - 1] << endl;
            cout << "The Current Price Is : " << chineseprices[item_id - 1] << endl;

            cout << "Enter The New Price You Want To Set :" << endl;
            cin >> newprice;
            chineseprices[item_id - 1] = newprice;

            cout << "New Chinese Menu:" << endl;
            for (int i = 0; i < chineseno; i++)
            {
                cout << chineseids[i] << ". " << chinesecategories[i] << " - Rs" << chineseprices[i] << endl;
            }
            break;

        case 2:
            system("cls");
            Decor();
            cout << "Italian Menu:" << endl;
            for (int i = 0; i < 5; i++) {
                cout << italianids[i] << ". " << italiancategories[i] << " - Rs" << italianprices[i] << endl;
            }
            cout << endl << endl;
            cout << "Enter the ID of the item you want to Update Price Of : " << endl;
            cin >> item_id;

            cout << "Name : " << italiancategories[item_id - 1] << endl;
            cout << "The Current Price Is : " << italianprices[item_id - 1] << endl;

            cout << "Enter The New Price You Want To Set :" << endl;
            cin >> newprice;
            italianprices[item_id - 1] = newprice;

            cout << "New Italian Menu:" << endl;
            for (int i = 0; i < italianno; i++)
            {
                cout << italianids[i] << ". " << italiancategories[i] << " - Rs" << italianprices[i] << endl;
            }
            break;

        case 3:
            system("cls");
            Decor();
            cout << "Indian Menu:" << endl;
            for (int i = 0; i < 5; i++) {
                cout << indianids[i] << ". " << indianacategories[i] << " - Rs" << indianprices[i] << endl;
            }
            cout << endl << endl;
            cout << "Enter the ID of the item you want to Update Price Of : " << endl;
            cin >> item_id;

            cout << "Name : " << indianacategories[item_id - 1] << endl;
            cout << "The Current Price Is : " << indianprices[item_id - 1] << endl;

            cout << "Enter The New Price You Want To Set :" << endl;
            cin >> newprice;
            indianprices[item_id - 1] = newprice;

            cout << "New Indian Menu:" << endl;
            for (int i = 0; i < indianno; i++)
            {
                cout << indianids[i] << ". " << indianacategories[i] << " - Rs" << indianprices[i] << endl;
            }
            break;
            system("cls");
            Decor();
            cout << "Indian Menu:" << endl;
            for (int i = 0; i < 5; i++) {
                cout << indianids[i] << ". " << indianacategories[i] << " - Rs" << indianprices[i] << endl;
            }
            break;

        case 4:
            system("cls");
            Decor();
            cout << "Pakistani Menu:" << endl;
            for (int i = 0; i < 5; i++) {
                cout << pakids[i] << ". " << pakcat[i] << " - Rs" << pakprices[i] << endl;
            }
            cout << endl << endl;
            cout << "Enter the ID of the item you want to Update Price Of : " << endl;
            cin >> item_id;

            cout << "Name : " << pakcat[item_id - 1] << endl;
            cout << "The Current Price Is : " << pakprices[item_id - 1] << endl;

            cout << "Enter The New Price You Want To Set :" << endl;
            cin >> newprice;
            pakprices[item_id - 1] = newprice;

            cout << "New Pakistani Menu:" << endl;
            for (int i = 0; i < pakno; i++)
            {
                cout << pakids[i] << ". " << pakcat[i] << " - Rs" << pakprices[i] << endl;
            }
            break;
            system("cls");
            Decor();
            cout << "Pakistani Menu:" << endl;
            for (int i = 0; i < 5; i++) {
                cout << pakids[i] << ". " << pakcat[i] << " - Rs" << pakprices[i] << endl;
            }
            break;

        case 5:
            system("cls");
            Decor();
            cout << "FastFood Menu:" << endl;
            for (int i = 0; i < 5; i++) {
                cout << ffids[i] << ". " << fftcat[i] << " - Rs" << ffprices[i] << endl;
            }
            cout << endl << endl;
            cout << "Enter the ID of the item you want to Update Price Of : " << endl;
            cin >> item_id;

            cout << "Name : " << fftcat[item_id - 1] << endl;
            cout << "The Current Price Is : " << ffprices[item_id - 1] << endl;

            cout << "Enter The New Price You Want To Set :" << endl;
            cin >> newprice;
            ffprices[item_id - 1] = newprice;

            cout << "New Fast Food Menu:" << endl;
            for (int i = 0; i < ffno; i++)
            {
                cout << ffids[i] << ". " << fftcat[i] << " - Rs" << ffprices[i] << endl;
            }
            break;
            system("cls");
            Decor();
            cout << "Fast Food Menu:" << endl;
            for (int i = 0; i < 5; i++) {
                cout << ffids[i] << ". " << fftcat[i] << " - Rs" << ffprices[i] << endl;
            }
            break;

        case 6:
            system("cls");
            Decor();
            cout << " Turkish Menu:" << endl;
            for (int i = 0; i < 5; i++) {
                cout << turkids[i] << ". " << turkcat[i] << " - Rs" << turkprices[i] << endl;
            }
            cout << endl << endl;
            cout << "Enter the ID of the item you want to Update Price Of : " << endl;
            cin >> item_id;

            cout << "Name : " << turkcat[item_id - 1] << endl;
            cout << "The Current Price Is : " << turkprices[item_id - 1] << endl;

            cout << "Enter The New Price You Want To Set :" << endl;
            cin >> newprice;
            turkprices[item_id - 1] = newprice;

            cout << "New Turkish Menu:" << endl;
            for (int i = 0; i < turkno; i++)
            {
                cout << turkids[i] << ". " << turkcat[i] << " - Rs" << turkprices[i] << endl;
            }
            break;
            system("cls");
            Decor();
            cout << "Turkish Menu:" << endl;
            for (int i = 0; i < 5; i++) {
                cout << turkids[i] << ". " << turkcat[i] << " - Rs" << turkprices[i] << endl;
            }
            break;

        case 7:
            system("cls");
            Decor();
            cout << " Drinks Menu:" << endl;
            for (int i = 0; i < 5; i++) {
                cout << drinkids[i] << ". " << drinkcat[i] << " - Rs" << drinkprices[i] << endl;
            }
            cout << endl << endl;
            cout << "Enter the ID of the item you want to Update Price Of : " << endl;
            cin >> item_id;

            cout << "Name : " << drinkcat[item_id - 1] << endl;
            cout << "The Current Price Is : " << drinkprices[item_id - 1] << endl;

            cout << "Enter The New Price You Want To Set :" << endl;
            cin >> newprice;
            drinkprices[item_id - 1] = newprice;

            cout << "New Drink Menu:" << endl;
            for (int i = 0; i < dno; i++)
            {
                cout << drinkids[i] << ". " << drinkcat[i] << " - Rs" << drinkprices[i] << endl;
            }
            break;
            system("cls");
            Decor();
            cout << "Drinks Menu:" << endl;
            for (int i = 0; i < 5; i++) {
                cout << drinkids[i] << ". " << drinkcat[i] << " - Rs" << drinkprices[i] << endl;
            }
            break;
        }
        cout << "Press 1 to Update MORE else 0 for MAIN MENU :" << endl;
        cin >> a;
        if (a == 1)
        {
            updateItem(object);
        }
        else
            object.AdminPage(object);
    }

    void removeItem(Admin& object)
    {
        int category;
        system("cls");
        Decor();
        cout << "Choose From The Category Below :" << endl;
        cout << "1. Chinese " << endl;
        cout << "2. Italian " << endl;
        cout << "3. Indian  " << endl;
        cout << "4. Pakistani " << endl;
        cout << "5. Fast Food " << endl;
        cout << "6. Turkish " << endl;
        cout << "7. Drinks " << endl;

        cin >> category;
        int a, x;
        int item_id;
        string item_name;

        switch (category)
        {
        case 1:
            system("cls");
            Decor();
            cout << "Chinese Menu:" << endl;
            for (int i = 0; i< chineseno; i++) {
                cout << chineseids[i] << ". " << chinesecategories[i] << " - Rs" << chineseprices[i] << endl;
            }
            cout << endl << endl;
            cout << "Enter the ID of the item you want to REMOVE: ";
            cin >> item_id;

            for (int i = 0; i < chineseno; i++)
            {
                if (chineseids[i] == item_id)
                {
                    for (int j = i; j < chineseno - 1; j++)
                    {
                        chinesecategories[j] = chinesecategories[j + 1];
                    }
                    chineseno--;
                }
            }
            cout << "New Chinese Menu:" << endl;
            for (int i = 0; i < chineseno; i++)
            {
                cout << chineseids[i] << ". " << chinesecategories[i] << " - Rs" << chineseprices[i] << endl;
            }
            break;

        case 2:
            system("cls");
            Decor();
            cout << "Italian Menu:" << endl;
            for (int i = 0; i < italianno; i++) {
                cout << italianids[i] << ". " << italiancategories[i] << " - Rs" << italianprices[i] << endl;
            }
            cout << endl << endl;
            cout << "Enter the ID of the item you want to REMOVE: ";
            cin >> item_id;

            for (int i = 0; i < italianno; i++)
            {
                if (italianids[i] == item_id)
                {
                    for (int j = i; j < italianno - 1; j++)
                    {
                        italiancategories[j] = italiancategories[j + 1];
                    }
                    italianno--;
                }
            }
            cout << "New Italian Menu:" << endl;
            for (int i = 0; i < italianno; i++)
            {
                cout << italianids[i] << ". " << italiancategories[i] << " - Rs" << italianprices[i] << endl;
            }
            break;

        case 3:
            system("cls");
            Decor();
            cout << "Indian Menu:" << endl;
            for (int i = 0; i < indianno; i++) {
                cout << indianids[i] << ". " << indianacategories[i] << " - Rs" << indianprices[i] << endl;
            }
            cout << endl << endl;
            cout << "Enter the ID of the item you want to REMOVE: ";
            cin >> item_id;

            for (int i = 0; i < indianno; i++)
            {
                if (indianids[i] == item_id)
                {
                    for (int j = i; j < indianno - 1; j++)
                    {
                        indianacategories[j] = indianacategories[j + 1];
                    }
                    indianno--;
                }
            }
            cout << "New Indian Menu:" << endl;
            for (int i = 0; i < indianno; i++)
            {
                cout << indianids[i] << ". " << indianacategories[i] << " - Rs" << indianprices[i] << endl;
            }
            break;

        case 4:
            system("cls");
            Decor();
            cout << "Pakistani Menu:" << endl;
            for (int i = 0; i < pakno; i++) {
                cout << pakids[i] << ". " << pakcat[i] << " - Rs" << pakprices[i] << endl;
            }
            cout << endl << endl;
            cout << "Enter the ID of the item you want to REMOVE: ";
            cin >> item_id;

            for (int i = 0; i < pakno; i++)
            {
                if (pakids[i] == item_id)
                {
                    for (int j = i; j < pakno - 1; j++)
                    {
                        pakcat[j] = pakcat[j + 1];
                    }
                    pakno--;
                }
            }
            cout << "New Pakistani Menu:" << endl;
            for (int i = 0; i < pakno; i++)
            {
                cout << pakids[i] << ". " << pakcat[i] << " - Rs" << pakprices[i] << endl;
            }
            break;

        case 5:
            system("cls");
            Decor();
            cout << "FastFood Menu:" << endl;
            for (int i = 0; i < ffno; i++) {
                cout << ffids[i] << ". " << fftcat[i] << " - Rs" << ffprices[i] << endl;
            }
            cout << endl << endl;
            cout << "Enter the ID of the item you want to REMOVE: ";
            cin >> item_id;

            for (int i = 0; i < ffno; i++)
            {
                if (ffids[i] == item_id)
                {
                    for (int j = i; j < ffno - 1; j++)
                    {
                        fftcat[j] = fftcat[j + 1];
                    }
                    ffno--;
                }
            }
            cout << "New FastFood Menu:" << endl;
            for (int i = 0; i < ffno; i++) {
                cout << ffids[i] << ". " << fftcat[i] << " - Rs" << ffprices[i] << endl;
            }
            break;


        case 6:
            system("cls");
            Decor();
            cout << " Turkish Menu:" << endl;
            for (int i = 0; i < turkno; i++) {
                cout << turkids[i] << ". " << turkcat[i] << " - Rs" << turkprices[i] << endl;
            }
            cout << endl << endl;
            cout << "Enter the ID of the item you want to order: ";
            cin >> item_id;

            for (int i = 0; i < turkno; i++)
            {
                if (turkids[i] == item_id)
                {
                    for (int j = i; j < turkno - 1; j++)
                    {
                        turkcat[j] = turkcat[j + 1];
                    }
                    turkno--;
                }
            }
            cout << "New Turkish Menu:" << endl;
            for (int i = 0; i < turkno; i++) {
                cout << turkids[i] << ". " << turkcat[i] << " - Rs" << turkprices[i] << endl;
            }
            break;

        case 7:
            system("cls");
            Decor();
            cout << " Drinks Menu:" << endl;
            for (int i = 0; i < dno; i++) {
                cout << drinkids[i] << ". " << drinkcat[i] << " - Rs" << drinkprices[i] << endl;
            }
            cout << endl << endl;
            cout << "Enter the ID of the item you want to order: ";
            cin >> item_id;
            for (int i = 0; i < dno; i++)
            {
                if (drinkids[i] == item_id)
                {
                    for (int j = i; j < dno - 1; j++)
                    {
                        drinkcat[j] = drinkcat[j + 1];
                    }
                    dno--;
                }
            }
            cout << "New Drinks Menu:" << endl;
            for (int i = 0; i < dno; i++) {
                cout << drinkids[i] << ". " << drinkcat[i] << " - Rs" << drinkprices[i] << endl;
            }
            break;

        default:
            cout << "Invalid choice." << endl;
            return;
        }
        cout << "Press 1 to REMOVE More products else 0" << endl;
        cin >> x;

        if (x == 1)
        {
            removeItem(object);
        }
        else
            object.AdminPage(object);
    }

    void addProduct(Admin& object)
    {
        system("cls");
        Decor();
        cout << "Enter the name of the new product: ";
        string newName;
        cin >> newName;
        cout << "Enter the price of the new product: ";
        float newPrice;
        cin >> newPrice;

        int category;
        cout << "Choose From The Category Below :" << endl;
        cout << "1. Chinese " << endl;
        cout << "2. Italian " << endl;
        cout << "3. Indian  " << endl;
        cout << "4. Pakistani " << endl;
        cout << "5. Fast Food " << endl;
        cout << "6. Turkish " << endl;
        cout << "7. Drinks " << endl;
        cin >> category;

        switch (category)
        {
        case 1:
            chinesecategories[chineseno] = newName;
            chineseprices[chineseno] = newPrice;
            ab = chineseno;
            chineseids[ab] = ++chineseno;

            cout << "New Chinese Menu:" << endl;
            for (int i = 0; i < chineseno; i++)
            {
                cout << chineseids[i] << ". " << chinesecategories[i] << " - Rs" << chineseprices[i] << endl;
            }
            break;

        case 2:
        {
            italiancategories[italianno] = newName;
            italianprices[italianno] = newPrice;
            ab = italianno;
            italianids[ab] = ++italianno;
            cout << "New Italian Menu:" << endl;
            for (int i = 0; i < italianno; i++)
            {
                cout << italianids[i] << ". " << italiancategories[i] << " - Rs" << italianprices[i] << endl;
            }
        }
        break;

        case 3:
        {
            indianacategories[indianno] = newName;
            indianprices[indianno] = newPrice;
            ab = indianno;
            indianids[ab] = ++indianno;
            cout << "New Indian Menu:" << endl;
            for (int i = 0; i < indianno; i++)
            {
                cout << indianids[i] << ". " << indianacategories[i] << " - Rs" << indianprices[i] << endl;
            }
        }
        break;

        case 4:
        {
            pakcat[pakno] = newName;
            pakprices[pakno] = newPrice;
            ab = pakno;
            pakids[ab] = ++pakno;
            cout << "New Pakistani Menu:" << endl;
            for (int i = 0; i < pakno; i++)
            {
                cout << pakids[i] << ". " << pakcat[i] << " - Rs" << pakprices[i] << endl;
            }
        }
        break;

        case 5:
        {
            fftcat[ffno] = newName;
            ffprices[ffno] = newPrice;
            ab = ffno;
            ffids[ab] = ++ffno;
            cout << "New FastFood Menu:" << endl;
            for (int i = 0; i < ffno; i++) {
                cout << ffids[i] << ". " << fftcat[i] << " - Rs" << ffprices[i] << endl;
            }
        }
        break;

        case 6:
        {
            turkcat[turkno] = newName;
            turkprices[turkno] = newPrice;
            ab = turkno;
            turkids[ab] = ++turkno;
            cout << "New Turkish Menu:" << endl;
            for (int i = 0; i < turkno; i++) {
                cout << turkids[i] << ". " << turkcat[i] << " - Rs" << turkprices[i] << endl;
            }
        }
        break;

        case 7:
        {
            drinkcat[dno] = newName;
            drinkprices[dno] = newPrice;
            ab = dno;
            drinkids[ab] = ++dno;
            cout << "New Drinks Menu:" << endl;
            for (int i = 0; i < dno; i++) {
                cout << drinkids[i] << ". " << drinkcat[i] << " - Rs" << drinkprices[i] << endl;
            }
        }
        break;

        default:
            cout << "Invalid choice." << endl;
            return;
        }
        int x;
        cout << "Press 1 to add More products else 0" << endl;
        cin >> x;

        if (x == 1)
        {
            addProduct(object);
        }
        else
            object.AdminPage(object);
    }

    //Customers Functions:
    void decider(Customer object)
    {
        int x;
        system("cls");
        Decor();
        cout << "WELCOME TO DECIDER !!" << endl << endl;

        srand(time(NULL)); // seed the random number generator with the current time

        // Chinese category
        int chi = rand() % 5; // generates a random number between 0 and 4
        cout << chineseids[chi] << ". " << chinesecategories[chi] << " - Rs" << chineseprices[chi] << endl;

        // Italian category
        int ita = rand() % 5;
        cout << italianids[ita] << ". " << italiancategories[ita] << " - Rs" << italianprices[ita] << endl;

        // Indian category
        int i = rand() % 5;
        cout << indianids[i] << ". " << indianacategories[i] << " - Rs" << indianprices[i] << endl;

        // Pakistani category
        int pak = rand() % 5;
        cout << pakids[pak] << ". " << pakcat[pak] << " - Rs" << pakprices[pak] << endl;


        // Fast food category
        int ff = rand() % 5;
        cout << ffids[ff] << ". " << fftcat[ff] << " - Rs" << ffprices[ff] << endl;

        // Turkish category
        int turk = rand() % 5;
        cout << turkids[turk] << ". " << turkcat[turk] << " - Rs" << turkprices[turk] << endl;

        // Drink category
        int d = rand() % 5;
        cout << drinkids[d] << ". " << drinkcat[d] << " - Rs" << drinkprices[d] << endl;

        cout << "Press 1 To Go Back Back To Menu " << endl;
        cin >> x;
        if (x == 1)
        {
            object.CustomerPage(object);
        }
        else
            exit(0);
    }

	void ViewBill(Customer& object)
    {
        int x;
        system("cls");
        Decor();
        cout << "Welcome " << object.getname() << endl << endl;
        cout << "YOUR TOTAL BILL IS :" << object.gettotalbill() << endl << endl << endl;
        cout << "Press 1 To Go Back Back To Menu " << endl;
        cin >> x;
        if (x == 1)
        {
            object.CustomerPage(object);
        }
        else
            exit(0);
    }
    void ViewCart(Customer& object) {
        int x;
        string a;
        system("cls");
        Decor();
        cout << "Welcome " << object.getname() << endl << endl;
        cout << "Items in Your Cart :" << endl << endl;

        if (object.forarr == 0) {
            cout << "Sorry! You have No Items in Your Cart." << endl;
            cout << "Can't Decide What To Eat? You can Try our New Feature ** DECIDER **" << endl;
            cout << "Yes/No" << endl;
            cin >> a;
            if (a == "Yes" || a == "yes") {
                // Assuming the decider function is defined somewhere
                // decider(object);
            } else {
                object.CustomerPage(object);
            }
        } else {
            cout << "ID" << setw(25) << "NAME" << setw(30) << "PRICE" << endl;
            for (int i = 0; i < object.forarr; i++) {
                cout << i + 1;
                cout << setw(30) << object.arrname[i];
                cout << setw(30) << object.arrprice[i] << endl;
            }
            cout << endl << endl;
        }
        
        cout << "Press 2 To Go Back To Menu OR Press 1 To Remove Item From Cart :" << endl;
        cin >> x;

        if (x == 1) {
            int b;
            cout << "Enter ID of Item You Want To Remove :" << endl;
            cin >> b;
            for (int i = 0; i < object.forarr; i++) {
                if (b == i + 1) {
                    for (int j = i; j < object.forarr - 1; j++) {
                        object.arrname[j] = object.arrname[j + 1];
                        object.arrprice[j] = object.arrprice[j + 1];
                    }
                    object.forarr--;
                }
            }
            object.CustomerPage(object);
        }

        if (x == 2) {
            ofstream billFile("bill.txt", ios::app); // Open the file in append mode
            if (!billFile.is_open()) {
                cout << "Error opening file!" << endl;
            }

            // Writing the items in the cart to the file
            for (int i = 0; i < object.forarr; i++) {
                billFile << object.arrname[i] << " - Rs" << object.arrprice[i] << endl;
            }

            billFile.close();

            object.CustomerPage(object);
        }
    }
    void choose(Customer& object)
    {
        int x, a;
        int category;

        //Using goto :
    cat:
        system("cls");
        Decor();
        cout << "Choose From The Category Below :" << endl;
        cout << "1. Chinese " << endl;
        cout << "2. Italian " << endl;
        cout << "3. Indian  " << endl;
        cout << "4. Pakistani " << endl;
        cout << "5. Fast Food " << endl;
        cout << "6. Turkish " << endl;
        cout << "7. Drinks " << endl;

        cin >> category;

        int item_id;
        string item_name;

        switch (category)
        {
        case 1:
            system("cls");
            Decor();
            cout << "Chinese Menu:" << endl;
            for (int i = 0; i < 5; i++) {
                cout << chineseids[i] << ". " << chinesecategories[i] << " - Rs" << chineseprices[i] << endl;
            }
            cout << endl << endl;
            cout << "Enter the ID of the item you want to order: ";
            cin >> item_id;

            object.arrname[object.forarr] = chinesecategories[item_id - 1];
            object.arrprice[object.forarr] = chineseprices[item_id - 1];
            object.totalbill += chineseprices[item_id - 1];

            //Increamenting it as static member as we above just saved in 0th place of array name and price both 
            //so now next order will be saved in the 1st place of array 
            object.forarr++;
            cout << endl;
            cout << "Press 1 to order MORE else 0 for MAIN MENU :" << endl;
            cin >> a;
            if (a == 1)
            {
                goto cat;
            }
            else
                object.CustomerPage(object);
            break;

        case 2:
            system("cls");
            Decor();
            cout << "Italian Menu:" << endl;
            for (int i = 0; i < 5; i++) {
                cout << italianids[i] << ". " << italiancategories[i] << " - Rs" << italianprices[i] << endl;
            }
            cout << endl << endl;
            cout << "Enter the ID of the item you want to order: ";
            cin >> item_id;
            object.arrname[object.forarr] = italiancategories[item_id - 1];
            object.arrprice[object.forarr] = italianprices[item_id - 1];
            object.totalbill += italianprices[item_id - 1];
            object.forarr++;
            cout << endl;
            cout << "Press 1 to order MORE else 0 for MAIN MENU :" << endl;
            cin >> a;
            if (a == 1)
            {
                goto cat;
            }
            else
                object.CustomerPage(object);
            break;

        case 3:
            system("cls");
            Decor();
            cout << "Indian Menu:" << endl;
            for (int i = 0; i < 5; i++) {
                cout << indianids[i] << ". " << indianacategories[i] << " - Rs" << indianprices[i] << endl;
            }
            cout << endl << endl;
            cout << "Enter the ID of the item you want to order: ";
            cin >> item_id;
            object.arrname[object.forarr] = indianacategories[item_id - 1];
            object.arrprice[object.forarr] = indianprices[item_id - 1];
            object.totalbill += indianprices[item_id - 1];
            object.forarr++;
            cout << endl;
            cout << "Press 1 to order MORE else 0 for MAIN MENU :" << endl;
            cin >> a;
            if (a == 1)
            {
                goto cat;
            }
            else
                object.CustomerPage(object);
            break;

        case 4:
            system("cls");
            Decor();
            cout << "Pakistani Menu:" << endl;
            for (int i = 0; i < 5; i++) {
                cout << pakids[i] << ". " << pakcat[i] << " - Rs" << pakprices[i] << endl;
            }
            cout << endl << endl;
            cout << "Enter the ID of the item you want to order: ";
            cin >> item_id;
            object.arrname[object.forarr] = pakcat[item_id - 1];
            object.arrprice[object.forarr] = pakprices[item_id - 1];
            object.totalbill += pakprices[item_id - 1];
            object.forarr++;
            cout << endl;
            cout << "Press 1 to order MORE else 0 for MAIN MENU :" << endl;
            cin >> a;
            if (a == 1)
            {
                goto cat;
            }
            else
                object.CustomerPage(object);
            break;

        case 5:
            system("cls");
            Decor();
            cout << "FastFood Menu:" << endl;
            for (int i = 0; i < 5; i++) {
                cout << ffids[i] << ". " << fftcat[i] << " - Rs" << ffprices[i] << endl;
            }
            cout << endl << endl;
            cout << "Enter the ID of the item you want to order: ";
            cin >> item_id;
            object.arrname[object.forarr] = fftcat[item_id - 1];
            object.arrprice[object.forarr] = ffprices[item_id - 1];
            object.totalbill += ffprices[item_id - 1];
            object.forarr++;
            cout << endl;
            cout << "Press 1 to order MORE else 0 for MAIN MENU :" << endl;
            cin >> a;
            if (a == 1)
            {
                goto cat;
            }
            else
                object.CustomerPage(object);
            break;


        case 6:
            system("cls");
            Decor();
            cout << " Turkish Menu:" << endl;
            for (int i = 0; i < 5; i++) {
                cout << turkids[i] << ". " << turkcat[i] << " - Rs" << turkprices[i] << endl;
            }
            cout << endl << endl;
            cout << "Enter the ID of the item you want to order: ";
            cin >> item_id;
            object.arrname[object.forarr] = turkcat[item_id - 1];
            object.arrprice[object.forarr] = turkprices[item_id - 1];
            object.totalbill += turkprices[item_id - 1];
            object.forarr++;
            cout << endl;
            cout << "Press 1 to order MORE else 0 for MAIN MENU :" << endl;
            cin >> a;
            if (a == 1)
            {
                goto cat;
            }
            else
                object.CustomerPage(object);
            break;

        case 7:
            system("cls");
            Decor();
            cout << " Drinks Menu:" << endl;
            for (int i = 0; i < 5; i++) {
                cout << drinkids[i] << ". " << drinkcat[i] << " - Rs" << drinkprices[i] << endl;
            }
            cout << endl << endl;
            cout << "Enter the ID of the item you want to order: ";
            cin >> item_id;
            object.arrname[object.forarr] = drinkcat[item_id - 1];
            object.arrprice[object.forarr] = drinkprices[item_id - 1];
            object.totalbill += drinkprices[item_id - 1];
            object.forarr++;
            cout << endl;
            cout << "Press 1 to order MORE else 0 for MAIN MENU :" << endl;
            cin >> a;
            if (a == 1)
            {
                goto cat;
            }
            else
                object.CustomerPage(object);
            break;

        default:
            cout << "Invalid choice." << endl;
            return;
        }
    }
};

//Customer Functions :
void ViewProfile(Customer& object)
{
    //Here we can view all of the deatils of the Customer as we have sent the object of customer as the parameter 
    //so everything can be accessed.
    int x;
    system("cls");
    Decor();
    cout << "Lets View Your PROFILE !" << endl << endl;
    cout << "NAME :" << object.getname() << endl << endl;
    cout << "EMAIL :" << object.getemail() << endl << endl;
    cout << "PHONE NUMBER :" << object.getphone() << endl << endl;
    cout << "ADDRESS DETAILS :" << endl << endl;
    cout << "HOUSE NUMBER :" << object.getaddhouseno() << endl << endl;
    cout << "STREET :" << object.getaddstreet() << endl << endl;
    cout << "POSTAL CODE :" << object.getaddpostalcode() << endl << endl;
    cout << "SECTOR :" << object.getaddsector() << endl << endl;
    cout << "PLACE :" << object.getaddplace() << endl << endl;
    cout << "CITY :" << object.getaddcity() << endl << endl;
    cout << "NEARBY :" << object.getaddnearby() << endl << endl;

    cout << "Press 1 To Go Back Back To Menu " << endl;
    cin >> x;
    if (x == 1)
    {
        object.CustomerPage(object);
    }
    else
        exit(0);
}

void Admin::AdminPage(Admin object)
{
    //Creating Product class object here but this is not COMPOSITION
    //Creating to access its functions 
    Product p;
    system("cls");
    Decor();
    int x;
    cout << "Choose Option : " << endl << endl;
    cout << "1.Add Item " << endl;
    cout << "2.Remove Item " << endl;
    cout << "3.Update Item " << endl;
    cout << "4.Display Feedback " << endl;
    cout << "5.Exit" << endl;
    cin >> x;

    switch (x)
    {
    case 1:
        p.addProduct(object);
        break;

    case 2:
        p.removeItem(object);
        break;

    case 3:
        p.updateItem(object);
        break;

    case 4:
        DisplayFeedback(object);
        break;

    case 5:
        exit(1);
        break;

    default:
        cout << "Invalid Option !" << endl;
        AdminPage(object);
        break;
    }
}

void Customer::CustomerPage(Customer& object)
{
    Product p;
    int x;
    system("cls");
    Decor();
    cout << "Choose Option : " << endl << endl;
    cout << "1.View Menu " << endl;
    cout << "2.View Bill  " << endl;
    cout << "3.View Cart /Remove Item " << endl;
    cout << "4.View Profile " << endl;
    cout << "5.Can't Choose What To Eat ---> DECIDER" << endl;
    cout << "6.Feedback" << endl;
    cout << "7.Exit" << endl;

    cin >> x;

    switch (x)
    {
        while (1 == 1)
        {
    case 1:
        p.choose(object);
        break;

    case 2:
    	p.ViewBill(object);
        break;

    case 3:
        p.ViewCart(object);
        break;

    case 4:
        ViewProfile(object);
        break;

    case 5:
        p.decider(object);
        break;

    case 6:
        Feedback(object);
        break;

    case 7:
    	Message();
        exit(1);

    default:
        cout << "Invalid Option !" << endl;
        object.CustomerPage(object);
        break;
        }
    }
}
void SignIn()
{
    system("cls");
    Decor();
    int x;
    string username, password;
    string correct_username = "user";
    string correct_password = "pass";
    cout << endl << endl;
    cout << "1.ADMIN" << endl << "2.CUSTOMER" << endl;
    cin >> x;

    if (x == 1)
    {
        cout << "Enter your username: ";
        cin >> username;

        cout << "Enter your password: ";
        cin >> password;

        if (username == correct_username && password == correct_password)
        {
            cout << "Login successful!" << endl;
            Admin object(username, password);
            object.AdminPage(object);
        }
        else
        {
            cout << "Invalid username or password." << endl;
        }

    }
    if (x == 2)
    {
        string y = "email";
        int a = 68;
        int b = 3;
        int c = 56;
        string d = "H";
        string e = "Malir";
        string f = "Karachi";
        string g = "Tuc Shop";

        system("cls");
        cout << "Enter your username/Email: ";
        cin >> username;

        cout << "Enter your password: ";
        cin >> password;

        if (username == correct_username && password == correct_password)
        {
            cout << "Login successful!" << endl;
            Customer object(username, y, password, Address(a, b, c, d, e, f, g));
            object.CustomerPage(object);
        }
        else
        {
            cout << "Invalid username or password." << endl;
        }
    }
}
void SignUp()
{
    system("cls");
    Decor();
    int x;
    cout << endl << endl;
    cout << "1.ADMIN" << endl << "2.CUSTOMER" << endl;
    cin >> x;

    if (x == 1)
    {
        string a, b, c;
        cout << "ENTER THE DETAILS :" << endl << endl;
        cout << "ENTER USERNAME :" << endl;
        cin >> a;
        cout << "ENTER PASSWORD :" << endl;
        cin >> b;
        cout << "ENTER DESIGNATION :" << endl;
        cin >> c;

        //Creating admin object and initializing its values 
        Admin object(a, b, c);
        system("cls");
        cout << "                            *********************   NEW ADMIN RECORD SAVED   **********************" << endl;
        Sleep(1500);
        system("cls");
        //Callinng using the object created 
        object.AdminPage(object);
    }
    if (x == 2)
    {
        string x, y, z;
        int a, b, c;
        string d, e, f, g;
        cout << "ENTER THE DETAILS :" << endl << endl;
        cout << "ENTER NAME :" << endl;
        cin >> x;
        cout << "ENTER EMAIL :" << endl;
        cin >> y;
        cout << "ENTER PASSWORD :" << endl;
        cin >> z;
        cout << endl;
        cout << "ENTER ADDRESS DETAILS  :" << endl;
        cout << endl;
        cout << "Enter House Number :" << endl;
        cin >> a;
        cout << "Enter Street Number :" << endl;
        cin >> b;
        cout << "Enter Postal Code :" << endl;
        cin >> c;
        cout << "Enter Sector :" << endl;
        cin >> d;
        cout << "Enter Place :" << endl;
        cin >> e;
        cout << "Enter City :" << endl;
        cin >> f;
        cout << "Enter Nearby :" << endl;
        cin >> g;

        //Creating customer object and address object also constrcted 
        //Compositon as address object is composed within customer object
        //Address object cannot exist independlty 
        Customer object(x, y, z, Address(a, b, c, d, e, f, g));

        system("cls");
        cout << "                            *********************   NEW CUSTOMER RECORD SAVED   **********************" << endl;
        Sleep(1500);
        system("cls");
        object.CustomerPage(object);
    }
}

void Intro()
{
    int x;
    cout << endl;
    cout << "                       =========================================================================" << endl;
    cout << "                       -------------------------------------------------------------------------" << endl;
    cout << "                       ****************          THE ONLINE CUISINE              ***************" << endl;
    cout << "                       -------------------------------------------------------------------------" << endl;
    cout << "                       *************************************************************************" << endl;
    cout << "                       -------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "                       =========================================================================" << endl;
    Sleep(1500);
    system("cls");
    Decor();

    cout << "CHOOSE FROM THE OPTION BELOW :" << endl << endl;
    cout << "1.SIGNUP" << endl << "2.SIGNIN" << endl << endl << endl;
    cin >> x;
    if (x == 1)
    {
        SignUp();
    }
    if (x == 2)
    {
        SignIn();
    }
}

void Decor()
{
    cout << endl;
    cout << "              -------------------------------------------------------------------------" << endl;
    cout << "              ****************          THE ONLINE CUISINE              ***************" << endl;
    cout << "              -------------------------------------------------------------------------" << endl;
    cout << "              *************************************************************************" << endl;
    cout << "              -------------------------------------------------------------------------" << endl;
    cout << endl << endl << endl << endl;
}

void Message()
{
	cout << "\nThank You for coming. Have a good day." << endl << endl;
}

int main()
{
    Intro();
}