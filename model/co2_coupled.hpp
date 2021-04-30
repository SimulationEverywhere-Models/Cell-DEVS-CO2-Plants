
/**
* Model developed by ChangGao in Cell-DEVS CD++
*/

#ifndef CADMIUM_CELLDEVS_CO2_COUPLED_HPP
#define CADMIUM_CELLDEVS_CO2_COUPLED_HPP

#include <nlohmann/json.hpp>
#include <cadmium/celldevs/coupled/grid_coupled.hpp>
#include "co2_lab_cell.hpp"

template <typename T>
class co2_coupled : public cadmium::celldevs::grid_coupled<T, co2, int> {
public:

    explicit co2_coupled(std::string const &id) : grid_coupled<T, co2, int>(id){}

    template <typename X>
    using cell_unordered = std::unordered_map<std::string,X>;

    void add_grid_cell_json(std::string const &cell_type, cell_map<co2, int> &map, std::string const &delay_id,
                            nlohmann::json const &config) override {
        if (cell_type == "CO2_cell") {
            auto conf = config.get<typename co2_lab_cell<T>::config_type>();
            this->template add_cell<co2_lab_cell>(map, delay_id, conf);
        } else throw std::bad_typeid();
    }
};


#endif //CADMIUM_CELLDEVS_CO2_COUPLED_HPP