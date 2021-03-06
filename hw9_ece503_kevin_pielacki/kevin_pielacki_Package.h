#ifndef PACKAGE_H_
#define PACKAGE_H_
#include <iostream>
#include <string>

class Package {

    public:
        // Default Constructor
        Package();
        // Set all parameters.
        Package(std::string send_name_in, std::string send_address_in, std::string send_city_in, std::string send_state_in, unsigned int send_zip_in, std::string rec_name_in, std::string rec_address_in, std::string rec_city_in, std::string rec_state_in, unsigned int rec_zip_in, double cost_rate_in, double weight_in);

        // All getters and calculate_cost method is const to allow for cout
        // operator to take a const pointer to the object so it remains
        // immutable.

        // Used to identify delivery type.
        virtual std::string get_delivery_type() const;

        // Sender getters and setters.
        std::string get_send_name() const;
        void set_send_name(std::string name_in);
        std::string get_send_address() const;
        void set_send_address(std::string address_in);
        std::string get_send_city() const;
        void set_send_city(std::string city_in);
        std::string get_send_state() const;
        void set_send_state(std::string state_in);
        unsigned int get_send_zip() const;
        // Return zero padded string of sender zip code.
        std::string get_send_zip_padded() const;
        void set_send_zip(unsigned int zip_in);

        // Receiver getters and setters.
        std::string get_rec_name() const;
        void set_rec_name(std::string name_in);
        std::string get_rec_address() const;
        void set_rec_address(std::string address_in);
        std::string get_rec_city() const;
        void set_rec_city(std::string city_in);
        std::string get_rec_state() const;
        void set_rec_state(std::string state_in);
        unsigned int get_rec_zip() const;
        // Return zero padded string of receiver zip code.
        std::string get_rec_zip_padded() const;
        void set_rec_zip(unsigned int zip_in);

        // Getter and setter for cost and weight parameters.
        double get_cost_rate() const;
        void set_cost_rate(double cost_rate_in);
        double get_weight() const; 
        void set_weight(double weight_in);

        // Virtual function for cost calculation.
        // Derived classes return different calculation methods.
        virtual double calculate_cost() const;

        // Prompts for populating sender, receiver, and weight information.
        void set_attributes();
        
        // Used to print sender, receiver, weight, cost, and shipment type info.
        virtual void print_info() const;
        friend std::ostream& operator<<(std::ostream &os, const Package& p);

    private:
        // Sender name and location information.
        std::string send_name;
        std::string send_address;
        std::string send_city;
        std::string send_state;
        unsigned int send_zip;

        // Receiver name and location information.
        std::string rec_name;
        std::string rec_address;
        std::string rec_city;
        std::string rec_state;
        unsigned int rec_zip;

        // Cost rate per ounce.
        // Default value: $0.50
        double cost_rate;
        // Minimum excepted weight of package.
        // Default value: 0.06
        double min_weight;
        // Weight of package.
        double weight;

        // Sets returned padding from zip_padded methods and restricts zip code to value.
        // Default value: 5
        unsigned int zip_digit_cnt;

};

#endif
