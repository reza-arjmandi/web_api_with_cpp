#pragma once

#include <string>
#include <tuple>

#include "IResourceFactory.h"

class CalcResourceFactory : public IResourceFactory {

public:

    CalcResourceFactory();
    shared_ptr<Resource> get_resource() const final;

private:

    float calculate(float num1, float num2, string operation);
    tuple<float, float, string> 
            get_path_parameters(const shared_ptr<Session> session) const;
    string to_json(float result);
    void get_handler(const shared_ptr<Session> session);

    shared_ptr<Resource> _resource;
};