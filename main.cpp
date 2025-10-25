#include <iostream>
#include <vector>
#include <memory>
#include "rectangle.h"
#include "trapezoid.h"
#include "rhombus.h"

int main() {
    std::vector<std::unique_ptr<Figure>> figures;
    int choice;

    std::cout << "=== Figure Management System ===\n";

    while (true) {
        std::cout << "\n1 - Rectangle\n2 - Trapezoid\n3 - Rhombus\n0 - Finish input\nChoice: ";
        std::cin >> choice;
        if (choice == 0) break;

        std::unique_ptr<Figure> fig;

        switch (choice) {
            case 1: fig = std::make_unique<Rectangle>(); break;
            case 2: fig = std::make_unique<Trapezoid>(); break;
            case 3: fig = std::make_unique<Rhombus>(); break;
            default:
                std::cout << "Invalid choice!\n";
                continue;
        }

        std::cin >> *fig;
        figures.push_back(std::move(fig));
    }

    double total_area = 0;
    std::cout << "\n=== All Figures ===\n";
    for (size_t i = 0; i < figures.size(); ++i) {
        auto [cx, cy] = figures[i]->center();
        std::cout << "Figure " << i << ": " << *figures[i]
                  << ", Center=(" << cx << ", " << cy << ")"
                  << ", Area=" << static_cast<double>(*figures[i]) << "\n";
        total_area += figures[i]->area();
    }
    std::cout << "Total area: " << total_area << "\n";

    if (!figures.empty()) {
        int idx;
        std::cout << "\nEnter index to delete: ";
        std::cin >> idx;
        if (idx >= 0 && idx < static_cast<int>(figures.size())) {
            figures.erase(figures.begin() + idx);
            std::cout << "Figure deleted.\n";
        } else {
            std::cout << "Invalid index!\n";
        }
    }

    total_area = 0;
    std::cout << "\n=== Figures after deletion ===\n";
    for (size_t i = 0; i < figures.size(); ++i) {
        std::cout << "Figure " << i << ": " << *figures[i]
                  << ", Area=" << static_cast<double>(*figures[i]) << "\n";
        total_area += figures[i]->area();
    }
    std::cout << "Total area after deletion: " << total_area << "\n";

    if (figures.size() >= 2) {
        std::cout << "Figure 0 == Figure 1: "
                  << ((*figures[0] == *figures[1]) ? "true" : "false") << "\n";
    }

    return 0;
}
