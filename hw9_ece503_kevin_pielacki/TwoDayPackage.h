#ifndef TWO_DAY_PACKAGE_H_
#define TWO_DAY_PACKAGE_H_

#include <iostream>
#include <string>
#include "Package.h"


class TwoDayPackage : public Package {

    public:
        // Default Constructor
        TwoDayPackage();
        // Set all values based on input.
        TwoDayPackage(std::string send_name_in, std::string send_address_in, std::string send_city_in, std::string send_state_in, unsigned int send_zip_in, std::string rec_name_in, std::string rec_address_in, std::string rec_city_in, std::string rec_state_in, unsigned int rec_zip_in, double weight_in, double flat_fee_in);

        // Used to indentify delivery type.
        // All getters set as const function so object remains immutable during call.
        std::string get_delivery_type() const;
        double get_flat_fee() const;
        void set_flat_fee(double flat_fee_in);
        double calculate_cost() const;

        // Overload cout operator for sender, receiver, cost, weight, and shipment type print.
        friend std::ostream& operator<<(std::ostream &os, const TwoDayPackage& p);

    private:
        // Flat fee rate per ounce additional to base fee.
        // Default value: 2
        double flat_fee;

};

#endif
