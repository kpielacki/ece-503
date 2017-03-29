#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include "Package.h"


// Default Constructor
Package::Package() {
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

    // Set cost rate and weight default values. 
    Package::set_cost_rate(0.5);
    Package::set_weight(0);
}


// Constructor set all values.
Package::Package(std::string send_name_in, std::string send_address_in, std::string send_city_in, std::string send_state_in, unsigned int send_zip_in, std::string rec_name_in, std::string rec_address_in, std::string rec_city_in, std::string rec_state_in, unsigned int rec_zip_in, double cost_rate_in, double weight_in) {
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

    // Set cost rate and weight values.
    Package::set_cost_rate(cost_rate_in);
    Package::set_weight(weight_in);
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


void Package::set_send_zip(unsigned int send_zip_in) {
    send_zip = send_zip_in;
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


void Package::set_rec_zip(unsigned int rec_zip_in) {
    rec_zip = rec_zip_in;
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
    // If entered weight is negative display message and set to zero.
    if ( weight_in < 0 ) {
        std::cout << "Weight must be non-negative. Setting weight value to 0." << std::endl;
        weight = 0;
    } else {
        weight = weight_in;
    }
}


// Calculate cost based on cost_rate and weight.
double Package::calculate_cost() const {
    // cost_rate * weight
    return (get_cost_rate() * get_weight());
}


// Overload cout operator for sender, receiver, cost, weight, and shipment type print.
std::ostream& operator<<(std::ostream &os, const Package& p) {
    return os << "Sender:\n" << p.send_name << "\n" << p.send_address << 
    "\n" << p.send_city << ", " << p.send_state << " " << p.send_zip <<
    "\n\nReceipent:\n" << p.rec_name << "\n" << p.rec_address <<
    "\n" << p.rec_city << ", " << p.rec_state << " " << p.rec_zip <<
    "\n\n" << "Weight of package: " << p.get_weight() << " ounces" <<
    "\n" << "Type of delivery: " << p.get_delivery_type() << " Delivery" <<
    "\n" << "Cost of package: $" << std::setprecision(3) << p.calculate_cost();
}

