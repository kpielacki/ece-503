#include <iostream>
#include <iomanip>
#include <string>
#include "kevin_pielacki_Package.h"
#include "kevin_pielacki_TwoDayPackage.h"


// Used base class default constructor and set flat_fee.
TwoDayPackage::TwoDayPackage() : Package() {
    set_flat_fee(2);
}


// Use base class parameter constructor and set flat_fee.
TwoDayPackage::TwoDayPackage(std::string send_name_in, std::string send_address_in, std::string send_city_in, std::string send_state_in, unsigned int send_zip_in, std::string rec_name_in, std::string rec_address_in, std::string rec_city_in, std::string rec_state_in, unsigned int rec_zip_in, double cost_rate_in, double weight_in, double flat_fee_in) : Package(send_name_in, send_address_in, send_city_in, send_state_in, send_zip_in, rec_name_in, rec_address_in, rec_city_in, rec_state_in, rec_zip_in, cost_rate_in, weight_in) {
    set_flat_fee(flat_fee_in);
}


// Print shipment type.
std::string TwoDayPackage::get_delivery_type() const {
    return "Two Day";
}


// Getter for flat_fee.
double TwoDayPackage::get_flat_fee() const {
    return flat_fee;
}


// Setter for flat_fee.
void TwoDayPackage::set_flat_fee(double flat_fee_in) {
    // Set flat_fee to one if non-positive.
    if ( flat_fee_in <= 0 ) {
        std::cout << "Flat fee must be positive. Setting value to 2." << std::endl;
        flat_fee = 2;
    } else {
        flat_fee = flat_fee_in;
    }
}


// Return cost calculation based on cost rate, flat_fee, and weight.
double TwoDayPackage::calculate_cost() const {
    // (cost_rate + flat_fee) * weight
    return ((get_cost_rate() + get_flat_fee()) * get_weight());
}


// Overload cout operator.
// Make sure pointer is casted as TwoDayPackage and not derived class Package.
std::ostream& operator<<(std::ostream &os, const TwoDayPackage& p) {
    return os << "Sender:\n" << p.get_send_name() << "\n" << p.get_send_address() <<
        "\n" << p.get_send_city() << ", " << p.get_send_state() << " " << p.get_send_zip() <<
        "\n\nReceipent:\n" << p.get_rec_name() << "\n" << p.get_rec_address() <<
        "\n" << p.get_rec_city() << ", " << p.get_rec_state() << " " << p.get_rec_zip() <<
        "\n\n" << "Weight of package: " << p.get_weight() << " ounces" <<
        "\n" << "Type of delivery: " << p.get_delivery_type() << " Delivery" <<
        "\n" << "Cost of package: $" << std::setprecision(3) << p.calculate_cost();
}
