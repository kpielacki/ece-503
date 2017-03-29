#ifndef PACKAGE_H_
#define PACKAGE_H_
#include <string>

class Package {

    public:
        Package();
        Package(std::string send_name_in, std::string send_address_in, std::string send_city_in, std::string send_state_in, unsigned int send_zip_in, std::string rec_name_in, std::string rec_address_in, std::string rec_city_in, std::string rec_state_in, unsigned int rec_zip_in, double weight_in);

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
        void set_rec_zip(unsigned int zip_in);

        double get_weight() const; 
        void set_weight(double weight_in);

        virtual double calculate_cost() const;
        friend std::ostream& operator<<(std::ostream &os, const Package& p);

    private:
        std::string send_name;
        std::string send_address;
        std::string send_city;
        std::string send_state;
        unsigned int send_zip;

        std::string rec_name;
        std::string rec_address;
        std::string rec_city;
        std::string rec_state;
        unsigned int rec_zip;

        double weight;

};

#endif
