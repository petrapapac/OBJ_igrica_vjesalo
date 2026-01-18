
class Statistics {
private:
    int games;
    int wins;
    int losses;

public:
    Statistics();

    void addWin();
    void addLoss();
    void display() const;
};
