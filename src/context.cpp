#include "context.h"
#include "uvc.h"
#include "r200.h"
#include "f200.h"

rs_context::rs_context() : context(rsimpl::uvc::create_context())
{
    for(auto device : query_devices(context))
    {
        // TODO: Check vendor ID against Intel's ID
        switch(get_product_id(*device))
        {
        case 2688: devices.push_back(rsimpl::make_r200_device(device)); break;
        case 2662: devices.push_back(rsimpl::make_f200_device(device)); break;
        case 2725: devices.push_back(rsimpl::make_sr300_device(device)); break;
        }
    }
}

