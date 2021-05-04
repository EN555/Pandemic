//
// Created by eviat on 5/2/2021.
//

#ifndef PANDEMIC_A_BOARD_HPP
#define PANDEMIC_A_BOARD_HPP

#include <sstream>
#include "City.hpp"
#include "Color.hpp"
#include <iostream>
#include <map>
#include <set>
#include <string>

namespace pandemic {
    class Board {
    public:
        Board();
        int &operator[](City city);
        friend std::ostream &operator<<(std::ostream &os, Board &board);
        bool is_clean();
        void remove_cures();    //doesn't throw exception any time
        void add_research_station(City city);  //add research station for city
        void add_cure_for_color(Color color);  //add cure for desease
        bool is_connected(City city1, City city2);
        bool is_have_have_research_station(City city);
        bool is_have_cure_desease(Color color);
        Color city_to_color(City city);

    private:
        std::map <City,std::string> city_color;
        std::map <City, std::set<City>> connections;  //every city have the list of all the cities that connect her
        std::map<City, int> desease_intense;
        std::set<City> research_station;       //boolean - is have research station at this city
        std::set<Color> is_have_cure;        //true if there already exist cure for this desease
        std::map <std::string, City> cities = {
                {"Algiers",       City::Algiers},
                {"Atlanta",       City::Atlanta},
                {"Baghdad",       City::Baghdad},
                {"Bangkok",       City::Bangkok},
                {"Beijing",       City::Beijing},
                {"Bogota",        City::Bogota},
                {"BuenosAires",   City::BuenosAires},
                {"Cairo",         City::Cairo},
                {"Chennai",       City::Chennai},
                {"Chicago",       City::Chicago},
                {"Delhi",         City::Delhi},
                {"Essen",         City::Essen},
                {"HoChiMinhCity", City::HoChiMinhCity},
                {"HongKong",      City::HongKong},
                {"Istanbul",      City::Istanbul},
                {"Jakarta",       City::Jakarta},
                {"Johannesburg",  City::Johannesburg},
                {"Karachi",       City::Karachi},
                {"Khartoum",      City::Khartoum},
                {"Kinshasa",      City::Kinshasa},
                {"Kolkata",       City::Kolkata},
                {"Lagos",         City::Lagos},
                {"Lima",          City::Lima},
                {"London",        City::London},
                {"LosAngeles",    City::LosAngeles},
                {"Madrid",        City::Madrid},
                {"Manila",        City::Manila},
                {"MexicoCity",    City::MexicoCity},
                {"Miami",         City::Miami},
                {"Milan",         City::Milan},
                {"Montreal",      City::Montreal},
                {"Moscow",        City::Moscow},
                {"Mumbai",        City::Mumbai},
                {"NewYork",       City::NewYork},
                {"Osaka",         City::Osaka},
                {"Paris",         City::Paris},
                {"Riyadh",        City::Riyadh},
                {"SanFrancisco",  City::SanFrancisco},
                {"Santiago",      City::Santiago},
                {"SaoPaulo",      City::SaoPaulo},
                {"Seoul",         City::Seoul},
                {"Shanghai",      City::Shanghai},
                {"StPetersburg",  City::StPetersburg},
                {"Sydney",        City::Sydney},
                {"Taipei",        City::Taipei},
                {"Tehran",        City::Tehran},
                {"Tokyo",         City::Tokyo},
                {"Washington",    City::Washington}
        };

        std::map <std::string, Color> Colors = {
                {"Blue", Color::Blue},
                {"Yellow", Color::Yellow},
                {"Black", Color::Black},
                {"Red", Color::Red}
        };

    };

}

#endif //PANDEMIC_A_BOARD_HPP
