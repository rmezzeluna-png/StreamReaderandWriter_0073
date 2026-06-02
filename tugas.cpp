#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <string>

using namespace std;


class TokoElektronik {
private:
    array<string, 3> etalase;


public:
    // Constructor
    TokoElektronik() {
        etalase[0] = "Laptop ASUS";
        etalase[1] = "Smartphone Samsung";
        etalase[2] = "Printer Epson";
    }
