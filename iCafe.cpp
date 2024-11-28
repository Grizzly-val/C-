#include <iostream>
#include <string>
#include <fstream>

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


const int maxacc = 3;
string AccountName[maxacc];
string AccountPass[maxacc];
double AccountBal[maxacc];
double UserBalance;
char name[16];
char password[8];
double balance = 0;

void play(int user){

    string selectPC;
    double howLong;
    double playPrice;
        cout << "Thank you for gaming @ Trixter's iCafe! \n==Offers== \n";
        do{
        cout << "[a]-|Regular| 50php for 1 Hour \n[b]-|VIP| 70php for 1 Hour \nWhere would you like to play?: ";
        cin >> selectPC;
        switch(selectPC.at(0)){
        case 'a':
            cout << "For how long will you be playing (minutes)? ";
            cin >> howLong;
            playPrice = (howLong / 60) * 50;
            if(AccountBal[user] - playPrice >= 0){
                cout << "Payment has been deducted from your Account Balance.\n";
                AccountBal[user] -= playPrice;
                cout << "Current Balance: " << AccountBal[user] << endl;
                cout << "Thank you for playing. Good luck Player! \n";
            }
            else{
                cout << "Payment failure.\nSending you back to your Account Menu...\n\n";
                }
            playPrice = 0;
            break;

            case 'b':
                cout << "For how long will you be playing sir(minutes)? ";
                cin >> howLong;
                playPrice = (howLong / 60) * 70;
            if(AccountBal[user] - playPrice >= 0){
                cout << "Payment has been deducted from your Account Balance.\n";
                AccountBal[user] -= playPrice;
                cout << "Current Balance: " << AccountBal[user] << endl;
                cout << "Thank you so much for playing. Good luck with your games, Player! \n";
            }
            else{
                cout << "\nPayment failure.\nSending you back to your Account Menu...\n\n";
            }
            playPrice = 0;
            break;
            default:
            break;
            }}while(selectPC.at(0) != 'a' && selectPC.at(0) != 'b');

}

void buy(int user, double total, string cart[]){
    if(cart[0] == "\0"){
        cout << "Your cart is empty. \nSending you back to Account Menu...\n";
        total = 0;
    };

    string confirmPurchase;
    cout << "The total of your order is " << total << ", do you want to confirm purchase? [y/n]: ";
    cin >> confirmPurchase;
    if(confirmPurchase.at(0) == 'y'){
        if(AccountBal[user] - total >= 0){
            AccountBal[user] -= total;
            cout << "Payment Received! Thank you for your purchase! \nCurrent Balance: " << AccountBal[user] << endl;
            for(int i = 0; i < 50; i++){
            cart[i] = "\0";
            }
            total = 0;
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
    cin >> itemSelect;
    switch(itemSelect.at(0)){
        case 'x':
            cout << "Emptying cart... Sending you back to Account Menu...\n";
            for(int i = 0; i < 50; i++){
                cart[i] = "\0";
                }
                total = 0;
                break;
        case '0':
            buy(user, total, cart);
            break;
        case '1':
        for(int i = 0; i < 50; i++){
            if(cart[i] == "\0"){
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

void InAccount(int user){
    string select;
    cout << "Hello there, " << AccountName[user] << "!" << endl;
    do{
    cout << "[a] Check balance  [b] Add balance\n[c] Play           [d] Buy\n[e] Logout" << endl;
    cin >> select;
        switch(select.at(0)){
            case 'a':
                cout << "=========================================\n";
                cout << "|Your Current Account Balance is " << AccountBal[user] << "php|" << endl;
                cout << "=========================================\n\n";
                break;
            case 'b':
                cout << "How much would you like to add? \nEnter Amount in php: " << endl; 
                cin >> UserBalance;
                AccountBal[user] += UserBalance;
                break;
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
                cout << "Please select only one of the following." << endl;
        }}while(select.at(0) != 'e');
}

void login(int i){
    do{
        cout << "Enter your password: ";
        cin >> password;
        if(password == AccountPass[i]){
            cout << endl;
            cout << "Login Successful\n\n";
            InAccount(i);

            } else{
                cout << endl;
                cout << "Incorrect Password\n\n";
            }
    }while(password != AccountPass[i]);
}

void CreateAcc(){

    cout << "Account Name: ";
    cin >> name;
    cout << "Create Password: ";
    cin >> password;
    for(int i = 0; i < maxacc; i++){
        if(name == AccountName[i]){
            cout << "Account name already exists.\n\n";
            break;
        }
        if(AccountName[i] == "\0"){
            AccountName[i] = name;
            AccountPass[i] = password;
            AccountBal[i] = balance;
            break;
        }
    }
}

void SearchAcc(string Sname){
    string nTemp;
    cout << "\n[Results Found]\n" << "_______________________\n";
    for(int i = 0; i <= maxacc; i++){
        if(Sname == AccountName[i]){
            cout << i + 1 << ". " << AccountName[i] << endl;
            nTemp = AccountName[i];
        }
        }
        cout << "_______________________\n\n";
        if(Sname == nTemp){
        cout << "Would you like to Login? (y/n): ";
        string YoN;
            do{
            cin >> YoN;
            for(int j = 0; j < maxacc; j++){
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
    cin >> password;
    if(password == AccountPass[acc]){
        do{
        cout << "\nAre you sure you want to delete " << AccountName[acc] << "?\nAccount Balance: " << AccountBal[acc] << "\ny/n? " << endl;
        cin >> auth;
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
}

int main(){
    string option;
    cout << "Welcome to Trixter's Gaming iCafe! \n" << "How may GrizzlyBOT help you? " << endl;
    do{
    cout << "[1] Search an Account" << endl;
    cout << "[2] Create an Account" << endl;
    cout << "[3] Delete an Account" << endl;
    cout << "[4] Display Accounts" << endl;
    cout << "[5] Cancel operations" << endl;
    cin >> option;
    switch(option.at(0)){
        case '1':
            cout << "Account Name: ";
            cin >> name;
            SearchAcc(name);
            break;
        case '2':
            CreateAcc();
            break;
        case '3':
            cout << "Account Name: ";
            cin >> name;
            for(int i = 0; i < maxacc; i++){
                if(name == AccountName[i]){
                    DeleteAcc(i);
                    break;
                }}
            break;
        case '4':
            cout << "|No.|    |Name|\n";
            for(int i = 0; i < maxacc; i++){
                if(AccountName[i] != "\0"){
                    cout << i + 1 << ".         " << AccountName[i] << endl;
                }
            }
            break;
        case '5':
            break;
        default:
            break;
    }}while(option.at(0) != '5');

    cout << "Bye!";

}

