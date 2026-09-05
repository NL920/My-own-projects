//Car Management System

#include <iostream>
#include <string>

enum Pojazdy{
    SPORTS,
    FAMILY,
    ELECTRIC
};

class Car{
protected:
    std::string Name;
    std::string Color;
    double Price;
    std::string Type;

public:
    Car (std::string name,std::string color, double price,std::string type ){
        Name = name;
        Color = color;
        Price = price;
        Type = type;

    };

    std::string* getName(){
        return &Name;
    }

    std::string* getColor(){
        return &Color;
    }

    double* getPrice(){
        return &Price; 
    }

    std::string* getType(){
        return &Type;
    }

    void setName(std::string* NewName){
        Name = *NewName;
    }

    void setColor(std::string* NewColor){
        Color = *NewColor;
    }

    void setPrice(double* NewPrice){
        if (*NewPrice > 0){Price = *NewPrice;}

    }
    void printInfo(){
        std::cout<<"Name: "<<Name<<std::endl;
        std::cout<<"Color: "<<Color<<std::endl;
        std::cout<<"Price: "<<Price<<std::endl;
    }
    virtual void move(){
        std::cout<<Name<<"is moving"<<std::endl;
    }
};

class SportsCar: public Car{ //dlaczego tu public
    public:
    SportsCar(std::string name,std::string color, double price,std::string type ):Car( name,color, price, type ){}

    void driveFast(){
        std::cout<<"Driving very fast! "<<std::endl;
    }
    void move() override{
        std::cout<<Name<<"is moving very fast"<<std::endl;
    }
};

class ElectricCar: public Car{ 
    public:
    ElectricCar(std::string name,std::string color, double price,std::string type ):Car( name,color, price, type ){}
    
    void charge(){
        std::cout<<"Charging the car... "<<std::endl;
    }
    void move() override {
        std::cout<<Name<<"is moving silently"<<std::endl;
    }
};



int main(){
    ElectricCar electric("Volvo", "Green", 500000, "electric"); // dlaczego inaccessible - konstruktor klasy był private
    electric.printInfo();
    electric.charge();
    electric.move();
    SportsCar sporty("BMW", "White", 800000, "sport"); 
    sporty.printInfo();
    sporty.driveFast();
    sporty.move();

    std::string newCars[3] ={"Ferrari", "Toyota", "Tesla"};
    std::string newColors[3]={"Red", "Yellow", "Blue"};
    SportsCar ferrari (newCars[0], newColors[0], 90000, "sport");
    Car toyota (newCars[1], newColors[1], 60000, "basic");
    ElectricCar tesla (newCars[2], newColors[2], 100000, "electric");
    Car* Cars[3] ={&ferrari, &toyota, &tesla};
    for (int i=0;i<3;i++){
        Cars[i]->printInfo();
    }

    int counter = 0;
    while(counter<3){
        //std::cout<<"Car name: ";
        //std::cout<< *(Cars[counter])<<std::endl; - tutaj trzeba by przeciążyć (nadpisać) cout
        std::cout<<"Car number: "<<counter+1<<std::endl;
        counter++;
    };

};

/*Uruchamianie:
g++ main.cpp -o main.exe
./main.exe
*/