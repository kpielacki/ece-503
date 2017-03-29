#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include "Package.h"


class TwoDayPackage : public Package {

    public:
        TwoDayPackage();
        TwoDayPackage(std::string send_name_in, std::string send_address_in, std::string send_city_in, std::string send_state_in, unsigned int send_zip_in, std::string rec_name_in, std::string rec_address_in, std::string rec_city_in, std::string rec_state_in, unsigned int rec_zip_in, double weight_in, double flat_fee_in);
        double get_flat_fee();
        void set_flat_fee(double flat_fee_in);
        double calculateCost();

    private:
        double flat_fee;

};

#endif
