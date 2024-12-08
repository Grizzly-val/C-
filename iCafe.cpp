#include <iostream>
#include <string>
#include <limits>

using namespace std;

// iCafe //
/* A console system for an internet cafe where you can rent pc and buy foods and drinks using the same balance from the same account */
// Inspired by an iCafe I went to for a tournament //


/*
string itemName[];
double itemPrice[];
string addItemName[];
double addItemPrice[];
*/


const int maxacc = 100;
string AccountName[maxacc];
string AccountPass[maxacc];
double AccountBal[maxacc];
double UserBalance;
string name;
string password;
double balance = 0;

void play(int user){

    string selectPC;
    double howLong;
    double playPrice;
        cout << "Thank you for gaming @ Trixter's iCafe! \n==Offers== \n";
        do{
        cout << "[a]-|Regular| 50php for 1 Hour \n[b]-|VIP| 70php for 1 Hour \nWhere would you like to play?: ";
        getline(cin, selectPC);
        while(selectPC.empty()) {
            cout << "Input empty\n";
            cout << "Where would you like to play?: ";
            getline(cin, selectPC);
        }
        switch(selectPC.at(0)){
        case 'a':
            cout << "For how long will you be playing, " << AccountName[user] << " (minutes)? " << endl;
            cin >> howLong;
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nInvalid input.\n";
            }
            else{
                playPrice = (howLong / 60) * 50;    //calculates the total cost based on duration in minutes entered. 50php per hour
            };

            if(AccountBal[user] - playPrice >= 0 && playPrice > 0){
                cout << "Payment has been deducted from your Account Balance.\n";
                AccountBal[user] -= playPrice;
                cout << "Current Balance: " << AccountBal[user] << endl;
                cout << "Thank you for playing. Good luck Player! \n";
            }
            else{
                cout << "\nPayment failure.\nSending you back to your Account Menu...\nEnter any key\n";
                }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // This clears the leftover input
            playPrice = 0;
            break;

        case 'b':
            cout << "For how long will you be playing, " << AccountName[user] << " (minutes)? " << endl;
            cin >> howLong;
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nInvalid input.\n";
            }
            else{
                playPrice = (howLong / 60) * 70;    //calculates the total cost based on duration in minutes entered. 50php per hour
            };

            if(AccountBal[user] - playPrice >= 0 && playPrice > 0){
                cout << "Payment has been deducted from your Account Balance.\n";
                AccountBal[user] -= playPrice;
                cout << "Current Balance: " << AccountBal[user] << endl;
                cout << "Thank you for playing. Good luck Player! \n";
            }
            else{
                cout << "\nPayment failure.\nSending you back to your Account Menu...\nEnter any key\n";
                }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // This clears the leftover input
            playPrice = 0;
            break;

        default:
            break;

            }}while(selectPC.at(0) != 'a' && selectPC.at(0) != 'b');

}

void buy(int user, double total, string cart[]){
    string confirmPurchase;
    cout << "The total of your cart is " << total << ", do you want to confirm purchase? [y/n]: ";
    getline(cin, confirmPurchase);
    while(confirmPurchase.empty()) {
        cout << "Input empty\n";
        cout << "The total of your cart is " << total << ", do you want to confirm purchase? [y/n]: ";
        getline(cin, confirmPurchase);
    }
    if(confirmPurchase.at(0) == 'y'){
        if(AccountBal[user] - total >= 0){
            AccountBal[user] -= total;
            cout << "Payment Received! Thank you for your purchase! \nCurrent Balance: " << AccountBal[user] << endl;
            for(int i = 0; i < 50; i++){
            cart[i] = "\0"; //empties the cart
            }
            total = 0; //resets the total price
        }
        else{
            cout << "\n!!Payment failure!!\nSending you back to Account Menu...\n\n";
        }
    }
    else if(confirmPurchase.at(0) == 'n'){
        cout << "Purchase cancelled... Sending you back to Account Menu\n";
    };
}

void store(int user){

    string itemSelect;
    double total;
    string cart[50];
    cout << "It wouldn't be a gaming session without any of these Gamers Favorites" << endl;
    cout << "[1]Noodles: 25php \n[2]Coca-Cola: 20php \n[3]Sprite: 20php \n[4]Royal: 20php \n[5]Red Bull: 76.50php \n[6]Vcut: 17.50php \n";
    cout << "[7]Nova: 17.50php \n[8]Piattos: 17.25php\n";
    cout << "[x] Empty cart \n[0] Check-out \n";
    cout << "Add any of the following to your cart! \n";
    do{
    getline(cin, itemSelect);
    while(itemSelect.empty()) {
        cout << "Input empty\n";
        getline(cin, itemSelect);
    }
    switch(itemSelect.at(0)){
        case 'x':
            cout << "Emptying cart... Sending you back to Account Menu...\n";
            for(int i = 0; i < 50; i++){
                cart[i] = "\0";
                }
                total = 0;  //total always resets to zero each time the user exits the loop
                break;
        case '0':
            if(cart[0] == "\0"){ //if the first index of the array is empty, that means that the array is empty (cart is empty)
                cout << "\nYour cart is empty. \nSending you back to Account Menu...\n";
                total = 0;
                break;
                }
            else{
            buy(user, total, cart);
            break;
            }
        case '1':
        for(int i = 0; i < 50; i++){
            if(cart[i] == "\0"){        //item stored to the first empty indext found in the array.
                cart[i] = "Noodles";
            }}
            total += 25;
            cout << "-Noodles added to your cart-\n";
            break;
        case '2':
        for(int i = 0; i < 50; i++){
            if(cart[i] == "\0"){
                cart[i] = "Coca-Cola";
            }}
            total += 20;
            cout << "-Coca-Cola added to your cart-\n";
            break;
        case '3':
        for(int i = 0; i < 50; i++){
            if(cart[i] == "\0"){
                cart[i] = "Sprite";
            }}
            total += 20;
            cout << "-Sprite added to your cart-\n";
            break;
        case '4':
        for(int i = 0; i < 50; i++){
            if(cart[i] == "\0"){
                cart[i] = "Royal";
            }}
            total += 20;
            cout << "-Royal added to your cart-\n";
            break;
        case '5':
        for(int i = 0; i < 50; i++){
            if(cart[i] == "\0"){
                cart[i] = "Red Bull";
            }}
            total += 76.50;
            cout << "-Red Bull added to your cart-\n";
            break;
        case '6':
        for(int i = 0; i < 50; i++){
            if(cart[i] == "\0"){
                cart[i] = "Vcut";
            }}
            total += 17.50;
            cout << "-Vcut added to your cart-\n";
            break;
        case '7':
        for(int i = 0; i < 50; i++){
            if(cart[i] == "\0"){
                cart[i] = "Nova";
            }}
            total += 17.50;
            cout << "-Nova added to your cart-\n";
            break;
        case '8':
        for(int i = 0; i < 50; i++){
            if(cart[i] == "\0"){
                cart[i] = "Piattos";
            }}
            total += 17.25;
            cout << "-Piattos added to your cart-\n";
            break;
        default:
            cout << "Please choose only from the available options\n";
            break;
    }
}while(itemSelect.at(0) != 'x' && itemSelect.at(0) != '0');
}

void InAccount(int user) {
    double UserBalance;
    string select;
    cout << "Hello there, " << AccountName[user] << "!" << endl;
    do {
        cout << "[a] Check balance   [b] Add balance\n";
        cout << "[c] Play            [d] Buy\n";
        cout << "[e] Logout" << endl;
        getline(cin, select);
        while(select.empty()) {
            cout << "Input empty\n";
            cout << "[a] Check balance   [b] Add balance\n";
            cout << "[c] Play            [d] Buy\n";
            cout << "[e] Logout" << endl;
            getline(cin, select);
        }
        switch (select.at(0)) {
            case 'a':
                cout << "==============================================================\n";
                cout << "Your Current Account Balance is " << AccountBal[user] << " php\n";
                cout << "==============================================================\n\n";
                break;

            case 'b': {
                cout << "How much would you like to add? \nEnter Amount in php: ";
                cin >> UserBalance;
                if (cin.fail()) {
                    cin.clear();  // Clear error state
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // This clears the invalid input
                    cout << "Invalid input. Returning to menu.\nEnter any key";
                } else {
                    AccountBal[user] += UserBalance;
                    cout << "Successfully Added!\n";
                }

                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // This clears the leftover input
                break;
            }

            case 'c':
                play(user);
                break;

            case 'd':
                store(user);
                break;

            case 'e':
                cout << "Logging you out...\n\n";
                break;

            default:
                cout << "Please select only one of the following.\n";
        }
    } while (select.at(0) != 'e');  // Loop until 'e' is selected
}

void login(int i){
    do{
        cout << "Enter your password: ";
        getline(cin, password);
        while(password.empty()) {
            cout << "Input empty\n";
            cout << "Enter your password: ";
            getline(cin, password);
        }
        if(password == AccountPass[i]){
            cout << endl;
            cout << "Login Successful\n\n";
            InAccount(i);   //if password correct, call the InAccount function and pass i, which is the index for you account. ex. name[i], password[i], and balance[i]

            } else{
                cout << endl;
                cout << "Incorrect Password\n\n";
            }
    }while(password != AccountPass[i]);
}

void CreateAcc(){

    cout << "Account Name: ";
    getline(cin, name);
    while(name.empty()) {           //ask for input again if no input entered
        cout << "Input empty\n";
        cout << "Account Name: ";
        getline(cin, name);
    }
    cout << "Create Password: ";
    getline(cin, password);
    while(password.empty()) {
        cout << "Input empty\n";
        cout << "Create Password: ";
        getline(cin, password);
    }
    for(int i = 0; i < maxacc; i++){ //for-loop to go through all of the index in the name array variable
        if(name == AccountName[i]){     //if name matched with existing name in the array, go back to main menu.
            cout << "Account name already exists.\n\n";
            break;
        };
        if(AccountName[i] == "\0"){     //if an empty index is found, store name, password, and balance in their respective array variable then stop loop.
            AccountName[i] = name;      //Different arrays but stores name, password, and balance to the SAME index.
            AccountPass[i] = password;
            AccountBal[i] = balance;
            break;
        };
    }
}

void SearchAcc(string Sname){ //function receives the input of the user which is the name the user is searching for
    string nTemp;                   //nTemp is a temporary variable that will store the name that matched
    cout << "\n[Result]\n" << "_______________________\n";
    for(int i = 0; i < maxacc; i++){
        if(Sname == AccountName[i]){
            cout << "Found: " << AccountName[i] << endl;
            nTemp = AccountName[i];
        }
        }; //independent if statement
        cout << "_______________________\n\n";
        if(Sname == nTemp){         //if name searched is the same as the name that was stored temporarily, proceed to login.
        cout << "Would you like to Login? (y/n): "; //the purpose of nTemp is to check if there are results found. If none, go back to main menu.
        string YoN;
            do{
            getline(cin, YoN);
            while(YoN.empty()) {
                cout << "Input empty\n";
                cout << "Would you like to Login? (y/n): ";
                getline(cin, YoN);
            }
            for(int j = 0; j < maxacc; j++){    //another for loop to check which index the name that matched with Sname is in
                if(Sname == AccountName[j]){
                    if(YoN.at(0) == 'y'){
                        cout << "Accessing " << AccountName[j] << "..." << endl << endl;
                        login(j);
                        break;
                    }else if(YoN.at(0) == 'n'){
                        break;
                    }
                    else{
                        cout << "y/n";
                    }
                    }}
}while(YoN.at(0) != 'y' && YoN.at(0) != 'n');
}}

void DeleteAcc(int acc){

    string auth;

    cout << "Enter password: ";
    getline(cin, password);
    while(password.empty()) {
        cout << "Input empty\n";
        cout << "Enter password: ";
        getline(cin, password);
    }

    if(password == AccountPass[acc]){ //prompt for password and if password is correct, proceed to confirmation/authentication
        do{
        cout << "\nAre you sure you want to delete " << AccountName[acc] << "?\nAccount Balance: " << AccountBal[acc] << "\ny/n? " << endl;
        getline(cin, auth);
        while(auth.empty()) {
            cout << "Input empty\n";
            cout << "\nAre you sure you want to delete " << AccountName[acc] << "?\nAccount Balance: " << AccountBal[acc] << "\ny/n? " << endl;
            getline(cin, auth);
        }
        switch(auth.at(0)){
            case 'y':
                AccountName[acc] = "\0";
                AccountPass[acc] = "\0";
                AccountBal[acc] = 0;
                cout << "Account deleted.\n";
                break;
            case 'n':
                cout << "Account deletion cancelled.\n";
                break;
            default:
                break;
            }
        }while(auth.at(0) != 'y' && auth.at(0) != 'n');
        }
    else{
        cout << "\nInvalid Password!\n";
    }
}

int main(){
    int Dcounter = 1; //variable for the account number for display and search accounts
    string option;  //variable option is a string and the program only takes the 0 index of that string because char variable goes through each of the characters entered
    cout << "Welcome to Trixter's Gaming iCafe! \n" << "How may GrizzlyBOT help you? " << endl;
    do{
    cout << "[1] Search an Account" << endl;
    cout << "[2] Create an Account" << endl;
    cout << "[3] Delete an Account" << endl;
    cout << "[4] Display Accounts" << endl;
    cout << "[5] Cancel operations" << endl;
    getline(cin, option);
    while(option.empty()) {
        cout << "Input empty\n";
        cout << "[1] Search an Account" << endl;
        cout << "[2] Create an Account" << endl;
        cout << "[3] Delete an Account" << endl;
        cout << "[4] Display Accounts" << endl;
        cout << "[5] Cancel operations" << endl;
        getline(cin, option);
    }
    switch(option.at(0)){
        case '1':
            cout << "Account Name: ";
            getline(cin, name);
            while(name.empty()) {
                cout << "Input empty\n";
                cout << "Account Name: ";
                getline(cin, name);
            }
            SearchAcc(name); //prompt for name and call the function to search while passing the input of the user to the function
            break;
        case '2':
            CreateAcc();
            break;
        case '3':
            cout << "Account Name: ";
            getline(cin, name);
            while(name.empty()) {
                cout << "Input empty\n";
                cout << "Account Name: ";
                getline(cin, name);
            }
            for(int i = 0; i < maxacc; i++){
                if(name == AccountName[i]){
                    DeleteAcc(i);
                    break;
                }
                }
            break;
        case '4':
            cout << "|No.|    |Name|\n";
            for(int i = 0; i < maxacc; i++){
                if(AccountName[i] != "\0"){
                    cout << Dcounter << ".         " << AccountName[i] << endl;
                    Dcounter++;
                }
            }
            Dcounter = 1; //Dcounter resets
            break;
        case '5':
            break;
        default:
            cout << "\nNo valid input read.\n";
            break;
    }}while(option.at(0) != '5');   //"input.at(0)" or reading the string input's first character. I did this for all of inputs to ensure only one character is read.
    cout << "Bye!";
}