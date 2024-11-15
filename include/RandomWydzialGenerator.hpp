#include <array>
#include <format>
#include <random>

inline constexpr std::array wydzial_names{
    "Chemiczny",
    "Geodezji i Kartografii",
    "Administracji i Nauk Spolecznych",
    "Architektury",
    "Budownictwa, Mechaniki i Petrochemii",
    "Elektroniki i Technik Informacyjnych",
    "Elektryczny",
    "Fizyki",
    "Instalacji Budowlanych, Hydrotechniki i Inzynierii Srodowiska",
    "Inzynierii Chemicznej i Procesowej",
    "Inzynierii Ladowej",
    "Inzynierii Materialowej",
    "Matematyki i Nauk Informacyjnych",
    "Mechaniczny Energetyki i Lotnictwa",
    "Mechaniczny Technologiczny",
    "Mechatroniki",
    "Samochodow i Maszyn Roboczych",
    "Transportu",
    "Zarzadzania"
};


inline auto getWydzialName() -> std::string {
    static auto prng = std::mt19937{std::random_device{}()};
    auto fnd = std::uniform_int_distribution<std::size_t>{0, wydzial_names.size() - 1};
    const auto wydzial_name = wydzial_names[fnd(prng)];
    return std::format("{}", wydzial_name);
}

