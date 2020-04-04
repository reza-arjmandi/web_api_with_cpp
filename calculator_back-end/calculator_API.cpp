#include <memory>
#include <cstdlib>
#include <restbed>
#include <string>

using namespace std;
using namespace restbed;

void calc_handler(const shared_ptr<Session> session)
{
    const auto& request = session->get_request();
    const auto operation = request->get_path_parameter("operation");
    auto num1 = atof(request->get_path_parameter("num1").c_str());
    auto num2 = atof(request->get_path_parameter("num2").c_str());

    auto result = string("{\"result\": ");

    if(operation == "add")
    {
        result +=  to_string(num1 + num2);
    }
    else if(operation == "subtract")
    {
        result += to_string(num1 - num2);
    }
    else if(operation == "multiply")
    {
        result += to_string(num1 * num2);
    }
    else if(operation == "divide")
    {
        result += to_string(num1 / num2);
    }

    result += "}";

    session->close(
        OK, result, {{"Content-Length", to_string(result.size())}});
}

int main(const int, const char**)
{
    auto calc_resource = make_shared<Resource>();
    calc_resource->set_path(
        "/{operation: add|subtract|multiply|divide}"
        "/{num1: [-+]?[0-9]*\\.?[0-9]*}"
        "/{num2: [-+]?[0-9]*\\.?[0-9]*}");
    calc_resource->set_method_handler("GET", calc_handler);

    auto settings = make_shared<Settings>();
    settings->set_port(8080);
    settings->set_default_header("Connection", "close");
    settings->set_default_header( "Access-Control-Allow-Origin", "*");

    Service service;
    service.publish(calc_resource);
    service.start(settings);

    return EXIT_SUCCESS;
}