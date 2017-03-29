#include <iostream>
#include <string>
#include <vector>
#include "Package.h"
#include "TwoDayPackage.h"


int main() {
    double base_rate = 0.5;
    double flat_rate_2day = 2;
    double flat_rate_next_day = 5;
    std::vector<Package*> packages;
    

    std::cout << "Cost per ounce for a package:           $0.50/ounce" << std::endl;
    std::cout << "Additional cost for two day delivery:   $2.00/ounce" << std::endl;
    std::cout << "Additional cost for overnight delivery: $5.00/ounce" << std::endl;
    
    Package package1("Michael Bay", "123 Fake St.", "Springfield", "MI", 42321, "John Snow", "142 Maple Ave.", "Newark", "NJ", 23134, base_rate, 12);
    TwoDayPackage package2("Mahmoud", "21 Constitutional Ave", "Piscataway", "NJ", 8892, "Kevin", "1 Ericsson Dr", "Piscataway", "NJ", 8895, base_rate, 0.666, flat_rate_2day);

    Package *p1 = &package1;
    TwoDayPackage *p2 = &package2;

    packages.push_back(p1);
    packages.push_back(p2);

    for (int i = 0; i < packages.size(); i++) {
        std::cout << "Package " << i + 1 << ":" << std::endl;
        std::cout << *packages[i] << std::endl;
    }

    return 0;
}
