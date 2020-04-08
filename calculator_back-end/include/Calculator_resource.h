#include <memory>
#include <restbed>
#include <string>
#include <sstream>
#include <iomanip>
#include <tuple>

#include "json.hpp"

using namespace std;
using namespace restbed;
using namespace nlohmann;

class Calculator_resource {

public:

    Calculator_resource();
    shared_ptr<Resource> get_resource();

private:

    float calculate(float num1, float num2, string operation);
    tuple<float, float, string> 
            get_path_parameters(const shared_ptr<Session> session);
    string to_json(float result);
    void get_handler(const shared_ptr<Session> session);

    shared_ptr<Resource> _resource;
};