#include "TransformHandler.h"

D3DXMATRIX* TransformHandler::GetScaleMatrix(Pair scale)
{
    D3DXMATRIX scaleMatrix;
    D3DXMatrixScaling(&scaleMatrix, scale.GetFirstValue(), scale.GetSecondValue(), 1);

    return &scaleMatrix;
}

// *
const D3DXMATRIX* TransformHandler::GetTransformMatrix(Point cameraPoint)
{
    D3DXMATRIX transformMatrix;
    D3DXMatrixIdentity(&transformMatrix);
    transformMatrix._22 = -1;
    transformMatrix._41 = -cameraPoint.GetFirstValue();
    transformMatrix._22 = cameraPoint.GetSecondValue();
    
    return &transformMatrix;
}

D3DXMATRIX* TransformHandler::GetTranslationMatrix(Pair translation)
{
    D3DXMATRIX translationMatrix;
    D3DXMatrixTranslation(&translationMatrix, translation.GetFirstValue(), translation.GetSecondValue(),
        0);

    return &translationMatrix;
}
// *