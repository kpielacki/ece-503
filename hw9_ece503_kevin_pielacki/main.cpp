#include <iostream>
#include <string>
#include <vector>
#include "Package.h"
#include "TwoDayPackage.h"


int main() {
    TwoDayPackage package1("Mahmoud", "21 Constitutional Ave", "Piscataway", "NJ", 8892, "Kevin", "1 Ericsson Dr", "Piscataway", "NJ", 8895, 0.666, 2);
    std::cout << package1 << std::endl;

    //std::cout << "Sender:" << std::endl;
    //std::cout << package1.get_send_name() << std::endl;    
    //std::cout << package1.get_send_address() << std::endl;    
    //std::cout << package1.get_send_city() << std::endl;
    //std::cout << package1.get_send_state() << std::endl;
    //std::cout << package1.get_send_zip() << std::endl;

    //std::cout << "Receipent:" << std::endl;
    //std::cout << package1.get_rec_name() << std::endl;
    //std::cout << package1.get_rec_address() << std::endl;
    //std::cout << package1.get_rec_city() << std::endl;
    //std::cout << package1.get_rec_state() << std::endl;
    //std::cout << package1.get_rec_zip() << std::endl;

    //std::cout << "Total cost: " << package1.calculate_cost() << std::endl;

    return 0;
}
