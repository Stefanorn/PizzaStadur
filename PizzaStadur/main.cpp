//
//  main.cpp
//  PizzaStadur
//
//  Created by Stefan Orn Hrafnsson on 28/11/2017.
//  Copyright © 2017 Stefan Orn Hrafnsson. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

static string PATH = "skra";

//class DataClass{
//private:
//    int i;
//    double d;
//    string str;
//    char c;
//
//public:
//    DataClass(){
//        i = 0;
//        d = 0;
//        str = "";
//        c = 0;
//    }
//    friend istream& operator >>(istream& in, DataClass& data){
//
//        cout << "pleace enter integer : ";
//        in >> data.i;
//        cout << "pleace enter number : ";
//        in >> data.d;
//        cout << "pleace enter string : ";
//        in >> data.str;
//        cout << "pleace enter char : ";
//        in >> data.c;
//
//
//        return  in;
//    }
//    friend ostream& operator >>(ostream&, DataClass& data){
//
//
//
//    }
//
//};

int main(int argc, const char * argv[]) {
    
//    DataClass data;
//
//    cin >> data;
//
//
//
//    ofstream stream;
//    stream.open(PATH);
//
//    fout << data;

    int* array = new int[10];
    for(int i = 0; i < 10 ;i++){
        array[i] = i+1;
        
    }
    for(int i = 0; i < 10 ;i++){
        cout << array[i];
        
    }
    cout << endl;
    array = new int[20];
    for(int i = 0; i < 20 ;i++){
        array[i] = i+1;
        
    }
    for(int i = 0; i < 20 ;i++){
        cout << array[i];
        
    }
    
    delete[] array;
    
//
//    fstream fin;
//
//    fin.open("skra");
//
//    fin.seeking(0, fin.end);
//    int records = fin.tellg();
//    fin.seeking(0, fin.beg);
//
//
//    for(int i = 0; i < records; i++){
//        fin.read((char*)(&data), sizeof(dataclass) );
//
//    }
//
    return 0;
}
