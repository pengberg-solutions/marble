// SPDX-License-Identifier: LGPL-2.1-or-later

#include "DgmlOpacityTagHandler.h"

#include "DgmlAttributeDictionary.h"
#include "DgmlElementDictionary.h"
#include "GeoParser.h"
#include "GeoSceneTileDataset.h"
#include "MarbleDebug.h"

namespace Marble
{
namespace dgml
{
static GeoTagHandlerRegistrar registrar( GeoParser::QualifiedName( dgmlTag_Opacity,
                                                                       dgmlTag_nameSpace20 ),
                                         new DgmlOpacityTagHandler );

GeoNode* DgmlOpacityTagHandler::parse( GeoParser& parser ) const
{
    // Check whether the tag is valid
    Q_ASSERT(parser.isStartElement() && parser.isValidElement(QLatin1String(dgmlTag_Opacity)));

    // Checking for parent item — opacity may apply to <texture> or <vectortile>
    GeoStackItem parentItem = parser.parentElement();
    if ( !parentItem.represents( dgmlTag_Texture ) && !parentItem.represents( dgmlTag_Vectortile ))
        return nullptr;

    // Attribute value: a qreal in [0.0, 1.0]. If missing or unparseable,
    // the texture's opacity stays at its constructor default (1.0).
    const QString valueStr = parser.attribute( dgmlAttr_value ).trimmed();
    bool ok = false;
    const qreal opacityValue = valueStr.toDouble( &ok );
    if ( ok ) {
        mDebug() << "DgmlOpacityTagHandler::parse" << opacityValue;
        parentItem.nodeAs<GeoSceneTileDataset>()->setOpacity( opacityValue );
    }

    return nullptr;
}


}
}
