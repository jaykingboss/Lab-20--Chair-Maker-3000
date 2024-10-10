    #include <iostream>
    #include <iomanip>

    using namespace std;
    const int SIZE = 3;

    class Chair {
    private:
        int legs;
        double* prices;
    public:
        Chair() {
            prices = new double[SIZE];
            legs = 3;       
            prices[0] = 412.34;
            prices[1] = 523.45;
            prices[2] = 634.56;
        }
        Chair(int l, const double p[SIZE]) {
            prices = new double[SIZE];
            legs = l;
            for (int i = 0; i < SIZE; i++)
                prices[i] = p[i];
        }

        void setLegs(int l) { legs = l; }
        int getLegs() { return legs; }

        void setPrices(double p1, double p2, double p3) {
            prices[0] = p1; prices[1] = p2; prices[2] = p3;
        }

        double getAveragePrices() {
            double sum = 0;
            for (int i = 0; i < SIZE; i++)
                sum += prices[i];
            return sum / SIZE;
        }

        void print() {
            cout << "CHAIR DATA - legs: " << legs << endl;
            cout << "Price history: ";
            for (int i = 0; i < SIZE; i++)
                cout << prices[i] << " ";
            cout << endl << "Historical avg price: " << getAveragePrices();
            cout << endl << endl;
        }
    };

    int main() {
        cout << fixed << setprecision(2);

        Chair* chairPtr = new Chair;
        chairPtr->setLegs(4);
        chairPtr->setPrices(121.21, 232.32, 414.14);
        chairPtr->print();

        double chairPrices1[SIZE] = { 525.25, 434.34, 252.52 };
        Chair* livingChair = new Chair(3, chairPrices1);
        livingChair->print();
        delete livingChair;
        livingChair = nullptr;

        Chair* collection = new Chair[SIZE];
        for (int i = 0; i < SIZE; i++) {
            collection[i].print();
        }

        return 0;
    }


