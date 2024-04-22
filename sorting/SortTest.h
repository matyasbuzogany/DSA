#include <string>


class SortTest{
private:
    void (*sort_)(int list[], int size); // the sort routine to be used
    std::string name_; // the name of the sort routine
    double slowtime_;
    bool tooslow_; 
public:
    // theconstructor receives a sorting function, its name, and a threshold time in nanoseconds
    // if the running time of the algorithm is more than the threshold, stop
    SortTest(void (*fn)(int[], int), std::string fnname, double max_ns=1.5e9)
        : sort_{fn}, name_{fnname}, slowtime_{max_ns}, tooslow_{false}
    {}

    // measure one sort and return time in ns
    double timeOne(int rlist[], int npoints) const;

    // measure N sort iterations and return average ns duration
    double timeN(int N, int rlist[], int npoints);

    // convenience method to return the name
    std::string name() const { return name_; }

    // allow reset of tooslow_ flag
    bool fastenough(bool flag) { tooslow_=!flag; }
};