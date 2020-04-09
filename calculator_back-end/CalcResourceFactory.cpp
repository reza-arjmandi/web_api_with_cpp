#include "CalcResourceFactory.h"

#include <sstream>
#include <iomanip>
#include "json.hpp"

using namespace nlohmann;

CalcResourceFactory::CalcResourceFactory() {
    _resource = make_shared<Resource>();
    _resource->set_path(
        "/{operation: add|subtract|multiply|divide}"
        "/{num1: [-+]?[0-9]*\\.?[0-9]*}"
        "/{num2: [-+]?[0-9]*\\.?[0-9]*}");
    _resource->set_method_handler("GET", 
        [&](const auto session) {
            get_handler(session);
        });
}

shared_ptr<Resource> CalcResourceFactory::get_resource() const {
        return _resource;
}

float CalcResourceFactory::calculate(float num1, float num2, string operation) {
    if(operation == "add") {
        return num1 + num2;
    }
    else if(operation == "subtract") {
        return num1 - num2;
    }
    else if(operation == "multiply") {
        return num1 * num2;
    }
    else if(operation == "divide") {
        return num1 / num2;
    }
}

tuple<float, float, string> CalcResourceFactory::get_path_parameters(
        const shared_ptr<Session> session) const {
    const auto& request = session->get_request();
    const auto operation = request->get_path_parameter("operation");
    auto num1 = atof(request->get_path_parameter("num1").c_str());
    auto num2 = atof(request->get_path_parameter("num2").c_str());
    return make_tuple(num1, num2, operation);
} 

string CalcResourceFactory::to_json(float result) {
    ostringstream str_stream;
    str_stream << result;
    json jsonResult = {
        {"result", str_stream.str()}
    };
    return jsonResult.dump();
}

void CalcResourceFactory::get_handler(const shared_ptr<Session> session) {
    const auto [num1, num2, operation] = get_path_parameters(session);
    auto result = calculate(num1, num2, operation);
    auto content = to_json(result);
    session->close(OK, content, 
        {{"Content-Length", to_string(content.size())}});
}