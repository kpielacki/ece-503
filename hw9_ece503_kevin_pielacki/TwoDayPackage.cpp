#include <iostream>
#include <string>
#include "Package.h"
#include "TwoDayPackage.h"


TwoDayPackage::TwoDayPackage() : Package() {
    set_flat_fee(1);
}


TwoDayPackage::TwoDayPackage(std::string send_name_in, std::string send_address_in, std::string send_city_in, std::string send_state_in, unsigned int send_zip_in, std::string rec_name_in, std::string rec_address_in, std::string rec_city_in, std::string rec_state_in, unsigned int rec_zip_in, double weight_in, double flat_fee_in) : Package(send_name_in, send_address_in, send_city_in, send_state_in, send_zip_in, rec_name_in, rec_address_in, rec_city_in, rec_state_in, rec_zip_in, weight_in) {
    set_flat_fee(flat_fee_in);
}


double TwoDayPackage::get_flat_fee() const {
    return flat_fee;
}


void TwoDayPackage::set_flat_fee(double flat_fee_in) {
    // Set flat_fee to one if non-positive.
    if ( flat_fee_in <= 0 ) {
        std::cout << "Flat fee must be positive. Setting value to 1." << std::endl;
        flat_fee = 1;
    } else {
        flat_fee = flat_fee_in;
    }
}


double TwoDayPackage::calculate_cost() const {
    return get_flat_fee() * get_weight();
}
