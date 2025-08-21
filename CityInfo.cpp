#include "CityInfo.hpp"

CityInfo::CityInfo(std::string city_name, std::string street_name, const int street_number, const int apartment_number)
    : city_name(std::move(city_name)),
      street_name(std::move(street_name)),
      street_number(street_number),
      apartment_number(apartment_number) {
}

[[nodiscard]] std::string CityInfo::get_city_name() const {
    return city_name;
}

[[nodiscard]] std::string CityInfo::get_street_name() const {
    return street_name;
}

[[nodiscard]] int CityInfo::get_street_number() const {
    return street_number;
}

[[nodiscard]] int CityInfo::get_apartment_number() const {
    return apartment_number;
}

bool CityInfo::operator<(const CityInfo &rhs) const {
    return this->city_name < rhs.city_name;
}

bool CityInfo::operator<=(const CityInfo &rhs) const {
    return rhs >= *this;
}

bool CityInfo::operator>(const CityInfo &rhs) const {
    return rhs < *this;
}

bool CityInfo::operator>=(const CityInfo &rhs) const {
    return !(*this < rhs);
}

/**
 * Fabric function for creating city info classes.
 * @param lines vector with strings
 * @return tuple value city count and vector with city info objects.
 */
auto city_info_fabric(const std::vector<std::string> &lines) -> std::tuple<int, std::vector<CityInfo> > {
    int city_number = std::stoi(lines[0]);
    auto output_vector = std::vector<CityInfo>();
    output_vector.reserve(city_number);
    int line_counter = 1;
    for (int entity_num = 0; entity_num < city_number; ++entity_num) {
        if (line_counter + CityInfo::magic_number > lines.size()) {
            break; //it can be error, but no...
        }
        output_vector.emplace_back(
            lines[line_counter],
            lines[line_counter + 1],
            std::stoi(lines[line_counter + 2]),
            std::stoi(lines[line_counter + 3])
        );

        line_counter += CityInfo::magic_number;
    }
    return std::make_tuple(city_number, output_vector);
}
