#pragma once

#include <memory>
#include <restbed>

using namespace std;
using namespace restbed;

class IServiceSettingsFactory {

public:

    virtual shared_ptr<Settings> get_settings() const = 0;

};