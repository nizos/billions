#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <cstddef>
#include <tuple>

using namespace std;

int main() {
    ifstream file("data.txt");

        string line;
        string country;
        int population;
        size_t last_space_index;
        unordered_map<string, tuple<int, int>> countries;

        if (file.is_open()) {

            while (getline(file, line)) {
                last_space_index = line.find_last_of(" ");
                country = line.substr(0, last_space_index);
                population = stoi(line.substr(last_space_index + 1));

                if (auto exists = countries.find(country); exists == countries.end())
                {
                    // Set initial population
                    get<0>(countries[country]) = population;
                }
                // update current population
                get<1>(countries[country]) += population;
            }

            file.close();

            // Find country with largest population change in percentage
            string country_name;
            double delta;
            double largest_delta = 0.0;

            for (auto country = countries.begin(); country != countries.end(); ++country)
            {
                // (current population - initial population) / initial population
                delta = abs((get<1>(country->second) - get<0>(country->second))) / get<0>(country->second);
                if (delta > largest_delta)
                {
                    largest_delta = delta;
                    country_name = country->first;
                }
            }

            cout << country_name << " " << get<1>(countries[country_name]) << endl;
        }
        else {
            cerr << "Unable to open file!" << endl;
        }
    return 0;
}
