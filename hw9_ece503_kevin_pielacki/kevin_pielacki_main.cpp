#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "kevin_pielacki_Package.h"
#include "kevin_pielacki_TwoDayPackage.h"
#include "kevin_pielacki_OvernightPackage.h"


int main() {
    std::vector<Package*> packages;
    double base_rate = 0.5;
    double flat_rate_2day = 2;
    double flat_rate_next_day = 5;
    double total_cost = 0;
    int test_option = -1;

    // Test predefined package list or manual input.
    while (true) {
        std::cout << "Since entering package information is long I have a predefined option:" << std::endl;
        std::cout << "0: Use predefined package list" << std::endl;
        std::cout << "1: Enter package information manually" << std::endl;
        std::cin >> test_option;

        if (test_option == 0 or test_option == 1) {
            break;
        } else {
            std::cout << "Invalid selection" << std::endl;
        }
    }

    switch (test_option) {
        case 0: {
            // Print cost of package delivery types.
            std::cout << "Cost per ounce for a package:           $0.50/ounce" << std::endl;
            std::cout << "Additional cost for two day delivery:   $2.00/ounce" << std::endl;
            std::cout << "Additional cost for overnight delivery: $5.00/ounce" << std::endl << std::endl;

            // Establish one of each package types.
            Package package1("Tyng Lee", "12 Oak St.", "Springfield", "MI", 120, "John Snow", "142 Maple Ave.", "Newark", "NJ", 23134, base_rate, 10);
            TwoDayPackage package2("Gabriel Johnson", "21 Corporate Ave.", "Piscataway", "NJ", 24503, "Tom Smith", "1 Elm Dr.", "Dallas", "TX", 8895, base_rate, 5, flat_rate_2day);
            OvernightPackage package3("Hank Williams", "214 Willow Ave.", "Edison", "NJ", 88329, "Adam Anderson", "343 Willow St.", "Rahway", "CO", 835, base_rate, 2, flat_rate_next_day);

            // Populate vector of Package pinter objects.
            packages.push_back(&package1);
            packages.push_back(&package2);
            packages.push_back(&package3);

            // Print sender, receiver, weight, and cost information for each package.
            for (int i = 0; i < packages.size(); i++) {
                std::cout << "Package " << i + 1 << ":" << std::endl;
                packages[i]->print_info();
                std::cout << std::endl << std::endl;
                total_cost = total_cost + packages[i]->calculate_cost();
            }
            // Print total cost of packages.
            std::cout << std::fixed << std::setprecision(2) << "Total cost of all the packages: " << "$" << total_cost << std::endl;
            break;
        } case 1: {
            bool show_menu = true;
            int selection;

            // Force adding packages until user quits.
            while (show_menu) {
                // Show current total of packages and cost.
                std::cout << "Number of packages: " << packages.size() << std::endl;
                std::cout << "Total cost: " << std::fixed << std::setprecision(2) << "$" << total_cost << std::endl;
                // Show package options.
                std::cout << "0) Cost per ounce for a package:             $0.50/ounce" << std::endl;
                std::cout << "1) Additional cost for two day delivery:     $2.00/ounce" << std::endl;
                std::cout << "2) Additional cost for overnight delivery:   $5.00/ounce" << std::endl;
                std::cout << "3) Print packages and quit" << std::endl << std::endl;
                std::cin >> selection;

                // Select what type of package you want to add.
                // Set new pointer and push back to vector for every new addition.
                switch (selection) {
                    case 0: {
                        Package *new_package = new Package;
                        new_package->set_attributes();
                        total_cost = total_cost + new_package->calculate_cost();
                        packages.push_back(new_package);
                        break;
                    } case 1: {
                        TwoDayPackage *new_package = new TwoDayPackage;
                        new_package->set_attributes();
                        total_cost = total_cost + new_package->calculate_cost();
                        packages.push_back(new_package);
                        break;
                    } case 2: {
                        OvernightPackage *new_package = new OvernightPackage;
                        total_cost = total_cost + new_package->calculate_cost();
                        new_package->set_attributes();
                        break;
                    } case 3: {
                        show_menu = false;
                        break;
                    } default: {
                        std::cout << "Invalid option" << std::endl << std:: endl;
                    }
                }
            }

            // Print all package information.
            for (int i = 0; i < packages.size(); i++) {
                std::cout << "Package " << i + 1 << ":" << std::endl;
                packages[i]->print_info();
                std::cout << std::endl << std::endl;
            }
            // Print total cost of packages.
            std::cout << std::fixed << std::setprecision(2) << "Total cost of all the packages: " << "$" << total_cost << std::endl;
        }
    }
    return 0;
}
