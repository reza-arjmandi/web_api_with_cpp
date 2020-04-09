#pragma once

#include <memory>
#include <restbed>

using namespace std;
using namespace restbed;

class IResourceFactory {

public:

    virtual shared_ptr<Resource> get_resource() const = 0;
     
};