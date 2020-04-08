#include <memory>
#include <cstdlib>
#include <restbed>

#include "Calculator_resource.h"

using namespace std;
using namespace restbed;

int main(const int, const char**)
{
    Calculator_resource calc_resource;

    auto settings = make_shared<Settings>();
    settings->set_port(8080);
    settings->set_default_header("Connection", "close");
    settings->set_default_header( "Access-Control-Allow-Origin", "*");

    Service service;
    service.publish(calc_resource.get_resource());
    service.start(settings);

    return EXIT_SUCCESS;
}