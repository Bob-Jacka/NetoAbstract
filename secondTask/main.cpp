#include "../HelperData.hpp"

auto outfile = libio::file::createWriteFile(R"(C:\Users\user\Downloads\NetoAbstract\secondTask\)" + output_file_name);

void print_city_info(const CityInfo &city_info) {
    outfile << city_info.get_city_name() << ", ";
    outfile << city_info.get_street_name() << ", ";
    outfile << city_info.get_street_number() << ", ";
    outfile << city_info.get_apartment_number() << std::endl;
}

int main() {
    const auto vec = libio::file::readFile(R"(C:\Users\user\Downloads\NetoAbstract\secondTask\)" + input_file_name);
    auto [city_number, city_info_vec] = city_info_fabric(vec);
    std::sort(city_info_vec.begin(), city_info_vec.end()); //compare entities in alphabet order of city name.
    outfile << city_number << std::endl;
    for (auto &city_info: city_info_vec) {
        print_city_info(city_info);
    }
    outfile.close();
}
