#ifndef CITY_INFO_HPP
#define CITY_INFO_HPP
#include "libio.hpp"

class CityInfo {
    std::string city_name;
    std::string street_name;
    int street_number;
    int apartment_number;

public:
    static constexpr int magic_number = 4; //number of elements in block

    CityInfo() = delete;

    CityInfo(std::string city_name, std::string street_name, int street_number, int apartment_number);

    ~CityInfo() = default;

    [[nodiscard]] std::string get_city_name() const;

    [[nodiscard]] std::string get_street_name() const;

    [[nodiscard]] int get_street_number() const;

    [[nodiscard]] int get_apartment_number() const;

    bool operator<(const CityInfo &rhs) const;

    bool operator<=(const CityInfo &rhs) const;

    bool operator>(const CityInfo &rhs) const;

    bool operator>=(const CityInfo &rhs) const;
};

auto city_info_fabric(const std::vector<std::string> &lines) -> std::tuple<int, std::vector<CityInfo> >;

#endif //CITY_INFO_HPP
