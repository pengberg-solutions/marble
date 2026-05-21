// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef MARBLE_DGML_OPACITY_TAG_HANDLER_H
#define MARBLE_DGML_OPACITY_TAG_HANDLER_H

#include "GeoTagHandler.h"

namespace Marble
{
namespace dgml
{

class DgmlOpacityTagHandler: public GeoTagHandler
{
public:
    GeoNode* parse( GeoParser& ) const override;
};

}
}

#endif
