#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include "kevin_pielacki_Package.h"


// Default Constructor
Package::Package() {
    // Set cost rate, weight, and zip digit count default values.
    Package::min_weight = 0.06;
    Package::set_cost_rate(0.5);
    Package::set_weight(Package::min_weight);
    Package::zip_digit_cnt = 5;

    // Set sender information to empty values.
    Package::set_send_name("");
    Package::set_send_address("");
    Package::set_send_city("");
    Package::set_send_state("");
    Package::set_send_zip(0);

    // Set receiver information to empty values.
    Package::set_rec_name("");
    Package::set_rec_address("");
    Package::set_rec_city("");
    Package::set_rec_state("");
    Package::set_rec_zip(0);
}


// Constructor set all values.
Package::Package(std::string send_name_in, std::string send_address_in, std::string send_city_in, std::string send_state_in, unsigned int send_zip_in, std::string rec_name_in, std::string rec_address_in, std::string rec_city_in, std::string rec_state_in, unsigned int rec_zip_in, double cost_rate_in, double weight_in) {
    // Set cost rate, weight, and zip digit count values.
    Package::min_weight = 0.06;
    Package::set_cost_rate(cost_rate_in);
    Package::set_weight(weight_in);
    Package::zip_digit_cnt = 5;

    // Set sender values.
    Package::set_send_name(send_name_in);
    Package::set_send_address(send_address_in);
    Package::set_send_city(send_city_in);
    Package::set_send_state(send_state_in);
    Package::set_send_zip(send_zip_in);

    // Set reciver values.
    Package::set_rec_name(rec_name_in);
    Package::set_rec_address(rec_address_in);
    Package::set_rec_city(rec_city_in);
    Package::set_rec_state(rec_state_in);
    Package::set_rec_zip(rec_zip_in);
}


// Returns shipment type. Used to identify object.
std::string Package::get_delivery_type() const {
    return "Regular";
}


/* ############################################################################
    Sender Methods
############################################################################ */


std::string Package::Package::get_send_name() const {
    return send_name;
}


void Package::set_send_name(std::string send_name_in) {
    send_name = send_name_in;
}


std::string Package::get_send_address() const {
    return send_address;
}


void Package::set_send_address(std::string send_address_in) {
   send_address = send_address_in;
}


std::string Package::get_send_city() const {
    return send_city;
}


void Package::set_send_city(std::string send_city_in) {
    send_city = send_city_in;
}


std::string Package::get_send_state() const {
    return send_state;
}


void Package::set_send_state(std::string send_state_in) {
    send_state = send_state_in;
}


unsigned int Package::get_send_zip() const {
    return send_zip;
}


// Returns zero padded zip code of sender.
std::string Package::get_send_zip_padded() const {
    std::string zip_string;
    int check_num, digit_cnt;

    zip_string = "";
    check_num = get_send_zip();
    digit_cnt = 0;

    // Count zip code digits to front pad zeros.
    do {
        check_num /= 10;
        digit_cnt++;
    } while (check_num);

    for (int i = 0; i < zip_digit_cnt - digit_cnt; i++) {
        zip_string = zip_string + "0";
    }

    // Opens string stream to convert int value to string.
    std::ostringstream ss;
    ss << get_send_zip();
    zip_string = zip_string + ss.str();

    return zip_string;
}


void Package::set_send_zip(unsigned int send_zip_in) {
    // Calculate range check for ensuring zip in proper range.
    unsigned int zip_range = 1;
    for (int i = 0; i < zip_digit_cnt; i++) {
       zip_range *= 10;
    }

    // Make sure zip code fits within digit range.
    if (send_zip_in >= zip_range) {
        std::cout << "Zip code can only have a maximum of " <<
        zip_digit_cnt << " digits. Setting sender zip code to 0." << std::endl;
        send_zip = 0;
    } else {
        send_zip = send_zip_in;
    }
}


/******************************************************************************
    Reciver Methods
******************************************************************************/


std::string Package::Package::get_rec_name() const {
    return rec_name;
}


void Package::set_rec_name(std::string rec_name_in) {
    rec_name = rec_name_in;
}


std::string Package::get_rec_address() const {
    return rec_address;
}


void Package::set_rec_address(std::string rec_address_in) {
   rec_address = rec_address_in;
}


std::string Package::get_rec_city() const {
    return rec_city;
}


void Package::set_rec_city(std::string rec_city_in) {
    rec_city = rec_city_in;
}


std::string Package::get_rec_state() const {
    return rec_state;
}


void Package::set_rec_state(std::string rec_state_in) {
    rec_state = rec_state_in;
}


unsigned int Package::get_rec_zip() const {
    return rec_zip;
}


// Returns zero padded zip code of receiver.
std::string Package::get_rec_zip_padded() const {
    std::string zip_string;
    int check_num, digit_cnt;

    zip_string = "";
    check_num = get_rec_zip();
    digit_cnt = 0;

    // Count digits in zip code.
    do {
        check_num /= 10;
        digit_cnt++;
    } while (check_num);

    for (int i = 0; i < zip_digit_cnt - digit_cnt; i++) {
        zip_string = zip_string + "0";
    }

    // Opens string stream to convert int value to string.
    std::ostringstream ss;
    ss << get_rec_zip();
    zip_string = zip_string + ss.str();

    return zip_string;
}


void Package::set_rec_zip(unsigned int rec_zip_in) {
    // Calculate range check for ensuring zip in proper range.
    unsigned int zip_range = 1;
    for (int i = 0; i < zip_digit_cnt; i++) {
       zip_range *= 10;
    }

    // Make sure zip code fits within digit range.
    if (rec_zip_in >= zip_range) {
        std::cout << "Zip code can only have a maximum of " <<
        zip_digit_cnt << " digits. Setting receiver zip code to 0." << std::endl;
        rec_zip = 0;
    } else {
        rec_zip = rec_zip_in;
    }
}


/*****************************************************************************
    Weight and Cost
*****************************************************************************/


double Package::get_cost_rate() const {
    return cost_rate;
}


void Package::set_cost_rate(double cost_rate_in) {
    if (cost_rate_in < 0) {
        std::cout << "Cost rate must be non-negative. Setting cost rate value to 0.5." << std::endl;
        cost_rate = 0.5;
    } else {
        cost_rate = cost_rate_in;
    }
}


double Package::get_weight() const {
    return weight;
}


void Package::set_weight(double weight_in) {
    // If entered weight is below minimum display message and set to min_weight.
    if ( weight_in < min_weight ) {
        std::cout << "Weight cannot be below " << min_weight <<
        ". Setting weight value to " << min_weight << "." << std::endl;
        weight = min_weight;
    } else {
        weight = weight_in;
    }
}


// Calculate cost based on cost_rate and weight.
double Package::calculate_cost() const {
    // cost_rate * weight
    return (get_cost_rate() * get_weight());
}


void Package::set_attributes() {
    std::string send_first_name_in;
    std::string send_last_name_in;
    std::string send_address_in;
    std::string send_city_in;
    std::string send_state_in;
    unsigned int send_zip_in;
    std::string rec_first_name_in;
    std::string rec_last_name_in;
    std::string rec_address_in;
    std::string rec_city_in;
    std::string rec_state_in;
    unsigned int rec_zip_in;
    double weight_in;

    // Sender information.
    std::cout << "Sender First Name: ";
    std::cin >> send_first_name_in;
    std::cout << "Sender Last Name: ";
    std::cin >> send_last_name_in;
    std::cout << "Sender Address: ";
    std::getline(std::cin.ignore(), send_address_in);
    std::cout << "Sender City: ";
    std::cin >> send_city_in;
    std::cout << "Sender State: ";
    std::cin >> send_state_in;
    while (true) {
        std::cout << "Sender Zip Code: ";
        std::cin >> send_zip_in;
        unsigned int zip_range = 1;
        for (int i = 0; i < zip_digit_cnt; i++) {
           zip_range *= 10;
        }

        // Make sure zip code fits within digit range.
        if (send_zip_in >= zip_range) {
            std::cout << "Zip code can only have a maximum of " <<
            zip_digit_cnt << " digits." << std::endl;
        } else {
            send_zip = send_zip_in;
            break;
        }
    }

    // Receiver information.
    std::cout << "Receiver First Name: ";
    std::cin >> rec_first_name_in;
    std::cout << "Receiver Last Name: ";
    std::cin >> rec_last_name_in;
    std::cout << "Receiver Address: ";
    std::getline(std::cin.ignore(), rec_address_in);

    std::cout << "Receiver City: ";
    std::cin >> rec_city_in;
    std::cout << "Receiver State: ";
    std::cin >> rec_state_in;

    // Ensure valid zip code range.
    while (true) {
        std::cout << "Receiver Zip Code: ";
        std::cin >> rec_zip_in;
        unsigned int zip_range = 1;
        for (int i = 0; i < zip_digit_cnt; i++) {
           zip_range *= 10;
        }

        // Make sure zip code fits within digit range.
        if (rec_zip_in >= zip_range) {
            std::cout << "Zip code can only have a maximum of " <<
            zip_digit_cnt << " digits." << std::endl;
        } else {
            rec_zip = rec_zip_in;
            break;
        }
    }

    // Ensure package is of minimum weight.
    do {
        std::cout << "Package Weight (cannot be below " << min_weight << "): ";
        std::cin >> weight_in;
    } while (weight_in < min_weight);
    Package::set_weight(weight_in);

    // Set sender values.
    Package::set_send_name(send_first_name_in + " " + send_last_name_in);
    Package::set_send_address(send_address_in);
    Package::set_send_city(send_city_in);
    Package::set_send_state(send_state_in);
    Package::set_send_zip(send_zip_in);

    // Set reciver values.
    Package::set_rec_name(rec_first_name_in + " " + rec_last_name_in);
    Package::set_rec_address(rec_address_in);
    Package::set_rec_city(rec_city_in);
    Package::set_rec_state(rec_state_in);
    Package::set_rec_zip(rec_zip_in);
}


// Print sender, receiver, cost, weight, and shipment type information.
void Package::print_info() const {
    std::cout << "Sender:\n" << get_send_name() << "\n" << get_send_address() <<
    "\n" << get_send_city() << ", " << get_send_state() << " " << get_send_zip_padded() <<
    "\n\nReceipent:\n" << get_rec_name() << "\n" << get_rec_address() <<
    "\n" << get_rec_city() << ", " << get_rec_state() << " " << get_rec_zip_padded() <<
    "\n\n" << "Weight of package: " << get_weight() << " ounces" <<
    "\n" << "Type of delivery: " << get_delivery_type() << " Delivery" <<
    "\n" << "Cost of package: $" <<  std::fixed << std::setprecision(2) << calculate_cost();
}


// Overload cout operator for sender, receiver, cost, weight, and shipment type print.
std::ostream& operator<<(std::ostream &os, const Package& p) {
    return os << "Sender:\n" << p.get_send_name() << "\n" << p.get_send_address() <<
    "\n" << p.get_send_city() << ", " << p.get_send_state() << " " << p.get_send_zip_padded() <<
    "\n\nReceipent:\n" << p.get_rec_name() << "\n" << p.get_rec_address() <<
    "\n" << p.get_rec_city() << ", " << p.get_rec_state() << " " << p.get_rec_zip_padded() <<
    "\n\n" << "Weight of package: " << p.get_weight() << " ounces" <<
    "\n" << "Type of delivery: " << p.get_delivery_type() << " Delivery" <<
    "\n" << "Cost of package: $" << std::fixed << std::setprecision(2) << p.calculate_cost();
}

