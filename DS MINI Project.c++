#include<bits/stdc++.h>


using namespace std;

struct PassengerDetails {
    char name[50];
    int bus_num;
    int num_of_seats;
};

void reservation();
void viewdetails();
void printticket(char name[], int, int, float);
void specificbus(int);
float charge(int, int);

int main() {
    system("cls");
    cout << "\t\t|           BUS TICKET RERSERVATION SYSTEM           |\n";
    cout << "\t\t|                            By K.V.N.AKHIL          |\n";
    cout << "\t\t|                            AM.EN.U4EAC19030        |\n";
    cout << "\t\t------------------------------------------------------\n";
    cout << "\t\t---------------press any key to continue--------------\n";
    cout << "\t\t------------------------------------------------------\n";
    cin.get();
    system("cls");
    int menu_choice, choice_return;
start:
    system("cls");
    cout << "\n=================================\n";
    cout << "    BUS RESERVATION SYSTEM\n";
    cout << "=================================\n";
    cout << "1>> Reserve A Ticket\n";
    cout << "------------------------\n";
    cout << "2>> View All Available Bus\n";
    cout << "------------------------\n";
    cout << "3>> Exit\n";
    cout << "------------------------\n";
    cout << "\n\n-->";
    cin >> menu_choice;
    switch (menu_choice) {
    case 1:
        reservation();
        break;
    case 2:
        viewdetails();
        cout << "\n\nPress any key to go to Main Menu..";
        cin.get();
        cin.ignore();
        break;
    case 3:
        return 0;
    default:
        cout << "\nInvalid choice";
    }
    goto start;
    return 0;
}

void viewdetails() {
    system("cls");
    cout << "\nBUS.No\tBUS Name\t\t\tDestinations\t\tfare\t\tTime\n";
    cout << "\n533101\tBus A\tKerala to karnataka\t\t       Rs.5000\t\t9am\n";
    cout << "533102\tBus B\tKarnataka to Maharastra\t\t   Rs.5000\t\t12pm\n";
    cout << "533103\tBus C\tKerala to Tamilnadu\t\t       Rs.4500\t\t8am\n";
    cout << "533104\tBus D\tTamilnadu to Andhrapradesh\t\tRs.4500\t\t11am\n";
    cout << "533105\tBus E\tAndhrapradesh to telangana\t\tRs.5000\t\t7am\n";
}

void reservation() {
    char confirm;
    int i = 0;
    float charges;
    PassengerDetails passdetails;
    FILE* fp;
    fp = fopen("seats_reserved.txt", "a");
    system("cls");

    cout << "\nEnter Your Name:> ";
    cin.ignore();
    cin.getline(passdetails.name, 50);

    cout << "\nEnter Number of seats:> ";
    cin >> passdetails.num_of_seats;
    cout << "\n\n>>Press Enter To View Available Bus<< ";
    cin.get();
    system("cls");
    viewdetails();
    cout << "\n\nEnter bus number:> ";
start1:
    cin >> passdetails.bus_num;
    if (passdetails.bus_num >= 533101 && passdetails.bus_num <= 533105) {
        charges = charge(passdetails.bus_num, passdetails.num_of_seats);
        printticket(passdetails.name, passdetails.num_of_seats, passdetails.bus_num, charges);
    }
    else {
        cout << "\nInvalid bus Number! Enter again--> ";
        goto start1;
    }

    cout << "\n\nConfirm Ticket (y/n):>";
start:
    cin >> confirm;
    if (confirm == 'y') {
        fprintf(fp, "%s\t\t%d\t\t%d\t\t%.2f\n", &passdetails.name, passdetails.num_of_seats, passdetails.bus_num, charges);
        cout << "==================\n";
        cout << " Reservation successful\n";
        cout << "==================\n";
        cout << "Press any key to go back to Main menu";
    }
    else {
        if (confirm == 'n') {
            cout << "\nReservation Not Done!\nPress any key to go back to  Main menu!";
        }
        else {
            cout << "\nInvalid choice entered! Enter again-----> ";
            goto start;
        }
    }
    fclose(fp);
    cin.get();
}

float charge(int bus_num, int num_of_seats) {
    if (bus_num == 533101 || bus_num == 533102 || bus_num == 533105) {
        return (5000.0 * num_of_seats);
    }
    else if (bus_num == 533103 || bus_num == 533104) {
        return (4500.0 * num_of_seats);
    }
}

void printticket(char name[], int num_of_seats, int bus_num, float charges) {
    system("cls");
    cout << "-------------------\n";
    cout << "\tTICKET\n";
    cout << "-------------------\n\n";
    cout << "Name:\t\t\t" << name;
    cout << "\nNumber Of Seats:\t" << num_of_seats;
    cout << "\nBus Number:\t\t" << bus_num;
    specificbus(bus_num);
    cout << "\nCharges:\t\t" << charges;
}

void specificbus(int bus_num) {

    if (bus_num == 533101) {
        cout << "\nBus:\t\t\tBUS A";
        cout << "\nDestination:\t\tKerala to karnataka";
        cout << "\nDeparture:\t\t9am ";
    }
    else if (bus_num == 533102) {
        cout << "\nBus:\t\t\tBUS B";
        cout << "\nDestination:\t\tKarnataka to Maharastra";
        cout << "\nDeparture:\t\t12pm";
    }
    else if (bus_num == 533103) {
        cout << "\nBus:\t\t\tBUS C";
        cout << "\nDestination:\t\tKerala to Tamilnadu";
        cout << "\nDeparture:\t\t8am";
    }
    else if (bus_num == 533104) {
        cout << "\nBus:\t\t\tBUS D";
        cout << "\nDestination:\t\tTamilnadu to Andhrapradesh";
        cout << "\nDeparture:\t\t11am ";
    }
    else if (bus_num == 533105) {
        cout << "\nBus:\t\t\tBUS C";
        cout << "\nDestination:\t\tAndhrapradesh to telangana";
        cout << "\nDeparture:\t\t7am";
    }
}
