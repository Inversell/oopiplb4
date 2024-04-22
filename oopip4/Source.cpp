#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Transport {
protected:
    string brand;
    int mileage;

public:
    Transport() : brand(""), mileage(0) 
    {
    }

    Transport(const string& brand, int mileage) : brand(brand), mileage(mileage)
    {
    }

    Transport(const Transport& other) : brand(other.brand), mileage(other.mileage) 
    {
    }

    void setBrand(const string& brand) {
        this->brand = brand;
    }

    void setMileage(int mileage) {
        this->mileage = mileage;
    }

    string getBrand() const 
    {
        return brand;
    }

    int getMileage() const
    {
        return mileage;
    }

    virtual void printInfo() const
    {
        cout << "Brand: " << brand << ", Mileage: " << mileage << " miles" << endl;
    }

    void saveToFile() {
        ofstream file("vehicles.txt");
        if (file.is_open()) {
            file << "Brand: " << brand << ", Mileage: " << mileage << " miles" << endl;
            file.close();
        }
        else {
            cout << "Unable to open file for writing" << endl;
        }
    }
};

class Airplane : public Transport {
public:
    Airplane(const string& brand, int mileage) : Transport(brand, mileage)
    {

        this->brand = brand;

        this->mileage = mileage;
    }
    void printInfo() const override {
        cout << "Airplane - Brand: " << brand << ", Mileage: " << mileage << " miles" << endl;
    }
};

class Train : public Transport {
public:
    Train(const string& brand, int mileage) : Transport(brand, mileage)
    {

        this->brand = brand;

        this->mileage = mileage;
    }
    void printInfo() const override {
        cout << "Train - Brand: " << brand << ", Mileage: " << mileage << " miles" << endl;
    }
};

class Truck : public Transport {
    int maxLoad;

public:
    Truck(const string& brand, int mileage, int maxLoad) : Transport(brand, mileage), maxLoad(maxLoad) {}

    void setMaxLoad(int maxLoad) {
        this->maxLoad = maxLoad;
    }

    int getMaxLoad() const {
        return maxLoad;
    }

    void printInfo() const override {
       cout << "Truck - Brand: " << brand << ", Mileage: " << mileage << " miles, Max Load: " << maxLoad << " kg" << endl;
    }
};

int main() {
    Truck truck1("Volvo", 50000, 2000);
    Truck truck2("Scania", 50000, 3000);
    Airplane airplane1("Boeing", 100000);
    Train train1("Eurostar", 150000);
    Train train2("Eurostar1", 50000);
    vector<Transport*> vehicles;
    vehicles.push_back(&truck1);
    vehicles.push_back(&truck2);
    vehicles.push_back(&airplane1);
    vehicles.push_back(&train1);
    vehicles.push_back(&train2);
   
    for (const auto& vehicle : vehicles)
    {
        vehicle->printInfo();
    }

    for (const auto& vehicle : vehicles)
    {
        vehicle->saveToFile();
    }

    for (int i = 0; i < vehicles.size(); i++) {
       
        for (int j = i + 1; j < vehicles.size(); j++) {
            if (vehicles[i]->getMileage() == vehicles[j]->getMileage()) {
                cout << "Vehicles with the same mileage:\n";
                vehicles[i]->printInfo();
                vehicles[j]->printInfo();
            }
        }
    }

    return 0;
}