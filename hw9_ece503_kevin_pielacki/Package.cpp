#include<iostream>
#include<string>
#include<cstring>
#include"Package.h"


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
}


Package::Package(std::string send_name_in, std::string send_address_in, std::string send_city_in, std::string send_state_in, unsigned int send_zip_in, std::string rec_name_in, std::string rec_address_in, std::string rec_city_in, std::string rec_state_in, unsigned int rec_zip_in, double weight_in) {
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

    Package::set_weight(weight_in);
}


/* ############################################################################
    Sender Methods
############################################################################ */


std::string Package::Package::get_send_name() {
    return send_name;
}


void Package::set_send_name(std::string send_name_in) {
    send_name = send_name_in;
}


std::string Package::get_send_address() {
    return send_address;
}


void Package::set_send_address(std::string send_address_in) {
   send_address = send_address_in;
}


std::string Package::get_send_city() {
    return send_city;
}


void Package::set_send_city(std::string send_city_in) {
    send_city = send_city_in;
}


std::string Package::get_send_state() {
    return send_state;
}


void Package::set_send_state(std::string send_state_in) {
    send_state = send_state_in;
}


unsigned int Package::get_send_zip() {
    return send_zip;
}


void Package::set_send_zip(unsigned int send_zip_in) {
    send_zip = send_zip_in;
}


/* ############################################################################
    Reciver Methods
############################################################################ */


std::string Package::Package::get_rec_name() {
    return rec_name;
}


void Package::set_rec_name(std::string rec_name_in) {
    rec_name = rec_name_in;
}


std::string Package::get_rec_address() {
    return rec_address;
}


void Package::set_rec_address(std::string rec_address_in) {
   rec_address = rec_address_in;
}


std::string Package::get_rec_city() {
    return rec_city;
}


void Package::set_rec_city(std::string rec_city_in) {
    rec_city = rec_city_in;
}


std::string Package::get_rec_state() {
    return rec_state;
}


void Package::set_rec_state(std::string rec_state_in) {
    rec_state = rec_state_in;
}


unsigned int Package::get_rec_zip() {
    return rec_zip;
}


void Package::set_rec_zip(unsigned int rec_zip_in) {
    rec_zip = rec_zip_in;
}


double Package::get_weight() {
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

