#include <iostream>
using namespace std;

// Código para usarse en juegos drag and drop.

class DraggableObject {
public:
    virtual void onDropEffect() = 0;
    virtual ~DraggableObject() = default;
};

class Warehouse{
public:
    virtual void getItems() = 0;
    virtual void produce() = 0;
    virtual ~Warehouse() = default;
};

class Seeds : public DraggableObject {
public:
    void onDropEffect() override {
        cout << "Planted a pot" << endl;
    }
};

class Paint : public DraggableObject {
    public:
        void onDropEffect() override {
            cout << "Painted a piece" << endl;
        }
    };

class GardenWarehouse : public Warehouse {
    public:
        void getItems() override {
            cout << "Seeds and fertilizer" << endl;
        }

        void produce() override {
            cout << "A plant has been produced" << endl;
        }
};

class ConstructionWarehouse : public Warehouse {
    public:
        void getItems() override {
            cout << "Paint, hammer" << endl;
        }

        void produce() override {
            cout << "A toy has been produced" << endl;
        }
};

int main() {
    Seeds seeds;
    Paint paint;

    // Probar efecto on Drop
    cout << "Seeds: ";
    seeds.onDropEffect();

    cout << "Paint: ";
    paint.onDropEffect();

    // Crear warehouses
    GardenWarehouse gardenWarehouse;
    ConstructionWarehouse constructionWarehouse;

    // Mostrar los items y producir
    cout << endl;
    gardenWarehouse.getItems();
    gardenWarehouse.produce();
    cout << endl;
    constructionWarehouse.getItems();
    constructionWarehouse.produce();

    return 0;
}
