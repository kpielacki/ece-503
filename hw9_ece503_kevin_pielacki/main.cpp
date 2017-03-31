#include <iostream>
#include <string>
#include <vector>
#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"


void v_pointer(const Package *pack) {
    pack->print_info();
    std::cout << std::endl << std::endl;
}


int main() {
    double base_rate = 0.5;
    double flat_rate_2day = 2;
    double flat_rate_next_day = 5;
    std::vector<Package*> packages(3);

    // Print cost of package delivery types.
    std::cout << "Cost per ounce for a package:           $0.50/ounce" << std::endl;
    std::cout << "Additional cost for two day delivery:   $2.00/ounce" << std::endl;
    std::cout << "Additional cost for overnight delivery: $5.00/ounce" << std::endl << std::endl;

    // Establish one of each package types.
    Package package1("Tyng Lee", "123 Fake St.", "Springfield", "MI", 42321, "John Snow", "142 Maple Ave.", "Newark", "NJ", 23134, base_rate, 0.666);
    TwoDayPackage package2("Gabriel Johnson", "21 Corporate Ave.", "Piscataway", "NJ", 8892, "Tom Smith", "1 Elm Dr.", "Dallas", "TX", 8895, base_rate, 0.666, flat_rate_2day);
    OvernightPackage package3("Hank Williams", "214 Willow Ave.", "Edison", "NJ", 88332, "Adam Anderson", "343 Willow St.", "Rahway", "CO", 8895, base_rate, 0.666, flat_rate_2day);

    // Populate vector of Package pinter objects.
    packages[0] = &package1;
    packages[1] = &package2;
    packages[2] = &package3;

    // Print sender, receiver, weight, and cost information for each package.
    for (int i = 0; i < packages.size(); i++) {
        std::cout << "Package " << i + 1 << ":" << std::endl;
        packages[i]->print_info();
        std::cout << std::endl << std::endl;
    }

    return 0;
}
