#include "StaffUI.h"

StaffUI::StaffUI(){
    while(true){
        cout << "Press 1 to pay for order, " << endl;
        cout << "press 2 to deliver order " << endl;
        cout << "press 3 to quit" << endl;
        char input;
        cin >> input;

        if(input == '1'){
            system("CLS");
        }
        else if(input == '2'){

            system("CLS");
        }
        else if (input == '3'){

            return;
        }
        else {
            cout << "Invalid input " << endl;
            system("CLS");
        }

    }
}



